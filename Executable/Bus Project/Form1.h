#pragma once
#include <Windows.h>
#include <time.h>
#include <stdio.h>


extern "C"
{
	extern void Serial_SetComport(unsigned char Comport);
	extern void Serial_SetBaudrate(unsigned int Baudrate);
	extern void Serial_Close(void);
	extern void Serial_ClearBuffer(void);
	extern void Serial_SetReceiveTimeout(unsigned int TimeoutMsec);
	extern int Serial_Open(void);
	extern int Serial_Send(unsigned char *SendBytes, unsigned int BytesToSend);
	extern int Serial_Receive(unsigned char *ReceiveBytes, unsigned int
		BytesToReceive);
	extern int HID_GetHandle(unsigned int VendorID, unsigned int ProductID, unsigned long DesiredAccess, HANDLE *Handle);
}

unsigned char ringbell = 0;
HANDLE HID_Handle = INVALID_HANDLE_VALUE;

namespace BusProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  tick;
	protected: 
	private: System::Windows::Forms::PictureBox^  cross;
	private: System::Windows::Forms::Label^  lblMessage;


	private: System::Windows::Forms::Button^  btnRing;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  lblDoor;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  lblPassenger;
	private: System::Windows::Forms::Label^  lblStatus;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lblCard;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  lblTime;
	private: System::Windows::Forms::Label^  lblDate;

	private: System::Windows::Forms::Label^  lblBalance;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  lblTemp;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  lblStatus2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  lblBell;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  lblFare;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  lel;
	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::Button^  btnStart;
	private: System::Windows::Forms::TextBox^  txtCom;

	private: System::Windows::Forms::TextBox^  txtProduct;
	private: System::Windows::Forms::TextBox^  txtVendor;
	private: System::Windows::Forms::Label^  comStatus;
	private: System::Windows::Forms::Label^  usbStatus;
	private: System::Windows::Forms::Label^  lblConnection;

	private: System::ComponentModel::IContainer^  components;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tick = (gcnew System::Windows::Forms::PictureBox());
			this->cross = (gcnew System::Windows::Forms::PictureBox());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			this->btnRing = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblDoor = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->lblPassenger = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblCard = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblTime = (gcnew System::Windows::Forms::Label());
			this->lblDate = (gcnew System::Windows::Forms::Label());
			this->lblBalance = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lblTemp = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblStatus2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblBell = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->lblFare = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lblConnection = (gcnew System::Windows::Forms::Label());
			this->usbStatus = (gcnew System::Windows::Forms::Label());
			this->comStatus = (gcnew System::Windows::Forms::Label());
			this->txtCom = (gcnew System::Windows::Forms::TextBox());
			this->txtProduct = (gcnew System::Windows::Forms::TextBox());
			this->txtVendor = (gcnew System::Windows::Forms::TextBox());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->lel = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tick))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cross))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tick
			// 
			this->tick->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tick.Image")));
			this->tick->Location = System::Drawing::Point(245, 30);
			this->tick->Name = L"tick";
			this->tick->Size = System::Drawing::Size(128, 128);
			this->tick->TabIndex = 0;
			this->tick->TabStop = false;
			this->tick->Visible = false;
			// 
			// cross
			// 
			this->cross->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cross.Image")));
			this->cross->Location = System::Drawing::Point(245, 30);
			this->cross->Name = L"cross";
			this->cross->Size = System::Drawing::Size(128, 128);
			this->cross->TabIndex = 1;
			this->cross->TabStop = false;
			this->cross->Visible = false;
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblMessage->Location = System::Drawing::Point(129, 171);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(0, 24);
			this->lblMessage->TabIndex = 2;
			this->lblMessage->Click += gcnew System::EventHandler(this, &Form1::lblMessage_Click);
			// 
			// btnRing
			// 
			this->btnRing->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"btnRing.Image")));
			this->btnRing->Location = System::Drawing::Point(473, 47);
			this->btnRing->Name = L"btnRing";
			this->btnRing->Size = System::Drawing::Size(75, 75);
			this->btnRing->TabIndex = 5;
			this->btnRing->UseVisualStyleBackColor = true;
			this->btnRing->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(366, 312);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Door :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 3.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(-14, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(696, 6);
			this->label3->TabIndex = 7;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// lblDoor
			// 
			this->lblDoor->AutoSize = true;
			this->lblDoor->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblDoor->Location = System::Drawing::Point(424, 312);
			this->lblDoor->Name = L"lblDoor";
			this->lblDoor->Size = System::Drawing::Size(61, 18);
			this->lblDoor->TabIndex = 8;
			this->lblDoor->Text = L"Closed";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(23, 360);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(184, 18);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Passengers on board : ";
			// 
			// lblPassenger
			// 
			this->lblPassenger->AutoSize = true;
			this->lblPassenger->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblPassenger->Location = System::Drawing::Point(233, 360);
			this->lblPassenger->Name = L"lblPassenger";
			this->lblPassenger->Size = System::Drawing::Size(0, 18);
			this->lblPassenger->TabIndex = 10;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(23, 460);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(107, 18);
			this->lblStatus->TabIndex = 11;
			this->lblStatus->Text = L"Card Detected ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(23, 409);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 18);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Card ID : ";
			// 
			// lblCard
			// 
			this->lblCard->AutoSize = true;
			this->lblCard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblCard->Location = System::Drawing::Point(111, 409);
			this->lblCard->Name = L"lblCard";
			this->lblCard->Size = System::Drawing::Size(0, 18);
			this->lblCard->TabIndex = 13;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(23, 312);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 18);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Time :";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(426, 360);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(0, 18);
			this->label7->TabIndex = 15;
			// 
			// lblTime
			// 
			this->lblTime->AutoSize = true;
			this->lblTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTime->Location = System::Drawing::Point(84, 312);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(0, 18);
			this->lblTime->TabIndex = 16;
			// 
			// lblDate
			// 
			this->lblDate->AutoSize = true;
			this->lblDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblDate->Location = System::Drawing::Point(495, 360);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(0, 18);
			this->lblDate->TabIndex = 17;
			// 
			// lblBalance
			// 
			this->lblBalance->AutoSize = true;
			this->lblBalance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblBalance->Location = System::Drawing::Point(159, 226);
			this->lblBalance->Name = L"lblBalance";
			this->lblBalance->Size = System::Drawing::Size(0, 18);
			this->lblBalance->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(23, 226);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Card Balance : ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(366, 360);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 18);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Temperature : ";
			// 
			// lblTemp
			// 
			this->lblTemp->AutoSize = true;
			this->lblTemp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTemp->Location = System::Drawing::Point(482, 360);
			this->lblTemp->Name = L"lblTemp";
			this->lblTemp->Size = System::Drawing::Size(0, 18);
			this->lblTemp->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(514, 360);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 18);
			this->label10->TabIndex = 20;
			this->label10->Text = L"°C";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// lblStatus2
			// 
			this->lblStatus2->AutoSize = true;
			this->lblStatus2->Location = System::Drawing::Point(395, 465);
			this->lblStatus2->Name = L"lblStatus2";
			this->lblStatus2->Size = System::Drawing::Size(0, 13);
			this->lblStatus2->TabIndex = 21;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(432, 459);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 18);
			this->label9->TabIndex = 22;
			// 
			// lblBell
			// 
			this->lblBell->AutoSize = true;
			this->lblBell->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblBell->Location = System::Drawing::Point(495, 459);
			this->lblBell->Name = L"lblBell";
			this->lblBell->Size = System::Drawing::Size(0, 18);
			this->lblBell->TabIndex = 23;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(79, 244);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 24;
			// 
			// lblFare
			// 
			this->lblFare->AutoSize = true;
			this->lblFare->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblFare->Location = System::Drawing::Point(366, 226);
			this->lblFare->Name = L"lblFare";
			this->lblFare->Size = System::Drawing::Size(0, 18);
			this->lblFare->TabIndex = 25;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(30, 25);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 24);
			this->button1->TabIndex = 26;
			this->button1->Text = L"Configure";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->lblConnection);
			this->panel1->Controls->Add(this->usbStatus);
			this->panel1->Controls->Add(this->comStatus);
			this->panel1->Controls->Add(this->txtCom);
			this->panel1->Controls->Add(this->txtProduct);
			this->panel1->Controls->Add(this->txtVendor);
			this->panel1->Controls->Add(this->btnStop);
			this->panel1->Controls->Add(this->btnStart);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->lel);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Location = System::Drawing::Point(-625, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(312, 515);
			this->panel1->TabIndex = 27;
			// 
			// lblConnection
			// 
			this->lblConnection->AutoSize = true;
			this->lblConnection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblConnection->Location = System::Drawing::Point(97, 188);
			this->lblConnection->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblConnection->Name = L"lblConnection";
			this->lblConnection->Size = System::Drawing::Size(0, 13);
			this->lblConnection->TabIndex = 11;
			// 
			// usbStatus
			// 
			this->usbStatus->AutoSize = true;
			this->usbStatus->Location = System::Drawing::Point(162, 69);
			this->usbStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->usbStatus->Name = L"usbStatus";
			this->usbStatus->Size = System::Drawing::Size(0, 13);
			this->usbStatus->TabIndex = 10;
			// 
			// comStatus
			// 
			this->comStatus->AutoSize = true;
			this->comStatus->Location = System::Drawing::Point(160, 142);
			this->comStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->comStatus->Name = L"comStatus";
			this->comStatus->Size = System::Drawing::Size(0, 13);
			this->comStatus->TabIndex = 9;
			// 
			// txtCom
			// 
			this->txtCom->Location = System::Drawing::Point(82, 139);
			this->txtCom->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtCom->Name = L"txtCom";
			this->txtCom->Size = System::Drawing::Size(22, 20);
			this->txtCom->TabIndex = 8;
			// 
			// txtProduct
			// 
			this->txtProduct->Location = System::Drawing::Point(82, 102);
			this->txtProduct->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtProduct->Name = L"txtProduct";
			this->txtProduct->Size = System::Drawing::Size(52, 20);
			this->txtProduct->TabIndex = 7;
			// 
			// txtVendor
			// 
			this->txtVendor->Location = System::Drawing::Point(82, 66);
			this->txtVendor->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtVendor->Name = L"txtVendor";
			this->txtVendor->Size = System::Drawing::Size(52, 20);
			this->txtVendor->TabIndex = 6;
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(165, 200);
			this->btnStop->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(72, 20);
			this->btnStop->TabIndex = 5;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &Form1::btnStop_Click);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(57, 200);
			this->btnStart->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(72, 20);
			this->btnStart->TabIndex = 4;
			this->btnStart->Text = L"Start";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Form1::btnStart_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(16, 142);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(56, 13);
			this->label13->TabIndex = 3;
			this->label13->Text = L"COM Port:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(16, 106);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(61, 13);
			this->label12->TabIndex = 2;
			this->label12->Text = L"Product ID:";
			// 
			// lel
			// 
			this->lel->AutoSize = true;
			this->lel->Location = System::Drawing::Point(16, 69);
			this->lel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lel->Name = L"lel";
			this->lel->Size = System::Drawing::Size(58, 13);
			this->lel->TabIndex = 1;
			this->lel->Text = L"Vendor ID:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(234, 23);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 22);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 505);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblFare);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->lblBell);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->lblStatus2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->lblTemp);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->lblDate);
			this->Controls->Add(this->lblTime);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->lblCard);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->lblPassenger);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->lblDoor);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnRing);
			this->Controls->Add(this->lblBalance);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->cross);
			this->Controls->Add(this->tick);
			this->Name = L"Form1";
			this->Text = L"Bus System";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tick))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cross))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void lblMessage_Click(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 ringbell=1;		 }
	private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {


			 }





	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 int query;
				 int query2;
				 int get;
				 int get2;
				 int verify;
				 int verify2;
				 int alarmreceive;
				 static int passengers;

				 unsigned char checksum;
				 unsigned char checksum2;
				 unsigned char tx_Query[9];
				 unsigned char rx_Query[10];
				 unsigned char tx_Get[9];
				 unsigned char rx_Get[30];
				 unsigned char tx_Verify[10];
				 unsigned char rx_Verify[9];
				 unsigned char Mifare[10];
				 unsigned char Felica[20];
				 unsigned char tx_Query2[9];
				 unsigned char rx_Query2[10];
				 unsigned char tx_Get2[9];
				 unsigned char rx_Get2[30];
				 unsigned char tx_Verify2[10];
				 unsigned char rx_Verify2[9];
				 unsigned char Mifare2[10];
				 unsigned char Felica2[20];
				 unsigned char tx_Alarm[5];
				 unsigned char rx_Alarm[5];

				 unsigned char write_buffer[6];
				 unsigned char read_buffer[6];
				 unsigned long bytes_written;
				 unsigned long bytes_read;
				 BOOL result3;

				 static unsigned char previouscard;
				 unsigned char currentcard;
				 static unsigned char previouscard2;
				 unsigned char currentcard2;
				 unsigned char result;
				 unsigned char result2;
				 static float cardvalue;
				 static float card1value;
				 static float card2value;
				 static float othervalue;
				 static int temp;
				 currentcard = 0;
				 currentcard2 = 0;

				 DateTime currDateTime = System::DateTime::Now;
				 lblTime->Text = currDateTime.ToString();

				 memset(read_buffer, 0, sizeof(read_buffer));
				 //	 lblBell -> Text = "";
				 //QUERY CARD
				 tx_Query[0] = 0xAA;
				 tx_Query[1] = 0xBB;
				 tx_Query[2] = 0x02;
				 tx_Query[3] = 0xFF;
				 tx_Query[4] = 0x90;
				 tx_Query[5] = 0x00;
				 tx_Query[6] = 0xFF - (tx_Query[2] + tx_Query[3] + tx_Query[4] + tx_Query[5]);
				 tx_Query[7] = 0xCC;
				 tx_Query[8] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Query, 9);
				 query = Serial_Receive(rx_Query, 10);
				 if (query<10) {
					 lblStatus-> Text = "";

					 return;
				 }
				 else {
					 checksum = 0xFF - (rx_Query[2] + rx_Query[3] + rx_Query[4] + rx_Query[5] + rx_Query[6]);

					 if(checksum != rx_Query[7]){
						 lblStatus-> Text = "Checksum failed";

						 return;
					 }

					 else {


						 if(rx_Query[6] == 0x01){
							 lblStatus-> Text = "MiFare card";
						 }

						 if(rx_Query[6] == 0x02){
							 lblStatus-> Text = "FeliCa card";
						 }

						 if(rx_Query[6] == 0x0F){
							 lblStatus-> Text = "Card error";
						 }


					 }
				 }



				 // Get card
				 tx_Get[0] = 0xAA;
				 tx_Get[1] = 0xBB;
				 tx_Get[2] = 0x02;
				 tx_Get[3] = 0xFF;
				 tx_Get[4] = 0x91;
				 tx_Get[5] = 0x00;
				 tx_Get[6] = 0xFF - (tx_Get[2] + tx_Get[3] + tx_Get[4] + tx_Get[5]);
				 tx_Get[7] = 0xCC;
				 tx_Get[8] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Get, 9);
				 get = Serial_Receive(rx_Get, 30);

				 int i;
				 if(rx_Get[6] == 0x01)
				 {
					 for (i=7; i<17; i++) {

						 Mifare[i] = rx_Get[i] - 48;
					 }

					 lblCard-> Text = "" + Mifare[7] + Mifare[8] + Mifare[9] + Mifare[10] + Mifare[11] + Mifare[12] + Mifare[13] + Mifare[14] + Mifare[15] + Mifare[16];
					 tick -> Visible = false;
					 cross -> Visible = true;
					 lblMessage -> Text ="Please use an SMRT Card";
					 //RED LED on board
					 write_buffer[0] = 0x00;
					 write_buffer[1] = 0xAB;
					 write_buffer[2] = 0x04;
					 write_buffer[3] = 0x44;
					 write_buffer[4] = 0x00;
					 write_buffer[5] = 0xFF - (0x04 + 0x44 + 0x00);
					 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
					 if(result3 ==0)
					 {
						 return;
					 }
					 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 }

				 else if(rx_Get[6] == 0x02)
				 {
					 for (i=7; i<27; i++) {

						 Felica[i] = rx_Get[i] - 48;
					 }

					 lblCard-> Text = "" + Felica[7] + Felica[8] + Felica[9] + Felica[10] + Felica[11] + Felica[12] + Felica[13] + Felica[14] + Felica[15] + Felica[16] + Felica[17] + Felica[18] + 
						 Felica[19] + Felica[20] + Felica[21] + Felica[22] + Felica[23] + Felica[24] + Felica[25] + Felica[26];

					 currentcard = Felica[7] + Felica[8] + Felica[9] + Felica[10] + Felica[11] + Felica[12] + Felica[13] + Felica[14] + Felica[15] + Felica[16] + Felica[17] + Felica[18] + 
						 Felica[19] + Felica[20] + Felica[21] + Felica[22] + Felica[23] + Felica[24] + Felica[25] + Felica[26];

					 if(currentcard != previouscard)
					 {
						 passengers++; // add passengers if current card is not previous card.
						 lblPassenger-> Text = "" + passengers;
						 lblMessage -> Text = "Welcome Aboard";
						 cross-> Visible = false;
						 tick -> Visible = true; //Tick picture
						 result = 0x01; //GreenLED lights up on card reader

						 //Green LED on board
						 write_buffer[0] = 0x00;
						 write_buffer[1] = 0xAB;
						 write_buffer[2] = 0x04;
						 write_buffer[3] = 0x45;
						 write_buffer[4] = 0x00;
						 write_buffer[5] = 0xFF - (0x04 + 0x45 + 0x00);
						 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
						 if(result3 ==0)
						 {
							 return;
						 }
						 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);


						 if(lblCard -> Text == "11525478905775395552")
						 {
							 cardvalue = 24.65;
							 lblBalance -> Text = "$" + cardvalue;
						 }

						 else if(lblCard -> Text == "03699712416102678793")

						 {
							 card1value = 98.55;
							 lblBalance -> Text = "$" + card1value;
						 }

						 else if(lblCard -> Text == "12830512704772442644")

						 {
							 card2value = 12.35;
							 lblBalance -> Text = "$" + card2value;
						 }

						 else { //use else if's for other cards, in the other reader, minus the float value.
							 othervalue = 15.25;
							 lblBalance -> Text = "$" + othervalue;
						 }
					 }

					 else {

						 lblMessage -> Text = "You have already tapped !";
						 tick -> Visible = false;
						 cross -> Visible = true; //Cross picture
						 result = 0x00; //blink red on card reader.

						 //RED LED on board
						 write_buffer[0] = 0x00;
						 write_buffer[1] = 0xAB;
						 write_buffer[2] = 0x04;
						 write_buffer[3] = 0x44;
						 write_buffer[4] = 0x00;
						 write_buffer[5] = 0xFF - (0x04 + 0x44 + 0x00);
						 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
						 if(result3 ==0)
						 {
							 return;
						 }
						 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
					 }

					 previouscard = currentcard;






				 }


				 // Verify card
				 tx_Verify[0] = 0xAA;
				 tx_Verify[1] = 0xBB;
				 tx_Verify[2] = 0x02;
				 tx_Verify[3] = 0xFF;
				 tx_Verify[4] = 0x92;
				 tx_Verify[5] = 0x01;
				 tx_Verify[6] = result; // result it will blink green if successful and blink red if not
				 tx_Verify[7] = 0xFF - (tx_Verify[2] + tx_Verify[3] + tx_Verify[4] + tx_Verify[5] + tx_Verify[6]);
				 tx_Verify[8] = 0xCC;
				 tx_Verify[9] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Verify, 10);
				 verify = Serial_Receive(rx_Verify, 9);
				 if (verify<9) {
					 lblStatus-> Text = "";

					 return;



				 }


				 //Code for reader 1 below.

				 //Query Reader 1
				 tx_Query2[0] = 0xAA;
				 tx_Query2[1] = 0xBB;
				 tx_Query2[2] = 0x01;
				 tx_Query2[3] = 0xFF;
				 tx_Query2[4] = 0x90;
				 tx_Query2[5] = 0x00;
				 tx_Query2[6] = 0xFF - (tx_Query2[2] + tx_Query2[3] + tx_Query2[4] + tx_Query2[5]);
				 tx_Query2[7] = 0xCC;
				 tx_Query2[8] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Query2, 9);
				 query2 = Serial_Receive(rx_Query2, 10);
				 if (query2<10) {
					 lblStatus-> Text = "";

					 return;
				 }
				 else {
					 checksum2 = 0xFF - (rx_Query2[2] + rx_Query2[3] + rx_Query2[4] + rx_Query2[5] + rx_Query2[6]);

					 if(checksum2 != rx_Query2[7]){
						 lblStatus-> Text = "Checksum failed";

						 return;
					 }

					 else {


						 if(rx_Query2[6] == 0x01){
							 lblStatus-> Text = "MiFare card Exit";
						 }

						 if(rx_Query2[6] == 0x02){
							 lblStatus-> Text = "FeliCa card Exit";
						 }

						 if(rx_Query2[6] == 0x0F){
							 lblStatus-> Text = "Card error Exit";
						 }


					 }
				 }



				 //Get Card Reader 1
				 tx_Get2[0] = 0xAA;
				 tx_Get2[1] = 0xBB;
				 tx_Get2[2] = 0x01;
				 tx_Get2[3] = 0xFF;
				 tx_Get2[4] = 0x91;
				 tx_Get2[5] = 0x00;
				 tx_Get2[6] = 0xFF - (tx_Get2[2] + tx_Get2[3] + tx_Get2[4] + tx_Get2[5]);
				 tx_Get2[7] = 0xCC;
				 tx_Get2[8] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Get2, 9);
				 get2 = Serial_Receive(rx_Get2, 30);

				 int d;

				 if(rx_Get2[6] == 0x01)
				 {
					 for (d=7; d<17; d++) {

						 Mifare2[d] = rx_Get2[d] - 48;
					 }

					 lblCard-> Text = "" + Mifare2[7] + Mifare2[8] + Mifare2[9] + Mifare2[10] + Mifare2[11] + Mifare2[12] + Mifare2[13] + Mifare2[14] + Mifare2[15] + Mifare2[16];
					 tick -> Visible = false;
					 cross -> Visible = true;
					 lblMessage -> Text ="Please use an SMRT Card";
					 //RED LED on board
					 write_buffer[0] = 0x00;
					 write_buffer[1] = 0xAB;
					 write_buffer[2] = 0x04;
					 write_buffer[3] = 0x44;
					 write_buffer[4] = 0x00;
					 write_buffer[5] = 0xFF - (0x04 + 0x44 + 0x00);
					 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
					 if(result3 ==0)
					 {
						 return;
					 }
					 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 }

				 else if(rx_Get2[6] == 0x02)
				 {
					 for (d=7; d<27; d++) {

						 Felica2[d] = rx_Get2[d] - 48;
					 }

					 lblCard-> Text = "" + Felica2[7] + Felica2[8] + Felica2[9] + Felica2[10] + Felica2[11] + Felica2[12] + Felica2[13] + Felica2[14] + Felica2[15] + Felica2[16] + Felica2[17] + Felica2[18] + 
						 Felica2[19] + Felica2[20] + Felica2[21] + Felica2[22] + Felica2[23] + Felica2[24] + Felica2[25] + Felica2[26];

					 currentcard2 = Felica2[7] + Felica2[8] + Felica2[9] + Felica2[10] + Felica2[11] + Felica2[12] + Felica2[13] + Felica2[14] + Felica2[15] + Felica2[16] + Felica2[17] + Felica2[18] + 
						 Felica2[19] + Felica2[20] + Felica2[21] + Felica2[22] + Felica2[23] + Felica2[24] + Felica2[25] + Felica2[26];

					 if(currentcard2 != previouscard2)
					 {
						 passengers--; //Decrease passenger count only if current card is not equal to previous card.
						 lblPassenger-> Text = "" + passengers;
						 lblMessage -> Text = "See you again, goodbye!";
						 cross-> Visible = false;
						 tick -> Visible = true; //Tick picture

						 result2 = 0x01; //GreenLED lights up on card reader

						 //Green LED on board
						 write_buffer[0] = 0x00;
						 write_buffer[1] = 0xAB;
						 write_buffer[2] = 0x04;
						 write_buffer[3] = 0x45;
						 write_buffer[4] = 0x00;
						 write_buffer[5] = 0xFF - (0x04 + 0x45 + 0x00);
						 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
						 if(result3 ==0)
						 {
							 return;
						 }
						 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);


						 if(lblCard -> Text == "11525478905775395552")
						 {
							 cardvalue = cardvalue - 2.20;
							 lblBalance -> Text = "$" + cardvalue;
						 }

						 else if(lblCard -> Text == "03699712416102678793")

						 {
							 card1value = card1value - 3.00;
							 lblBalance -> Text = "$" + card1value;
						 }

						 else if(lblCard -> Text == "12830512704772442644")

						 {
							 card2value = card2value - 1.55;
							 lblBalance -> Text = "$" + card2value;
						 }

						 else { //use else if's for other cards, in the other reader, minus the float value.
							 othervalue = othervalue - 1.40;
							 lblBalance -> Text = "$" + othervalue;
						 }
					 }

					 else {

						 lblMessage -> Text = "Please exit, you've already tapped";
						 tick -> Visible = false;
						 cross -> Visible = true; //Cross picture
						 result2 = 0x00;

						 //RED LED on board
						 write_buffer[0] = 0x00;
						 write_buffer[1] = 0xAB;
						 write_buffer[2] = 0x04;
						 write_buffer[3] = 0x44;
						 write_buffer[4] = 0x00;
						 write_buffer[5] = 0xFF - (0x04 + 0x44 + 0x00);
						 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
						 if(result3 ==0)
						 {
							 return;
						 }
						 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
					 }

					 previouscard2 = currentcard2;





				 }


				 // Verify card reader 2
				 tx_Verify2[0] = 0xAA;
				 tx_Verify2[1] = 0xBB;
				 tx_Verify2[2] = 0x01;
				 tx_Verify2[3] = 0xFF;
				 tx_Verify2[4] = 0x92;
				 tx_Verify2[5] = 0x01;
				 tx_Verify2[6] = result;
				 tx_Verify2[7] = 0xFF - (tx_Verify2[2] + tx_Verify2[3] + tx_Verify2[4] + tx_Verify2[5] + tx_Verify2[6]);
				 tx_Verify2[8] = 0xCC;
				 tx_Verify2[9] = 0xDD;
				 Serial_ClearBuffer();
				 Serial_Send(tx_Verify2, 10);
				 verify2 = Serial_Receive(rx_Verify2, 9);
				 if (verify2<9) {
					 lblStatus-> Text = "";

					 return;
				 }



				 if(ringbell == 1) // If user presses on the alarm button, send command to board to light up LED 4 (Yellow LED)
				 {

					 ringbell = 0;
					 write_buffer[0] = 0x00;
					 write_buffer[1] = 0xAB;
					 write_buffer[2] = 0x04;
					 write_buffer[3] = 0x43;
					 write_buffer[4] = 0x00;
					 write_buffer[5] = 0xFF - (0x04 + 0x43 + 0x00);
					 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
					 if(result3 ==0)
					 {
						 return;
					 }
					 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
					 if(result3 != 0)
					 {
						 lblBell -> Text = "Bell Ring";
					 }
					 else{
						 lblBell -> Text = "error bell";
					 }
				 }

				 //Poll to see if Door Open Switch is pressed

				 write_buffer[0] = 0x00;
				 write_buffer[1] = 0xAB;
				 write_buffer[2] = 0x04;
				 write_buffer[3] = 0x41;
				 write_buffer[4] = 0x00;
				 write_buffer[5] = 0xFF - (0x04 + 0x41 + 0x00);
				 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
				 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 if(result3 ==0)
				 {
					 return;
				 }
				 if(result3 != 0)
				 {
					 if(read_buffer[3] == 0x55)
					 {
						 lblDoor -> Text = "Open";
					 }

				 }

				 // Poll to see if Door Close Switch is pressed

				 write_buffer[0] = 0x00;
				 write_buffer[1] = 0xAB;
				 write_buffer[2] = 0x04;
				 write_buffer[3] = 0x42;
				 write_buffer[4] = 0x00;
				 write_buffer[5] = 0xFF - (0x04 + 0x42 + 0x00);
				 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
				 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 if(result3 ==0)
				 {
					 return;
				 }
				 if(result3 != 0)
				 {
					 if(read_buffer[3] == 0x65)
					 {
						 lblDoor -> Text = "Closed";
					 }

				 }


				 //Poll to see if Temp Up Switch is pressed (S4)

				 write_buffer[0] = 0x00;
				 write_buffer[1] = 0xAB;
				 write_buffer[2] = 0x04;
				 write_buffer[3] = 0x50;
				 write_buffer[4] = 0x00;
				 write_buffer[5] = 0xFF - (0x04 + 0x50 + 0x00);
				 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
				 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 if(result3 ==0)
				 {
					 return;
				 }
				 if(result3 != 0)
				 {
					 if(read_buffer[3] == 0x65)
					 {
						 temp++;
						 if (temp>28){
							 temp = 28;
						 }
						 lblTemp -> Text ="" + temp;
					 }

				 }

				 // Poll to see if Temp Down Switch is pressed

				 write_buffer[0] = 0x00;
				 write_buffer[1] = 0xAB;
				 write_buffer[2] = 0x04;
				 write_buffer[3] = 0x51;
				 write_buffer[4] = 0x00;
				 write_buffer[5] = 0xFF - (0x04 + 0x51 + 0x00);
				 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
				 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0);
				 if(result3 ==0)
				 {
					 return;
				 }
				 if(result3 != 0)
				 {
					 if(read_buffer[3] == 0x65)
					 {
						 temp--;
						 if (temp<16){
							 temp = 16;
						 }
						 lblTemp -> Text = "" + temp;
					 }

				 }


			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) //linkhttps://www.youtube.com/watch?v=thekOcADucU
			 {
				 panel1->Location=Point(-625,0);
				 while(panel1->Location.X!=0)
				 {
					 panel1->Location=Point(panel1->Location.X+1,0);
					 System::Threading::Thread::Sleep(10);
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 panel1->Location=Point(0,0);
				 while(panel1->Location.X!=-625)
				 {
					 panel1->Location=Point(panel1->Location.X-1,0);
					 System::Threading::Thread::Sleep(5);
				 }
			 }
	private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
				 timer1-> Enabled = false;
				 if(HID_Handle != INVALID_HANDLE_VALUE)
					 CloseHandle(HID_Handle);

				 HID_Handle=INVALID_HANDLE_VALUE;
				 usbStatus->Text = "USB Channel Closed" ;

				 Serial_Close();
				 comStatus-> Text="Serial Channel Closed";

				 lblConnection->Text ="Card Reader Deactivated";
				 lblBalance -> Text="";
				 lblTemp -> Text="";
				 lblTime -> Text="";
				 lblPassenger -> Text="";
				 lblMessage -> Text="";
				 lblCard -> Text="";
				 lblDoor -> Text="Closed";
				 cross-> Visible = false;
				 tick -> Visible = false;
			 }
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
				 unsigned int vendor_id ;
				 unsigned int product_id ;
				 unsigned int comportval;
				 int status;
				 int ret;
				 vendor_id = Convert::ToInt32(txtVendor->Text,16);
				 product_id = Convert::ToInt32(txtProduct->Text,16);
				 comportval = Convert::ToInt32(txtCom->Text,16);

				 if(HID_Handle != INVALID_HANDLE_VALUE)
				 {
					 CloseHandle(HID_Handle);
				 }

				 status= HID_GetHandle(vendor_id,product_id, GENERIC_READ | GENERIC_WRITE, &HID_Handle);

				 if(status==0)
				 {
					 usbStatus->Text = "USB Channel Open" ;

				 }
				 else 
				 {
					 usbStatus->Text = "USB Fail" ;

				 }


				 Serial_SetComport(comportval);
				 Serial_SetBaudrate(19200);
				 Serial_ClearBuffer();

				 ret=Serial_Open(); //Open serial communications
				 if(ret!=0)
				 {
					 comStatus-> Text="Failed to open COM Port";
				 }
				 else {
					 Serial_ClearBuffer();
					 comStatus-> Text="Serial Channel Open";


				 }

				 if((status==0) && (ret==0)){
					 lblConnection->Text ="Card Reader Active";
					 timer1->Enabled=true;
				 }
				 else {
					 lblConnection ->Text ="Connection Failed";
				 }

			 }
	};
}



