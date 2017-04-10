#include <iomanip>
#include <iostream>
#include "Settings.h"
#include "Records.h"
#include <ctime>
#include <cstdlib>
#pragma once
extern bool Is_3_Ok = false;
extern int FieldSize = 4;
extern int MaxNumber = 2048;
extern bool RandomNumbers = false;
void GetFirstRandom(int &a, int &b, int &c, int &d, int &e, int &f, int n, bool Is_3_ok);
void MoveNumbers(int **Field,int n,int pos); // Сдесь pos указывает на то, в какую сторону будем перемещать
int CountScore(int **Field, int n); // Данная функция считает очки путем сложения всех значений в игровом поле
void RealMove(int **Field, int n, int x, int y, int pos);
void GetRandom(int ** Field, int n, int &a, int &b);
bool IsLoseGame(int **Field, int n);
bool IsWinGame(int **Field, int n, int maxn);
int ** BackupField(int **Field, int n);
void FillGrid(int **grid, int n, int pos);
void UpdateGreed(int **grid, int pos,int n);

namespace My_CP {
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
	private: System::Windows::Forms::Label^  LabelSetings;
	private: System::Windows::Forms::Label^  StartNumber;
	private: System::Windows::Forms::Label^  StrMaxNumber;
	private: System::Windows::Forms::Label^  SizeField;
	private: System::Windows::Forms::Label^  LRandomNumber;
	private: System::Windows::Forms::Button^  StopB;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;

	public:
		int **Field;
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
	private: System::Windows::Forms::Button^  RecordsBottom;
	private: System::Windows::Forms::Button^  SettingsBottom;
	private: System::Windows::Forms::Label^  Counter;
	private: System::Windows::Forms::Label^  CountRez;

