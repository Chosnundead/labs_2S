#include "lab11add1.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

lab11add1::lab11add1() {
	setlocale(LC_ALL, "Russian");
	map<string, int> arr;

	string input = "";
	int number = 0;
	do {
		cout << "key: ";
		getline(cin, input);
		if (input == "")
			break;
		cout << "number: ";
		cin >> number;
		cin.ignore(256, '\n');
		arr.insert(pair<string, int>(input, number));
	} while (true);

	for (auto& item : arr) {
		cout << "arr[" << item.first << "] == " << item.second << endl;
	}

	do {
		cout << "dynamic add:\n key: ";
		getline(cin, input);
		if (input == "")
			break;
		cout << "number: ";
		cin >> number;
		cin.ignore(256, '\n');
		arr.insert(pair<string, int>(input, number));
	} while (true);

	for (auto& item : arr) {
		cout << "arr[" << item.first << "] == " << item.second << endl;
	}
}