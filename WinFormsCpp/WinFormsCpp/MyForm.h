#pragma once
#include <windows.h>
#include <math.h>
#include <iostream>
#include <string>

namespace WinFormsCpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;




	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(430, 430);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(459, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(198, 61);
			this->button1->TabIndex = 1;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(566, 89);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 40);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(459, 89);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 40);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(456, 401);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 44);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Привет!";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 454);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {	
		timer1->Start();

	}

    double l;           
	double R = 60, r = 20;  
    int alpha = 0;       
    double x0 = 230.5, y0 = 300.5;
	int k = 0;
	int label_tmp = 0;
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		x0 = (x0 + l * cos(alpha));
		y0 = (y0 + l * sin(alpha));
		l = k % 2 == 0 ? r : R;
		alpha += 3.14;
		Graphics^ g = pictureBox1->CreateGraphics();
		Pen^ p = gcnew Pen(Color::Blue, 1.0f);
		k++;
		g->DrawEllipse(Pens::Blue, x0, y0, 10, 10);
		label_tmp++;
		String ^ str = System::Convert::ToString(label_tmp);
		label1->Text = str;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->Invalidate();
		label_tmp = 0;
		String^ str = System::Convert::ToString(label_tmp);
		label1->Text = str;
	}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Stop();
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
