/*#include "lab8add1.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Tree //дерево
{
	int key; //ключ
	char text[5]; //текст - не более 4 букв
	Tree* Left, * Right;
};

struct Tree6 //дерево
{
	int key; //ключ
	Tree6* Left, * Right;
};

struct Tree8 //дерево
{
	int key;
	int num1;
	int num2;
	Tree8* Left, * Right;
};

struct Tree9 //дерево
{
	int key;
	int num;
	Tree9* Left, * Right;
};

Tree* makeTree(Tree* Root); //Создание дерева
Tree* list(int i, char* s); //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s); //Добавление нового элемента
Tree* search(Tree* n, int key); //Поиск элемента по ключу
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level); //Вывод дерева
int count(Tree* t, char letter); //Подсчет количества слов
void delAll(Tree* t); //Очистка дерева
void var6();
int var7(Tree* t, int x);
Tree6* makeTree6(Tree6* Root); //Создание дерева
Tree6* list6(int i); //Создание нового элемента
Tree6* insertElem6(Tree6* Root, int key); //Добавление нового элемента
void view6(Tree6* t, int level);
void to2file(Tree6* t);
void var8();
Tree8* makeTree8(Tree8* Root); //Создание дерева
Tree8* list8(int i, int n, int n2); //Создание нового элемента
Tree8* insertElem8(Tree8* Root, int key, int n1, int n2); //Добавление нового элемента
Tree8* delet8(Tree8* Root, int key); //Удаление элемента по ключу
void view8(Tree8* t, int level); //Вывод дерева
void task8(Tree8* t, int level);
void var9();
Tree9* makeTree9(Tree9* Root); //Создание дерева
Tree9* list9(int i, int n); //Создание нового элемента
Tree9* insertElem9(Tree9* Root, int key, int n1); //Добавление нового элемента
void view9(Tree9* t, int level); //Вывод дерева
void task9(Tree9* t, int k);

int c = 0; //количество слов
Tree* Root = NULL; //указатель корня

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
		cout << "1 - создание дерева\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по ключу\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - подсчет количества букв\n";
		cout << "7 - очистка дерева\n";
		cout << "8 - вариант 3\n";
		cout << "9 - вариант 7\n";
		cout << "10 - вариант 8\n";
		cout << "11 - вариант 9\n";
		cout << "13 - Сумма ключей дерева(Лаб 13)" << endl;
		cout << "14 - Количество не пустых элементов дерева(Лаб 13)" << endl;
		cout << "15 - Среднее значение всех ключей(Лаб 13)" << endl;
		cout << "0 - выход\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeTree(Root); break;
		case 2: cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите слово: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3: cout << "\nВведите ключ: "; cin >> key;
			rc = search(Root, key);
			cout << "Найденное слово= ";
			puts(rc->text); break;
		case 4: cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key); break;
		case 5: if (Root->key >= 0)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6: cout << "\nВведите букву: "; cin >> letter;
			n = count(Root, letter);
			cout << "Количество слов, начинающихся с буквы " << letter;
			cout << " равно " << n << endl; break;
		case 7: delAll(Root); break;
		case 8:
			var6();
			break;
		case 9:
			if (Root != NULL) cout << "Количество листье дерева = " << var7(Root, 0) << endl;
			else cout << "Дерево пустое" << endl;
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
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();

	if (fAin.is_open())
	{
		RootVar6 = makeTree6(RootVar6);
	}
	else
	{
		cout << " Невозможно открыть файл!"
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
		cout << " Невозможно открыть файл!" << endl;
	}
	fBout.close();
}

Tree6* makeTree6(Tree6* Root) //Создание дерева
{
	int key;
	if (Root == NULL) // если дерево не создано
	{
		fAin.getline(str, sizeof(str));
		key = atoi(str);
		Root = list6(key); // установка указателя на корень
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

Tree6* insertElem6(Tree6* t, int key) //Добавление нового элемента
{
	Tree6* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //найдено место с адресом Prev
	{
		t = list6(key); //создается новый узел
		if (key < Prev->key) // и присоединяется либо
			Prev->Left = t; //переход на левую ветвь,
		else
			Prev->Right = t; // либо на правую
	}
	return t;
}

Tree6* list6(int i) //Создание нового элемента
{
	Tree6* t = new Tree6[sizeof(Tree6)];
	t->key = i;
	t->Left = t->Right = NULL;
	return t;
}

void view6(Tree6* t, int level) //Вывод дерева
{
	if (t)
	{
		view6(t->Right, level + 1); //вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << endl;
		view6(t->Left, level + 1); //вывод левого поддерева
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

Tree8* makeTree8(Tree8* Root) //Создание дерева
{
	int key, num1, num2;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL) // если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите первое число: "; cin >> num1;
		cout << "Введите второе число: "; cin >> num2;
		Root = list8(key, num1, num2); // установка указателя на корень
	}
	while (1) //добавление элементов
	{
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0) break; //признак выхода (ключ < 0)
		cout << "Введите первое число: "; cin >> num1;
		cout << "Введите второе число: "; cin >> num2;
		insertElem8(Root, key, num1, num2);
	}
	return Root;
}

Tree8* list8(int i, int n1, int n2) //Создание нового элемента
{
	Tree8* t = new Tree8[sizeof(Tree8)];
	t->key = i;
	t->num1 = n1;
	t->num2 = n2;
	t->Left = t->Right = NULL;
	return t;
}

Tree8* insertElem8(Tree8* t, int key, int n1, int n2) //Добавление нового элемента
{
	Tree8* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //найдено место с адресом Prev
	{
		t = list8(key, n1, n2); //создается новый узел
		if (key < Prev->key) // и присоединяется либо
			Prev->Left = t; //переход на левую ветвь,
		else
			Prev->Right = t; // либо на правую
	}
	return t;
}

void task8(Tree8* t, int level)
{
	if (t)
	{
		task8(t->Right, level + 1); //вывод правого поддерева
		if (t->num1 + t->num2 > maxNum)
		{
			maxKey = t->key;
			maxNum = t->num1 + t->num2;
		}
		task8(t->Left, level + 1); //вывод левого поддерева
	}
}

Tree8* delet8(Tree8* Root, int key) //Удаление элемента по ключу
{
	Tree8* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL &&
		Del->key != key)//поиск элемента и его родителя
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R; //удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь
		else
			Prev_Del->Right = R; // на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

void view8(Tree8* t, int level) //Вывод дерева
{
	if (t)
	{
		view8(t->Right, level + 1); //вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << " (" << t->num1 << " " << t->num2 << ")" << endl;
		view8(t->Left, level + 1); //вывод левого поддерева
	}
}

Tree9* RootVar9;
int count9;
void var9()
{
	RootVar9 = NULL;
	count9 = 0;
	int k;
	cout << "Введите k: ";
	cin >> k;
	RootVar9 = makeTree9(RootVar9);
	view9(RootVar9, 0);
	task9(RootVar9, k);
	cout << "Количества вершин дерева, значение которых равно k = " << count9 << endl;
}

Tree9* makeTree9(Tree9* Root) //Создание дерева
{
	int key, n;
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL) // если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите число корня: "; cin >> n;
		Root = list9(key, n); // установка указателя на корень
	}
	while (1) //добавление элементов
	{
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0) break; //признак выхода (ключ < 0)
		cout << "Введите число: "; cin >> n;
		insertElem9(Root, key, n);
	}
	return Root;
}

Tree9* list9(int i, int n) //Создание нового элемента
{
	Tree9* t = new Tree9[sizeof(Tree9)];
	t->key = i;
	t->num = n;
	t->Left = t->Right = NULL;
	return t;
}

Tree9* insertElem9(Tree9* t, int key, int n) //Добавление нового элемента
{
	Tree9* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //найдено место с адресом Prev
	{
		t = list9(key, n); //создается новый узел
		if (key < Prev->key) // и присоединяется либо
			Prev->Left = t; //переход на левую ветвь,
		else
			Prev->Right = t; // либо на правую
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

void view9(Tree9* t, int level) //Вывод дерева
{
	if (t)
	{
		view9(t->Right, level + 1); //вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->key << " (" << t->num << ")" << endl;
		view9(t->Left, level + 1); //вывод левого поддерева
	}
}

Tree* makeTree(Tree* Root) //Создание дерева
{
	int key; char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL) // если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите слово корня: "; cin >> s;
		Root = list(key, s); // установка указателя на корень
	}
	while (1) //добавление элементов
	{
		cout << "\nВведите ключ: "; cin >> key;
		if (key < 0) break; //признак выхода (ключ < 0)
		cout << "Введите слово: "; cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}


Tree* list(int i, char* s) //Создание нового элемента
{
	Tree* t = new
		Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}

Tree* insertElem(Tree* t, int key, char* s) //Добавление нового элемента
{
	Tree* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1; //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find) //найдено место с адресом Prev
	{
		t = list(key, s); //создается новый узел
		if (key < Prev->key) // и присоединяется либо
			Prev->Left = t; //переход на левую ветвь,
		else
			Prev->Right = t; // либо на правую
	}
	return t;
}

Tree* delet(Tree* Root, int key) //Удаление элемента по ключу
{ // Del, Prev_Del - удаляемый элемент и его предыдущий ;
// R, Prev_R - элемент, на который заменяется удаленный, и его родитель;
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R; //удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь
		else
			Prev_Del->Right = R; // на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key) //Поиск элемента по ключу
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
		cout << "Нет такого элемента\n";
	return rc;
}

int count(Tree* t, char letter) //Подсчет количества слов
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

void view(Tree* t, int level) //Вывод дерева
{
	if (t)
	{
		view(t->Right, level + 1); //вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << " ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1); //вывод левого поддерева
	}
}

void delAll(Tree* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}


*/