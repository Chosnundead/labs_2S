#include "Lab11.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tree {
	int index;
	string value;
	Tree* right = NULL, * left = NULL;
};

void _createTree(vector<Tree>& arr) {
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

void _addInTree(vector<Tree>& arr) {
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
	Tree* newTree = &arr.back();
	while (true) {
		if (test->index < newTree->index) {
			if (test->right)
				test = test->right;
			else {
				test->right = newTree;
				break;
			}
		}
		else if (test->index > newTree->index) {
			if (test->left)
				test = test->left;
			else {
				test->left = newTree;
				break;
			}
		}
		else {
			test->value = newTree->value;
			break;
		}
	}
}

void _showTree(vector<Tree>& arr, int index) {
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

void _choiseTreeAndShow(vector<Tree>& arr) {
	int index;
	cout << "Введите индекс: ";
	cin >> index;
	_showTree(arr, index);
}

int _menuTree() {

	int choise;
	cout << "1: Создать дерево" << endl;
	cout << "2: Добавить ветку" << endl;
	cout << "3: Вывод ветки по индексу" << endl;
	cout << "0: Выход" << endl;
	cout << "Ваш выбор: ";
	cin >> choise;
	return choise;
}

Lab11::Lab11() {
	vector<Tree> tree;

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
		default:
			break;
		}
		if (choise == 0)
			break;
	}
}