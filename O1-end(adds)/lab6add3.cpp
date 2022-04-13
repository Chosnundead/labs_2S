#include "lab6add3.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int _countList(vector<float>* arr) {
	return arr->size();
}

void _deleteList(vector<float>* arr) {
	arr->erase(arr->begin(), arr->end());
}

lab6add3::lab6add3() {
	setlocale(LC_ALL, "russian");
	string input;
	vector<float> arr;

	do {
		cout << "Введите значение для вашей очереди(float через запятую): ";
		getline(cin, input);
		if (input != "") {
			arr.push_back(stof(input.c_str()));
			cout << "Ваше значение: " << stof(input.c_str()) << endl;
		}
	} while (input != "");

	cout << "Размер до функции удаления: " << _countList(&arr) << endl;
	_deleteList(&arr);
	cout << "Размер после функции удаления: " << _countList(&arr) << endl;
}