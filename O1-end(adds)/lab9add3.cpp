#include "lab9add3.h"
#include <iostream>

using namespace std;

struct Tree {
	int value;
	Tree* l, * r;
};

lab9add3::lab9add3() {
	int n;
	cout << "n == ";
	cin >> n;

	Tree root;

	Tree* next = &root;
	for (int step = 0; step < n; step++) {
		next->value = step;
		next->r = new Tree;
		next = next->r;
	}

	next = &root;
	for (int step = 0; step < n; step++) {
		for (int anotherStep = 0; anotherStep < step; anotherStep++)
			cout << "\t";
		cout << next->value << endl;
		next = next->r;
	}
}