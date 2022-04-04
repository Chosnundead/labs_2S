#include "lab5add2.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

lab5add2::lab5add2() {
	ifstream FileF("f.txt", ios::out);
	ofstream FileG("g.txt", ios::in | ios::trunc);
	string inputString;
	vector<string> arr, arrOfNumber, arrOfChar;

	while (!FileF.eof()) {
		getline(FileF, inputString);
		arr.push_back(inputString);
	}

	/*for (int step = 0; step < arr.size(); step++) {
		cout << arr[step] << endl;
	}*/

	for (int step = 0; step < arr.size(); step++) {
		arrOfNumber.push_back("");
		for (int stepOfNumber = 0; stepOfNumber < arr[step].length(); stepOfNumber++) {
			if (arr[step][stepOfNumber] >= 48 && arr[step][stepOfNumber] <= 57) {
				arrOfNumber[step] += arr[step][stepOfNumber];
			}
		}
		arrOfChar.push_back("");
		for (int stepOfChar = 0; stepOfChar < arr[step].length(); stepOfChar++) {
			if (!(arr[step][stepOfChar] >= 48 && arr[step][stepOfChar] <= 57)) {
				arrOfChar[step] += arr[step][stepOfChar];
			}
		}
		FileG << arrOfChar[step] << arrOfNumber[step] << endl;
	}

	FileF.close();
	FileG.close();
}