	private: System::Windows::Forms::TextBox^  textBox1;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->StartBottom = (gcnew System::Windows::Forms::Button());
			this->RecordsBottom = (gcnew System::Windows::Forms::Button());
			this->SettingsBottom = (gcnew System::Windows::Forms::Button());
			this->Counter = (gcnew System::Windows::Forms::Label());
			this->CountRez = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->LabelSetings = (gcnew System::Windows::Forms::Label());
			this->StartNumber = (gcnew System::Windows::Forms::Label());
			this->StrMaxNumber = (gcnew System::Windows::Forms::Label());
			this->SizeField = (gcnew System::Windows::Forms::Label());
			this->LRandomNumber = (gcnew System::Windows::Forms::Label());
			this->StopB = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
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
			// RecordsBottom
			// 
			this->RecordsBottom->Location = System::Drawing::Point(483, 342);
			this->RecordsBottom->Name = L"RecordsBottom";
			this->RecordsBottom->Size = System::Drawing::Size(124, 23);
			this->RecordsBottom->TabIndex = 2;
			this->RecordsBottom->Text = L"Рекорды";
			this->RecordsBottom->UseVisualStyleBackColor = true;
			this->RecordsBottom->Click += gcnew System::EventHandler(this, &MainForm::RecordsBottom_Click);
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
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::Color::Olive;
			this->textBox1->Location = System::Drawing::Point(201, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 6;
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
			this->StartNumber->Size = System::Drawing::Size(116, 17);
			this->StartNumber->TabIndex = 8;
			this->StartNumber->Text = L"Начальные значения";
			// 
			// StrMaxNumber
			// 
			this->StrMaxNumber->AutoSize = true;
			this->StrMaxNumber->BackColor = System::Drawing::SystemColors::Desktop;
			this->StrMaxNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->StrMaxNumber->Location = System::Drawing::Point(486, 127);
			this->StrMaxNumber->Name = L"StrMaxNumber";
			this->StrMaxNumber->Size = System::Drawing::Size(134, 13);
			this->StrMaxNumber->TabIndex = 9;
			this->StrMaxNumber->Text = L"Максимальное значение";
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
			// LRandomNumber
			// 
			this->LRandomNumber->AutoSize = true;
			this->LRandomNumber->BackColor = System::Drawing::SystemColors::Desktop;
			this->LRandomNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->LRandomNumber->Location = System::Drawing::Point(486, 186);
			this->LRandomNumber->Name = L"LRandomNumber";
			this->LRandomNumber->Size = System::Drawing::Size(185, 13);
			this->LRandomNumber->TabIndex = 11;
			this->LRandomNumber->Text = L"не вставлять рандомные значения";
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
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(694, 468);
			this->Controls->Add(this->StopB);
			this->Controls->Add(this->LRandomNumber);
			this->Controls->Add(this->SizeField);
			this->Controls->Add(this->StrMaxNumber);
			this->Controls->Add(this->StartNumber);
			this->Controls->Add(this->LabelSetings);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->CountRez);
			this->Controls->Add(this->Counter);
			this->Controls->Add(this->SettingsBottom);
			this->Controls->Add(this->RecordsBottom);
			this->Controls->Add(this->StartBottom);
			this->Controls->Add(this->pictureBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->KeyPreview = true;
			this->Name = L"MainForm";
			this->Text = L"Игра 2048";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::MainForm_KeyPress);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void F_Closed(Object^ sender, EventArgs^ e)
		{
			textBox1->Text = System::Convert::ToString(RandomNumbers);
			if (Is_3_Ok) StartNumber->Text = "Начальные значения" + " 3,6";
			else StartNumber->Text = "Начальные значения" + " 2,4";
			StrMaxNumber->Text = "Максимальное значение " + System::Convert::ToString(MaxNumber);
			if (RandomNumbers) LRandomNumber->Text = "Вставлять рандомные значения";
			else LRandomNumber->Text = "Не вставлять рандомные значения";
			if (FieldSize == 8) SizeField->Text = "Размер поля 8";
			if (FieldSize == 4) SizeField->Text = "Размер поля 4";

		}
#pragma endregion
	private: System::Void SettingsBottom_Click(System::Object^  sender, System::EventArgs^  e) {
				 Settings ^ F = gcnew Settings();
				 F->Show();
				 F->Closed += gcnew EventHandler(this, &MainForm::F_Closed);
				 
	}
private: System::Void MainForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 
}
		 

