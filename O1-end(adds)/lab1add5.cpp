#include "lab1add5.h"
//12_1

//Скопировать из файла FILE1 в файл FILE2 все строки, в которых есть слова, совпадающие с первым словом.Определить количество согласных букв в последней строке  файла FILE2.

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
int checker_word(char buff[256], char word[256]) {
	int checker = 1, checkpoint = strlen(word);
	for (int a = 1, b = 1; a < 256; a++) {
		if (word[b] == buff[a]) {
			checker++;
			b++;
		}
		if (buff[a] != word[b - 1] and a > 1) {
			b = 1;
		}
		if (checker == checkpoint) {
			return true;
		}
		else if (a == strlen(buff)) {
			return false;
		}

	}
}

lab1add5::lab1add5()
{
	setlocale(LC_ALL, "ru");
	ofstream fout;
	fout.open("FILE1.txt");
	if (!fout.is_open())
		cout << "Ошибка открытия" << endl;
	else
		fout << "well hight low small\nhight low well\nlow well small\nmid light low";
	fout.close();


	char buff[256];
	ifstream fin;
	fin.open("FILE1.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия" << endl;
	}
	else
	{

		char first_word[80];
		int rows = 0;
		//cout << "Файл открыт!" << endl;
		fin >> first_word;
		cout << "first_word: " << first_word << endl;
		for (;;) {
			fin.getline(buff, 256);
			rows++;
			if (fin.eof()) break;
		}
		fin.close();




		fin.open("FILE1.txt");
		ofstream fout;
		fout.open("FILE2.txt");
		for (; fin;) {
			fin.getline(buff, 256);
			if (checker_word(buff, first_word) == true) {
				fout << buff << "\n";
				cout << buff << endl;
			}
		}



	}
	fin.close();
	fout.close();



	fin.open("FILE2.txt");

	char buff2[256];
	int rows = 0;
	char massiv_glasnih[] = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c' ,'v' ,'b', 'n', 'm' };
	int cont_soglasnih = 0;
	int rows_checker = 1;
	for (;;) {
		fin.getline(buff2, 256);
		if (fin.eof()) break;
		rows++;
	}

	fin.close();
	fin.open("FILE2.txt");

	for (;;) {
		if (rows_checker > rows) {
			for (int letter = 0;; letter++) {
				for (int a = 0; a < 20; a++) {
					if (buff2[letter] == massiv_glasnih[a] || (int)buff2[letter] == ((int)massiv_glasnih[a] - 20)) {
						cont_soglasnih++;
					}
				}
				if (buff2[letter] == '\0') {
					break;
				}
			}
			cout << cont_soglasnih << endl;
			break;
		}
		fin.getline(buff2, 256);
		rows_checker++;
	}
	fin.close();
}