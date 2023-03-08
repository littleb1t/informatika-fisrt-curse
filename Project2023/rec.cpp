#include "Header.h"
#include "labirint.h"

void RecMenu()
{
	UCHAR ch = 0;
	do {
		cout << "\n\n    ���� ��������:\n\n";
		cout << "0 - �������� �������\n";
		cout << "\n\n��� ������ ������� ������� ESC\n\n";

		ch = _getch();
		switch (ch)
		{
		case '0':RecTable(); break;
		default:
			break;
		}
	} while (ch != 27);
}

void RecTable()
{
	float x,ept;
	CLEAR;
	SetColor(CL_BLACK, CL_LIGHT_RED);
	cout << "������������� �������� ������������ ���� ������ ������������������ �� N ������\n\n\n\n";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	cout << "������� ����� � ������ ���� ������ 1\n\n";
	cout << "X = ";
	cin >> x;
	cout << "������� ����������� �������\n\n";
	cout << "epsilon = ";
	cin >> ept;
	cout << endl << endl << endl;
	SetColor(CL_BLACK, CL_LIGHT_BLUE);
	cout << setw(4) << "���" << setw(20) << "���� ����" << setw(35) << "����������� ��������\n\n";
	SetColor(CL_BLACK, CL_LIGHT_WHITE);
	float y = rec(x, ept, 0, 1, 1, 0);
	SKIP;
	PAUSE;
}

float rec(float x, float ept, float n, float an, float numc,float y)
{
	an = an * (-1) * x * x / ((n + 1) * (n + 2) * (n + 3) * (n + 4));
	y = y + an;
	cout << setw(4) << numc << setw(20) << an << setw(25) << y << endl;
	if (abs(an) <= ept)
	{
		return an;
	}
	return rec(x, ept, n + 4, an, numc+1, y);
}