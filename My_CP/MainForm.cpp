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
void GetFirstRandom(int &a, int &b, int &c, int &d, int &e, int &f,int n, bool Is_3_ok) // ����������� � ������ ���� ������������� ��������� ������
{
	/* ����� ���������� ���������� � �������� ������ ���� ������
	� ��� ����� ��������� �� �� ����������*/
	a = rand() % n;
	b = rand() % n;
	int firstn, secondn;
	srand(time(NULL));

	
	if (Is_3_ok)
	{
		firstn = 3;
		secondn = 6;
	}
	else
	{
		firstn = 2;
		secondn = 4;
	}
	do
	{
		c = rand() % n;
		_sleep(2);
		d = rand() % n;
	} while (a == c && b == d);
	_sleep(2);
	e = rand() % 1;
	if (e == 1)
	{
		e = firstn;
		f = secondn;
	}
	else
	{
		e = firstn;
		_sleep(2);
		f = rand() % 1;
	}
	if (f == 1)
	{
		f = secondn;
	}
	else
	{
		f = firstn;
	}
}

void MoveNumbers(int **Field, int n, int pos)
{

	BackupField(Field, n);
	FillGrid(Field, n, pos);
	UpdateGreed(Field, pos,n);
	FillGrid(Field, n, pos);
}

int ** BackupField(int **Field, int n)
{
	int **BField = new int *[n];
	for (int i = 0; i < n; i++)
	{
		BField[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		BField[i][j] = Field[i][j];
	}
	return BField;
}

void FillGrid(int **grid, int n,int pos)
{
	switch (pos)
	{
	case 1:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (!grid[j][i])
			{
				for (int k = j + 1; k<n; k++)
				if (grid[k][i])
				{
					grid[j][i] = grid[k][i];
					grid[k][i] = 0;
					break;
				}
			}

		}break;

	case 2:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			if (!grid[j][i])
			{
				for (int k = j - 1; k >= 0; k--)
				if (grid[k][i])
				{
					grid[j][i] = grid[k][i];
					grid[k][i] = 0;
					break;
				}
			}

		}break;
	case 3:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (!grid[i][j])
			{
				for (int k = j + 1; k<n; k++)
				if (grid[i][k])
				{
					grid[i][j] = grid[i][k];
					grid[i][k] = 0;
					break;
				}
			}

		}break;


	case 4:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			if (!grid[i][j])
			{
				for (int k = j - 1; k >= 0; k--)
				if (grid[i][k])
				{
					grid[i][j] = grid[i][k];
					grid[i][k] = 0;
					break;
				}
			}

		}break;

	}
}

void UpdateGreed(int **grid, int pos,int n)
{

	switch (pos)
	{
	case 1:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n - 1; j++)
		{
			if (grid[j][i] && grid[j][i] == grid[j + 1][i])
			{
				grid[j][i] += grid[j + 1][i];
				grid[j + 1][i] = 0;

			}
		}break;

	case 2:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j>0; j--)
		{
			if (grid[j][i] && grid[j][i] == grid[j - 1][i])
			{
				grid[j][i] += grid[j - 1][i];
				grid[j - 1][i] = 0;

			}
		}break;

	case 3:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n - 1; j++)
		{
			if (grid[i][j] && grid[i][j] == grid[i][j + 1])
			{

				grid[i][j] += grid[i][j + 1];
				grid[i][j + 1] = 0;
				
			}
		}break;

	case 4:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j>0; j--)
		{
			if (grid[i][j] && grid[i][j] == grid[i][j - 1])
			{

				grid[i][j] += grid[i][j - 1];
				grid[i][j - 1] = 0;
			}
		}break;


	}
}
int CountScore(int **Field, int n)
{
	int i, j;
	int sum = 0;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		sum += Field[i][j];
	}
	return sum;
}

void GetRandom(int ** Field,int n,int &a, int &b)
{
	a = rand() % n;
	b = rand() % n;
	if (Field[a][b] != 0)
		GetRandom(Field,n,a, b);
}

bool IsLoseGame(int **Field, int n)
{
	bool Lose = true;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (Field[i][j] == 0)
		{
			Lose = false;
		}
	}
	return Lose;
}

bool IsWinGame(int **Field, int n, int maxn)
{
	bool IsWin = false;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (Field[i][j] == maxn)
		{
			IsWin = true;
		}
	}
	return IsWin;
}