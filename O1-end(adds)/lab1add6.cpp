#include "lab1add6.h"
//12_2
//������ � ���������� ������ ��������, ��������� �� ����, ����, �������, �����, ������ + � , � ����-���� �� � ����. ��������� �� ����� ������ � ��������� � ������� ���������� �������.

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

lab1add6::lab1add6() {
	using namespace std;
	setlocale(LC_CTYPE, "Russian");
	char a[256], buff[256];
	ofstream fout;

	fout.open("File_Part2.txt");

	if (!fout.is_open()) {
		cout << "Error" << endl;
	}
	else {
		cout << "������� �������: ";
		cin >> a;
		fout << a;

	}
	fout.close();


	ifstream fin;
	fin.open("File_Part2.txt");

	int count = 0;

	if (!fin.is_open()) {
		cout << "Error" << endl;
	}
	else {
		fin >> buff;
		for (int a = 0; a < strlen(buff); a++) {
			if (buff[a] == ',')
				count++;
		}
	}
	cout << "���-�� �������: " << count;
	fin.close();
}

