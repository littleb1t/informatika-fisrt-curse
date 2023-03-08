#include "labirint.h"

const int nL = 32;
const int nC = 32;
UINT map[nL] =
{
	0b1101'1111'1111'1111'1111'1111'1111'1111,
	0b1101'1111'1101'1100'0011'0000'0000'0011,
	0b1101'1111'1001'1101'1000'0110'1111'1011,
	0b1101'1111'1011'1001'1000'0000'0011'1011,
	0b1100'0000'0000'0000'0000'1111'1000'0011,
	0b1110'1111'1111'1101'1110'1111'1110'0011,
	0b1110'0111'1111'1101'1110'1111'1110'1011,
	0b1111'0000'1111'1001'1110'1111'1110'1011,
	0b1111'1110'1111'1011'1110'0000'0000'1000,
	0b1111'1110'1111'1011'1111'1111'1111'1111,
	0b1111'1100'1110'0000'0011'1111'1111'1111,
	0b1100'0001'1110'1000'0000'0001'1111'1111,
	0b1101'1111'1110'1011'1011'1101'1111'1111,
	0b1101'1000'0110'0011'1011'1100'0011'1111,
	0b1100'0011'0000'0111'1011'1111'1000'0011,
	0b1111'1111'1111'1111'1000'0011'1111'1011,
	0b1111'1001'1000'0001'1011'1011'1111'1111,
	0b1000'1011'1011'1100'0011'1001'1111'1111,
	0b1110'0000'1001'1111'1011'1101'1111'1111,
	0b1111'1011'1000'1111'1011'1100'0001'1111,
	0b1111'0000'0000'0011'1000'0111'1101'1111,
	0b1111'1101'1111'1111'1101'0001'1101'1111,
	0b1100'0001'0000'0000'1101'1101'1100'0011,
	0b1101'1111'1111'1110'1101'1100'0111'1011,
	0b1101'1100'0111'1110'1100'0001'0000'0011,
	0b1100'0101'0011'1110'1111'1011'1101'1111,
	0b1111'0001'1000'1110'1111'1011'1101'1111,
	0b1111'1101'1111'1110'0000'0011'1000'0011,
	0b1111'1001'1000'0001'1111'1000'0011'1111,
	0b1111'1011'1011'1101'1111'1011'1001'1111,
	0b1111'1000'0011'1100'0000'0011'1100'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111
};
UINT nbit = 0b1000'0000'0000'0000'0000'0000'0000'0000; //Маска стены
int nSRow = 0, nSCol = 2;	//Стартовая позиция жука в лабиринте
int nERow = 8, nECol = 31;	//КОнечная позиция лабиринта 
int nRow = nSRow, nCol = nSCol;	//Текущая позиция жука в лабиринте

int LabirintMenu()
{
	UCHAR ch = 0;
	do
	{
		CLEAR;
		cout << "\n\n    Меню лабиринта:\n\n";
		cout << "0 - Лабиринт\n";
		//cout << "1 - Программы первого семестра\n";
		cout << "\n\nДля выхода нажмите клавишу ESC\n\n";

		ch = _getch();
		switch (ch)
		{
		case '0':labirint(); break;
		//case '1':FirstTermMenu(); break;
		default:
			break;
		}

	} while (ch != 27);


	return 0;
}


int labirint()
{
	CLEAR;

	UCHAR ch = ESC;
	
	SetCursor(0, 0);
	nRow = nSRow;
	nCol = nSCol;
	for (int i = 0; i < nL; i++)
	{
		for (int j = 0; j < nC; j++)
		{
		if (map[i] & (nbit >> j))
			{					SetColor(9, 9);
				cout << "00";
			}
			else				{
				if ((i == nRow) && (j == nCol))		//Позиция жука
				{
					//SetColor(CL_BLACK,CL_LIGHT_GREEN);
					SetColor(CL_LIGHT_GREEN, CL_LIGHT_GREEN);				
					cout << "ЖЖ";
				}
				else
				{						SetColor(0, 15);
					cout << "  ";
				}
			}
		}
			cout << endl;
	}
	do
	{
		SetCursor(nRow, nCol*2);
		SetColor(CL_GREEN);
		cout << "ЖЖ";
		ch = _getch();
		SetColor(CL_BLACK);
		SetCursor(nRow, nCol * 2);
		cout << "  ";
		HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);   //Получение хендла
		CONSOLE_CURSOR_INFO cursor = { 1, false };   // Число от 1 до 100 размер курсора в процентах
		// false\true - видимость
		SetConsoleCursorInfo(hCons, &cursor);
		//CONSOLE_CURSOR_INFO cursor = { 1, false };   // Число от 1 до 100 размер курсора в процентах
		// false\true - видимость
		//SetConsoleCursorInfo(hCons, &cursor);  //Применение заданных параметров курсора

		switch (ch)
		{
			case 72:  if ((nRow == 0) || (map[nRow - 1] & (nbit >> nCol))) Beep(27, 500); else nRow--; break;			// Вверх
			case 75: if ((nCol == 0) || (map[nRow] & (nbit >> (nCol - 1)))) Beep(10000, 500); else nCol--;	break;		// Влево
			case 77:if ((nCol + 1 == nC) || (map[nRow] & (nbit >> nCol + 1))) Beep(10000, 500); else nCol++; break;	// Вправо
			case 80:if (((nRow+1) ==nL)||(map[nRow+1]& (nbit>>nCol))) Beep(10000, 500);else  nRow++;			// Вниз
				break;

			default:
				break;
		}
	} while (!((nRow == nERow) && (nCol == nECol)) && (ch != ESC)); 


	SetCursor(nL + 2, 0);
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	if (ch == ESC) cout << "Аварийный выход\n\n\n"; else cout << "Успешный выход из лабиринта. УРААА ПОБЕДА!!!!\n\n\n\n";
	SetColor(0, 15);
	PAUSE;
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, true };
	SetConsoleCursorInfo(hCons, &cursor);
	return 0;
}
