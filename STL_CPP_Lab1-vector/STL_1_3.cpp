
//Лабораторная работа STL №1-3 "Вектора"
//Ситникова В.А.
//Задание: Напишите алгоритм сортировки(любой простейший) содержимого вектора целых чисел, используя для доступа к содержимому 
//вектора только итераторы. Для работы с итераторами допустимо использовать только операторы получения текущего элемента 
//и перехода в следующему(подсказка, можно сохранять копию итератора указывающего на некоторый элемент)
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
	//int x;
	vector<int>::iterator iter, i, j;

	for (iter = v1.begin(); iter != v1.end(); iter++) *iter = rand() % 100;   // Запись вектора из 10 случайных чисел от 0 до 99
	cout << endl << "The vector of 10 random numbers: ";
	for (iter = v1.begin(); iter != v1.end(); iter++) cout << *iter << " ";      // Вывод вектора
	cout << endl;

	cout << "___________ SORT _____________" << endl;             // Сортировка камушком, прописанная в ручную

																  //sort(v1.begin(), v1.end());
	float t = clock();
	for (i = v1.end(); i > v1.begin(); i--)              // внешний цикл сортировки
	{
		for (j = v1.begin(); j < i - 1; j++)        // внутренний цикл сортировки
		{
			if (*j > *(j + 1))
			{
				int tmp = *(j);
				*(j) = *(j + 1);
				*(j + 1) = tmp;
			}
		}
	}

	for (iter = v1.begin(); iter != v1.end(); iter++) cout << *iter << " ";      //Вывод отсортированного массива
	cout << endl;

	t = clock()-t;                                      //Вывод времени в сек., которое заняла программа. 
	cout << "time = " << t / CLOCKS_PER_SEC << " sec";
	_getch();
}