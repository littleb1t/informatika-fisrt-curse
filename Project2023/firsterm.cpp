#include "Header.h"

using namespace std;




void task1()
{
	CLEAR;
	cout << "����������� 1\n\n";
	PAUSE;
}

void task2()
{
	CLEAR;
	cout << "����������� 2\n\n";
	PAUSE;
}

void task3()
{
	CLEAR;
	cout << "����������� 3\n\n";
	PAUSE;
}


int FirstTermMenu()
{
	UCHAR ch = 0;

	do
	{
		CLEAR;
		cout << "\n\n    ���� ������� ��������:\n\n";
		cout << "1 - ������������ ������1\n";
		cout << "2 - ������������ ������2\n";
		cout << "3 - ������������ ������3\n";
		cout << "\n\n��� ������ ������� ������� ESC\n\n";

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