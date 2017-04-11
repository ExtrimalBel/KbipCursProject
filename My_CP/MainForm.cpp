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














