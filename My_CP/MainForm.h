#include <iomanip>
//#include <iostream>
#include "Settings.h"
#include <ctime>
#include <time.h>
#include <cstdlib>
#include "GameField.h"
#pragma once
extern bool Is_3_Ok = false;
extern int FieldSize = 4;
extern int MaxNumber = 2048;
bool IsLoseGame(int **Field, int n);
bool IsWinGame(int **Field, int n, int maxn);
int ** BackupField(int **Field, int n);


namespace My_CP {
	using namespace GameField;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//
	using namespace std;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>

	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		int n;
		int maxn;
		bool Is_Game_Started = false;
		bool is_3;
	private: System::Windows::Forms::Label^  LabelSetings;
	private: System::Windows::Forms::Label^  StartNumber;
	private: System::Windows::Forms::Label^  StrMaxNumber;
	private: System::Windows::Forms::Label^  SizeField;

	private: System::Windows::Forms::Button^  StopB;


	private: System::Windows::Forms::HelpProvider^  helpProvider1;
	private: System::Windows::Forms::Button^  button1;



	public:
		GField ^ Field;
		MainForm(void)
		{		
			/*
			Сдесь игровое поле представленно в виде матрицы с размером n где n задаёться на форме настроек
			*/
			// Инициализация игрового поля
			InitializeComponent();
			//
			//

			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Button^  StartBottom;

	private: System::Windows::Forms::Button^  SettingsBottom;
	private: System::Windows::Forms::Label^  Counter;
	private: System::Windows::Forms::Label^  CountRez;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->StartBottom = (gcnew System::Windows::Forms::Button());
			this->SettingsBottom = (gcnew System::Windows::Forms::Button());
			this->Counter = (gcnew System::Windows::Forms::Label());
			this->CountRez = (gcnew System::Windows::Forms::Label());
			this->LabelSetings = (gcnew System::Windows::Forms::Label());
			this->StartNumber = (gcnew System::Windows::Forms::Label());
			this->StrMaxNumber = (gcnew System::Windows::Forms::Label());
			this->SizeField = (gcnew System::Windows::Forms::Label());
			this->StopB = (gcnew System::Windows::Forms::Button());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(13, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBox1_Paint);
			// 
			// StartBottom
			// 
			this->StartBottom->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->StartBottom->Location = System::Drawing::Point(486, 261);
			this->StartBottom->Name = L"StartBottom";
			this->StartBottom->Size = System::Drawing::Size(118, 23);
			this->StartBottom->TabIndex = 1;
			this->StartBottom->Text = L"Начать игру";
			this->StartBottom->UseVisualStyleBackColor = true;
			this->StartBottom->Click += gcnew System::EventHandler(this, &MainForm::StartBottom_Click);
			// 
			// SettingsBottom
			// 
			this->SettingsBottom->Location = System::Drawing::Point(486, 302);
			this->SettingsBottom->Name = L"SettingsBottom";
			this->SettingsBottom->Size = System::Drawing::Size(118, 23);
			this->SettingsBottom->TabIndex = 3;
			this->SettingsBottom->Text = L"Настройки";
			this->SettingsBottom->UseVisualStyleBackColor = true;
			this->SettingsBottom->Click += gcnew System::EventHandler(this, &MainForm::SettingsBottom_Click);
			// 
			// Counter
			// 
			this->Counter->AutoSize = true;
			this->Counter->BackColor = System::Drawing::SystemColors::Desktop;
			this->Counter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Counter->ForeColor = System::Drawing::Color::Yellow;
			this->Counter->Location = System::Drawing::Point(448, 414);
			this->Counter->Name = L"Counter";
			this->Counter->Size = System::Drawing::Size(54, 24);
			this->Counter->TabIndex = 4;
			this->Counter->Text = L"Счёт";
			this->Counter->Visible = false;
			// 
			// CountRez
			// 
			this->CountRez->AutoSize = true;
			this->CountRez->BackColor = System::Drawing::SystemColors::Desktop;
			this->CountRez->ForeColor = System::Drawing::Color::Red;
			this->CountRez->Location = System::Drawing::Point(531, 422);
			this->CountRez->Name = L"CountRez";
			this->CountRez->Size = System::Drawing::Size(13, 13);
			this->CountRez->TabIndex = 5;
			this->CountRez->Text = L"0";
			this->CountRez->Visible = false;
			// 
			// LabelSetings
			// 
			this->LabelSetings->AutoSize = true;
			this->LabelSetings->BackColor = System::Drawing::SystemColors::WindowText;
			this->LabelSetings->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 20.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LabelSetings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->LabelSetings->Location = System::Drawing::Point(477, 38);
			this->LabelSetings->Name = L"LabelSetings";
			this->LabelSetings->Size = System::Drawing::Size(199, 33);
			this->LabelSetings->TabIndex = 7;
			this->LabelSetings->Text = L"Ваши настройки";
			// 
			// StartNumber
			// 
			this->StartNumber->AutoSize = true;
			this->StartNumber->BackColor = System::Drawing::SystemColors::Desktop;
			this->StartNumber->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StartNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->StartNumber->Location = System::Drawing::Point(483, 95);
			this->StartNumber->Name = L"StartNumber";
			this->StartNumber->Size = System::Drawing::Size(141, 17);
			this->StartNumber->TabIndex = 8;
			this->StartNumber->Text = L"Начальные значения: 2,4";
			// 
			// StrMaxNumber
			// 
			this->StrMaxNumber->AutoSize = true;
			this->StrMaxNumber->BackColor = System::Drawing::SystemColors::Desktop;
			this->StrMaxNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->StrMaxNumber->Location = System::Drawing::Point(486, 127);
			this->StrMaxNumber->Name = L"StrMaxNumber";
			this->StrMaxNumber->Size = System::Drawing::Size(164, 13);
			this->StrMaxNumber->TabIndex = 9;
			this->StrMaxNumber->Text = L"Максимальное значение: 2048";
			// 
			// SizeField
			// 
			this->SizeField->AutoSize = true;
			this->SizeField->BackColor = System::Drawing::SystemColors::Desktop;
			this->SizeField->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->SizeField->Location = System::Drawing::Point(486, 158);
			this->SizeField->Name = L"SizeField";
			this->SizeField->Size = System::Drawing::Size(82, 13);
			this->SizeField->TabIndex = 10;
			this->SizeField->Text = L"Размер поля 4";
			// 
			// StopB
			// 
			this->StopB->Location = System::Drawing::Point(486, 261);
			this->StopB->Name = L"StopB";
			this->StopB->Size = System::Drawing::Size(121, 23);
			this->StopB->TabIndex = 12;
			this->StopB->Text = L"Остановить игру";
			this->StopB->UseVisualStyleBackColor = true;
			this->StopB->Visible = false;
			this->StopB->Click += gcnew System::EventHandler(this, &MainForm::StopB_Click);
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"./help.chm";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(680, 422);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Справка";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(767, 468);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->StopB);
			this->Controls->Add(this->SizeField);
			this->Controls->Add(this->StrMaxNumber);
			this->Controls->Add(this->StartNumber);
			this->Controls->Add(this->LabelSetings);
			this->Controls->Add(this->CountRez);
			this->Controls->Add(this->Counter);
			this->Controls->Add(this->SettingsBottom);
			this->Controls->Add(this->StartBottom);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->helpProvider1->SetShowHelp(this, true);
			this->Text = L"Игра 2048";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void F_Closed(Object^ sender, EventArgs^ e)
		{
			if (Is_3_Ok) StartNumber->Text = "Начальные значения" + " 3,6";
			else StartNumber->Text = "Начальные значения" + " 2,4";
			StrMaxNumber->Text = "Максимальное значение " + System::Convert::ToString(MaxNumber);
			if (FieldSize == 8) SizeField->Text = "Размер поля 8";
			if (FieldSize == 4) SizeField->Text = "Размер поля 4";

		}
#pragma endregion
	private: System::Void SettingsBottom_Click(System::Object^  sender, System::EventArgs^  e) {
				 Settings ^ F = gcnew Settings();
				 F->Show();
				 F->Closed += gcnew EventHandler(this, &MainForm::F_Closed);
				 
	}
		 

private: System::Void StartBottom_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 Field = gcnew GField(FieldSize,MaxNumber,Is_3_Ok);

			 Field->GetFirstRandom(Is_3_Ok);
			 StartBottom->Visible = false;
			 SettingsBottom->Visible = false;
			 StopB->Visible = true;
			 Is_Game_Started = true;
			 CountRez->Visible = true;
			 Counter->Visible = true;
			 is_3 = Is_3_Ok;
			 DrawField();
}
private: System::Void StopB_Click(System::Object^  sender, System::EventArgs^  e) {
			 Field->ClearField();
			 delete (Field);		
			 StopB->Visible = false;
			 StartBottom->Visible = true;
			 SettingsBottom->Visible = true;
			 Is_Game_Started = false;
			 CountRez->Visible = false;
			 Counter->Visible = false;
}
private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			
}
void DrawField()
{
	pictureBox1->Refresh();
}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		
			 if (Is_Game_Started)
			 {
				 if (FieldSize == 4)
				 {
					 int x = 15;
					 int y = 10;
					 String ^n;
					 StringFormat^ drawFormat = gcnew StringFormat;
					 drawFormat->FormatFlags = StringFormatFlags::DirectionVertical;
					 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
					 SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
					 for (int i = 0; i < 4; i++)
					 {
						 for (int j = 0; j < 4; j++)
						 {
							 SolidBrush ^Cr = GetBrash(i, j,is_3);
							 e->Graphics->FillRectangle(Cr, x, y, 83,83);
							 n = System::Convert::ToString(Field->GetElement(i,j));
							 PointF drawPoint = PointF(x + 30, y + 30);
							 e->Graphics->DrawString(n, drawFont, System::Drawing::Brushes::Black, drawPoint);
							 x += 95;
						 }
						 x = 15;
						 y += 95;
					 }
				 }
					 if (FieldSize == 8)
					 {
						 int x = 10;
						 int y = 10;
						 String ^n;
						 StringFormat^ drawFormat = gcnew StringFormat;
						 drawFormat->FormatFlags = StringFormatFlags::DirectionVertical;
						 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 11);
						 SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
						 for (int i = 0; i < FieldSize; i++)
						 {
							 for (int j = 0; j < FieldSize; j++)
							 {
								 SolidBrush ^Cr = GetBrash(i, j,is_3);
								 e->Graphics->FillRectangle(Cr, x, y, 36, 36);
								 n = System::Convert::ToString(Field->GetElement(i,j));
								 PointF drawPoint = PointF(x + 6, y + 6);
								 e->Graphics->DrawString(n, drawFont, System::Drawing::Brushes::Black, drawPoint);
								 x += 47;
							 }
							 x = 10;
							 y += 46;
						 }
				
					 }
			
			 }
}
		 private: System::Drawing::SolidBrush ^ GetBrash(int i, int j,bool is_3);
