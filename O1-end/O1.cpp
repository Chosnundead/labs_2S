#include <iostream>
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab8.h"
#include "Lab11.h"
#include "Lab13.h"
#include "Lab14.h"
#include "Lab16.h"

using namespace std;

bool _menu() {
	system("cls");

	int check;
	cout << "1: Лабораторная работа #3." << endl;
	cout << "2: Лабораторная работа #4, 7." << endl;
	cout << "3: Лабораторная работа #5." << endl;
	cout << "4: Лабораторная работа #6." << endl;
	cout << "5: Лабораторная работа #8, 9, 10." << endl;
	cout << "6: Лабораторная работа #11, 12." << endl;
	cout << "7: Лабораторная работа #13." << endl;
	cout << "8: Лабораторная работа #14, 15." << endl;
	cout << "9: Лабораторная работа #16, 17." << endl;
	cout << "0: Выход." << endl;
	cout << "Введите номер пункта: ";
	cin >> check;

	switch (check) {
	case 0:
		return false;
	case 1:
	{
		system("cls");
		Lab3 startLab3;
	}
	break;
	case 2:
	{
		system("cls");
		Lab4 startLab4;
	}
	break;
	case 3:
	{
		system("cls");
		Lab5 startLab5;
	}
	break;
	case 4:
	{
		system("cls");
		Lab6 startLab6;
	}
	break;
	case 5:
	{
		system("cls");
		Lab8 startLab8;
	}
	break;
	case 6:
	{
		system("cls");
		Lab11 startLab11;
	}
	break;
	case 7:
	{
		system("cls");
		Lab13 startLab13;
	}
	break;
	case 8:
	{
		system("cls");
		Lab14 startLab14;
	}
	break;
	case 9:
	{
		system("cls");
		Lab16 startLab16;
	}
	break;
	}

	return true;
}

int main() {
	setlocale(LC_ALL, "Russian");

	while (_menu());

	return 0;
}