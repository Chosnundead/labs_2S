#include "lab6add1.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct student {
	string fName;
	string sName;
	string tName;
	int year;
	int course;
	int numberOfGroup;
	int numbers[5];
	float number;
};

vector<student> students;

void _add(string fName, string sName, string tName, int year, int course, int numberOfGroup, int numbers1, int numbers2, int numbers3, int numbers4, int numbers5) {
	student newStudent;
	newStudent.fName = fName;
	newStudent.sName = sName;
	newStudent.tName = tName;
	newStudent.year = year;
	newStudent.course = course;
	newStudent.numberOfGroup = numberOfGroup;
	newStudent.numbers[0] = numbers1;
	newStudent.numbers[1] = numbers2;
	newStudent.numbers[2] = numbers3;
	newStudent.numbers[3] = numbers4;
	newStudent.numbers[4] = numbers5;
	newStudent.number = (numbers1 + numbers2 + numbers3 + numbers4 + numbers5) / 5;
	students.push_back(newStudent);
}

void _show() {
	int indexOfNewest = 0, indexOfOldest = 0;
	//sort
	for (int step = 0; step < students.size(); step++) {
		for (int anotherStep = students.size() - 1; anotherStep - 1 >= 0; anotherStep--) {
			if ((students[anotherStep].course * 1000 + students[anotherStep].fName[0]) < (students[anotherStep - 1].course * 1000 + students[anotherStep - 1].fName[0])) {
				student temp = students[anotherStep];
				students[anotherStep] = students[anotherStep - 1];
				students[anotherStep - 1] = temp;
			}
		}
	}
	set<int> groups;
	for (int step = 0; step < students.size(); step++) {
		if (students[step].year > students[indexOfNewest].year) {
			indexOfNewest = step;
		}
		if (students[step].year < students[indexOfOldest].year) {
			indexOfOldest = step;
		}
		if (groups.end() == groups.find(students[step].course * 10 + students[step].numberOfGroup)) {
			int idexOfBest = step;
			float medi = 0;
			int counter = 0;
			for (int anotherStep = 0; anotherStep < students.size(); anotherStep++) {
				if (students[anotherStep].course * 10 + students[anotherStep].numberOfGroup == students[step].course * 10 + students[step].numberOfGroup) {
					medi += students[anotherStep].number;
					counter++;
					if (students[idexOfBest].number < students[anotherStep].number) {
						idexOfBest = anotherStep;
					}
				}
			}
			medi /= counter;
			cout << students[step].course << "/" << students[step].numberOfGroup << ": " << medi << "; Лучший студент группы - " << students[idexOfBest].fName << endl;
			groups.insert(students[step].course * 10 + students[step].numberOfGroup);
		}
	}
	cout << "======666======" << endl;
	for (int step = 0; step < students.size(); step++) {
		cout << students[step].course << "/" << students[step].numberOfGroup << ": " << students[step].fName << " " << students[step].sName << " " << students[step].tName << endl;
		if (step == indexOfNewest) {
			cout << "Самый молодой год выпуска:) " << students[step].year << "Оценка: " << students[step].number << endl;
		}
		else if (step == indexOfOldest) {
			cout << "Самый старый год выпуска:) " << students[step].year << "Оценка: " << students[step].number << endl;
		}
		else {
			cout << "Год выпуска: " << students[step].year << "; Оценка: " << students[step].number << endl;
		}
	}
}

lab6add1::lab6add1() {
	setlocale(LC_ALL, "Russian");
	_add("Denis", "Solodkiy", "Viktorovich", 2001, 1, 8, 2, 4, 4, 5, 4);
	_add("No", "Name", "", 1999, 3, 2, 5, 5, 5, 5, 5);
	_add("Vadim", "Vadimov", "Vadimovich", 2002, 1, 8, 4, 9, 2, 6, 3);
	_add("Egor", "Denisovich", "Dmitrievich", 2001, 3, 9, 2, 6, 6, 4, 1);
	_add("Sasha", "Kupalov", "Maximov", 2000, 2, 2, 4, 4, 3, 3, 4);
	_add("Eleonora", "Moringova", "Jacksonova", 2002, 1, 8, 8, 8, 6, 8, 7);
	_add("Ivan", "Vasil'evich", "Ivanovich", 1984, 4, 5, 9, 9, 9, 9, 7);
	_show();
}