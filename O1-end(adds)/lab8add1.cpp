/*#include "lab8add1.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Tree //������
{
	int key; //����
	char text[5]; //����� - �� ����� 4 ����
	Tree* Left, * Right;
};

struct Tree6 //������
{
	int key; //����
	Tree6* Left, * Right;
};

struct Tree8 //������
{
	int key;
	int num1;
	int num2;
	Tree8* Left, * Right;
};

struct Tree9 //������
{
	int key;
	int num;
	Tree9* Left, * Right;
};

Tree* makeTree(Tree* Root); //�������� ������
Tree* list(int i, char* s); //�������� ������ ��������
Tree* insertElem(Tree* Root, int key, char* s); //���������� ������ ��������
Tree* search(Tree* n, int key); //����� �������� �� �����
Tree* delet(Tree* Root, int key); //�������� �������� �� �����
void view(Tree* t, int level); //����� ������
int count(Tree* t, char letter); //������� ���������� ����
void delAll(Tree* t); //������� ������
void var6();
int var7(Tree* t, int x);
Tree6* makeTree6(Tree6* Root); //�������� ������
Tree6* list6(int i); //�������� ������ ��������
Tree6* insertElem6(Tree6* Root, int key); //���������� ������ ��������
void view6(Tree6* t, int level);
void to2file(Tree6* t);
void var8();
Tree8* makeTree8(Tree8* Root); //�������� ������
Tree8* list8(int i, int n, int n2); //�������� ������ ��������
Tree8* insertElem8(Tree8* Root, int key, int n1, int n2); //���������� ������ ��������
Tree8* delet8(Tree8* Root, int key); //�������� �������� �� �����
void view8(Tree8* t, int level); //����� ������
void task8(Tree8* t, int level);
void var9();
Tree9* makeTree9(Tree9* Root); //�������� ������
Tree9* list9(int i, int n); //�������� ������ ��������
Tree9* insertElem9(Tree9* Root, int key, int n1); //���������� ������ ��������
void view9(Tree9* t, int level); //����� ������
void task9(Tree9* t, int k);

int c = 0; //���������� ����
Tree* Root = NULL; //��������� �����

int tree_sum(Tree* tr) {
	int l = 0, r = 0;
	if (tr != NULL) {
		l = (tr->Left != NULL) ? tree_sum(tr->Left) : 0;
		r = (tr->Right != NULL) ? tree_sum(tr->Right) : 0;
		return l + r + tr->key;
	}
	return 0;
}

int tree_allNumber(Tree* tr) {
	int l = 0, r = 0;
	if (tr != NULL) {
		l = (tr->Left != NULL) ? tree_allNumber(tr->Left) : 0;
		r = (tr->Right != NULL) ? tree_allNumber(tr->Right) : 0;
		return l + r + 1;
	}
	return 0;
}

lab8add1::lab8add1()
{
	setlocale(0, "Russian");
	int key, choice, n;
	Tree* rc; char s[5], letter;
	for (;;)
	{
		cout << "1 - �������� ������\n";
		cout << "2 - ���������� ��������\n";
		cout << "3 - ����� �� �����\n";
		cout << "4 - �������� ��������\n";
		cout << "5 - ����� ������\n";
		cout << "6 - ������� ���������� ����\n";
		cout << "7 - ������� ������\n";
		cout << "8 - ������� 3\n";
		cout << "9 - ������� 7\n";
		cout << "10 - ������� 8\n";
		cout << "11 - ������� 9\n";
		cout << "13 - ����� ������ ������(��� 13)" << endl;
		cout << "14 - ���������� �� ������ ��������� ������(��� 13)" << endl;
		cout << "15 - ������� �������� ���� ������(��� 13)" << endl;
		cout << "0 - �����\n";
		cout << "��� �����?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeTree(Root); break;
		case 2: cout << "\n������� ����: "; cin >> key;
			cout << "������� �����: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3: cout << "\n������� ����: "; cin >> key;
			rc = search(Root, key);
			cout << "��������� �����= ";
			puts(rc->text); break;
		case 4: cout << "\n������� ��������� ����: "; cin >> key;
			Root = delet(Root, key); break;
		case 5: if (Root->key >= 0)
		{
			cout << "������ ��������� �� 90 ����. �����" << endl;
			view(Root, 0);
		}
			  else cout << "������ ������\n"; break;
		case 6: cout << "\n������� �����: "; cin >> letter;
			n = count(Root, letter);
			cout << "���������� ����, ������������ � ����� " << letter;
			cout << " ����� " << n << endl; break;
		case 7: delAll(Root); break;
		case 8:
			var6();
			break;
		case 9:
			if (Root != NULL) cout << "���������� ������ ������ = " << var7(Root, 0) << endl;
			else cout << "������ ������" << endl;
			break;
		case 10:
			var8();
			break;
		case 11:
			var9();
			break;
		case 13:
			cout << "sum == " << tree_sum(Root) << endl;
			break;
		case 14:
			cout << "elem == " << tree_allNumber(Root) << endl;
			break;
		case 15:
			cout << "avg == " << tree_sum(Root) / tree_allNumber(Root) << endl;
			break;
		case 0: exit(0); break;
		}
	}
}

Tree6* RootVar6 = NULL;
string A = "A.txt", B = "B.txt";
ofstream fAout(A), fBout(B);
ifstream fAin(A), fBin(B);
char str[100];
void var6()
{
	int arr[] = { 20, 23, 15, 13, 29, 24, 18, 22 };
	if (fAout.is_open())
	{
		for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
		{
			fAout << arr[i] << "\n";
		}
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fAout.close();

	if (fAin.is_open())
	{
		RootVar6 = makeTree6(RootVar6);
	}
	else
	{
		cout << " ���������� ������� ����!"
			<< endl;
	}
	fAin.close();

	view6(RootVar6, 0);

	if (fBout.is_open())
	{
		to2file(RootVar6);
	}
	else
	{
		cout << " ���������� ������� ����!" << endl;
	}
	fBout.close();
}

Tree6* makeTree6(Tree6* Root) //�������� ������
{
	int key;
	if (Root == NULL) // ���� ������ �� �������
	{
		fAin.getline(str, sizeof(str));
		key = atoi(str);
		Root = list6(key); // ��������� ��������� �� ������
	}
	while (!fAin.eof())
	{
		fAin.getline(str, sizeof(str));
		if (fAin.eof() != 0) break;
		key = atoi(str);
		insertElem6(Root, key);
	}
	return Root;
}

Tree6* insertElem6(Tree6* t, int key) //���������� ������ ��������
{
	Tree6* Prev = NULL; // Prev - ������� ����� �������
	int find = 0; // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //������� ����� � ������� Prev
	{
		t = list6(key); //��������� ����� ����
		if (key < Prev->key) // � �������������� ����
			Prev->Left = t; //������� �� ����� �����,
		else
			Prev->Right = t; // ���� �� ������
	}
	return t;
}

Tree6* list6(int i) //�������� ������ ��������
{
	Tree6* t = new Tree6[sizeof(Tree6)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}

void view6(Tree6* t, int level) //����� ������
{
	if (t)
	{
		view6(t->Right, level + 1); //����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << endl;
		view6(t->Left, level + 1); //����� ������ ���������
	}
}

void to2file(Tree6* t)
{
	if (t)
	{
		to2file(t->Left);
		fBout << t->key << "\n";
		to2file(t->Right);
	}
}

int var7(Tree* t, int x)
{
	if (t->Left == NULL && t->Right == NULL) return x + 1;
	else
	{
		if (t->Right != NULL) x = var7(t->Right, x);
		if (t->Left != NULL) x = var7(t->Left, x);
	}
	return x;
}

Tree8* RootVar8;
int maxNum = 0, maxKey = 0;
void var8()
{
	RootVar8 = NULL;
	maxNum = 0;
	maxKey = 0;
	RootVar8 = makeTree8(RootVar8);
	view8(RootVar8, 0);
	task8(RootVar8, 0);
	delet8(RootVar8, maxKey);
	view8(RootVar8, 0);
}

Tree8* makeTree8(Tree8* Root) //�������� ������
{
	int key, num1, num2;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL) // ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ������ �����: "; cin >> num1;
		cout << "������� ������ �����: "; cin >> num2;
		Root = list8(key, num1, num2); // ��������� ��������� �� ������
	}
	while (1) //���������� ���������
	{
		cout << "\n������� ����: "; cin >> key;
		if (key < 0) break; //������� ������ (���� < 0)
		cout << "������� ������ �����: "; cin >> num1;
		cout << "������� ������ �����: "; cin >> num2;
		insertElem8(Root, key, num1, num2);
	}
	return Root;
}

Tree8* list8(int i, int n1, int n2) //�������� ������ ��������
{
	Tree8* t = new Tree8[sizeof(Tree8)];
	t->key = i;
	t->num1 = n1;
	t->num2 = n2;
	t->Left = t->Right = NULL;
	return t;
}

Tree8* insertElem8(Tree8* t, int key, int n1, int n2) //���������� ������ ��������
{
	Tree8* Prev = NULL; // Prev - ������� ����� �������
	int find = 0; // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //������� ����� � ������� Prev
	{
		t = list8(key, n1, n2); //��������� ����� ����
		if (key < Prev->key) // � �������������� ����
			Prev->Left = t; //������� �� ����� �����,
		else
			Prev->Right = t; // ���� �� ������
	}
	return t;
}

void task8(Tree8* t, int level)
{
	if (t)
	{
		task8(t->Right, level + 1); //����� ������� ���������
		if (t->num1 + t->num2 > maxNum)
		{
			maxKey = t->key;
			maxNum = t->num1 + t->num2;
		}
		task8(t->Left, level + 1); //����� ������ ���������
	}
}

Tree8* delet8(Tree8* Root, int key) //�������� �������� �� �����
{
	Tree8* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL &&
		Del->key != key)//����� �������� � ��� ��������
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R; //�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� �����
		else
			Prev_Del->Right = R; // �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

void view8(Tree8* t, int level) //����� ������
{
	if (t)
	{
		view8(t->Right, level + 1); //����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << " (" << t->num1 << " " << t->num2 << ")" << endl;
		view8(t->Left, level + 1); //����� ������ ���������
	}
}

Tree9* RootVar9;
int count9;
void var9()
{
	RootVar9 = NULL;
	count9 = 0;
	int k;
	cout << "������� k: ";
	cin >> k;
	RootVar9 = makeTree9(RootVar9);
	view9(RootVar9, 0);
	task9(RootVar9, k);
	cout << "���������� ������ ������, �������� ������� ����� k = " << count9 << endl;
}

Tree9* makeTree9(Tree9* Root) //�������� ������
{
	int key, n;
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL) // ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> n;
		Root = list9(key, n); // ��������� ��������� �� ������
	}
	while (1) //���������� ���������
	{
		cout << "\n������� ����: "; cin >> key;
		if (key < 0) break; //������� ������ (���� < 0)
		cout << "������� �����: "; cin >> n;
		insertElem9(Root, key, n);
	}
	return Root;
}

Tree9* list9(int i, int n) //�������� ������ ��������
{
	Tree9* t = new Tree9[sizeof(Tree9)];
	t->key = i;
	t->num = n;
	t->Left = t->Right = NULL;
	return t;
}

Tree9* insertElem9(Tree9* t, int key, int n) //���������� ������ ��������
{
	Tree9* Prev = NULL; // Prev - ������� ����� �������
	int find = 0; // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //������� ����� � ������� Prev
	{
		t = list9(key, n); //��������� ����� ����
		if (key < Prev->key) // � �������������� ����
			Prev->Left = t; //������� �� ����� �����,
		else
			Prev->Right = t; // ���� �� ������
	}
	return t;
}

void task9(Tree9* t, int k)
{
	if (t)
	{
		task9(t->Right, k);
		if (t->num == k) count9++;
		task9(t->Left, k);
	}
}

void view9(Tree9* t, int level) //����� ������
{
	if (t)
	{
		view9(t->Right, level + 1); //����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << " (" << t->num << ")" << endl;
		view9(t->Left, level + 1); //����� ������ ���������
	}
}

Tree* makeTree(Tree* Root) //�������� ������
{
	int key; char s[5];
	cout << "����� ����� - ������������� �����\n\n";
	if (Root == NULL) // ���� ������ �� �������
	{
		cout << "������� ���� �����: "; cin >> key;
		cout << "������� ����� �����: "; cin >> s;
		Root = list(key, s); // ��������� ��������� �� ������
	}
	while (1) //���������� ���������
	{
		cout << "\n������� ����: "; cin >> key;
		if (key < 0) break; //������� ������ (���� < 0)
		cout << "������� �����: "; cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}


Tree* list(int i, char* s) //�������� ������ ��������
{
	Tree* t = new
		Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s) //���������� ������ ��������
{
	Tree* Prev = NULL; // Prev - ������� ����� �������
	int find = 0; // ������� ������
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //����� ������ ���� ���������
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //������� ����� � ������� Prev
	{
		t = list(key, s); //��������� ����� ����
		if (key < Prev->key) // � �������������� ����
			Prev->Left = t; //������� �� ����� �����,
		else
			Prev->Right = t; // ���� �� ������
	}
	return t;
}

Tree* delet(Tree* Root, int key) //�������� �������� �� �����
{ // Del, Prev_Del - ��������� ������� � ��� ���������� ;
// R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������;
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//����� �������� � ��� ��������
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // ������� �� ������
	{
		puts("\n��� ������ �����");
		return Root;
	}
	if (Del->Right == NULL) // ����� �������� R ��� ������
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //����� ������ ������� �������� � ����� ���������
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R; //�������� ����� � ������ ��� �� R
	else
		// ��������� R �������������� � �������� ���������� ����
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // �� ����� �����
		else
			Prev_Del->Right = R; // �� ������ �����
	int tmp = Del->key;
	cout << "\n������ ������� � ������ " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key) //����� �������� �� �����
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "��� ������ ��������\n";
	return rc;
}

int count(Tree* t, char letter) //������� ���������� ����
{
	if (t)
	{
		count(t->Right, letter);
		if (*(t->text) == letter)
			c++;
		count(t->Left, letter);
	}
	return c;
}

void view(Tree* t, int level) //����� ������
{
	if (t)
	{
		view(t->Right, level + 1); //����� ������� ���������
		for (int i = 0; i < level; i++)
			cout << " ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1); //����� ������ ���������
	}
}

void delAll(Tree* t) //������� ������
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}


*/