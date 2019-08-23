//Лабораторная работа STL №1-2 "Вектора"
//Ситникова В.А.
//Задание: Напишите алгоритм сортировки (любой простейший) содержимого вектора целых чисел, используя метод at() и с описанной сортировкой.
//СПб, 22.02.2017 

//#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"
#include "stdlib.h"    //библиотака для rand()
#include "time.h"      //библиотека для cloc()

using namespace std;

void main(void)
{
	vector< int > v1(10);
	int x;

	for (x = 0; x < v1.capacity(); x++) v1.at(x) = rand() % 100;   // Запись вектора из 10 случайных чисел от 0 до 99
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < v1.size(); x++) cout << v1.at(x) << " ";      // Вывод вектора
	cout << endl;

	cout << "___________ SORT _____________" << endl;             // Сортировка камушком, прописанная в ручную

	float t = clock();
	
	for (int i = v1.size(); i > 0; i--)              // внешний цикл сортировки
	{
		for (int j = 0; j < i-1; j++)        // внутренний цикл сортировки
		{
			if (v1.at(j) > v1.at(j+1))
			{
				int tmp = v1.at(j);
				v1.at(j) = v1.at(j+1);
				v1.at(j+1) = tmp;
			}
		}		
	}

	
	for (x = 0; x < v1.size(); x++)                      //Вывод отсортированного массива
		cout << v1.at(x) << " ";
	cout << endl;

	t = clock()-t;                                      //Вывод времени в сек., которое заняла программа. 
	cout << "time = " << t / CLOCKS_PER_SEC << " sec";
	_getch();
}