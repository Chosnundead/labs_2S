#include "Lab3.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int _numberOfCharInString(string str, char ch) {
	int counter = 0;

	for (int step = 0; step < str.length(); step++) {
		if (str[step] == ch)
			counter++;
	}

	return counter;
}

Lab3::Lab3() {
	ifstream file1In("file1.txt", ios::out);

	vector<string> lines;
	string buffer;
	while (!(file1In.eof())) {
		getline(file1In, buffer);
		lines.push_back(buffer);
	}

	file1In.close();
	ofstream file2Out("file2.txt", ios::in | ios::trunc);

	for (int step = 0; step < lines.size(); step++) {
		if (lines[step].find(" ") != -1) {
			file2Out << lines[step] << endl;
		}
	}

	file2Out.close();

	vector<string> words;
	int pos = 0;
	string temp;
	for (int i = 0; i < lines.size(); i++) {
		while (!(lines[i].empty())) {
			pos = lines[i].find(32, pos);
			if (pos == -1) {
				for (int j = 0; j < lines[i].size(); j++) {
					temp.push_back(lines[i][j]);
				}
				words.push_back(temp);
				temp.clear();
				lines[i].erase(0, lines[i].size());
				pos = 0;
			}
			else {
				for (int j = 0; j < pos; j++) {
					temp.push_back(lines[i][j]);
				}
				words.push_back(temp);
				temp.clear();
				lines[i].erase(0, pos + 1);
				pos = 0;
			}
		}
	}
	vector<int> wordsNumber;
	int test = 0;
	for (string x : words) {
		test = 0;
		for (char f : x) {
			if (f == 'a' || f == 'e' || f == 'y' || f == 'u' || f == 'i' || f == 'o')
				test++;
		}
		wordsNumber.push_back(test);
		cout << x << endl;
	}
	int max = INT_MIN;
	for (int i = 0; i < wordsNumber.size(); i++) {
		if (wordsNumber[i] > max)
			max = wordsNumber[i];
	}
	for (int step = 0; step < wordsNumber.size(); step++) {
		if (wordsNumber[step] == max)
			cout << step << "; ";
	}
	cout << endl;
	buffer = "";
	cout << "¬ведите строку: ";
	cin.ignore(256, '\n');
	getline(cin, buffer);

	ofstream file3Out("file3.txt", ios::in | ios::trunc);
	file3Out << buffer;
	file3Out.close();

	cout << "(: " << _numberOfCharInString(buffer, '(') << endl;
	cout << "): " << _numberOfCharInString(buffer, ')') << endl;
	getchar();
}