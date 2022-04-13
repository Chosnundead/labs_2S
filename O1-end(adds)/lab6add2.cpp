#include "lab6add2.h"
#include <iostream>
#include <vector>

using namespace std;

lab6add2::lab6add2() {
	int n, k;
	cout << "n == ";
	cin >> n;
	cout << "k == ";
	cin >> k;

	k--;
	vector<int> arr;
	for (int step = 0; step < n; step++) {
		arr.push_back(step);
	}
	int idx = 0;
	while (arr.size() >= 1) {
		if (arr.size() < idx + k) {
			idx = (idx + k) % arr.size();
		}
		else {
			idx += k;
		}
		cout << arr[idx] << " ";
		arr.erase(arr.begin() + idx);
	}
}