#include <iostream>
#include <vector>
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab8.h"
#include "Lab11.h"
#include "Lab13.h"
#include "Lab14.h"
#include "Lab16.h"

using namespace std;

bool _menu() {
	system("cls");

	int check;
	cout << "1: Лабораторная работа #3." << endl;
	cout << "2: Лабораторная работа #4, 7." << endl;
	cout << "3: Лабораторная работа #5." << endl;
	cout << "4: Лабораторная работа #6." << endl;
	cout << "5: Лабораторная работа #8, 9, 10." << endl;
	cout << "6: Лабораторная работа #11, 12." << endl;
	cout << "7: Лабораторная работа #13." << endl;
	cout << "8: Лабораторная работа #14, 15." << endl;
	cout << "9: Лабораторная работа #16, 17." << endl;
	cout << "0: Выход." << endl;
	cout << "Введите номер пункта: ";
	cin >> check;

	switch (check) {
	case 0:
		return false;
	case 1:
	{
		system("cls");
		Lab3 startLab3;
	}
	break;
	case 2:
	{
		system("cls");
		Lab4 startLab4;
	}
	break;
	case 3:
	{
		system("cls");
		Lab5 startLab5;
	}
	break;
	case 4:
	{
		system("cls");
		Lab6 startLab6;
	}
	break;
	case 5:
	{
		system("cls");
		Lab8 startLab8;
	}
	break;
	case 6:
	{
		system("cls");
		Lab11 startLab11;
	}
	break;
	case 7:
	{
		system("cls");
		Lab13 startLab13;
	}
	break;
	case 8:
	{
		system("cls");
		Lab14 startLab14;
	}
	break;
	case 9:
	{
		system("cls");
		Lab16 startLab16;
	}
	break;
	}

	return true;
}

bool quickSort(vector<int>& arr, int endSort, int startSort = 0) {
	if (endSort - 1 < arr.size() && endSort - 1 >= 0) {
		int element = arr[endSort - 1]; 
		int pointerOfLeftChapter = startSort;
	if (endSort - 1 <= startSort) { return false; }
	else {
		int pointerOfRightChapter = endSort - 1;
		while (pointerOfLeftChapter != pointerOfRightChapter) {
			if (pointerOfLeftChapter + 1 == endSort - 1 && element > arr[pointerOfLeftChapter]) {
				int temp = arr[endSort - 1];
				arr[endSort - 1] = arr[pointerOfLeftChapter];
				arr[pointerOfLeftChapter] = temp;
			}
			else {
				if (arr[--pointerOfRightChapter] < element) {
					while (pointerOfLeftChapter != pointerOfRightChapter) {
						if (arr[pointerOfLeftChapter] > element) {
							int temp = arr[pointerOfLeftChapter];
							arr[pointerOfLeftChapter] = arr[pointerOfRightChapter];
							arr[pointerOfRightChapter] = temp;
							pointerOfLeftChapter++;
							break;
						}
						else {
							pointerOfLeftChapter++;
						}
					}
				}
			}
		}
		if (pointerOfLeftChapter == pointerOfRightChapter && arr[pointerOfRightChapter + 1] > element) {
			int temp = arr[pointerOfRightChapter + 1];
			arr[pointerOfRightChapter + 1] = arr[endSort - 1];
			arr[endSort - 1] = temp;
		}
	}
	}
	else { return false; }//Опорный элемент
	quickSort(arr, endSort / 2, startSort);
	quickSort(arr, endSort, startSort + endSort / 2);
}

int main() {
	setlocale(LC_ALL, "Russian");

	vector<int> arr;
	srand(time(0));
	cout << "Before:\n";
	for (int step = 0; step < 4; step++) {
		arr.push_back(rand() % 10 - rand() % 10);
		cout << "arr[" << step << "] == " << arr[step] << endl;
	}
	cout << "\n\nAfter:\n";
	quickSort(arr, arr.size());
	for (int step = 0; step < arr.size(); step++) {
		cout << "arr[" << step << "] == " << arr[step] << endl;
	}
	return 0;

	while (_menu());

	return 0;
}