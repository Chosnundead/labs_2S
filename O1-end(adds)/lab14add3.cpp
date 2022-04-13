#include "lab14add3.h"
#include <vector>
#include <iostream>
#include <set>

using namespace std;

lab14add3::lab14add3() {
	setlocale(LC_ALL, "Russian");
	vector<int> result, arr;
	set<int> test;
	srand(time(0));

	int n = 15;

	for (int step = 0; step < n; step++) {
		arr.push_back(rand() % 5 - rand() % 5);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < arr.size(); step++) {
		cout << "arr[" << step << "] == " << arr[step] << endl;
		test.insert(arr[step]);
	}

	for (int item : test) {
		result.push_back(item);
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

	cout << "После сортировки: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arr[" << step << "] == " << result[step] << endl;
	}
}
