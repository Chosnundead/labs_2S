#include <iostream>
#include "Lab3.h"

using namespace std;

bool _menu() {
	system("cls");

	int check;
	cout << "1: Лабораторная работа #3." << endl;
	cout << "0: Выход." << endl;
	cout << "Введите номер пункта: ";
	cin >> check;

	switch (check) {
	case 0:
		return false;
	case 1:
		system("cls");
		Lab3 start;
		break;
	}

	return true;
}

int main() {
	setlocale(LC_ALL, "Russian");

	while (_menu());

	return 0;
}