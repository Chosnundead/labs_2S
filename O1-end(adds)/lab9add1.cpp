/*#include "lab9add1.h"
//доп 1 12 лаба внизу
#include <iostream>
using namespace std;
#define max 100

long long phones[5] = { 3123123,43423443,52323423,1321423,8078798 };
const char* names[5] = { "Sergay","Alex","Sasha","Oleg","Mihail" };
const char* last_names[5] = { "Anisim","Larkin","Volosevich","Marat","Bublegum" };
int tarifs[5] = { 1,3,2,2,2 };

struct User
{
	long long number;
	char name[max];
	char surname[max];
	int tarif;
	User* Left, * Right;
};

User* makeUser(User* Root); //Создание дерева
User* list(int i, char* s, char* l, int d); //Создание нового элемента
User* insertElem(User* t, int number, char* name, char* surname, int tarif); //Добавление нового элемента
User* search(User* n, int number); //Поиск элемента по номеру
User* delet(User* Root, int number); //Удаление элемента по номеру
void view(User* t, int level); //Вывод дерева
void delAll(User* t); //Очистка дерева
int checkpopT(User* t);
User* fill(User* t);
User* inserеFILL(User* t, int number, const char* name, const char* surname, int tarif);
User* listFILL(int i, const char* s, const char* l, int d);
void printTARIFS();
User* Root = NULL; //указатель корня
int a[] = { 0,0,0 };

lab9add1::lab9add1()
{
	setlocale(0, "Russian");
	int number, choice, Left_count = 0, Right_count = 0;
	User* rc; int s, letter;
	for (;;)
	{
		cout << "1 - создание дерева\n";
		cout << "2 - добавление элемента\n";
		cout << "3 - поиск по номеру\n";
		cout << "4 - удаление элемента\n";
		cout << "5 - вывод дерева\n";
		cout << "6 - очистка дерева\n";
		cout << "7 - show tarifs\n";
		cout << "8 - popular tarif\n";
		cout << "9 - fill tree(!)\n";
		cout << "10 - выход\n";
		cout << "Ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1: Root = makeUser(Root); break;
		case 2: int tarif; char name[max], surname[max];
			cout << "input phone: "; cin >> number;
			cin.ignore();
			cout << "input name "; cin.getline(name, max);
			cout << "input last_name:"; cin.getline(surname, max);
			cout << "input № tarif:"; cin >> tarif;
			insertElem(Root, number, name, surname, tarif); break;
		case 3: cout << "\ninput phone: "; cin >> number;
			rc = search(Root, number);
			if (rc != NULL)
			{
				cout << "find answer: ";
				cout << rc->number << "-" << rc->name << "-" << rc->surname << "-" << rc->tarif << endl;
			}break;
		case 4: cout << "\ninput delet phone: "; cin >> number;
			Root = delet(Root, number); break;
		case 5: if (Root != NULL)
		{
			cout << "Дерево повернуто на 90 град. влево" << endl;
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 6: delAll(Root); Root = NULL; break;
		case 7: printTARIFS(); break;
		case 8: for (int i = 0; i < 3; i++) a[i] = 0; checkpopT(Root);
			if (a[0] > a[1] && a[0] > a[2])
			{
				cout << "popular tarif is Unlimited\n";
			}
			else if (a[1] > a[2])
			{
				cout << "popular tarif is Summer\n";
			}
			else if (a[0] == a[1])
			{
				cout << "popular tarifs are - Summer and Unlimited\n";
			}
			else if (a[0] == a[2])
			{
				cout << "popular tarifs are - Unlimited and A1\n";
			}
			else if (a[1] == a[2])
			{
				cout << "popular tarif are - Summer and A1\n";
			}
			else if (a[1] == a[2] == a[0])
			{
				cout << "All tarifs are popular\n";
			}
			else
			{
				cout << "popular tarif is - A1\n";
			}
			break;
		case 9: Root = fill(Root); break;
		case 10: exit(0);
		}
	}
}

User* makeUser(User* Root) //Создание дерева
{
	int number, tarif; char name[max], surname[max];
	cout << "Конец ввода - отрицательный номер\n\n";
	if (Root == NULL) // если дерево не создано
	{
		cout << "input phone: "; cin >> number;
		if (number < 0) return Root;
		cin.ignore();
		cout << "input name: "; cin.getline(name, max);
		cout << "input last_name: "; cin.getline(surname, max);
		cout << "input № tarif: "; cin >> tarif;
		Root = list(number, name, surname, tarif); // установка указателя на корень

	}
	while (1) //добавление элементов
	{
		cout << "input phone: "; cin >> number;
		if (number < 0) return
			Root;
		cin.ignore();
		cout << "input name: "; cin.getline(name, max);
		cout << "input last_name: "; cin.getline(surname, max);
		cout << "input № tarif: "; cin >> tarif;
		insertElem(Root, number, name, surname, tarif);
	}
	return Root;
}

User* list(int i, char* s, char* l, int d) //Создание нового элемента
{
	User* t = new User[sizeof(User)];
	t->number = i;
	strcpy_s(t->name, s);
	strcpy_s(t->surname, l);
	t->tarif = d;
	t->Left = t->Right = NULL;
	return t;
}

User* insertElem(User* t, int number, char* name, char* surname, int tarif) //Добавление нового элемента
{
	User* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1; //номера должны быть уникальны
		else
			if (number < t->number) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = list(number, name, surname, tarif);
		if (number < Prev->number)
		{
			Prev->Left = t;
		}
		else
		{
			Prev->Right = t;
		}
	}
	return t;
}

User* delet(User* Root, int number) //Удаление элемента по номеру
{ // Del, Prev_Del - удаляемый элемент и его предыдущий ;
// R, Prev_R - элемент, на который заменяется удаленный, и его родитель;
	User* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->number != number)//поиск элемента и его родителя
	{
		Prev_Del = Del;
		if (Del->number > number)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL) // элемент не найден
	{
		puts("\nНет такого номера");
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
		if (Del->number < Prev_Del->number)
			Prev_Del->Left = R; // на левую ветвь
		else
			Prev_Del->Right = R; // на правую ветвь
	int tmp = Del->number;
	cout << "\nDelet element with phone" << tmp << endl;
	delete Del;
	return Root;
}

User* search(User* n, int number) //Поиск элемента по номеру
{
	User* rc = n;
	if (rc != NULL)
	{
		if (number < n->number)
			rc = search(n->Left, number);
		else
			if (number > n->number)
				rc = search(n->Right, number);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}

void view(User* t, int level) //Вывод дерева
{
	if (t == NULL)return;
	else
	{
		view(t->Left, ++level);
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << t->number << "-" << t->name << "-" << t->surname << "-" << t->tarif << endl;
		level--;
	}
	view(t->Right, ++level);
}

void delAll(User* t) //Очистка дерева
{
	if (t != NULL)
	{
		delAll(t->Left);
		delAll(t->Right);
		delete t;
	}
}

int checkpopT(User* t)
{
	if (t == NULL) { return NULL; }
	if (t->tarif == 1)
	{
		a[0]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}
	else if (t->tarif == 2)
	{
		a[1]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}
	else if (t->tarif == 3)
	{
		a[2]++;
		return(checkpopT(t->Right) + checkpopT(t->Left));
	}

}

User* fill(User* Root)
{
	for (int i = 0; i < 5; i++)
	{
		if (Root == NULL) // если дерево не создано
		{
			Root = listFILL(phones[i], names[i], last_names[i], tarifs[i]); // установка указателя на корень
		}
		else
		{
			inserеFILL(Root, phones[i], names[i], last_names[i], tarifs[i]);
		}
	}
	return Root;
}

User* inserеFILL(User* t, int number, const char* name, const char* surname, int tarif) //Добавление нового элемента
{
	User* Prev = NULL; // Prev - элемент перед текущим
	int find = 0; // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (number == t->number)
			find = 1; //номера должны быть уникальны
		else
			if (number < t->number) t = t->Left;
			else t = t->Right;
	}

	if (!find)
	{
		t = listFILL(number, name, surname, tarif);
		if (number < Prev->number)
		{
			Prev->Left = t;
		}
		else
		{
			Prev->Right = t;
		}
	}
	return t;
}

User* listFILL(int i, const char* s, const char* l, int d) //Создание нового элемента
{
	User* t = new User[sizeof(User)];
	t->number = i;
	strcpy_s(t->name, s);
	strcpy_s(t->surname, l);
	t->tarif = d;
	t->Left = t->Right = NULL;
	return t;
}

void printTARIFS()
{
	cout << "Тарифы:\n1.Unlimited.\n2.Summer.\n3.A1.\n";
}
*/