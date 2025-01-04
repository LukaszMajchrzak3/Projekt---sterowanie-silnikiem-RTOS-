/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD1602.h"
#include "aio.h"
#include<stdio.h>
#include <math.h>
#include <stdint.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim8;
TIM_HandleTypeDef htim16;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;

/* Definitions for freq_measure */
osThreadId_t freq_measureHandle;
const osThreadAttr_t freq_measure_attributes = {
  .name = "freq_measure",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityHigh1,
};
/* Definitions for motor_control */
osThreadId_t motor_controlHandle;
const osThreadAttr_t motor_control_attributes = {
  .name = "motor_control",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime2,
};
/* Definitions for lcd_text */
osThreadId_t lcd_textHandle;
const osThreadAttr_t lcd_text_attributes = {
  .name = "lcd_text",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityRealtime7,
};
/* Definitions for diode_control */
osThreadId_t diode_controlHandle;
const osThreadAttr_t diode_control_attributes = {
  .name = "diode_control",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* USER CODE BEGIN PV */

int pot1_mV = 0;
int pot1_mV_filtered = 0;
int previous_value = 0;
int previous_value2 = 0;
uint16_t prev_period = 0;
uint16_t freq = 0;
//float freq = 0;
uint16_t cur_period = 0;
//uint16_t vel = 0;
uint16_t vel = 0;
int count_to_clear_lcd = 0;
int ref_vel = 300; //wartosc referencyjna  - JAK NIE DZIALA ZMIENIC NA FLOAT!!!!!!!!!
int pwm_level = 400;
int brake_dyn = 1;
int en_brake = 0;
int direction = 0;
int ref_vel_from_key = 0;
int change_refvel_key = 0;
int was_clicked=0;

int was_reached = 0;

char uart_buf[50];
int uart_buf_len;
char led_buf[50];
int led_buf_len;
HAL_StatusTypeDef uart2_received_status;
//uint8_t single_message_received[] = {0};
uint8_t single_message_received[11];
char single_message_response[30]={0};
uint16_t timer_val = 0;
int change_operation = 0;
int time_acc = 0;

int row=0;
int col=0;

int pwm_control_count = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM3_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM8_Init(void);
static void MX_TIM16_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM1_Init(void);
void start_freq_meas(void *argument);
void start_motor_control(void *argument);
void start_lcd_work(void *argument);
void start_diode_contr(void *argument);

/* USER CODE BEGIN PFP */


/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	HAL_UART_Receive_DMA(&huart2, single_message_received, 11);
	char *charTable = (char *)malloc(10 * sizeof(char));
	sscanf((char*)single_message_received,"%c%c%c%c%c%c%c%c%c%c;",&charTable[0],&charTable[1],&charTable[2],&charTable[3],&charTable[4],&charTable[5],&charTable[6],&charTable[7],&charTable[8],&charTable[9]);
	if((charTable[0] == 'S') & (charTable[1] == 'T') & (charTable[2] == 'A') & (charTable[3] == 'R') & (charTable[4] == 'T') & (charTable[5] == 'M') & (charTable[6] == 'O') & (charTable[7] == 'T') & (charTable[8] == 'O') & (charTable[9] == 'R'))
	{
		brake_dyn = 0;
		en_brake = 0;
		sprintf(single_message_response, "Silnik zalaczony!\r\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
	if((charTable[0] == 'B') & (charTable[1] == 'R') & (charTable[2] == 'A') & (charTable[3] == 'K') & (charTable[4] == 'E') & (charTable[5] == '_') & (charTable[6] == 'D') & (charTable[7] == 'N') & (charTable[8] == 'M') & (charTable[9] == 'C'))
	{
		brake_dyn = 1;
		en_brake = 0;
		sprintf(single_message_response, "Hamowanie dynamiczne!\r\n");
    	HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);

	}
	if((charTable[0] == 'C') & (charTable[1] == 'O') & (charTable[2] == 'N') & (charTable[3] == 'T') & (charTable[4] == 'R') & (charTable[5] == '_') & (charTable[6] == 'S') & (charTable[7] == 'T') & (charTable[8] == 'O') & (charTable[9] == 'P'))
	{
		en_brake = 1;
		brake_dyn = 0;
		sprintf(single_message_response, "Aktywne hamowanie!\r\n");
    	HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
	if((charTable[0] == 'V') & (charTable[1] == 'E') & (charTable[2] == 'L') & (charTable[3] == ':') & (charTable[8] == ';') & (charTable[9] == ';'))
	{
		int num1int = charTable[4] - 48;
		int num2int = charTable[5] - 48;
		int num3int = charTable[6] - 48;
		int num4int = charTable[7] - 48;
//		int ref_vel_local = 0;
		ref_vel = num1int*1000 + num2int*100 + num3int*10 + num4int*1;
//		ref_vel = ref_vel_local;
		sprintf(single_message_response, "Nowa predkosc: %i RPM\r\n",ref_vel);
    	HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
	if((charTable[0] == 'D') & (charTable[1] == 'I') & (charTable[2] == 'R') & (charTable[3] == '_') & (charTable[4] == 'C') & (charTable[5] == 'L') & (charTable[6] == 'K') & (charTable[7] == 'W') & (charTable[8] == 'I') & (charTable[9] == 'S'))
	{
		direction = 0;
		sprintf(single_message_response, "Zmiana kierunku\r\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
	if((charTable[0] == 'D') & (charTable[1] == 'I') & (charTable[2] == 'R') & (charTable[3] == '_') & (charTable[4] == 'C') & (charTable[5] == 'N') & (charTable[6] == 'T') & (charTable[7] == 'R') & (charTable[8] == 'C') & (charTable[9] == 'L'))
	{
		direction = 1;
		sprintf(single_message_response, "Zmiana kierunku\r\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
	if((charTable[0] == 'S') & (charTable[1] == 'E') & (charTable[2] == 'T') & (charTable[3] == '_') & (charTable[4] == 'R') & (charTable[5] == 'E') & (charTable[6] == 'F') & (charTable[7] == 'V') & (charTable[8] == 'E') & (charTable[9] == 'L'))
	{
		change_refvel_key = 1;
		sprintf(single_message_response, "Ustawianie predkosci\r\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)single_message_response, strlen(single_message_response), 50000);
	}
}



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_ADC1_Init();
  MX_TIM8_Init();
  MX_TIM16_Init();
  MX_TIM2_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start(&htim3);
  HAL_TIM_Base_Start(&htim16);
  HAL_TIM_Base_Start(&htim8);

  //lcd_init ();

  //pwm_level = 1000.0;

  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

   if(brake_dyn == 0)
   {
 	  //HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
 	  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1000.0-pwm_level); //wypelnienie
   }
   else if(brake_dyn == 1)
   {
 	  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1000.0);
 	  HAL_GPIO_WritePin(BRAKE_DYN_GPIO_Port, BRAKE_DYN_Pin, GPIO_PIN_SET);
   }

//   UART_StartReception_IT();

   HAL_UART_Receive_DMA(&huart2, single_message_received, 11);

  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of freq_measure */
  freq_measureHandle = osThreadNew(start_freq_meas, NULL, &freq_measure_attributes);

  /* creation of motor_control */
  motor_controlHandle = osThreadNew(start_motor_control, NULL, &motor_control_attributes);

  /* creation of lcd_text */
  lcd_textHandle = osThreadNew(start_lcd_work, NULL, &lcd_text_attributes);

  /* creation of diode_control */
  diode_controlHandle = osThreadNew(start_diode_contr, NULL, &diode_control_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_TIM1
                              |RCC_PERIPHCLK_TIM16|RCC_PERIPHCLK_TIM8
                              |RCC_PERIPHCLK_ADC12|RCC_PERIPHCLK_TIM2
                              |RCC_PERIPHCLK_TIM34;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.Adc12ClockSelection = RCC_ADC12PLLCLK_DIV1;
  PeriphClkInit.Tim1ClockSelection = RCC_TIM1CLK_HCLK;
  PeriphClkInit.Tim16ClockSelection = RCC_TIM16CLK_HCLK;
  PeriphClkInit.Tim8ClockSelection = RCC_TIM8CLK_HCLK;
  PeriphClkInit.Tim2ClockSelection = RCC_TIM2CLK_HCLK;
  PeriphClkInit.Tim34ClockSelection = RCC_TIM34CLK_HCLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_MultiModeTypeDef multimode = {0};
  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Common config
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_ASYNC_DIV1;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_OVERWRITTEN;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the ADC multi-mode
  */
  multimode.Mode = ADC_MODE_INDEPENDENT;
  if (HAL_ADCEx_MultiModeConfigChannel(&hadc1, &multimode) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SingleDiff = ADC_SINGLE_ENDED;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  sConfig.OffsetNumber = ADC_OFFSET_NONE;
  sConfig.Offset = 0;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_SlaveConfigTypeDef sSlaveConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_RESET;
  sSlaveConfig.InputTrigger = TIM_TS_TI1FP1;
  sSlaveConfig.TriggerPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sSlaveConfig.TriggerPrescaler = TIM_ICPSC_DIV1;
  sSlaveConfig.TriggerFilter = 0;
  if (HAL_TIM_SlaveConfigSynchro(&htim1, &sSlaveConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_FALLING;
  sConfigIC.ICSelection = TIM_ICSELECTION_INDIRECTTI;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 71;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 32;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 71;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65534;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM8 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 0;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 65535;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */

}

/**
  * @brief TIM16 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM16_Init(void)
{

  /* USER CODE BEGIN TIM16_Init 0 */

  /* USER CODE END TIM16_Init 0 */

  /* USER CODE BEGIN TIM16_Init 1 */

  /* USER CODE END TIM16_Init 1 */
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 71;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 65535;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM16_Init 2 */

  /* USER CODE END TIM16_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 5, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, A5_Pin|A4_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, A0_Pin|A1_Pin|A2_Pin|BRAKE_DYN_Pin
                          |BRAKE_EN_Pin|D8_Pin|RED_DIODE_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A3_Pin|GREEN_DIODE_Pin|BLUE_DIODE_Pin|PWM_SIGNAL_Pin
                          |DIRECTION_CTRL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : A5_Pin A4_Pin */
  GPIO_InitStruct.Pin = A5_Pin|A4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : A0_Pin A1_Pin A2_Pin D8_Pin
                           RED_DIODE_Pin */
  GPIO_InitStruct.Pin = A0_Pin|A1_Pin|A2_Pin|D8_Pin
                          |RED_DIODE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BRAKE_DYN_Pin BRAKE_EN_Pin */
  GPIO_InitStruct.Pin = BRAKE_DYN_Pin|BRAKE_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_3_Pin BUTTON_2_Pin BUTTON_1_Pin */
  GPIO_InitStruct.Pin = BUTTON_3_Pin|BUTTON_2_Pin|BUTTON_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : A3_Pin GREEN_DIODE_Pin BLUE_DIODE_Pin PWM_SIGNAL_Pin */
  GPIO_InitStruct.Pin = A3_Pin|GREEN_DIODE_Pin|BLUE_DIODE_Pin|PWM_SIGNAL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : BUTTON_4_Pin */
  GPIO_InitStruct.Pin = BUTTON_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BUTTON_4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DIRECTION_CTRL_Pin */
  GPIO_InitStruct.Pin = DIRECTION_CTRL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DIRECTION_CTRL_GPIO_Port, &GPIO_InitStruct);

  /**/
  HAL_I2CEx_EnableFastModePlus(SYSCFG_CFGR1_I2C_PB7_FMP);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_start_freq_meas */
/**
  * @brief  Function implementing the freq_measure thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_start_freq_meas */
void start_freq_meas(void *argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  HAL_ADC_Start(&hadc1);

	  if(HAL_ADC_PollForConversion(&hadc1, ADC1_TIMEOUT) == HAL_OK)
	  {
		  pot1_mV = ADC_REG2VOLTAGE(HAL_ADC_GetValue(&hadc1));
			if((was_reached == 0) & (pot1_mV > 2800)) //2500
			{
				was_reached = 1;
			}

			if((was_reached == 1) & (pot1_mV < 100) & (previous_value < 100))
			{
				was_reached = 0;
				if(change_operation == 0)
				{
					timer_val = __HAL_TIM_GET_COUNTER(&htim16);
					change_operation = 1;
				}
				else if(change_operation == 1)
				{
					timer_val = __HAL_TIM_GET_COUNTER(&htim16) - timer_val;
					change_operation = 0;
					cur_period = timer_val;
					freq = 1000000/cur_period;
					vel = freq*60/4;
					osDelay(1);
				}
			}
	  }
  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_start_motor_control */
/**
* @brief Function implementing the motor_control thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_motor_control */
void start_motor_control(void *argument)
{
  /* USER CODE BEGIN start_motor_control */
  /* Infinite loop */
  for(;;)
  {
	  if(brake_dyn == 1)
	  {
		  HAL_GPIO_WritePin(BRAKE_DYN_GPIO_Port, BRAKE_DYN_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(BRAKE_EN_GPIO_Port, BRAKE_EN_Pin, GPIO_PIN_RESET);
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1000.0-0.0);
		  timer_val = 0;
	  }
	  else if(en_brake == 1)
	  {
		  HAL_GPIO_WritePin(BRAKE_DYN_GPIO_Port, BRAKE_DYN_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(BRAKE_EN_GPIO_Port, BRAKE_EN_Pin, GPIO_PIN_SET);
		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1000.0-0.0);
		  timer_val = 0;
	  }
	  else if((brake_dyn == 0) & (en_brake == 0))
	  {
		  HAL_GPIO_WritePin(BRAKE_DYN_GPIO_Port, BRAKE_DYN_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(BRAKE_EN_GPIO_Port, BRAKE_EN_Pin, GPIO_PIN_RESET);

		  if(vel <= ref_vel)
		  {
			  pwm_level = pwm_level + 1;
		  }
		  else if(vel > ref_vel)
		  {
			  pwm_level = pwm_level - 1;
		  }

		  __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, 1000.0-pwm_level);

		  if(fabs(ref_vel-vel) > 260.0)
		  {
			  osDelay(10);
		  }
		  else if((fabs(ref_vel-vel) <= 260.0) & (fabs(ref_vel-vel) > 70.0))
		  {
			  osDelay(40);
		  }
		  else if(fabs(ref_vel-vel) <= 70.0)
		  {
			  osDelay(500);
		  }
	  }

	  if(direction == 0)
	  {
		  HAL_GPIO_WritePin(DIRECTION_CTRL_GPIO_Port, DIRECTION_CTRL_Pin, GPIO_PIN_RESET);
	  }
	  else if(direction == 1)
	  {
		  HAL_GPIO_WritePin(DIRECTION_CTRL_GPIO_Port, DIRECTION_CTRL_Pin, GPIO_PIN_SET);
	  }
  }
  /* USER CODE END start_motor_control */
}

/* USER CODE BEGIN Header_start_lcd_work */
/**
* @brief Function implementing the lcd_text thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_lcd_work */
void start_lcd_work(void *argument)
{
  /* USER CODE BEGIN start_lcd_work */
	lcd_init();
  /* Infinite loop */
  for(;;)
  {
	  if((brake_dyn == 1) & (change_refvel_key == 0))
	  {
		  lcd_clear();
		  lcd_put_cur(0, 0);
		  lcd_send_string("HAMOWANIE");
		  lcd_put_cur(1, 0);
		  lcd_send_string("DYNAMICZNE!");
		  osDelay(10);
	  }
	  else if((en_brake == 1) & (change_refvel_key == 0))
	  {
		  lcd_clear();
		  lcd_put_cur(0, 0);
		  lcd_send_string("HAMOWANIE");
		  lcd_put_cur(1, 0);
		  lcd_send_string("AKTYWNE!");
		  osDelay(10);
	  }
	  else if((brake_dyn == 0) & (en_brake == 0) & (change_refvel_key == 0))
	  {
			lcd_clear();
			lcd_put_cur(0, 0);
			lcd_send_string("Predkosc:");
//			vel = freq*60/4;
			uart_buf_len = sprintf(led_buf, "%uRPM",vel);
			lcd_send_string(led_buf);
			lcd_put_cur(1, 0);
			uart_buf_len = sprintf(led_buf, "PWM:%d ",pwm_level/10);
			lcd_send_string(led_buf);
			uart_buf_len = sprintf(led_buf, "Ref.:%i",ref_vel);
			lcd_send_string(led_buf);
			osDelay(750);
	  }
	  else if(change_refvel_key == 1)
	  {
		  lcd_clear();
		  lcd_put_cur(0, 0);
		  lcd_send_string("Obecna pr. ref.:");
		  lcd_put_cur(1, 0);
		  uart_buf_len = sprintf(led_buf, "%iRPM",ref_vel_from_key);
		  lcd_send_string(led_buf);

		  if((HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin) == GPIO_PIN_RESET) & (was_clicked == 0))
		  {
			  ref_vel_from_key = ref_vel_from_key + 1;
			  was_clicked = 1;
		  }
		  else if((HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin) == GPIO_PIN_RESET) & (was_clicked == 0))
		  {
			  ref_vel_from_key = ref_vel_from_key + 50;
			  was_clicked = 1;
		  }
		  else if((HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin) == GPIO_PIN_RESET) & (was_clicked == 0))
		  {
			  ref_vel_from_key = ref_vel_from_key - 20;
			  was_clicked = 1;
		  }
		  else if(HAL_GPIO_ReadPin(BUTTON_4_GPIO_Port, BUTTON_4_Pin) == GPIO_PIN_RESET)
		  {
			  ref_vel = ref_vel_from_key;
			  change_refvel_key = 0;
		  }
		  else
		  {
			  was_clicked = 0;
		  }

		  osDelay(100);
	  }
  }
  /* USER CODE END start_lcd_work */
}

/* USER CODE BEGIN Header_start_diode_contr */
/**
* @brief Function implementing the diode_control thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_start_diode_contr */
void start_diode_contr(void *argument)
{
  /* USER CODE BEGIN start_diode_contr */
  /* Infinite loop */
  for(;;)
  {
	  if((vel < 1000) & (brake_dyn == 0) & (en_brake == 0))
	  {
		  HAL_GPIO_WritePin(RED_DIODE_GPIO_Port, RED_DIODE_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(BLUE_DIODE_GPIO_Port, BLUE_DIODE_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GREEN_DIODE_GPIO_Port, GREEN_DIODE_Pin, GPIO_PIN_RESET);
	  }
	  else if((vel >= 1000) & (vel < 2500) & (brake_dyn == 0) & (en_brake == 0))
	  {
		  HAL_GPIO_WritePin(RED_DIODE_GPIO_Port, RED_DIODE_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(BLUE_DIODE_GPIO_Port, BLUE_DIODE_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GREEN_DIODE_GPIO_Port, GREEN_DIODE_Pin, GPIO_PIN_RESET);
	  }
	  else if((vel >= 2500) & (brake_dyn == 0) & (en_brake == 0))
	  {
		  HAL_GPIO_WritePin(RED_DIODE_GPIO_Port, RED_DIODE_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(BLUE_DIODE_GPIO_Port, BLUE_DIODE_Pin, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GREEN_DIODE_GPIO_Port, GREEN_DIODE_Pin, GPIO_PIN_SET);
	  }
	  else if((brake_dyn == 1) || (en_brake == 1))
	  {
		  HAL_GPIO_WritePin(RED_DIODE_GPIO_Port, RED_DIODE_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(BLUE_DIODE_GPIO_Port, BLUE_DIODE_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GREEN_DIODE_GPIO_Port, GREEN_DIODE_Pin, GPIO_PIN_RESET);
	  }
    osDelay(1);
  }
  /* USER CODE END start_diode_contr */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
