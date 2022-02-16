#include "Lab16.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int>& _choiseArr(vector<int>& arrA, vector<int>& arrB) {
	cout << "1: arrA" << endl;
	cout << "2: arrB" << endl;
	cout << "Выберите массив для работы: ";
	int number;
	cin >> number;
	if (number == 1) {
		return arrA;
	}
	else if (number == 2) {
		return arrB;
	}
	else {
		return _choiseArr(arrA, arrB);
	}
}

void _recreateArr16(vector<int>& arr) {
	srand(time(0));
	arr.clear();
	int number;
	cout << "Введите размер массива: ";
	cin >> number;
	for (int step = 0; step < number; step++) {
		arr.push_back(rand() % 100 - rand() % 100);
	}
}

void _showArr16(vector<int>& arr) {
	for (int step = 0; step < arr.size(); step++) {
		cout << "arr[" << step << "] == " << arr[step] << endl;
	}
}

int _menu16() {
	int choise;
	cout << "1: Пересоздание массива." << endl;
	cout << "2: Отобразить массив." << endl;
	cout << "3: Задание 16ой лабы." << endl;
	cout << "4: Сортировка пузырьком arrB." << endl;
	cout << "5: Сортировка Хоара arrB." << endl;
	cout << "6: Сортировка слиянием arrB." << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return choise;
}

void _taskOfLab16(vector<int>& arrA, vector<int>& arrB) {
	int indexOfMaxA, max = INT_MIN;
	for (int step = 0; step < arrA.size(); step++) {
		if (arrA[step] > max) {
			max = arrA[step];
			indexOfMaxA = step;
		}
	}
	for (int step = indexOfMaxA + 1; step < arrA.size(); step++) {
		if (!(step % 2)) {
			arrB.push_back(arrA[step]);
			arrA[step] = 2121;
		}
	}
	for (int step = 0; step < arrA.size(); step++) {
		if (arrA[step] == 2121)
			arrA.erase((arrA.begin() + step), (arrA.begin() + step + 1));
	}
}

void _sortByBubble(vector<int>& arr) {
	int temp;
	for (int step = 0; step < arr.size(); step++) {
		for (int stepNext = 0; stepNext < arr.size() - 1; stepNext++) {
			if (arr[stepNext] > arr[stepNext + 1]) {
				temp = arr[stepNext];
				arr[stepNext] = arr[stepNext + 1];
				arr[stepNext + 1] = temp;
			}
		}
	}
}

//Не мой код!
int getHoarBorder(vector<int>& arr, int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = arr[sm];
	int buf;
	while (i < j)
	{
		while (arr[--j] > brd);
		while (arr[++i] < brd);
		if (i < j)
		{
			buf = arr[j];
			arr[j] = arr[i];
			arr[i] = buf;
		};
	}
	return j;
}

//Не мой код!
vector<int>& sortHoar(vector<int>& arr, int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(arr, sm, em);
		sortHoar(arr, sm, hb);
		sortHoar(arr, hb + 1, em);
	}
	return arr;
};

//Не мой код!
int amount = 0;
template<typename Type>
static void merge(vector<Type>& buf, size_t left, size_t right, size_t middle) //слияние
{
	if (left >= right || middle < left || middle > right) return;
	if (right == left + 1 && buf[left] > buf[right]) {
		swap(buf[left], buf[right]);
		amount++;
		return;
	}

	vector<Type> tmp(&buf[left], &buf[right] + 1);

	for (size_t i = left, j = 0, k = middle - left + 1; i <= right; ++i) {
		if (j > middle - left) {
			buf[i] = tmp[k++];
		}
		else if (k > right - left) {
			buf[i] = tmp[j++];
		}
		else {
			buf[i] = (tmp[j] < tmp[k]) ? tmp[j++] : tmp[k++];
		}
	}
}

//Не мой код!
template<typename Type>
void MergeSort(vector<Type>& buf, size_t left, size_t right) //сортировка
{
	if (left >= right) return;

	size_t middle = left + (right - left) / 2;

	MergeSort(buf, left, middle);
	MergeSort(buf, middle + 1, right);
	merge(buf, left, right, middle);
}

Lab16::Lab16() {
	vector<int> arrA;
	vector<int> arrB;

	while (int choise = _menu16()) {
		switch (choise) {
		case 1:
			_recreateArr16(_choiseArr(arrA, arrB));
			break;
		case 2:
			_showArr16(_choiseArr(arrA, arrB));
			break;
		case 3:
			_taskOfLab16(arrA, arrB);
			break;
		case 4:
			_sortByBubble(arrB);
			break;
		case 5:
			sortHoar(arrB, 0, arrB.size() - 1);
			break;
		case 6:
			MergeSort(arrB, 0, arrB.size() - 1);
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}