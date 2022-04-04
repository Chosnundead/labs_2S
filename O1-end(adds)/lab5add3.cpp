#include "lab5add3.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<float> remove(vector<float>& arr) {
	arr.erase(arr.begin(), arr.begin() + 1);
	return arr;
}

lab5add3::lab5add3() {
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

	for (int step = 0; step < arr.size(); step++) {
		for (int anotherStep = 0; (anotherStep + 1) < arr.size(); anotherStep++) {
			if (arr[anotherStep] < arr[(anotherStep + 1)]) {
				float* temp = new float;
				*temp = arr[anotherStep];
				arr[anotherStep] = arr[(anotherStep + 1)];
				arr[(anotherStep + 1)] = *temp;
				delete temp;
			}
		}
	}
	cout << "Ваша очередь: " << endl;
	for (int step = 0; step < arr.size(); step++) {
		cout << "arr[" << step << "] == " << arr[step] << endl;
	}
	cout << "Пример удаления: " << endl;
	remove(arr);
	for (int step = 0; step < arr.size(); step++) {
		cout << "arr[" << step << "] == " << arr[step] << endl;
	}
}