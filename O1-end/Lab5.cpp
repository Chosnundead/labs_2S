#include "Lab5.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum faculties {
	FIT, TOV, HTIT
};

struct student {
	string name;
	unsigned day : 5;
	string spec;
	unsigned group : 3;
	faculties facult;
	double mark;
};

struct country {
	string name;
	string capital;
	double population;
	double area;
	string surname;
};

void _deleteTrain(vector<student>& arr) {
	int number;
	cout << "Введите индекс поезда: ";
	cin >> number;
	arr.erase((arr.begin() + number), (arr.begin() + number + 1));
}

void _deleteTrain(vector<country>& arr, bool f) {
	int number;
	cout << "Введите индекс поезда: ";
	cin >> number;
	arr.erase((arr.begin() + number), (arr.begin() + number + 1));
}

int _menu2() {

	int choise;
	cout << "1: Ввод элементов структуры с клавиатуры" << endl;
	cout << "2: Вывод элементов структуры в консольное окно" << endl;
	cout << "3: Удаление заданной структурированной переменной" << endl;
	cout << "4: Поиск информации" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return choise;
}

void _showTrainStation(vector<student>& arr) {
	for (int step = 0; step < arr.size(); step++) {
		cout << "train[" << step << "] == " << endl;
		cout << "day(string): " << arr[step].day << endl;
		cout << "facul(string): " << arr[step].facult << endl;
		cout << "group(string): " << arr[step].group << endl;
		cout << "mark(string): " << arr[step].mark << endl;
		cout << "name(string): " << arr[step].name << endl;
		cout << "spec(string): " << arr[step].spec << endl;
		cout << "\t\t======666======\n\n";
	}
}

void _showTrainStation(vector<country>& arr, bool f) {
	for (int step = 0; step < arr.size(); step++) {
		cout << "train[" << step << "] == " << endl;
		cout << "area(string): " << arr[step].area << endl;
		cout << "capital(string): " << arr[step].capital << endl;
		cout << "name(string): " << arr[step].name << endl;
		cout << "population(string): " << arr[step].population << endl;
		cout << "surname(string): " << arr[step].surname << endl;
		cout << "\t\t======666======\n\n";
	}
}

void _outputInfo(vector<student>& arr) {
	string search;
	cin.ignore(256, '\n');
	cout << "Введите name(string) для поиска: ";
	getline(cin, search);
	for (int step = 0; step < arr.size(); step++) {
		if (search == arr[step].name) {
			cout << "train[" << step << "];" << endl;
		}
	}
}

void _outputInfo(vector<country>& arr, bool f) {
	string search;
	cin.ignore(256, '\n');
	cout << "Введите name(string) для поиска: ";
	getline(cin, search);
	for (int step = 0; step < arr.size(); step++) {
		if (search == arr[step].name) {
			cout << "train[" << step << "];" << endl;
		}
	}
}

int _menu1() {

	int choise;
	cout << "1: Студенты" << endl;
	cout << "2: Государства" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return (int)choise;
}

void _createTrain(vector<student>& arr) {
	student train;
	int i;

	cin.ignore(256, '\n');
	cout << "name(string): ";
	getline(cin, train.name);
	cout << "spec(string): ";
	getline(cin, train.spec);
	cout << "day(int): ";
	cin >> i;
	train.day = i;
	cout << "group(int): ";
	cin >> i;
	train.group = i;
	cout << "facult(int): ";
	cin >> i;
	train.facult = static_cast<faculties>(i);
	cout << "mark(int): ";
	cin >> train.mark;

	arr.push_back(train);
}

void _createTrain(vector<country>& arr, bool f) {
	country train;


	cin.ignore(256, '\n');
	cout << "name(string): ";
	getline(cin, train.name);
	cout << "capit(string): ";
	getline(cin, train.capital);
	cout << "surname(string): ";
	getline(cin, train.surname);
	cout << "popul(int): ";
	cin >> train.population;
	cout << "area(int): ";
	cin >> train.area;

	arr.push_back(train);
}

Lab5::Lab5() {
	cout << "Лабы #4 и #5 очень похожи -> мне не интересно. Всё реализованно максимально сжато и сухо." << endl;

	vector<student> arr1;
	vector<country> arr2;

	while (int choise = _menu1()) {
		switch (choise) {
		case 1:
			switch (_menu2())
			{
			case 1:
				_createTrain(arr1);
				break;
			case 2:
				_showTrainStation(arr1);
				break;
			case 3:
				_deleteTrain(arr1);
				break;
			case 4:
				_outputInfo(arr1);
				break;
			default:
				break;
			}
			break;
		case 2:
			switch (_menu2())
			{
			case 1:
				_createTrain(arr2, true);
				break;
			case 2:
				_showTrainStation(arr2, true);
				break;
			case 3:
				_deleteTrain(arr2, true);
				break;
			case 4:
				_outputInfo(arr2, true);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}