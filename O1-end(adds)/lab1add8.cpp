#include "lab1add8.h"

//2_1
//����������� � ���� FILE2 ������ �� ������ �� FILE1,  ������� ���������� � ����� ���. ���������� ���������� ���� � FILE2.
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

lab1add8::lab1add8() {
	setlocale(LC_CTYPE, "rus");
	fstream FILE1, FILE2;
	FILE1.open("FILE1.txt", fstream::in);//��������� �����
	FILE2.open("FILE2.txt", fstream::out);

	if (FILE1.is_open())//����������� ������ ��� �������� ������
		cout << "���� FILE1.txt ������� ������" << endl;
	else
	{
		cout << "������ �������� ����� FILE1.txt" << endl;
	}

	if (FILE2.is_open())
		cout << "���� FILE2.txt ������� ������" << endl;
	else
	{
		cout << "������ �������� ����� FILE2.txt" << endl;
	}


	string str;
	int counter = 0;
	while (!FILE1.eof()) {
		str = "";
		getline(FILE1, str);//������ ������ �� ����� � ���������� str
		if (str[0] == 'A')
		{
			FILE2 << str << '\n';
			for (int i = 0; i < str.size(); i++) {//������� ����
				if (str[i] == ' ' || str[i] == '\n')
					counter++;

			}
			counter++;//���������� ����� ��� �������� ������
		}
	}

	cout << "FILE2.txt �������� " << counter + 1 << " ����." << endl;

	FILE1.close();//�������� ������
	FILE2.close();

}

