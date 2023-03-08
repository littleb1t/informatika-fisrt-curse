#include "Header.h"

using namespace std;




void task1()
{
	CLEAR;
	cout << "Лабораторка 1\n\n";
	PAUSE;
}

void task2()
{
	CLEAR;
	cout << "Лабораторка 2\n\n";
	PAUSE;
}

void task3()
{
	CLEAR;
	cout << "Лабораторка 3\n\n";
	PAUSE;
}


int FirstTermMenu()
{
	UCHAR ch = 0;

	do
	{
		CLEAR;
		cout << "\n\n    Меню первого семестра:\n\n";
		cout << "1 - Лабораторная работа№1\n";
		cout << "2 - Лабораторная работа№2\n";
		cout << "3 - Лабораторная работа№3\n";
		cout << "\n\nДля выхода нажмите клавишу ESC\n\n";

		ch = _getch();
		switch (ch)
		{
			case '1':task1(); break;
			case '2':task2(); break;
			case '3':task3(); break;
			default:
			break;
		}

	} while (ch != 27);


	return 0;
}