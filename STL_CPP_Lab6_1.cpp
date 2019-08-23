//Ћабораторная работа STL є6-1 "Algorithm"
//—итникова ¬.ј.
/*«адание: Ќаписать программу, которая выполняет следующие действия:
a.	„итает содержимое текстового файла
b.	¬ыделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции и/или символами новой строки
c.	¬ывести список слов присутствующий в тексте без повторений (имеется в виду, что одно и то же слово может присутствовать в списке только один раз)
*/
//—ѕб, 04.03.2017 

#include "iostream"
#include "conio.h"
#include "algorithm"
#include "fstream"   //файловый ввод-вывод
#include < stdio.h > 
#include "string"
#include "vector"
#include <locale.h>


using namespace std;

void main(void)
{
	vector <string> word;

	char simvol;
	string str;
	int count=0;
	FILE *mf;

	setlocale(LC_ALL, "RUS");

	fopen_s (&mf,"STL_LAB6_1.CPP", "r");

	cout << "----------------------- original text ----------------------" << endl << endl;

	while ((simvol = fgetc(mf)) !=EOF)								//цикл читает из файда по буквам
	{
		cout << simvol;
		if ((simvol >= 'A' && simvol <= 'z') || (simvol >= '0' && simvol <= '9'))
	//	if ((simvol >= 65 && simvol <= 122) || (simvol >= '0' && simvol <= '9') || (simvol >= 192 && simvol <= 255))
		{
			count++;
			str += simvol;
		}
		else if (count > 0)
		{
			count = 0;
			word.push_back(str);
			str.clear();
		}
	}
	if (count > 0)
	{
		count = 0;
		word.push_back(str);
		str.clear();
	}
	
	cout << endl << endl << "----------------------- Read words ----------------------" << endl << endl;
	for (int i = 0;  i < word.size(); i++) cout << word[i] << " ";

	cout << endl << endl << "----------------------- Used words ----------------------" << endl << endl;

	sort(word.begin(), word.end());			//сортировка 
	unique(word.begin(), word.end());		// удолит похожие эл-ты

	for (int i = 0; i < word.size(); i++) cout << word[i] << " ";

	_getch();
}