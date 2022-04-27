/*#include "lab10add1.h"
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

#define vec vector
#define vec_i vector<int>
#define vec_c vector<char>
#define vec_s vector<string>
#define SIZE Max_size

struct Heap {
	static const int Max_size = 100;
	vec_i h;
	int HeapSize;
	Heap() {
		h.resize(Max_size);
		HeapSize = 0;
	}
	void insert(int n) {
		int i = HeapSize;
		h[i] = n;
		int parent = (i - 1) / 2;
		while (parent >= 0 && i > 0) {
			if (h[i] > h[parent]) swap(h[parent], h[i]);
			i = parent;
			parent = (i - 1) / 2;
		}
		HeapSize++;
	}
	void outHeap(void) {
		int i = 0, k = 1;
		while (i < HeapSize) {
			while ((i < k) && (i < HeapSize)) {
				cout << h[i] << " ";
				i++;
			}
			cout << endl;
			k = k * 2 + 1;
		}
	}
	int _sumOfAll() {
		int sum = 0;
		for (int i = 0; i < HeapSize; i++) sum += h[i];
		return sum;
	}
	float _averageOfAll() {
		return (float)this->_sumOfAll() / (float)this->HeapSize;
	}
	void _addTenRandom() {
		for (int i = 0; i < 10; i++) {
			this->insert(rand() % 10);
		}
	}
	void out(void) {
		for (int i = 0; i < HeapSize; i++) cout << h[i] << " ";
		cout << endl;
	}
	int getmax(void) {
		int x;
		x = h[0];
		h[0] = h[HeapSize - 1];
		HeapSize--;
		heapify(0);
		return x;
	}
	void heapify(int i) {
		int left, right;
		int temp;
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < HeapSize) {
			if (h[i] < h[left]) {
				temp = h[i];
				h[i] = h[left];
				h[left] = temp;
				heapify(left);
			}
		}
		if (right < HeapSize) {
			if (h[i] < h[right]) {
				temp = h[i];
				h[i] = h[right];
				h[right] = temp;
				heapify(right);
			}
		}
	}
};

lab10add1::lab10add1() {
	setlocale(LC_ALL, "Russian");
	Heap heap;
	srand(time(0));
	heap._addTenRandom();
	heap.outHeap();
	cout << "_sumOfAll() == " << heap._sumOfAll() << endl;
	cout << "_averageOfAll() == " << heap._averageOfAll() << endl;
}*/