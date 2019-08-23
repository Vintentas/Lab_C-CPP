//Лабораторная работа STL №1-5 "Вектора"
//Ситникова В.А.
//Задание: Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода (окончанием ввода является число 0).
//Удалите все элементы, которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1. 
//Если последнее число 2, добавьте после каждого числа которое делится на 3 три единицы.
//СПб, 22.02.2017 


#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"


using namespace std;

void main(void)
{
	vector< int > v1(100);
	int x, a, y;   // x - кол-во элементов в векторе
				   // а, y - временные перемеееные

				   // Запись вектора из потока до первого встреченного 0.
	cout << "Enter integer numbers. The program considers the number to the first \"0\"." << endl;
	cin >> a;
	for (x = 0; (x < v1.capacity() && a != 0); x++)
	{
		v1[x] = a;
		cin >> a;
	}

	cout << endl << "The enter vector: " << endl;                //Вывод полученного вектора.
	for (y = 0; y < x; y++) cout << v1[y] << " ";
	//cout << fixed << setprecision(1) << v1[y] << " ";
	cout << endl;

	cout << "-----------------------------------------" << endl;

	if (v1[x - 1] == 1)											//Если последний элемент = 1, удаляем все четные элементы
	{
		for (y = 0; y < x; y++)
		{
			if (v1[y] % 2 == 0)
			{
				v1.erase(v1.begin() + y);
				x--;
			}
		}
		cout << "Last element=1. Deleted if // 2" << endl;
	}

	else if (v1[x - 1] == 2)									//Если последний элемент = 2, добавляем 3 к каждому числу, которое делится на 3
	{
		for (y = 0; y < x; y++)
		{
			if (v1[y] % 3 == 0) v1[y] = v1[y]*1000+111;
		}
		cout << "Last element=2. Add +3 if // 3" << endl;
	}

	else cout << "No changes!" << endl;				//Иначе не происходит никаких изменений.

	cout << endl << "The modified vector: " << endl;                //Вывод модифицированного вектора вектора.
	for (y = 0; y < x; y++) cout << v1[y] << " ";
	cout << endl;

	_getch();
}