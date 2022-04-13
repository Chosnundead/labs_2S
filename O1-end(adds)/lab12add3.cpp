#include <iostream>
#include "lab12add3.h"
#include <map>
#include <string>

using namespace std;

lab12add3::lab12add3() {
	setlocale(LC_ALL, "Russian");

	map<string, string> arr;

	arr["char"] = "is a data type";

	string input;

	cout << "¬ведите слово(char): ";
	getline(cin, input);
	cout << input << " " << arr[input] << endl;

	string key;
	cout << "¬ведите key: ";
	getline(cin, key);
	cout << "¬ведите value: ";
	getline(cin, input);
	arr[key] = input;

	for (auto item : arr) {
		cout << item.first << " " << item.second << endl;
	}
}