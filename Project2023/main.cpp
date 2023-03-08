#include "Header.h"
void creator()
{
	CLEAR;
	cout << "\n\nПрограмму создал хороший человек ГТИ.\n\n";
	PAUSE;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	
	SetConsoleTitle(L"Учебный проект по дисциплине \"Технологии программирования\" Студента Головей Т. И.");
	if (argc > 0)
	{
		cout << "Аргументы у приложения есть\n";
		for (int i = 0; i < argc; i++)
		{
			cout << "Аргумент № " << (i + 1) << "  " << argv[i] << "\n";
		}
	}

	UCHAR ch = 0;

	do
	{
		CLEAR;
		cout << "\n\n    Меню программы:\n\n";
		cout << "0 - Сведения о программисте\n";
		cout << "1 - Программы первого семестра\n";
		cout << "2 - Битовая маска\n";
		cout << "L - Лабиринт\n";
		cout << "\n\nДля выхода нажмите клавишу ESC\n\n";
		cout << "R - Рекурсия\n";
	
		ch = _getch();
		switch (ch)
		{
			case '0':creator(); break;
			case '1':FirstTermMenu(); break;
			case'2':maska(); break;
			case 'L':case 'l':case (UCHAR)'Д': case (UCHAR)'д':LabirintMenu();
			case 'R':case'r':case (UCHAR)'к':case (UCHAR)'К': RecMenu();
			default:
				break;
		}

	} while (ch != 27);



	system("pause");
	return 0;
}