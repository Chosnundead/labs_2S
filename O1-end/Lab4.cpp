#include "Lab4.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Train {
	string number;
	string to;
	string days;
	string timeIn;
	string timeOut;
};

void _add(vector<Train>& arr, Train train) {
	arr.push_back(train);
}

Train _createTrain() {
	Train train;

	cin.ignore(256, '\n');
	cout << "number(string): ";
	getline(cin, train.number);
	cout << "to(string): ";
	getline(cin, train.to);
	cout << "days(string): ";
	getline(cin, train.days);
	cout << "timeIn(string): ";
	getline(cin, train.timeIn);
	cout << "timeOut(string): ";
	getline(cin, train.timeOut);

	return train;
}

void _showTrainStation(vector<Train>& arr) {
	for (int step = 0; step < arr.size(); step++) {
		cout << "train[" << step << "] == " << endl;
		cout << "number(string): " << arr[step].number << endl;
		cout << "to(string): " << arr[step].to << endl;
		cout << "days(string): " << arr[step].days << endl;
		cout << "timeIn(string): " << arr[step].timeIn << endl;
		cout << "timeOut(string): " << arr[step].timeOut << endl;
		cout << "\t\t======666======\n\n";
	}
}

int _menu() {

	int choise;
	cout << "1: Ввод элементов структуры с клавиатуры" << endl;
	cout << "2: Вывод элементов структуры в консольное окно" << endl;
	cout << "3: Удаление заданной структурированной переменной" << endl;
	cout << "4: Поиск информации" << endl;
	cout << "5: Запись информации в файл" << endl;
	cout << "6: Чтение данных из файла" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return (int)choise;
}

void _deleteTrain(vector<Train>& arr, int number) {
	arr.erase((arr.begin() + number), (arr.begin() + number + 1));
}

int _choise() {
	int number;
	cout << "Введите индекс поезда: ";
	cin >> number;
	return number;
}

void _outputInfo(vector<Train>& arr) {
	string search;
	cin.ignore(256, '\n');
	cout << "Введите number(string) для поиска: ";
	getline(cin, search);
	for (int step = 0; step < arr.size(); step++) {
		if (search == arr[step].number) {
			cout << "train[" << step << "];" << endl;
		}
	}
}

void _saveToFile(vector<Train>& arr, int number) {
	ofstream file("file.txt", ios::in | ios::trunc);
	file << arr[number].number << endl << arr[number].to << endl << arr[number].days << endl << arr[number].timeIn << endl << arr[number].timeOut;
	file.close();
}

void _addFromFile(vector<Train>& arr) {
	Train train;
	ifstream file("file.txt", ios::out);
	string buffer;
	int counter = 0;
	while (!(file.eof())) {
		getline(file, buffer);
		switch (counter) {
		case 0:
			train.number = buffer;
			break;
		case 1:
			train.to = buffer;
			break;
		case 2:
			train.days = buffer;
			break;
		case 3:
			train.timeIn = buffer;
			break;
		case 4:
			train.timeOut = buffer;
			break;
		}
	}
	file.close();
	_add(arr, train);
}

Lab4::Lab4() {
	vector<Train> trainStantion;

	while (int choise = _menu()) {
		switch (choise) {
		case 1:
			_add(trainStantion, _createTrain());
			break;
		case 2:
			_showTrainStation(trainStantion);
			break;
		case 3:
			_deleteTrain(trainStantion, _choise());
			break;
		case 4:
			_outputInfo(trainStantion);
			break;
		case 5:
			_saveToFile(trainStantion, _choise());
			break;
		case 6:
			_addFromFile(trainStantion);
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}