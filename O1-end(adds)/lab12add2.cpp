#include "lab12add2.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

lab12add2::lab12add2() {
	setlocale(LC_ALL, "Russian");
	map<char, int>chars;

	string line;
	cout << "Предложение: ";
	getline(cin, line);
	int temp = 0;
	for (int step = 0; step < line.length(); step++) {
		if ((line[step] >= 'A' && line[step] <= 'Z') || (line[step] >= 'a' && line[step] <= 'z')) {
			for (int anotherStep = step + 1; anotherStep < line.length(); anotherStep++) {
				if (line[step] == line[anotherStep]) {
					line[anotherStep] = ' ';
					temp++;
				}
			}
			chars.insert(pair<char, int>(line[step], temp));
		}
		temp = 0;
	}

	for (auto item : chars) {
		cout << "arr[\'" << item.first << "\'] == " << item.second + 1 << endl;
	}

	char c;
	cout << "c == ";
	cin >> c;

	cout << c << " == " << chars[c] + 1 << endl;
}