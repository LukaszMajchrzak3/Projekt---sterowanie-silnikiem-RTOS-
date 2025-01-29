namespace SerialPortApp
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.serialSettingsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.config = new System.Windows.Forms.TabPage();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.radioActBrake = new System.Windows.Forms.RadioButton();
            this.radioDynBrake = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioCounterClockwise = new System.Windows.Forms.RadioButton();
            this.radioClockwise = new System.Windows.Forms.RadioButton();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.trackBarVel = new System.Windows.Forms.TrackBar();
            this.label2 = new System.Windows.Forms.Label();
            this.buttonSetVel = new System.Windows.Forms.Button();
            this.textBoxSetVel = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.buttonStart = new System.Windows.Forms.Button();
            this.configTab = new System.Windows.Forms.TabControl();
            this.tabSerialPort = new System.Windows.Forms.TabPage();
            this.groupBox_settings = new System.Windows.Forms.GroupBox();
            this.baudRateComboBox = new System.Windows.Forms.ComboBox();
            this.btnStop = new System.Windows.Forms.Button();
            this.baudRateLabel = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.stopBitsComboBox = new System.Windows.Forms.ComboBox();
            this.stopBitsLabel = new System.Windows.Forms.Label();
            this.dataBitsLabel = new System.Windows.Forms.Label();
            this.portNameComboBox = new System.Windows.Forms.ComboBox();
            this.dataBitsComboBox = new System.Windows.Forms.ComboBox();
            this.portNameLabel = new System.Windows.Forms.Label();
            this.parityLabel = new System.Windows.Forms.Label();
            this.parityComboBox = new System.Windows.Forms.ComboBox();
            this.groupBox_exceptions = new System.Windows.Forms.GroupBox();
            this.btnClearError = new System.Windows.Forms.Button();
            this.error_label = new System.Windows.Forms.Label();
            this.groupBox_transmit = new System.Windows.Forms.GroupBox();
            this.btnSend = new System.Windows.Forms.Button();
            this.tbDataTransmit = new System.Windows.Forms.TextBox();
            this.groupBox_receive = new System.Windows.Forms.GroupBox();
            this.rxEnableCheckBox = new System.Windows.Forms.CheckBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.tbDataReceive = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).BeginInit();
            this.config.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarVel)).BeginInit();
            this.configTab.SuspendLayout();
            this.tabSerialPort.SuspendLayout();
            this.groupBox_settings.SuspendLayout();
            this.groupBox_exceptions.SuspendLayout();
            this.groupBox_transmit.SuspendLayout();
            this.groupBox_receive.SuspendLayout();
            this.SuspendLayout();
            // 
            // config
            // 
            this.config.BackColor = System.Drawing.SystemColors.HighlightText;
            this.config.Controls.Add(this.groupBox5);
            this.config.Controls.Add(this.groupBox4);
            this.config.Controls.Add(this.groupBox3);
            this.config.Controls.Add(this.label1);
            this.config.Controls.Add(this.buttonStart);
            this.config.Location = new System.Drawing.Point(4, 25);
            this.config.Margin = new System.Windows.Forms.Padding(4);
            this.config.Name = "config";
            this.config.Padding = new System.Windows.Forms.Padding(4);
            this.config.Size = new System.Drawing.Size(616, 552);
            this.config.TabIndex = 3;
            this.config.Text = "Silnik";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.groupBox2);
            this.groupBox5.Controls.Add(this.groupBox1);
            this.groupBox5.Location = new System.Drawing.Point(367, 89);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(244, 232);
            this.groupBox5.TabIndex = 22;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "groupBox5";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radioActBrake);
            this.groupBox2.Controls.Add(this.radioDynBrake);
            this.groupBox2.Location = new System.Drawing.Point(7, 142);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(209, 81);
            this.groupBox2.TabIndex = 19;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Sterowanie Hamowaniem";
            // 
            // radioActBrake
            // 
            this.radioActBrake.AutoSize = true;
            this.radioActBrake.Location = new System.Drawing.Point(13, 50);
            this.radioActBrake.Margin = new System.Windows.Forms.Padding(4);
            this.radioActBrake.Name = "radioActBrake";
            this.radioActBrake.Size = new System.Drawing.Size(153, 20);
            this.radioActBrake.TabIndex = 9;
            this.radioActBrake.TabStop = true;
            this.radioActBrake.Text = "Hamowanie Aktywne";
            this.radioActBrake.UseVisualStyleBackColor = true;
            this.radioActBrake.CheckedChanged += new System.EventHandler(this.radioActBrake_CheckedChanged);
            // 
            // radioDynBrake
            // 
            this.radioDynBrake.AutoSize = true;
            this.radioDynBrake.Location = new System.Drawing.Point(13, 21);
            this.radioDynBrake.Margin = new System.Windows.Forms.Padding(4);
            this.radioDynBrake.Name = "radioDynBrake";
            this.radioDynBrake.Size = new System.Drawing.Size(177, 20);
            this.radioDynBrake.TabIndex = 8;
            this.radioDynBrake.TabStop = true;
            this.radioDynBrake.Text = "Hamowanie Dynamiczne";
            this.radioDynBrake.UseVisualStyleBackColor = true;
            this.radioDynBrake.CheckedChanged += new System.EventHandler(this.radioDynBrake_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioCounterClockwise);
            this.groupBox1.Controls.Add(this.radioClockwise);
            this.groupBox1.Location = new System.Drawing.Point(7, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(209, 101);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Sterowanie Kierunkiem ruchu";
            // 
            // radioCounterClockwise
            // 
            this.radioCounterClockwise.AutoSize = true;
            this.radioCounterClockwise.Location = new System.Drawing.Point(19, 64);
            this.radioCounterClockwise.Margin = new System.Windows.Forms.Padding(4);
            this.radioCounterClockwise.Name = "radioCounterClockwise";
            this.radioCounterClockwise.Size = new System.Drawing.Size(139, 20);
            this.radioCounterClockwise.TabIndex = 3;
            this.radioCounterClockwise.TabStop = true;
            this.radioCounterClockwise.Text = "Counter-Clockwise";
            this.radioCounterClockwise.UseVisualStyleBackColor = true;
            this.radioCounterClockwise.CheckedChanged += new System.EventHandler(this.radioCounterClockwise_CheckedChanged);
            // 
            // radioClockwise
            // 
            this.radioClockwise.AutoSize = true;
            this.radioClockwise.Location = new System.Drawing.Point(19, 35);
            this.radioClockwise.Margin = new System.Windows.Forms.Padding(4);
            this.radioClockwise.Name = "radioClockwise";
            this.radioClockwise.Size = new System.Drawing.Size(89, 20);
            this.radioClockwise.TabIndex = 2;
            this.radioClockwise.TabStop = true;
            this.radioClockwise.Text = "Clockwise";
            this.radioClockwise.UseVisualStyleBackColor = true;
            this.radioClockwise.CheckedChanged += new System.EventHandler(this.radioClockwise_CheckedChanged);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.textBox1);
            this.groupBox4.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.groupBox4.Location = new System.Drawing.Point(4, 397);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(608, 151);
            this.groupBox4.TabIndex = 21;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Odpowiedź zwrotna układu";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(21, 20);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox1.Size = new System.Drawing.Size(570, 118);
            this.textBox1.TabIndex = 16;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.trackBarVel);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.buttonSetVel);
            this.groupBox3.Controls.Add(this.textBoxSetVel);
            this.groupBox3.Location = new System.Drawing.Point(25, 92);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(261, 259);
            this.groupBox3.TabIndex = 20;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Sterowanie prędkością";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(52, 198);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(142, 32);
            this.label4.TabIndex = 16;
            this.label4.Text = "Prędkość silnika [rpm]\r\nZakres: 300-3300 [rpm]\r\n";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // trackBarVel
            // 
            this.trackBarVel.Location = new System.Drawing.Point(21, 139);
            this.trackBarVel.Maximum = 3300;
            this.trackBarVel.Minimum = 300;
            this.trackBarVel.Name = "trackBarVel";
            this.trackBarVel.Size = new System.Drawing.Size(218, 56);
            this.trackBarVel.TabIndex = 15;
            this.trackBarVel.Value = 300;
            this.trackBarVel.Scroll += new System.EventHandler(this.trackBarVel_Scroll);
            this.trackBarVel.ValueChanged += new System.EventHandler(this.trackBarVel_ValueChanged);
            this.trackBarVel.MouseCaptureChanged += new System.EventHandler(this.trackBarVel_MouseCaptureChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(52, 39);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(140, 16);
            this.label2.TabIndex = 7;
            this.label2.Text = "Prędkość silnika [rpm]";
            // 
            // buttonSetVel
            // 
            this.buttonSetVel.Location = new System.Drawing.Point(73, 104);
            this.buttonSetVel.Margin = new System.Windows.Forms.Padding(4);
            this.buttonSetVel.Name = "buttonSetVel";
            this.buttonSetVel.Size = new System.Drawing.Size(92, 28);
            this.buttonSetVel.TabIndex = 6;
            this.buttonSetVel.Text = "USTAW";
            this.buttonSetVel.UseVisualStyleBackColor = true;
            this.buttonSetVel.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBoxSetVel
            // 
            this.textBoxSetVel.Location = new System.Drawing.Point(48, 74);
            this.textBoxSetVel.Margin = new System.Windows.Forms.Padding(4);
            this.textBoxSetVel.Name = "textBoxSetVel";
            this.textBoxSetVel.Size = new System.Drawing.Size(144, 22);
            this.textBoxSetVel.TabIndex = 5;
            this.textBoxSetVel.Text = "0300";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(272, 13);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(95, 16);
            this.label1.TabIndex = 1;
            this.label1.Text = "Wystartuj silnik";
            // 
            // buttonStart
            // 
            this.buttonStart.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonStart.ForeColor = System.Drawing.Color.Lime;
            this.buttonStart.Location = new System.Drawing.Point(250, 33);
            this.buttonStart.Margin = new System.Windows.Forms.Padding(4);
            this.buttonStart.Name = "buttonStart";
            this.buttonStart.Size = new System.Drawing.Size(141, 52);
            this.buttonStart.TabIndex = 0;
            this.buttonStart.Text = "START";
            this.buttonStart.UseVisualStyleBackColor = true;
            this.buttonStart.Click += new System.EventHandler(this.buttonStart_Click);
            // 
            // configTab
            // 
            this.configTab.Controls.Add(this.tabSerialPort);
            this.configTab.Controls.Add(this.config);
            this.configTab.Dock = System.Windows.Forms.DockStyle.Fill;
            this.configTab.Location = new System.Drawing.Point(0, 0);
            this.configTab.Margin = new System.Windows.Forms.Padding(4);
            this.configTab.Name = "configTab";
            this.configTab.SelectedIndex = 0;
            this.configTab.Size = new System.Drawing.Size(624, 581);
            this.configTab.TabIndex = 17;
            // 
            // tabSerialPort
            // 
            this.tabSerialPort.BackColor = System.Drawing.SystemColors.HighlightText;
            this.tabSerialPort.Controls.Add(this.groupBox_settings);
            this.tabSerialPort.Controls.Add(this.groupBox_exceptions);
            this.tabSerialPort.Controls.Add(this.groupBox_transmit);
            this.tabSerialPort.Controls.Add(this.groupBox_receive);
            this.tabSerialPort.Location = new System.Drawing.Point(4, 25);
            this.tabSerialPort.Margin = new System.Windows.Forms.Padding(4);
            this.tabSerialPort.Name = "tabSerialPort";
            this.tabSerialPort.Padding = new System.Windows.Forms.Padding(4);
            this.tabSerialPort.Size = new System.Drawing.Size(616, 552);
            this.tabSerialPort.TabIndex = 0;
            this.tabSerialPort.Text = "Serial Port";
            // 
            // groupBox_settings
            // 
            this.groupBox_settings.BackColor = System.Drawing.Color.Transparent;
            this.groupBox_settings.Controls.Add(this.baudRateComboBox);
            this.groupBox_settings.Controls.Add(this.btnStop);
            this.groupBox_settings.Controls.Add(this.baudRateLabel);
            this.groupBox_settings.Controls.Add(this.btnStart);
            this.groupBox_settings.Controls.Add(this.stopBitsComboBox);
            this.groupBox_settings.Controls.Add(this.stopBitsLabel);
            this.groupBox_settings.Controls.Add(this.dataBitsLabel);
            this.groupBox_settings.Controls.Add(this.portNameComboBox);
            this.groupBox_settings.Controls.Add(this.dataBitsComboBox);
            this.groupBox_settings.Controls.Add(this.portNameLabel);
            this.groupBox_settings.Controls.Add(this.parityLabel);
            this.groupBox_settings.Controls.Add(this.parityComboBox);
            this.groupBox_settings.Location = new System.Drawing.Point(11, 7);
            this.groupBox_settings.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox_settings.Name = "groupBox_settings";
            this.groupBox_settings.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox_settings.Size = new System.Drawing.Size(325, 246);
            this.groupBox_settings.TabIndex = 11;
            this.groupBox_settings.TabStop = false;
            this.groupBox_settings.Text = "Serial Port Settings";
            // 
            // baudRateComboBox
            // 
            this.baudRateComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "BaudRate", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.baudRateComboBox.FormattingEnabled = true;
            this.baudRateComboBox.Location = new System.Drawing.Point(103, 69);
            this.baudRateComboBox.Margin = new System.Windows.Forms.Padding(4);
            this.baudRateComboBox.Name = "baudRateComboBox";
            this.baudRateComboBox.Size = new System.Drawing.Size(203, 24);
            this.baudRateComboBox.TabIndex = 2;
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(209, 202);
            this.btnStop.Margin = new System.Windows.Forms.Padding(4);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(97, 28);
            this.btnStop.TabIndex = 12;
            this.btnStop.Text = "Disconnect";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.BtnStop_Click);
            // 
            // baudRateLabel
            // 
            this.baudRateLabel.AutoSize = true;
            this.baudRateLabel.Location = new System.Drawing.Point(13, 73);
            this.baudRateLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.baudRateLabel.Name = "baudRateLabel";
            this.baudRateLabel.Size = new System.Drawing.Size(74, 16);
            this.baudRateLabel.TabIndex = 1;
            this.baudRateLabel.Text = "Baud Rate:";
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(103, 202);
            this.btnStart.Margin = new System.Windows.Forms.Padding(4);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(99, 28);
            this.btnStart.TabIndex = 12;
            this.btnStart.Text = "Connect";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.BtnStart_Click);
            // 
            // stopBitsComboBox
            // 
            this.stopBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "StopBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.stopBitsComboBox.FormattingEnabled = true;
            this.stopBitsComboBox.Location = new System.Drawing.Point(103, 169);
            this.stopBitsComboBox.Margin = new System.Windows.Forms.Padding(4);
            this.stopBitsComboBox.Name = "stopBitsComboBox";
            this.stopBitsComboBox.Size = new System.Drawing.Size(203, 24);
            this.stopBitsComboBox.TabIndex = 10;
            // 
            // stopBitsLabel
            // 
            this.stopBitsLabel.AutoSize = true;
            this.stopBitsLabel.Location = new System.Drawing.Point(13, 172);
            this.stopBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.stopBitsLabel.Name = "stopBitsLabel";
            this.stopBitsLabel.Size = new System.Drawing.Size(63, 16);
            this.stopBitsLabel.TabIndex = 9;
            this.stopBitsLabel.Text = "Stop Bits:";
            // 
            // dataBitsLabel
            // 
            this.dataBitsLabel.AutoSize = true;
            this.dataBitsLabel.Location = new System.Drawing.Point(13, 106);
            this.dataBitsLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.dataBitsLabel.Name = "dataBitsLabel";
            this.dataBitsLabel.Size = new System.Drawing.Size(64, 16);
            this.dataBitsLabel.TabIndex = 3;
            this.dataBitsLabel.Text = "Data Bits:";
            // 
            // portNameComboBox
            // 
            this.portNameComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "PortName", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.portNameComboBox.FormattingEnabled = true;
            this.portNameComboBox.Location = new System.Drawing.Point(103, 36);
            this.portNameComboBox.Margin = new System.Windows.Forms.Padding(4);
            this.portNameComboBox.Name = "portNameComboBox";
            this.portNameComboBox.Size = new System.Drawing.Size(203, 24);
            this.portNameComboBox.TabIndex = 8;
            // 
            // dataBitsComboBox
            // 
            this.dataBitsComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "DataBits", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.dataBitsComboBox.FormattingEnabled = true;
            this.dataBitsComboBox.Location = new System.Drawing.Point(103, 102);
            this.dataBitsComboBox.Margin = new System.Windows.Forms.Padding(4);
            this.dataBitsComboBox.Name = "dataBitsComboBox";
            this.dataBitsComboBox.Size = new System.Drawing.Size(203, 24);
            this.dataBitsComboBox.TabIndex = 4;
            // 
            // portNameLabel
            // 
            this.portNameLabel.AutoSize = true;
            this.portNameLabel.Location = new System.Drawing.Point(13, 39);
            this.portNameLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.portNameLabel.Name = "portNameLabel";
            this.portNameLabel.Size = new System.Drawing.Size(74, 16);
            this.portNameLabel.TabIndex = 7;
            this.portNameLabel.Text = "Port Name:";
            // 
            // parityLabel
            // 
            this.parityLabel.AutoSize = true;
            this.parityLabel.Location = new System.Drawing.Point(13, 139);
            this.parityLabel.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.parityLabel.Name = "parityLabel";
            this.parityLabel.Size = new System.Drawing.Size(44, 16);
            this.parityLabel.TabIndex = 5;
            this.parityLabel.Text = "Parity:";
            // 
            // parityComboBox
            // 
            this.parityComboBox.DataBindings.Add(new System.Windows.Forms.Binding("Text", this.serialSettingsBindingSource, "Parity", true, System.Windows.Forms.DataSourceUpdateMode.OnPropertyChanged));
            this.parityComboBox.FormattingEnabled = true;
            this.parityComboBox.Location = new System.Drawing.Point(103, 135);
            this.parityComboBox.Margin = new System.Windows.Forms.Padding(4);
            this.parityComboBox.Name = "parityComboBox";
            this.parityComboBox.Size = new System.Drawing.Size(203, 24);
            this.parityComboBox.TabIndex = 6;
            // 
            // groupBox_exceptions
            // 
            this.groupBox_exceptions.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox_exceptions.Controls.Add(this.btnClearError);
            this.groupBox_exceptions.Controls.Add(this.error_label);
            this.groupBox_exceptions.Location = new System.Drawing.Point(344, 7);
            this.groupBox_exceptions.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox_exceptions.Name = "groupBox_exceptions";
            this.groupBox_exceptions.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox_exceptions.Size = new System.Drawing.Size(263, 246);
            this.groupBox_exceptions.TabIndex = 16;
            this.groupBox_exceptions.TabStop = false;
            this.groupBox_exceptions.Text = "Exceptions";
            // 
            // btnClearError
            // 
            this.btnClearError.Location = new System.Drawing.Point(155, 210);
            this.btnClearError.Margin = new System.Windows.Forms.Padding(4);
            this.btnClearError.Name = "btnClearError";
            this.btnClearError.Size = new System.Drawing.Size(99, 28);
            this.btnClearError.TabIndex = 13;
            this.btnClearError.Text = "Clear error";
            this.btnClearError.UseVisualStyleBackColor = true;
            this.btnClearError.Click += new System.EventHandler(this.BtnClearError_Click);
            // 
            // error_label
            // 
            this.error_label.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.error_label.ForeColor = System.Drawing.Color.Red;
            this.error_label.Location = new System.Drawing.Point(23, 36);
            this.error_label.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.error_label.Name = "error_label";
            this.error_label.Size = new System.Drawing.Size(231, 153);
            this.error_label.TabIndex = 0;
            // 
            // groupBox_transmit
            // 
            this.groupBox_transmit.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox_transmit.Controls.Add(this.btnSend);
            this.groupBox_transmit.Controls.Add(this.tbDataTransmit);
            this.groupBox_transmit.Location = new System.Drawing.Point(11, 454);
            this.groupBox_transmit.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox_transmit.Name = "groupBox_transmit";
            this.groupBox_transmit.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox_transmit.Size = new System.Drawing.Size(596, 89);
            this.groupBox_transmit.TabIndex = 15;
            this.groupBox_transmit.TabStop = false;
            this.groupBox_transmit.Text = "Transmit";
            // 
            // btnSend
            // 
            this.btnSend.Location = new System.Drawing.Point(474, 53);
            this.btnSend.Margin = new System.Windows.Forms.Padding(4);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(113, 28);
            this.btnSend.TabIndex = 1;
            this.btnSend.Text = "Send";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.BtnSend_Click);
            // 
            // tbDataTransmit
            // 
            this.tbDataTransmit.Location = new System.Drawing.Point(16, 23);
            this.tbDataTransmit.Margin = new System.Windows.Forms.Padding(4);
            this.tbDataTransmit.Name = "tbDataTransmit";
            this.tbDataTransmit.Size = new System.Drawing.Size(571, 22);
            this.tbDataTransmit.TabIndex = 0;
            // 
            // groupBox_receive
            // 
            this.groupBox_receive.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBox_receive.Controls.Add(this.rxEnableCheckBox);
            this.groupBox_receive.Controls.Add(this.btnClear);
            this.groupBox_receive.Controls.Add(this.tbDataReceive);
            this.groupBox_receive.Location = new System.Drawing.Point(12, 261);
            this.groupBox_receive.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox_receive.Name = "groupBox_receive";
            this.groupBox_receive.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox_receive.Size = new System.Drawing.Size(595, 185);
            this.groupBox_receive.TabIndex = 14;
            this.groupBox_receive.TabStop = false;
            this.groupBox_receive.Text = "Receive";
            // 
            // rxEnableCheckBox
            // 
            this.rxEnableCheckBox.AutoSize = true;
            this.rxEnableCheckBox.Checked = true;
            this.rxEnableCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.rxEnableCheckBox.Location = new System.Drawing.Point(15, 149);
            this.rxEnableCheckBox.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.rxEnableCheckBox.Name = "rxEnableCheckBox";
            this.rxEnableCheckBox.Size = new System.Drawing.Size(91, 20);
            this.rxEnableCheckBox.TabIndex = 15;
            this.rxEnableCheckBox.Text = "Rx Enable";
            this.rxEnableCheckBox.UseVisualStyleBackColor = true;
            this.rxEnableCheckBox.CheckedChanged += new System.EventHandler(this.RxEnableCheckBox_CheckedChanged);
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(473, 149);
            this.btnClear.Margin = new System.Windows.Forms.Padding(4);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(113, 28);
            this.btnClear.TabIndex = 14;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.BtnClear_Click);
            // 
            // tbDataReceive
            // 
            this.tbDataReceive.Location = new System.Drawing.Point(15, 23);
            this.tbDataReceive.Margin = new System.Windows.Forms.Padding(4);
            this.tbDataReceive.Multiline = true;
            this.tbDataReceive.Name = "tbDataReceive";
            this.tbDataReceive.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.tbDataReceive.Size = new System.Drawing.Size(571, 118);
            this.tbDataReceive.TabIndex = 13;
            this.tbDataReceive.TextChanged += new System.EventHandler(this.tbDataReceive_TextChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSize = true;
            this.ClientSize = new System.Drawing.Size(624, 581);
            this.Controls.Add(this.configTab);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.Text = "BLDC Motor Control";
            ((System.ComponentModel.ISupportInitialize)(this.serialSettingsBindingSource)).EndInit();
            this.config.ResumeLayout(false);
            this.config.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarVel)).EndInit();
            this.configTab.ResumeLayout(false);
            this.tabSerialPort.ResumeLayout(false);
            this.groupBox_settings.ResumeLayout(false);
            this.groupBox_settings.PerformLayout();
            this.groupBox_exceptions.ResumeLayout(false);
            this.groupBox_transmit.ResumeLayout(false);
            this.groupBox_transmit.PerformLayout();
            this.groupBox_receive.ResumeLayout(false);
            this.groupBox_receive.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.BindingSource serialSettingsBindingSource;
        private System.Windows.Forms.TabPage config;
        private System.Windows.Forms.Button buttonStart;
        private System.Windows.Forms.TabControl configTab;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RadioButton radioCounterClockwise;
        private System.Windows.Forms.RadioButton radioClockwise;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button buttonSetVel;
        private System.Windows.Forms.TextBox textBoxSetVel;
        private System.Windows.Forms.RadioButton radioActBrake;
        private System.Windows.Forms.RadioButton radioDynBrake;
        private System.Windows.Forms.TrackBar trackBarVel;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TabPage tabSerialPort;
        private System.Windows.Forms.GroupBox groupBox_settings;
        private System.Windows.Forms.ComboBox baudRateComboBox;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Label baudRateLabel;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.ComboBox stopBitsComboBox;
        private System.Windows.Forms.Label stopBitsLabel;
        private System.Windows.Forms.Label dataBitsLabel;
        private System.Windows.Forms.ComboBox portNameComboBox;
        private System.Windows.Forms.ComboBox dataBitsComboBox;
        private System.Windows.Forms.Label portNameLabel;
        private System.Windows.Forms.Label parityLabel;
        private System.Windows.Forms.ComboBox parityComboBox;
        private System.Windows.Forms.GroupBox groupBox_exceptions;
        private System.Windows.Forms.Button btnClearError;
        private System.Windows.Forms.Label error_label;
        private System.Windows.Forms.GroupBox groupBox_transmit;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.TextBox tbDataTransmit;
        private System.Windows.Forms.GroupBox groupBox_receive;
        private System.Windows.Forms.CheckBox rxEnableCheckBox;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.TextBox tbDataReceive;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox5;
    }
}

