#include "lab13add1.h"
#include <vector>
#include <iostream>

using namespace std;

lab13add1::lab13add1() {
	setlocale(LC_ALL, "Russian");
	vector<int> arr, result;
	srand(time(0));

	int n;
	cout << "Размер: ";
	cin >> n;
	for (int step = 0; step < n; step++) {
		arr.push_back(rand() % 10 - rand() % 10);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < n; step++) {
		cout << "arrA[" << step << "] == " << arr[step] << endl;
	}

	for (int step = 0; step < n; step++) {
		if (step % 2 == 0)
			result.push_back(arr[step]);
	}

	for (int step = 0; step < result.size(); step++) {
		for (int anotherStep = result.size() - 1; anotherStep - 1 >= 0; anotherStep--) {
			if (result[anotherStep] > result[anotherStep - 1]) {
				int temp = result[anotherStep];
				result[anotherStep] = result[anotherStep - 1];
				result[anotherStep - 1] = temp;
			}
		}
	}

	cout << "После пузырька: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrB[" << step << "] == " << result[step] << endl;
	}

	for (int i = 1; i < result.size(); i++)
		for (int j = i; j > 0 && result[j - 1] > result[j]; j--)
			swap(result[j - 1], result[j]);
	reverse(result.begin(), result.end());

	cout << "После вставок: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrB[" << step << "] == " << result[step] << endl;
	}
}