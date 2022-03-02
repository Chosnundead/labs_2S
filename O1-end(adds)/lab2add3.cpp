#include "lab2add3.h"

#include <iostream>
#include <string>
#include <clocale>
#include <fstream>
using namespace std;
int l2StrToInt(string b)
{
	int l, M;
	l = b.length();
	M = 0;
	for (int i = 0; i < l; i++)
	{
		M += (b[i] - '0') * pow(10, l - i - 1);
	}
	return M;
}
struct person
{
	string name;
	string number;
	string time;

};
int COUNT = 0;
int SIZE = 100;
person* people = new person[SIZE];
void l2addPerson() {
	string name;
	string number;
	string time;

	cout << "������� �������� ������ ����������" << endl;
	cin >> name;
	cout << "������� ����� ������" << endl;
	cin >> number;
	cout << "������� ����� �����������" << endl;
	cin >> time;

	people[COUNT].name = name;
	people[COUNT].number = number;
	people[COUNT].time = time;


	person a;
	COUNT++;
	for (int i = 0; i < COUNT - 1; i++) {
		if (people[i].name[0] > people[i + 1].name[0]) {
			a = people[i];
			people[i] = people[i + 1];
			people[i + 1] = a;
		}
	}


}
void l2showPerson() {
	int id = 0;
	cout << "������� ���� ������" << endl;
	cin >> id;
	cout << "�����: " << people[id].name << endl;
	cout << "����� ������: " << people[id].number << endl;
	cout << "����� �����������: " << people[id].time << endl;


}
void l2deletePerson() {
	int id = 0;
	person* newPerson = new person[SIZE--];
	cout << "������� ���� ������ �������� ������ �������" << endl;
	cin >> id;
	for (int i = 0; i < id; i++) {
		newPerson[i] = people[i];

	}
	for (int i = id + 1; i < SIZE; i++) {
		newPerson[i - 1] = people[i];
	}
	people = newPerson;


}
void l2readInfo() {
	int id = 0;
	int choice = 0;
	cout << "������� ���� ������:" << endl;
	cin >> id;
	cout << "1.��� ������" << endl;
	cout << "2.����� ������" << endl;
	cout << "3.����� ����������� ������" << endl;
	cin >> choice;
	if (choice == 1) {
		cout << people[id].name << endl;
	}
	else if (choice == 2) {
		cout << people[id].number << endl;
	}
	else if (choice == 3) {
		cout << people[id].time << endl;
	}
}
void l2writingFile() {
	int id = 0;
	cout << "������� ���� ������" << endl;
	cin >> id;
	string fields[3] = { people[id].name,people[id].number,people[id].time };
	ofstream file;
	file.open("information.txt", ofstream::app);
	for (int i = 0; i < 3; i++) {
		file << fields[i] << " ";
	}
	file << "\n";

}
void l2readingFile() {
	int id = 0;
	cout << "������� ���� ������" << endl;
	cin >> id;
	ifstream file;
	string information;
	int numString = 0;
	file.open("information.txt");
	while (!file.eof()) {
		getline(file, information);
		if (numString == id) {
			cout << information << endl;
			break;
		}
		numString++;
	}
	file.close();
}
void l2time() {
	cout << "������� �����" << endl;
	int t;
	cin >> t;
	for (int i = 0; i < SIZE; i++) {
		if (l2StrToInt(people[i].time) > t) {
			cout << "����� ��� �������: " << people[i].number << endl;
		}
	}
}
void l2menu() {
	int choice;
	cout << "1.������� �������" << endl;
	cout << "2.����� ������ � �������" << endl;
	cout << "3.�������� �������" << endl;
	cout << "4.������ ���������� � �������" << endl;
	cout << "5.������ ���������� � ������� � ����" << endl;
	cout << "6.������� ������ � ������� � �����" << endl;
	cout << "7.�������� ������� ����� ��������� �������" << endl;
	cin >> choice;
	if (choice == 1) {
		l2addPerson();
		l2menu();
	}
	else if (choice == 2) {
		l2showPerson();
		l2menu();
	}
	else if (choice == 3) {
		l2deletePerson();
		l2menu();
	}
	else if (choice == 4) {
		l2readInfo();
		l2menu();
	}
	else if (choice == 5) {
		l2writingFile();
		l2menu();
	}
	else if (choice == 6) {
		l2readingFile();
		l2menu();

	}
	else if (choice == 7) {
		l2time();
		l2menu();
	}
}
lab2add3::lab2add3() {
	setlocale(LC_ALL, "Russian");
	l2menu();
}