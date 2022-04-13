#include "lab13add2.h"
#include <vector>
#include <iostream>

using namespace std;

lab13add2::lab13add2() {
	setlocale(LC_ALL, "Russian");
	vector<int> arrA, arrB, result;
	srand(time(0));

	int n;
	cout << "Размер: ";
	cin >> n;
	for (int step = 0; step < n; step++) {
		arrA.push_back(rand() % 10 - rand() % 10);
		arrB.push_back(rand() % 10 - rand() % 10);
	}

	int max = arrB[0];
	for (int step = 0; step < n; step++) {
		if (max < arrB[step])
			max = arrB[step];
	}

	for (int step = 0; step < n; step++) {
		if (max < arrA[step])
			result.push_back(arrA[step]);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrC[" << step << "] == " << result[step] << endl;
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
		cout << "arrC[" << step << "] == " << result[step] << endl;
	}

	for (int i = 1; i < result.size(); i++)
		for (int j = i; j > 0 && result[j - 1] > result[j]; j--)
			swap(result[j - 1], result[j]);
	reverse(result.begin(), result.end());

	cout << "После вставок: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrC[" << step << "] == " << result[step] << endl;
	}
}
