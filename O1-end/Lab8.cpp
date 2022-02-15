#include "Lab8.h"
#include <iostream>
#include <list>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

int _menu8() {

	int choise;
	cout << "1: Ввод числа с клавиатуры" << endl;
	cout << "2: Вывод элементов в консольное окно" << endl;
	cout << "3: Удаление последнего" << endl;
	cout << "4: Минимальный и максимальный" << endl;
	cout << "5: Подсчет элементов с заданным значением" << endl;
	cout << "6: Лаба #10(13)" << endl;
	cout << "7: Лаба #10(15)" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return (int)choise;
}

void _lab10(int* arr) {
	if (arr[1] > 0) {
		if (!(arr[0] % arr[1])) {
			cout << arr[1] << "\t";
		}
		arr[1]--;
		return _lab10(arr);
	}
}

void _lab1015(int number, int step) {
	if (number > 100) {
		number += 10;
	}
	else {
		number += 4;
	}
	cout << step << ": " << number << endl;
	step++;
	_lab1015(number, step);
}

void _lab1015start() {
	int number;
	do {
		cout << "Введите число: ";
		cin >> number;
	} while (number < 0);
	_lab1015(number, 0);
}

void _lab10start() {
	int number;
	cout << "Введите положительное натуральное число для подсчета: ";
	cin >> number;
	int arr[2] = { number, number };
	_lab10(arr);
	cout << endl;
}

void _add8(list<int>& arr) {
	int number;
	cout << "Введите число: ";
	cin >> number;
	number = (number > 0) ? (-number) : number;
	arr.push_back(number);
}

void _show8(list<int>& arr) {
	int counter = 0;
	for (int i : arr) {
		cout << "queue[" << counter << "] == " << i << endl;
		counter++;
	}
	cout << counter << " элементов." << endl;
}

void _minMax8(list<int>& arr) {
	if (arr.size()) {
		int min = INT_MAX, max = INT_MIN;
		for (int i : arr) {
			if (i < min)
				min = i;
			if (i > max)
				max = i;
		}
		cout << "min == " << min << endl << "max == " << max << endl;
	}
	else {
		cout << "!0 элементов!" << endl;
	}
}

void _countOfNumber8(list<int>& arr) {
	int number, counter = 0;
	cout << "Введите ваше значение для посчета: ";
	cin >> number;
	for (int i : arr) {
		if (i == number) {
			counter++;
		}
	}
	cout << "Значение повторяется " << counter << " раз." << endl;
}

Lab8::Lab8() {
	list<int> queue;

	while (int choise = _menu8()) {
		switch (choise) {
		case 1:
			_add8(queue);
			break;
		case 2:
			_show8(queue);
			break;
		case 3:
			queue.pop_back();
			break;
		case 4:
			_minMax8(queue);
			break;
		case 5:
			_countOfNumber8(queue);
			break;
		case 6:
			_lab10start();
			break;
		case 7:
			_lab1015start();
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}