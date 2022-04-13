#include "lab13add3.h"
#include <vector>
#include <iostream>

using namespace std;

lab13add3::lab13add3() {
	setlocale(LC_ALL, "Russian");
	vector<int> arrA, result;
	srand(time(0));

	int n;
	cout << "Размер: ";
	cin >> n;
	for (int step = 0; step < n; step++) {
		arrA.push_back(rand() % 10 - rand() % 10);
	}

	for (int step = 0; step < n; step++) {
		if (step % 2 == 0)
			result.push_back(arrA[step]);
	}

	cout << "До сортировки: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrB[" << step << "] == " << result[step] << endl;
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
	reverse(result.begin(), result.end());

	cout << "После пузырька: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrB[" << step << "] == " << result[step] << endl;
	}

	int min = 0;
	int buf = 0;
	for (int i = 0; i < result.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < result.size(); j++)
			min = (result[j] < result[min]) ? j : min;

		if (i != min)
		{
			buf = result[i];
			result[i] = result[min];
			result[min] = buf;
		}
	}

	cout << "После выбора: " << endl;
	for (int step = 0; step < result.size(); step++) {
		cout << "arrB[" << step << "] == " << result[step] << endl;
	}
}

