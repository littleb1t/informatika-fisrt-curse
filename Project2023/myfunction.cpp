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
	short int mas[n], maska;//������ ��������� ����� � ����� 
	CLEAR;
	cout << "������� �� ������� ��������� ����� ��,\n ������� ������������� �����\n\n";
	cout << "\n������ ��������� �����\n";
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand();
		cout << mas[i] << " ";
	}
	cout << "\n\n������� �����:"; cin >> maska;
	cout << "\n\n\n����� ��������������� �����: \n";
	for (int i = 0; i < n; i++)
		if ((mas[i] & maska) == maska) cout << mas[i] << "; ";
	SKIP;
	PAUSE;
}


