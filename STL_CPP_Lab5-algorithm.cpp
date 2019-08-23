//Лабораторная работа STL №5 "Algorithm"
//Ситникова В.А.
/*Задание:  Написать программа, которая выполняет следующие действия :

		a.Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от - 5 до 5, 
	str заполняется из таблицы(таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
		b.Выводит полученный вектор на печать
		c.Сортирует вектор следующим образом :
			i.По возрастанию key1
			ii.Если key1 одинаковые, то по возрастанию key2
			iii.Если key1 и key2 одинаковые, то по возрастанию длинны строки str
		d.Выводит полученный вектор на печать

DataStruct определена следующим образом :
typedef struct
{
	int       key1;
	int       key2;
	string  str;
} DataStruct;
*/
//СПб, 04.03.2017 


#include "string"
#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>

#define Kol_vo 30						// константа кол-ва элементов в стринге

using namespace std;

typedef struct
{
	int     key1;
	int     key2;
	string	str;
} DataStruct;

typedef struct							// Структура - таблица для заполнения DataStruct.str
{
	string	str_0=("AAAAA");
	string	str_1 = ("BB");
	string	str_2 = ("CCCCCCC");
	string	str_3 = ("DDDDD");
	string	str_4 = ("EEEEEEE");
	string	str_5 = ("FFFF");
	string	str_6 = ("GGGGG");
	string	str_7 = ("HHH");
	string	str_8 = ("II");
	string	str_9 = ("JJJJ");
} TableString;

void My_Swap(DataStruct* A, DataStruct* B)			// функция обмена
{
	DataStruct DStr = *A;
	*A = *B;
	*B = DStr;
}

void main(void)
{
	vector <DataStruct> VectorString;
	int i, j;

	//Заполнение стринга
	for (i = 0; i < Kol_vo; i++)
	{
		DataStruct DStr;
		TableString TabStr;
		int namber;

		DStr.key1 = (rand() % 11 - 5);
		DStr.key2 = (rand() % 11 - 5);
		namber = (rand() % 10);
		switch (namber)
		{
		case 0: DStr.str = TabStr.str_0; break;
		case 1: DStr.str = TabStr.str_1; break;
		case 2: DStr.str = TabStr.str_2; break;
		case 3: DStr.str = TabStr.str_3; break;
		case 4: DStr.str = TabStr.str_4; break;
		case 5: DStr.str = TabStr.str_5; break;
		case 6: DStr.str = TabStr.str_6; break;
		case 7: DStr.str = TabStr.str_7; break;
		case 8: DStr.str = TabStr.str_8; break;
		case 9: DStr.str = TabStr.str_9; break;		
		default: break;
		}		
		VectorString.push_back(DStr);
	}

	cout << "--------------Output--------------" << endl << endl;
	//Вывод стринга
	for (i = 0; i < VectorString.size(); i++)					
	{
		cout << i+1 << ".\tkey1=" << VectorString[i].key1 << "\tkey2=" << VectorString[i].key2 << "\tstr=" << VectorString[i].str<<endl;
	}

	//Сортировка
	for (i = VectorString.size(); i >0; i--) // внешний цикл сортировки
	{
		for (j = 0; j < i - 1; j++)        // внутренний цикл сортировки
		{
			if (VectorString[j].key1 > VectorString[j+1].key1)
				My_Swap(&VectorString[j], &VectorString[j+1]);			// обмен
	
			if ((VectorString[j].key1 == VectorString[j + 1].key1)&& (VectorString[j].key2 > VectorString[j + 1].key2))
				My_Swap(&VectorString[j], &VectorString[j + 1]);					
				
			if ((VectorString[j].key1 == VectorString[j + 1].key1) && (VectorString[j].key2 == VectorString[j + 1].key2) && (VectorString[j].str > VectorString[j + 1].str))
				My_Swap(&VectorString[j], &VectorString[j + 1]);	
		}
	}


	cout << endl << "--------------Output after sorting--------------" << endl << endl;
	//Вывод стринга
	for (i = 0; i < VectorString.size(); i++)
	{
		cout << i + 1 << ".\tkey1=" << VectorString[i].key1 << "\tkey2=" << VectorString[i].key2 << "\tstr=" << VectorString[i].str << endl;
	}

	_getch();
}