#pragma once

using namespace System;

namespace GameField{

	public ref class GField
		/*
		Объект реализующий игровое поле и функции работы с ним
		*/
	{
	private:
		int max;
		int startnumber;
		int i, j;
		int **Field;
		int n;
		int **BField;
		bool IsFieldEqual();
	public:
		GField(int size, int maxn,bool Is_3_Ok);
		void GetFirstRandom(bool Is_3_ok);
		void MoveNumbers(int pos);
		void BackupField();
		void FillGrid(int pos, bool Move);
		void UpdateGreed(int pos,bool &Sum);
		int CountScore();
		void InsertRandom();
		bool IsLoseGame();
		bool IsWinGame();
		int GetElement(int i, int j)
		{
			return Field[i][j];
		}
		void ClearField();
	};
}