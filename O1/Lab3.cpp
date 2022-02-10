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