#include "Header.h"
void creator()
{
	CLEAR;
	cout << "\n\n��������� ������ ������� ������� ���.\n\n";
	PAUSE;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	
	SetConsoleTitle(L"������� ������ �� ���������� \"���������� ����������������\" �������� ������� �. �.");
	if (argc > 0)
	{
		cout << "��������� � ���������� ����\n";
		for (int i = 0; i < argc; i++)
		{
			cout << "�������� � " << (i + 1) << "  " << argv[i] << "\n";
		}
	}

	UCHAR ch = 0;

	do
	{
		CLEAR;
		cout << "\n\n    ���� ���������:\n\n";
		cout << "0 - �������� � ������������\n";
		cout << "1 - ��������� ������� ��������\n";
		cout << "2 - ������� �����\n";
		cout << "L - ��������\n";
		cout << "\n\n��� ������ ������� ������� ESC\n\n";
		cout << "R - ��������\n";
	
		ch = _getch();
		switch (ch)
		{
			case '0':creator(); break;
			case '1':FirstTermMenu(); break;
			case'2':maska(); break;
			case 'L':case 'l':case (UCHAR)'�': case (UCHAR)'�':LabirintMenu();
			case 'R':case'r':case (UCHAR)'�':case (UCHAR)'�': RecMenu();
			default:
				break;
		}

	} while (ch != 27);



	system("pause");
	return 0;
}