#include "lab12add1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

lab12add1::lab12add1() {
	setlocale(LC_ALL, "Russian");
	ifstream FileARead("fileA.txt", ios::out);
	vector<string> numbers;
	string input;
	getline(FileARead, input);
	FileARead.close();

	int temp = 0;//число отвечающее за номер строки с числом
	for (int positionInStringOfNumbers = 0; positionInStringOfNumbers < input.length(); positionInStringOfNumbers++) {
		numbers.push_back("");
		while (input[positionInStringOfNumbers] != ' ') {
			numbers[temp] += input[positionInStringOfNumbers];
			if (positionInStringOfNumbers + 1 < input.length()) {
				positionInStringOfNumbers++;
			}
			else {
				break;
			}
		}
		temp++;
	}

	set<int> numberz;
	for (string item : numbers) {
		numberz.insert(atoi(item.c_str()));
	}

	int n;
	cout << "number == ";
	cin >> n;
	auto it = numberz.end();
	if (numberz.find(n) != it) {
		cout << "Есть такое число в файле!" << endl;
	}
	else {
		cout << "Нету такого числа в файле!" << endl;
	}
}