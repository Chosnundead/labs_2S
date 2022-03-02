//#include "lab2add1.h"
//#include <iostream>
//#include <string>
//using namespace std;
//struct person
//{
//	string name;
//	string adress;
//	string profile;
//	string birtday;
//	int counts;
//
//};
//int COUNT = 0;
//int COUNT1 = 0;
//int heartCOUNT = 0;
//int faceCOUNT = 0;
//int SIZE = 100;
//int SIZE1 = 20;
//
//person* people = new person[SIZE];
//string* profiles = new string[SIZE1];
//
//void l1addPerson() {
//	string name;
//	string adress;
//	string profile;
//	string birtday;
//	int counts;
//
//
//	cout << "Введите название" << endl;
//	cin >> name;
//	cout << "Введите место расположения" << endl;
//	cin >> adress;
//	cout << "Введите личебный профиль" << endl;
//	cin >> profile;
//	cout << "Введите количество путевок" << endl;
//	cin >> counts;
//
//	people[COUNT].name = name;
//	people[COUNT].adress = adress;
//	people[COUNT].profile = profile;
//	people[COUNT].counts = counts;
//
//	COUNT++;
//
//}
//void l1showPerson() {
//	string name;
//	cout << "Введите название санатория" << endl;
//	cin >> name;
//	for (int i = 0; i < COUNT; i++) {
//		if (name == people[i].name) {
//			cout << "Название санатория: " << people[i].name << endl;
//			cout << "Место расположение санатория: " << people[i].adress << endl;
//			cout << "Лечебный профиль санатория: " << people[i].profile << endl;
//			cout << "Количесвто путевок в санаторий: " << people[i].counts << endl;
//			break;
//		}
//	}
//
//
//}
//void l1group() {
//
//	/*for (int i = 0; i < COUNT; i++) {
//	profiles[i] = people[i].profile;
//
//	}
//	for (int i = 0; i < COUNT; i++) {
//	cout << profiles[i] << ": " << endl;
//	for (int k = 0; k < COUNT; k++) {
//	if (profiles[k] == people[i].profile) {
//	cout << people[i].name << endl;
//	}
//	}
//	}*/
//	cout << "HEART: " << endl;
//	for (int i = 0; i < COUNT; i++) {
//		if (people[i].profile == "heart") {
//			cout << people[i].name << endl;
//		}
//	}
//	cout << "NOSE: " << endl;
//	for (int i = 0; i < COUNT; i++) {
//		if (people[i].profile == "nose") {
//			cout << people[i].name << endl;
//		}
//	}
//	cout << "LIPS: " << endl;
//	for (int i = 0; i < COUNT; i++) {
//		if (people[i].profile == "lips") {
//			cout << people[i].name << endl;
//		}
//	}
//}
//void l1deletePerson() {
//	string name;
//	int id = 0;
//	person* newPerson = new person[SIZE--];
//	cout << "Введите имя санатория который хотите удалить" << endl;
//	cin >> name;
//	for (int i = 0; i < COUNT; i++) {
//		if (name == people[i].name) {
//			break;
//		}
//		id++;
//	}
//	for (int i = 0; i < id; i++) {
//		newPerson[i] = people[i];
//
//	}
//	for (int i = id + 1; i < SIZE; i++) {
//		newPerson[i - 1] = people[i];
//	}
//	people = newPerson;
//	//cout << SIZE;
//
//}
//
//void l1menu() {
//	int choice;
//	cout << "1.Добавить санаторий" << endl;
//	cout << "2.Вывод данных о санатории" << endl;
//	cout << "3.Удаление санатория" << endl;
//	cout << "4.Группировка санаторие по лечебным профилям" << endl;
//	cin >> choice;
//	if (choice == 1) {
//		l1addPerson();
//		l1menu();
//	}
//	else if (choice == 2) {
//		l1showPerson();
//		l1menu();
//	}
//	else if (choice == 3) {
//		l1deletePerson();
//		l1menu();
//	}
//	else if (choice == 4) {
//		l1group();
//		l1menu();
//	}
//
//}
//
//lab2add1::lab2add1() {
//	setlocale(LC_ALL, "ru");
//	l1menu();
//}