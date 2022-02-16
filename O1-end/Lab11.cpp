#include "Lab11.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct Tree {
	int index;
	string value;
	Tree* right = NULL, * left = NULL;
};

void _createTree(list<Tree>& arr) {
	int index;
	string value;
	Tree add;
	cout << "Введите индекс: ";
	cin >> index;
	add.index = index;
	cin.ignore(256, '\n');
	cout << "Введите значение: ";
	getline(cin, value);
	add.value = value;
	arr.push_back(add);
}

void _addInTree(list<Tree>& arr) {
	int index;
	string value;
	Tree add;
	cout << "Введите индекс: ";
	cin >> index;
	add.index = index;
	cin.ignore(256, '\n');
	cout << "Введите значение: ";
	getline(cin, value);
	add.value = value;
	arr.push_back(add);
	Tree* test = &arr.front();
	//Tree* newTree = &arr.back();
	while (true) {
		if (test->index < arr.back().index) {
			if (test->right)
				test = test->right;
			else {
				test->right = &arr.back();
				break;
			}
		}
		else if (test->index > arr.back().index) {
			if (test->left)
				test = test->left;
			else {
				test->left = &arr.back();
				break;
			}
		}
		else {
			test->value = arr.back().value;
			break;
		}
	}
}

void _showTree(list<Tree>& arr, int index) {
	Tree* root = &arr.front();
	while (true) {
		if (root->index < index) {
			if (root->right)
				root = root->right;
			else {
				cout << "Нету." << endl;
				break;
			}
		}
		else if (root->index > index) {
			if (root->left)
				root = root->left;
			else {
				cout << "Нету." << endl;
				break;
			}
		}
		else {
			cout << "Tree[" << root->index << "] == " << root->value << endl << "left: " << root->left << endl << "right: " << root->right << endl;
			break;
		}
	}
}

void _choiseTreeAndShow(list<Tree>& arr) {
	int index;
	cout << "Введите индекс: ";
	cin >> index;
	_showTree(arr, index);
}

void _showLevelOfTree(list<Tree>& arr) {
	Tree* root = &arr.front();
	Tree* rootStep = root;
	int level, counter = 0;
	cout << "Введите уровень для сканирования: ";
	cin >> level;
	for (int step = 0; step < (int)pow(2, level); step++) {
		for (int stepLevel = 0; stepLevel < (level + 1); stepLevel++) {
			if (rootStep->left && (step & (1 << stepLevel))) {
				rootStep = rootStep->left;
			}
			else if (rootStep->right && !(step & (1 << stepLevel))) {
				rootStep = rootStep->right;
			}
			else {
				if (stepLevel == level) {
					cout << "tree[" << rootStep->index << "];" << "\t";
					counter++;
				}
				break;
			}
		}
	}
	cout << endl;
	if (counter >= 2) {
		cout << "Древо сбалансированно до\\на этом уровне!" << endl;
	}
	else {
		cout << "Древо не сбалансированно на этом уровне!" << endl;
	}
}

int _menuTree() {

	int choise;
	cout << "1: Создать дерево" << endl;
	cout << "2: Добавить ветку" << endl;
	cout << "3: Вывод ветки по индексу" << endl;
	cout << "4: Сканирование уровня + его проверка на сбалансированность" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return choise;
}

Lab11::Lab11() {
	list<Tree> tree;

	while (int choise = _menuTree()) {
		switch (choise) {
		case 1:
			_createTree(tree);
			break;
		case 2:
			_addInTree(tree);
			break;
		case 3:
			_choiseTreeAndShow(tree);
			break;
		case 4:
			_showLevelOfTree(tree);
			break;
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}