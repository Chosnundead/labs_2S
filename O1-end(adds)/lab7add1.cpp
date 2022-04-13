#include "lab7add1.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <malloc.h>
#include <fstream>

using namespace std;

int var3(int m, int n)
{
	if (m > 0 && n > 0) return var3(m - 1, n - 1) + var3(m - 1, var3(m - 1, n - 1));
	else if (m > 0) return var3(m - 1, 0) + var3(m - 1, 1);
	else return n + 1;
}

double f(double x)
{
	return pow(x, 3) + x - 3;
}

double var5(double a, double b, double e)
{
	double c = (a + b) / 2;
	if (b - a <= 2 * e) return c;
	else if (f(a) * f(c) <= 0) return var5(a, c, e);
	else return var5(c, b, e);
}

int dop1(int a, int b, int*& arr, int x, int& size)
{
	if (b == 0)
	{
		arr[size++] = x;
		return 0;
	}
	else
	{
		for (int i = 1; i <= a; i++)
		{
			dop1(a, b - 1, arr, i * pow(10, b - 1) + x, size);
		}
	}
	return 0;
}

const int N = 5;
int arr[N];
void dop3(int k)
{
	int i, j, t, p;
	for (i = 0; i < N - k; i++)
	{
		if (k < N - 2) dop3(k + 1);
		else
		{
			for (p = 0; p < N; p++) cout << " " << arr[p];
			cout << endl;
		}

		t = arr[k];
		for (j = k + 1; j < N; j++)
		{
			arr[j - 1] = arr[j];
		}
		arr[j - 1] = t;
	}
}

char xx, help;
void dop4(int all, int cur, char q, int x, int curX)
{
	for (int i = 0; i <= cur; i++)
	{
		help = q + cur;
		cout << help;
		if (curX == x) xx = q + cur;
		curX++;
	}
	if (cur < all) dop4(all, ++cur, q, x, curX);
}

lab7add1::lab7add1() {
	setlocale(LC_ALL, "rus");
	int c = 1, m, n;
	double a, b, e;

	while (c)
	{

		cout << "1. 1add\n";
		cout << "2. 3add\n";
		cout << "3. 4add\n";
		cout << "0. Закончить\n";
		cin >> c;
		switch (c)
		{


		case 1:
			cout << "Введите a: ";
			cin >> m;
			if (m >= 0)
			{
				int* arr = new int[pow(m, m)];
				int size = 0;
				dop1(m, m, arr, 0, size);
				ofstream fAout("A.txt");
				if (fAout.is_open())
				{
					for (int i = 0; i < _msize(arr) / sizeof(int); i++)
					{
						fAout << arr[i] << "\n";
					}
				}
				fAout.close();
				delete[] arr;
			}
			break;

		case 2:
			cout << "Введите 5 чисел: ";
			for (size_t i = 0; i < N; i++)
			{
				cin >> arr[i];
			}
			dop3(0);
			break;

		case 3:
			cout << "Введите n: ";
			cin >> n;
			dop4(26, 0, 'a', n, 0);
			cout << "\nСимвол, который стоит на n-ом месте последовательности: " << xx << endl;
			break;

		default:
			break;
		}
	}
}