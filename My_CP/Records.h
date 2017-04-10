#pragma once

namespace My_CP {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Records
	/// </summary>
	public ref class Records : public System::Windows::Forms::Form
	{
	public:
		Records(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все пользуемые ресурсы.
		/// </summary>
		~Records()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;


	private: System::ComponentModel::IContainer^  components;
	protected:



	protected:

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Location = System::Drawing::Point(51, 37);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(384, 228);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Рекорды пользователей";
			// 
			// Records
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->ClientSize = System::Drawing::Size(497, 314);
			this->Controls->Add(this->groupBox1);
			this->Name = L"Records";
			this->Text = L"Records";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
