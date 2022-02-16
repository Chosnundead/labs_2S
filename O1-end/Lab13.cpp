#include "Lab13.h"
#include <iostream>
#include <vector>

using namespace std;

int _menu13() {

	int choise;
	cout << "1: Ввод элемента" << endl;
	cout << "2: Вывод элементов" << endl;
	cout << "3: Удаление минимальных элементов" << endl;
	cout << "4: Удаление по индексу" << endl;
	cout << "5: Объединение с статичной кучей" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return (int)choise;
}

void _sum13(vector<int>& arr, vector<int> addArr) {
	for (int i = 0; i < addArr.size(); i++) {
		arr.push_back(addArr[i]);
	}
}

void _deleteByIndex13(vector<int>& arr) {
	int number;
	cout << "Введите индекс: ";
	cin >> number;
	arr.erase((arr.begin() + number), (arr.begin() + number + 1));
}

void _deleteMin13(vector<int>& arr) {
	int min = INT_MAX, index;
	for (int i : arr) {
		if (i < min)
			min = i;
	}
	for (int step = 0; step < arr.size(); step++) {
		if (min == arr[step])
			index = step;
	}
	arr.erase((arr.begin() + index), (arr.begin() + index + 1));
}

void _showAll13(vector<int>& arr) {
	int counter = 0;
	for (int i : arr) {
		cout << "arr[" << counter << "] == " << i << endl;
		counter++;
	}
}

void _add13(vector<int>& arr) {
	int number;
	cout << "Введите значение для добавления: ";
	cin >> number;
	arr.push_back(number);
}

Lab13::Lab13() {
	vector<int> arr;
	vector<int> exampleForSum;

	while (int choise = _menu13()) {
		switch (choise) {
		case 1:
			_add13(arr);
			break;
		case 2:
			_showAll13(arr);
			break;
		case 3:
			_deleteMin13(arr);
			break;
		case 4:
			_deleteByIndex13(arr);
			break;
		case 5:
			_sum13(arr, exampleForSum);
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}