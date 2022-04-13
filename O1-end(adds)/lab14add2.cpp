#include "lab14add2.h"
#include <vector>
#include <iostream>

using namespace std;

lab14add2::lab14add2() {
	setlocale(LC_ALL, "Russian");
	vector<int> result;
	srand(time(0));

	int n = 10;

	for (int step = 0; step < n; step++) {
		result.push_back(rand() % 10 - rand() % 10);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arr[" << step << "] == " << result[step] << endl;
	}

	for (int step = 0; step < 4; step++) {
		for (int anotherStep = 4 - 1; anotherStep - 1 >= 0; anotherStep--) {
			if (result[anotherStep] > result[anotherStep - 1]) {
				int temp = result[anotherStep];
				result[anotherStep] = result[anotherStep - 1];
				result[anotherStep - 1] = temp;
			}
		}
	}
	vector <int>::iterator itData = result.begin() + 4;
	reverse(result.begin(), itData);

	for (int step = 6; step < result.size(); step++) {
		for (int anotherStep = result.size() - 1; anotherStep - 1 >= 6; anotherStep--) {
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