private: System::Void StartBottom_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 int i, j;
			 n = FieldSize;
			 int **f = new int *[n]; // Поле игры
			 for (i = 0; i < n; i++)
			 {
				 f[i] = new int[n];
			 }
			 for (i = 0; i < n; i++)
			 for (j = 0; j < n; j++)
			 {
				 f[i][j] = 0;
			 }
			 Field = f;
			 int a, b, c, d, g, s;
			 GetFirstRandom(a, b, c, d, g, s, n,Is_3_Ok);
			 Field[a][b] = g;
			 Field[c][d] = s;
			 system("cls");
			 for (i = 0; i < n; i++)
			 {
				 for (j = 0; j < n; j++)
				 {
					 cout << setw(4) << Field[i][j];
				 }
				 cout << endl;
			 }
			 StartBottom->Visible = false;
			 SettingsBottom->Visible = false;
			 StopB->Visible = true;
			 RecordsBottom->Visible = false;
			 Is_Game_Started = true;
			 CountRez->Visible = true;
			 Counter->Visible = true;
			 DrawField();
}
private: System::Void StopB_Click(System::Object^  sender, System::EventArgs^  e) {
			 int i, j;
			 for (i = 0; i < n; i++)
			 for (j = 0; j < n; j++)
			 {
				 Field[i][j] = 0;
			 }
			 system("cls");
			 for (i = 0; i < n; i++)
			 {
				 for (j = 0; j < n; j++)
				 {
					 cout << setw(4) << Field[i][j];
				 }
				 cout << endl;
			 }
			 StartBottom->Visible = true;
			 SettingsBottom->Visible = true;
			 StopB->Visible = false;
			 RecordsBottom->Visible = true;
			 Is_Game_Started = false;
			 CountRez->Visible = false;
			 Counter->Visible = false;
}
private: System::Void RecordsBottom_Click(System::Object^  sender, System::EventArgs^  e) {
			 Records ^ R = gcnew Records();
			 R->Show();
}
private: System::Void MainForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
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
				 
				 textBox1->Text = System::Convert::ToString(pos);
				 MoveNumbers(Field, n, pos);
				 int i, j;
				 system("cls");
				 int a1, a2;
				 GetRandom(Field,n,a1, a2);
				 int insertn;
				 if (Is_3_Ok) insertn = 3;
				 else insertn = 2;
				 Field[a1][a2] = insertn;
				 DrawField();
				 for (i = 0; i < n; i++)
				 {
					 for (j = 0; j < n; j++)
					 {
						 cout << setw(4) << Field[i][j];
					 }
					 cout << endl;
				 }
				 CountRez->Text = System::Convert::ToString(CountScore(Field, n));
				 if (IsWinGame(Field, n, MaxNumber))
				 {
					 for (i = 0; i < n; i++)
					 for (j = 0; j < n; j++)
					 {
						 Field[i][j] = 0;
					 }
					 
					 system("cls");
					 for (i = 0; i < n; i++)
					 {
						 for (j = 0; j < n; j++)
						 {
							 cout << setw(4) << Field[i][j];
						 }
						 cout << endl;
					 }
					 StartBottom->Visible = true;
					 SettingsBottom->Visible = true;
					 StopB->Visible = false;
					 RecordsBottom->Visible = true;
					 Is_Game_Started = false;
					 CountRez->Visible = false;
					 Counter->Visible = false;
					 MessageBox::Show("Вы выиграли, ваш результат " + CountRez->Text);
				 }
				 if (IsLoseGame(Field, n))
				 {
					 for (i = 0; i < n; i++)
					 for (j = 0; j < n; j++)
					 {
						 Field[i][j] = 0;
					 }
					 system("cls");
					 for (i = 0; i < n; i++)
					 {
						 for (j = 0; j < n; j++)
						 {
							 cout << setw(4) << Field[i][j];
						 }
						 cout << endl;
					 }
					 StartBottom->Visible = true;
					 SettingsBottom->Visible = true;
					 StopB->Visible = false;
					 RecordsBottom->Visible = true;
					 Is_Game_Started = false;
					 CountRez->Visible = false;
					 Counter->Visible = false;
					 MessageBox::Show("Вы проиграли, ваш результат " + CountRez->Text);
				 }
				 
			 }

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
					 int x = 10;
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
							 e->Graphics->DrawRectangle(System::Drawing::Pens::Red, x, y, 75, 75);
							 n = System::Convert::ToString(Field[i][j]);
							 PointF drawPoint = PointF(x + 35, y + 35);
							 e->Graphics->DrawString(n, drawFont, System::Drawing::Brushes::Black, drawPoint);
							 x += 85;
						 }
						 x = 10;
						 y += 85;
					 }
				 }
					 if (FieldSize == 8)
					 {
						 int x = 10;
						 int y = 10;
						 String ^n;
						 StringFormat^ drawFormat = gcnew StringFormat;
						 drawFormat->FormatFlags = StringFormatFlags::DirectionVertical;
						 System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
						 SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
						 for (int i = 0; i < 8; i++)
						 {
							 for (int j = 0; j < 8; j++)
							 {
								 e->Graphics->FillRectangle(gcnew SolidBrush(Color::Red),x,y,46,46);
								 n = System::Convert::ToString(Field[i][j]);
								 PointF drawPoint = PointF(x + 15, y + 15);
								 e->Graphics->DrawString(n, drawFont, System::Drawing::Brushes::Black, drawPoint);
								 x += 56;
							 }
							 x = 10;
							 y += 56;
						 }
				
					 }
			
			 }
}
};

}
