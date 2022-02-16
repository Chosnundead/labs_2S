#include "Lab14.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Studentz {
	string key;
	int amount;
};

void _search14(vector<Studentz>& arr) {
	string search;
	cin.ignore(256, '\n');
	cout << "key(string) or numberOfGroup(string): ";
	getline(cin, search);
	for (Studentz one : arr) {
		if (one.key == search) {
			cout << "arr[\"" << one.key << "\"] == " << one.amount << endl;
		}
	}
}

bool _isEqual14(Studentz one, Studentz two) {
	if (one.key == two.key && one.amount == two.amount) {
		return false;
	}
	return true;
}

bool _check14(vector<Studentz>& arr, Studentz one) {
	bool is—oncursus = true;
	for (Studentz two : arr) {
		if (is—oncursus)
			is—oncursus = _isEqual14(one, two);
		else
			break;
	}
	if (is—oncursus) {
		cout << " ÓÎÎËÁËˇ ÌÂ Ì‡·Î˛‰‡ÂÚÒˇ!" << endl;
		return true;
	}
	else {
		cout << "»ÏÂÎ‡ ÏÂÒÚÓ ÍÓÎÎËÁËˇ!" << endl;
		return false;
	}
}

void _add14(vector<Studentz>& arr) {
	Studentz add;
	add.key = "";
	add.amount = 0;
	cin.ignore(256, '\n');
	cout << "key(string) or numberOfGroup(string): ";
	getline(cin, add.key);
	cout << "amount(int): ";
	cin >> add.amount;
	if (_check14(arr, add))
		arr.push_back(add);
}

void _show14(vector<Studentz>& arr) {
	for (Studentz one : arr) {
		cout << "arr[\"" << one.key << "\"] == " << one.amount << endl;
	}
}

int _menu14() {
	int choise;
	cout << "1: ƒÓ·‡‚ËÚ¸ ‚ Ú‡·ÎËˆÛ." << endl;
	cout << "2: ¬˚‚Ó‰ Ú‡·ÎËˆ˚." << endl;
	cout << "3: œÓËÒÍ ÔÓ ıÂ¯-ÍÎ˛˜Û." << endl;
	cout << "0: ¬˚ıÓ‰" << endl;
	cout << "¬‡¯ ‚˚·Ó: ";
	cin >> choise;
	return choise;
}

Lab14::Lab14() {
	vector<Studentz> arr;

	while (int choise = _menu14()) {
		switch (choise) {
		case 1:
			_add14(arr);
			break;
		case 2:
			_show14(arr);
			break;
		case 3:
			_search14(arr);
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}