#include "lab1add2.h"
//15_2
//������ � ���������� ������ ��������, ��������� �� ����, ����������� ���������, � �������� �� � ����. ��������� �� ����� ������ � ������� ��� �����, ������� �������� ����� ���.
#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
lab1add2::lab1add2() {
	setlocale(LC_ALL, "RUS");
	FILE* F1;
	int i = 0;
	char str[255];
	errno_t err;
	err = fopen_s(&F1, "f1_second.txt", "w");
	fflush(stdin);
	printf("������� ������: \n");
	gets_s(str);
	fputs(str, F1);
	fputs("\n", F1);
	fclose(F1);
	err = fopen_s(&F1, "f1_second.txt", "r");
	char c = 'x';
	char S[255];
	fgets(S, 255, F1);
	istringstream ist(S);
	string tmp;
	while (ist >> tmp) {
		i = 0;
		while (tmp[i]) {
			if (tmp[i] == c) {
				cout << tmp << endl;
				break;
			}
			i++;
		}

	}
}