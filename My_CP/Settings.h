#include <cmath>
#include <cstdlib>
#pragma once
extern bool Is_3_Ok;
extern int FieldSize;
extern int MaxNumber;
extern bool RandomNumbers;
namespace My_CP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		
		Settings(void)
		{
			InitializeComponent();
			RandomNumbers = false;
			//
			//TODO: добавьте код конструктора
			//
			/*if (RandomNumbers == true)
			{
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			}
			else
			{
			this->checkBox1->Checked = false;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			}*/
			int Stz;
			if (Is_3_Ok)
			{
				Stz = 3;
				radioButton1->Checked = true;
				radioButton2->Checked = false;
			}
			else
			{
				Stz = 2;
				radioButton2->Checked = true;
				radioButton1->Checked = false;
			}
			textBox2->Text = System::Convert::ToString(FieldSize);
			int st = log(MaxNumber)/log(Stz);
			textBox1->Text = System::Convert::ToString(st);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::TabPage^  tabpage;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  ExitButton;


	protected:

	protected:

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->tabpage = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabpage);
			this->tabControl1->Location = System::Drawing::Point(13, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(403, 192);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->checkBox1);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->radioButton2);
			this->tabPage1->Controls->Add(this->radioButton1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(395, 166);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Настройки";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 11);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Начальные значения";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(17, 137);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(246, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Вставлять случайные  числа во времяигры";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckedChanged);
			this->checkBox1->CheckStateChanged += gcnew System::EventHandler(this, &Settings::checkBox1_CheckStateChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(180, 117);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(123, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(34, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Settings::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Размер поля (4, 8)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(223, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"=";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Максимальная степень числа";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(180, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(36, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Settings::textBox1_TextChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(17, 53);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(49, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"2 и 4";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(17, 30);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(49, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"3 и 6";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton1_CheckedChanged);
			// 
			// tabpage
			// 
			this->tabpage->Location = System::Drawing::Point(4, 22);
			this->tabpage->Name = L"tabpage";
			this->tabpage->Padding = System::Windows::Forms::Padding(3);
			this->tabpage->Size = System::Drawing::Size(395, 166);
			this->tabpage->TabIndex = 1;
			this->tabpage->Text = L"Дополнительно";
			this->tabpage->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(274, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Настройки";
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(17, 227);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(75, 23);
			this->ExitButton->TabIndex = 2;
			this->ExitButton->Text = L"Закрыть";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &Settings::ExitButton_Click);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(442, 262);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 Is_3_Ok = true;
	}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 Is_3_Ok = false;
}
		 bool IsStrNumber(String ^s)
		 {
			 bool isnumber = true;
			 for (int i = 0; i < s->Length; i++)
			 {
				 if (!(s[i] >= '0' && s[i] <= '9'))
				 {
					 isnumber = false;
				 }

			 }
			 return isnumber;
		 }
		 bool IsStrEmpty(String ^s)
		 {
			 bool isempty = false;
			 if (s->Length == 0)
			 {
				 isempty = true;
			 }
			 return isempty;
		 }
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 
				 int os;
				 if (Is_3_Ok) os = 3;
				 else os = 2;
				 bool isnumber;
				 bool isempty = false;
				 int number;
				 int maxnumber  = 2048;
				 String ^s = textBox1->Text;
				 isempty = IsStrEmpty(s);
				 if (!isempty) isnumber = IsStrNumber(s);
				 if (isnumber && !isempty)
				 {
					 number = System::Convert::ToInt32(s);
					 if (number < 5 && number > 20) label3->Text = "Допустимы значения от 5 до 20";
					 else
					 {
						 label3->Text = "=" + System::Convert::ToString(pow(os, number));
						 maxnumber = pow(os, number);
						 MaxNumber = maxnumber;
					 }
					 
				 }
				 else
				 {
					 label3->Text = "Только цифры";
				 }				 
	}

private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 String ^s = textBox2->Text;
			 bool isnumber;
			 bool isempty = false;
			 isempty = IsStrEmpty(s);
			 if(!isempty) isnumber = IsStrNumber(s);
			 if (isnumber && !isempty)
			 {
				 int number = System::Convert::ToInt32(s);
				 if (number == 4 || number == 8)
				 {
					 label5->Text = "";
					 FieldSize = number;
				 }
				 else label5->Text = "4 или 8";

			 }
			 else
			 {
				 label5->Text = "Только цифры";
			 }
}

private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			
}
private: System::Void checkBox1_CheckStateChanged(System::Object^  sender, System::EventArgs^  e) {
			 RandomNumbers = !RandomNumbers;
}
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
};
}
