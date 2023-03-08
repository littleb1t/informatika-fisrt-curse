#include "MyFunction.h"

void SetColor(int pnColorBackground, int pnCOlorText)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnCOlorText & 0x000F)));
}


void SetColor(int pnColor)
{
	SetColor(pnColor, pnColor);
}


void SetCursor(short int pnRow,short int pnCol)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position{pnCol, pnRow};
	SetConsoleCursorPosition(hStdOut, position);
}


void maska()
{
	const int n = 20;
	short int mas[n], maska;//массив случайных чисел и маска 
	CLEAR;
	cout << "Выбрать из массива случайных чисел те,\n которые удовлетворяют маске\n\n";
	cout << "\nМассив случайных чисел\n";
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand();
		cout << mas[i] << " ";
	}
	cout << "\n\nВведите маску:"; cin >> maska;
	cout << "\n\n\nЧисла удовлетворябщие маске: \n";
	for (int i = 0; i < n; i++)
		if ((mas[i] & maska) == maska) cout << mas[i] << "; ";
	SKIP;
	PAUSE;
}


