#include <iostream>
#include <iomanip>
#include <random>
#include <conio.h>
#include "MainForm.h"
#include "Settings.h"
#include <ctime>
using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThread]
void main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	My_CP::MainForm form;
	Application::Run(%form);
}


System::Drawing::SolidBrush ^ My_CP::MainForm::GetBrash(int i, int j,bool is_3)
{
	int x = Field->GetElement(i, j);
	SolidBrush ^ Br;
	if (!is_3)
	switch (x)
	{
	case 0:
		Br = gcnew SolidBrush(Color::Gray);
		break;
		case 2:
			Br = gcnew SolidBrush(Color::FromArgb(0xEEE4DA00));
			break;
	case 4:
		Br = gcnew SolidBrush(Color::FromArgb(0xEAE0C800));
		break;
	case 8:
		Br = gcnew SolidBrush(Color::FromArgb(0xF5956300));
		break;
	case 16:
		Br = gcnew SolidBrush(Color::FromArgb(0x3399bf00));
		break;
	case 32:
		Br = gcnew SolidBrush(Color::FromArgb(0xffa33300));
		break;
		case 64:
			Br = gcnew SolidBrush(Color::FromArgb(0xcef03000));
			break;
		case 128:
			Br = gcnew SolidBrush(Color::FromArgb(0xE8D8CE00));
			break;
		case 256:
			Br = gcnew SolidBrush(Color::FromArgb(0x99030300));
			break;
		case 512:
			Br = gcnew SolidBrush(Color::FromArgb(0x6BA5DE00));
			break;
		case 1024:
			Br = gcnew SolidBrush(Color::FromArgb(0xDCAD6000));
			break;
		case 2048:
			Br = gcnew SolidBrush(Color::FromArgb(0xB6002200));
			break;
	default:
		Br = gcnew SolidBrush(Color::FromArgb(0xB6002200));
		break;
	}
	else
		switch (x)
	{
		case 0:
			Br = gcnew SolidBrush(Color::Gray);
			break;
		case 3:
			Br = gcnew SolidBrush(Color::FromArgb(0xEEE4DA00));
			break;
		case 6:
			Br = gcnew SolidBrush(Color::FromArgb(0xEAE0C800));
			break;
		case 12:
			Br = gcnew SolidBrush(Color::FromArgb(0xF5956300));
			break;
		case 24:
			Br = gcnew SolidBrush(Color::FromArgb(0x3399ff00));
			break;
		case 48:
			Br = gcnew SolidBrush(Color::FromArgb(0xffa33300));
			break;
		case 96:
			Br = gcnew SolidBrush(Color::FromArgb(0xcef03000));
			break;
		case 192:
			Br = gcnew SolidBrush(Color::FromArgb(0xcef03000));
			break;
		case 384:
			Br = gcnew SolidBrush(Color::FromArgb(0xE8D8CE00));
			break;
		case 768:
			Br = gcnew SolidBrush(Color::FromArgb(0x99030300));
			break;
		case 1536:
			Br = gcnew SolidBrush(Color::FromArgb(0x6BA5DE00));
			break;
		case 3072:
			Br = gcnew SolidBrush(Color::FromArgb(0xDCAD6000));
			break;
		case 6144:
			Br = gcnew SolidBrush(Color::FromArgb(0xB6002200));
			break;
		default:
			Br = gcnew SolidBrush(Color::FromArgb(0xB6002200));
			break;
	}
	return Br;
}











