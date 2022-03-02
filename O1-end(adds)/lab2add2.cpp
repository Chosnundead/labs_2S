//#include "lab2add2.h"
//#include <iostream>
//#include <string>
//#include <clocale>
//#include <fstream>
//using namespace std;
//int StrToInt(string b)
//{
//	int l, M;
//	l = b.length();
//	M = 0;
//	for (int i = 0; i < l; i++)
//	{
//		M += (b[i] - '0') * pow(10, l - i - 1);
//	}
//	return M;
//}
//
//struct person
//{
//	string name;
//	string surname;
//	string patronymic;
//	string numExams;
//	string evaluations;
//
//};
//float fiveOrFour = 0;
//float other = 0;
//int COUNT = 0;
//int SIZE = 100;
//person* people = new person[SIZE];
//void l3addPerson() {
//	string name;
//	string surname;
//	string patronymic;
//	string numExams;
//	string evaluations;
//
//
//	cout << "Введите имя" << endl;
//	cin >> name;
//	cout << "Введите фамилию" << endl;
//	cin >> surname;
//	cout << "Введите отчество" << endl;
//	cin >> patronymic;
//	cout << "Введите количество экзаменов" << endl;
//	cin >> numExams;
//	cout << "Введите оценки(без пробела,пример:4567)" << endl;
//	cin >> evaluations;
//	people[COUNT].name = name;
//	people[COUNT].surname = surname;
//	people[COUNT].patronymic = patronymic;
//	people[COUNT].numExams = numExams;
//	people[COUNT].evaluations = evaluations;
//	other++; +
//		COUNT++;
//	cout << "COUNT: " << COUNT << endl;
//	cout << "FiveOrFour" << fiveOrFour << endl;
//
//
//}
//void l3showPerson() {
//	int id = 0;
//	cout << "Введите айди студента" << endl;
//	cin >> id;
//	cout << "name: " << people[id].name << endl;
//	cout << "surname: " << people[id].surname << endl;
//	cout << "patronymic: " << people[id].patronymic << endl;
//	cout << "numExams: " << people[id].numExams << endl;
//	cout << "evoluations: " << people[id].evaluations << endl;
//
//
//}
//void l3deletePerson() {
//	int id = 0;
//	person* newPerson = new person[SIZE--];
//	cout << "Введите айди студента которого хотите удалить" << endl;
//	cin >> id;
//	for (int i = 0; i < id; i++) {
//		newPerson[i] = people[i];
//
//	}
//	for (int i = id + 1; i < SIZE; i++) {
//		newPerson[i - 1] = people[i];
//	}
//	people = newPerson;
//
//
//}
//void l3readInfo() {
//	int id = 0;
//	int choice = 0;
//	cout << "Введите айди студента:" << endl;
//	cin >> id;
//	cout << "1.Имя" << endl;
//	cout << "2.Фамилия" << endl;
//	cout << "3.Отчество" << endl;
//	cout << "4.Число экзаменов" << endl;
//	cout << "5.Полученные оценки" << endl;
//	cin >> choice;
//	if (choice == 1) {
//		cout << people[id].name << endl;
//	}
//	else if (choice == 2) {
//		cout << people[id].surname << endl;
//	}
//	else if (choice == 3) {
//		cout << people[id].patronymic << endl;
//	}
//	else if (choice == 4) {
//		cout << people[id].numExams << endl;
//	}
//	else if (choice == 5) {
//		cout << people[id].evaluations << endl;
//	}
//
//}
//void l3writingFile() {
//	int id = 0;
//	cout << "Введите айди студента" << endl;
//	cin >> id;
//	string fields[4] = { people[id].name,people[id].surname,people[id].patronymic,people[id].numExams };
//	ofstream file;
//	file.open("information.txt", ofstream::app);
//	for (int i = 0; i < 4; i++) {
//		file << fields[i] << " ";
//	}
//	file << "\n";
//
//}
//void l3readingFile() {
//	int id = 0;
//	cout << "Введите айди студента" << endl;
//	cin >> id;
//	ifstream file;
//	string information;
//	int numString = 0;
//	file.open("information.txt");
//	while (!file.eof()) {
//		getline(file, information);
//		if (numString == id) {
//			cout << information << endl;
//			break;
//		}
//		numString++;
//	}
//	file.close();
//}
//void l3checkevaluations() {
//	int id = 0;
//	int count = 0;
//	cout << "Введите id студента" << endl;
//	cin >> id;
//	int size = StrToInt(people[id].numExams);
//	for (int i = 0; i < size; i++) {
//		if (people[id].evaluations[i] == '4' || people[id].evaluations[i] == '5') {
//			count++;
//		}
//	}
//	if (count == size) {
//		cout << "Студент сдал все экзамены на 4 или 5" << endl;
//		fiveOrFour++;
//	}
//	else {
//		cout << "Студент сдал все экзамены не на 4 или 5" << endl;
//		other++;
//	}
//}
//void l3statistic() {
//	float stat;
//	stat = (fiveOrFour / other) * 100;
//	cout << stat << endl;
//}
//void l3menu() {
//	int choice;
//	cout << "1.Ввод информации о студенте" << endl;
//	cout << "2.Вывод информации о студенте" << endl;
//	cout << "3.Удаление информации о студенте" << endl;
//	cout << "4.Чтение информации о студенте" << endl;
//	cout << "5.Запись информации о студенте в файл" << endl;
//	cout << "6.Считать данные о студенте с файла" << endl;
//	cout << "7.Проверка оценок" << endl;
//	cout << "8.Общая статистика" << endl;
//	cin >> choice;
//	if (choice == 1) {
//		l3addPerson();
//		l3menu();
//	}
//	else if (choice == 2) {
//		l3showPerson();
//		l3menu();
//	}
//	else if (choice == 3) {
//		l3deletePerson();
//		l3menu();
//	}
//	else if (choice == 4) {
//		l3readInfo();
//		l3menu();
//	}
//	else if (choice == 5) {
//		l3writingFile();
//		l3menu();
//	}
//	else if (choice == 6) {
//		l3readingFile();
//		l3menu();
//
//	}
//	else if (choice == 7) {
//		l3checkevaluations();
//		l3menu();
//	}
//	else if (choice == 8) {
//		l3statistic();
//		l3menu();
//	}
//}
//lab2add2::lab2add2() {
//	setlocale(LC_ALL, "Russian");
//	l3menu();
//}