private: System::Void MainForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 // 1 - Вверх 2 - Вниз 3 - Влево 4 - Вправо
			 int pos;
			 bool Move_Ok = false;
			 if (Is_Game_Started == false) return;
			 if (e->KeyCode == Keys::Left)
			 {
				 pos = 3;
				 Move_Ok = true;
			 }
			 if (e->KeyCode == Keys::Right)
			 {

				 pos = 4;
				 Move_Ok = true;
			 }
			 if (e->KeyCode == Keys::Up)
			 {

				 pos = 1;
				 Move_Ok = true;
			 }
			 if (e->KeyCode == Keys::Down)
			 {
				 pos = 2;
				 Move_Ok = true;
			 }
			 if (Move_Ok)
			 {
				 //System::Media::SoundPlayer ^simpleSound = gcnew System::Media::SoundPlayer("Click.wav");
				 //simpleSound->Play();
				 std::cout << pos << endl;
				 Field->MoveNumbers(pos);
				 DrawField();
				 CountRez->Text = System::Convert::ToString(Field->CountScore());
				 if (Field->IsWinGame())
				 {


					 StartBottom->Visible = true;
					 SettingsBottom->Visible = true;
					 StopB->Visible = false;
					// RecordsBottom->Visible = true;
					 Is_Game_Started = false;
					 CountRez->Visible = false;
					 Counter->Visible = false;
					 MessageBox::Show("Вы выиграли, ваш результат " + CountRez->Text);
				 }
				 if (Field->IsLoseGame())
				 {
					 StartBottom->Visible = true;
					 SettingsBottom->Visible = true;
					 StopB->Visible = false;
					 Is_Game_Started = false;
					 CountRez->Visible = false;
					 Counter->Visible = false;
					 MessageBox::Show("Вы проиграли, ваш результат " + CountRez->Text);
				 }
				 Field->InsertRandom();
				 DrawField();
			 }

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
			 Help::ShowHelp(this, helpProvider1->HelpNamespace);
}
};

}
