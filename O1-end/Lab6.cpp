#include "Lab6.h"
#include <iostream>
#include <list>

using namespace std;

Lab6::Lab6() {
	list<int> numbers = { -11, 22, 33, -44, 55 };
	int result = 0, counter = 0;
	for (int i : numbers) {
		cout << "numbers[" << counter << "] == " << i << endl;
		if (i > -100 && i < -9) {
			result += i;
		}
		counter++;
	}
	if (result == 0) {
		cout << "Таких элементов нету!" << endl;
	}
	else {
		cout << "result == " << result << endl;
	}
	do {
		cout << "Введите 0 для выхода: ";
		cin >> result;
	} while (result);
}