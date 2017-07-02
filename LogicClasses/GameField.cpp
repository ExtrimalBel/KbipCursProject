#include "Stdafx.h"
#include "GameField.h"
#include <cstdlib>				 
#include <iostream>
#include <ctime>

using namespace	GameField;

void GField::GetFirstRandom(bool Is_3_ok)
{
	int i, j; 
	int sn; 
	if (startnumber == 2) sn = 2;
	else sn = 3;
	int x;
	x = rand() % 2;
	i = rand() % n;
	j = rand() % n;
	if (x == 1) Field[i][j] = sn + sn;
	else Field[i][j] = sn;
	while (Field[i][j] != 0)
	{
		i = rand() % n;
		j = rand() % n;
	}
	x = rand() % 2;
	if (x == 1) Field[i][j] = sn + sn;
	else Field[i][j] = sn;
}

GField::GField(int size, int maxn, bool Is_3_Ok)
{
	max = maxn;
	int i, j;
	n = size;
	if (Is_3_Ok) startnumber = 3;
	else startnumber = 2;
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
	BField = new int *[n];
	for (int i = 0; i < n; i++)
	{
		BField[i] = new int[n];
	}
}

void GField::MoveNumbers(int pos) // Метод вызывающий методы перемещения чисел в игровом поле
{
	bool isSum = false;
	bool isMove = false;
	BackupField();

	FillGrid(pos,isSum);
	isSum = false;
	UpdateGreed(pos,isMove);
	isMove = false;
	do
	{	   
		isMove = false;
		isSum = false;
		FillGrid(pos,&isSum);
		UpdateGreed(pos,isMove);
	} while (isMove);
}

void GField::BackupField()
{
	for (int i = 0; i < n; i++)
	{
		BField[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		BField[i][j] = Field[i][j];
	}
}


void GField::FillGrid(int pos, bool Move)
{
	switch (pos)
	{
	case 1:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (!Field[j][i])
			{
				for (int k = j + 1; k<n; k++)
				if (Field[k][i])
				{
					Move = true;
					Field[j][i] = Field[k][i];
					Field[k][i] = 0;
					break;
				}
			}

		}break;

	case 2:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			if (!Field[j][i])
			{
				for (int k = j - 1; k >= 0; k--)
				if (Field[k][i])
				{
					Move = true;
					Field[j][i] = Field[k][i];
					Field[k][i] = 0;
					break;
				}
			}

		}break;
	case 3:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
		{
			if (!Field[i][j])
			{
				for (int k = j + 1; k<n; k++)
				if (Field[i][k])
				{
					Move = true;
					Field[i][j] = Field[i][k];
					Field[i][k] = 0;
					break;
				}
			}

		}break;


	case 4:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j >= 0; j--)
		{
			if (!Field[i][j])
			{
				for (int k = j - 1; k >= 0; k--)
				if (Field[i][k])
				{
					Move = true;
					Field[i][j] = Field[i][k];
					Field[i][k] = 0;
					break;
				}
			}

		}break;

	}
}

void GField::UpdateGreed(int pos,bool &Sum)
{

	switch (pos)
	{
	case 1:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n - 1; j++)
		{
			if (Field[j][i] && Field[j][i] == Field[j + 1][i])
			{
				Sum = true;
				Field[j][i] += Field[j + 1][i];
				Field[j + 1][i] = 0;

			}
		}break;

	case 2:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j>0; j--)
		{
			if (Field[j][i] && Field[j][i] == Field[j - 1][i])
			{
				Sum = true;
				Field[j][i] += Field[j - 1][i];
				Field[j - 1][i] = 0;

			}
		}break;

	case 3:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n - 1; j++)
		{
			if (Field[i][j] && Field[i][j] == Field[i][j + 1])
			{
				Sum = true;
				Field[i][j] += Field[i][j + 1];
				Field[i][j + 1] = 0;

			}
		}break;

	case 4:
		for (int i = 0; i<n; i++)
		for (int j = n - 1; j>0; j--)
		{
			if (Field[i][j] && Field[i][j] == Field[i][j - 1])
			{
				Sum = true;
				Field[i][j] += Field[i][j - 1];
				Field[i][j - 1] = 0;
			}
		}break;


	}
}

int GField::CountScore()
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

void GField::InsertRandom()
{
	if (IsFieldEqual())
		return;
	int a, b;
	a = rand() % n;
	b = rand() % n;
	while (Field[a][b] != 0)
	{
		a = rand() % n;
		b = rand() % n;
	}
	Field[a][b] = startnumber;
}

bool GField::IsLoseGame()
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

bool GField::IsWinGame()
{
	bool IsWin = false;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		if (Field[i][j] == max)
		{
			IsWin = true;
		}
	}
	return IsWin;
}

void GField::ClearField()
{
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		Field[i][j] = 0;
	}
}

bool GField::IsFieldEqual()
{
	bool Equal = true;
	for (int i = 0; i < n;i++)
	for (int j = 0; j < n; j++)
	{
		if (BField[i][j] != Field[i][j])
			Equal = false;
	}
	return Equal;
}

