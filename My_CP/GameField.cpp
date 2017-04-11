#include <cstdlib>
#include <ctime>
#include "GameField.h"

void GField::GetFirstRandom( bool Is_3_ok) // ����������� � ������ ���� ������������� ��������� ������
{
	/* Получаем случайные числа при старте и координаты на которые их надо записаь
	*/
	int a, b, c, d, g, s,e,f;
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
	Field[a][b] = g;
	Field[c][d] = s;
}

GField::GField(int size,int maxn)
{
	max = maxn;
	int i, j;
	n = size;
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
}

void GField::MoveNumbers(int pos)
{

	BackupField();
	FillGrid(pos);
	UpdateGreed(pos);
	FillGrid(pos);
}

int ** GField::BackupField()
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


void GField::FillGrid(int pos)
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
					Field[j][i] =Field[k][i];
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
					Field[i][j] = Field[i][k];
					Field[i][k] = 0;
					break;
				}
			}

		}break;

	}
}

void GField::UpdateGreed(int pos)
{

	switch (pos)
	{
	case 1:
		for (int i = 0; i<n; i++)
		for (int j = 0; j<n - 1; j++)
		{
			if (Field[j][i] && Field[j][i] == Field[j + 1][i])
			{
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
	int a, b;
	a = rand() % n;
	b = rand() % n;
	int insertn = 2;
	if (Field[a][b] != 0)
		this->InsertRandom();
	else
	Field[a][b] = insertn;
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