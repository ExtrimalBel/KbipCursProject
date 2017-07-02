#include <cmath>
#include <cstdlib>
#include <cmath>
#include <iostream>
#pragma once
extern bool Is_3_Ok;
extern int FieldSize;
extern int MaxNumber;
namespace My_CP {
	using namespace std;

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
			//
			//TODO: добавьте код конструктора
			// Добавил))
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

	protected:

	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;


	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Button^  ExitButton;
	private: System::Windows::Forms::ComboBox^  FieldSizeBox;
	private: System::Windows::Forms::ComboBox^  MaxFor2Box;
	private: System::Windows::Forms::ComboBox^  MaxFor3Box;


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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->FieldSizeBox = (gcnew System::Windows::Forms::ComboBox());
			this->MaxFor2Box = (gcnew System::Windows::Forms::ComboBox());
			this->MaxFor3Box = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(196, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Начальные значения";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(234, 117);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Размер поля (4, 8)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 62);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Максимальное число";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(199, 27);
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
			this->radioButton1->Location = System::Drawing::Point(261, 27);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(49, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"3 и 6";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Settings::radioButton1_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Настройки";
			// 
			// ExitButton
			// 
			this->ExitButton->Location = System::Drawing::Point(12, 136);
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->Size = System::Drawing::Size(75, 23);
			this->ExitButton->TabIndex = 2;
			this->ExitButton->Text = L"Закрыть";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &Settings::ExitButton_Click);
			// 
			// FieldSizeBox
			// 
			this->FieldSizeBox->FormattingEnabled = true;
			this->FieldSizeBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"4x4", L"8x8" });
			this->FieldSizeBox->Location = System::Drawing::Point(178, 101);
			this->FieldSizeBox->Name = L"FieldSizeBox";
			this->FieldSizeBox->Size = System::Drawing::Size(121, 21);
			this->FieldSizeBox->TabIndex = 10;
			this->FieldSizeBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::FieldSizeBox_SelectedIndexChanged);
			// 
			// MaxFor2Box
			// 
			this->MaxFor2Box->FormattingEnabled = true;
			this->MaxFor2Box->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"512", L"1024", L"2048", L"4096", L"8192" });
			this->MaxFor2Box->Location = System::Drawing::Point(178, 62);
			this->MaxFor2Box->Name = L"MaxFor2Box";
			this->MaxFor2Box->Size = System::Drawing::Size(121, 21);
			this->MaxFor2Box->TabIndex = 11;
			this->MaxFor2Box->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::MaxFor2Box_SelectedIndexChanged);
			// 
			// MaxFor3Box
			// 
			this->MaxFor3Box->FormattingEnabled = true;
			this->MaxFor3Box->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"384", L"768", L"1536", L"3072", L"6144" });
			this->MaxFor3Box->Location = System::Drawing::Point(178, 62);
			this->MaxFor3Box->Name = L"MaxFor3Box";
			this->MaxFor3Box->Size = System::Drawing::Size(121, 21);
			this->MaxFor3Box->TabIndex = 12;
			this->MaxFor3Box->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::MaxFor3Box_SelectedIndexChanged);
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(319, 174);
			this->Controls->Add(this->MaxFor3Box);
			this->Controls->Add(this->MaxFor2Box);
			this->Controls->Add(this->FieldSizeBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->ExitButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->radioButton2);
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 MaxFor2Box->Visible = false;
				 MaxFor3Box->Visible = true;
				 Is_3_Ok = true;
	}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 MaxFor2Box->Visible = true;
			 MaxFor3Box->Visible = false;
			 Is_3_Ok = false;	
}
		
	


private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			
}
private: System::Void ExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void FieldSizeBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (FieldSizeBox->SelectedIndex == 0)
				 FieldSize = 4;
			 else
				 FieldSize = 8;
}
private: System::Void MaxFor2Box_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (MaxFor2Box->SelectedIndex)
			 {
			 case 0:
				 MaxNumber = 512;
				 break;
			 case 1:
				 MaxNumber = 1024;
				 break;
			 case 3:
				 MaxNumber = 2048;
				 break;
			 case 4:
				 MaxNumber = 4096;
				 break;
			 case 5:
				 MaxNumber = 8192;
				 break;
			 }
}
private: System::Void MaxFor3Box_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 switch (MaxFor3Box->SelectedIndex)
			 {
			 case 0:
				 MaxNumber = 384;
				 break;
			 case 1:
				 MaxNumber = 768;
				 break;
			 case 3:
				 MaxNumber = 1536;
				 break;
			 case 4:
				 MaxNumber = 3072;
				 break;
			 case 5:
				 MaxNumber = 6144;
				 break;
			 }
}
};
}
