#include "lab14add1.h"
#include <vector>
#include <iostream>

using namespace std;

lab14add1::lab14add1() {
	setlocale(LC_ALL, "Russian");
	vector<int> arrA, result;
	srand(time(0));

	int n;
	cout << "Размер: ";
	cin >> n;

	for (int step = 0; step < n; step++) {
		result.push_back(rand() % 10 - rand() % 10);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arr[" << step << "] == " << result[step] << endl;
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

	cout << "max == " << result[0] << endl << "min == " << result[result.size() - 1] << endl;
}

