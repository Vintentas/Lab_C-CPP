//Лабораторная работа STL №1-1 "Вектора"
//Ситникова В.А.
//Задание: Напишите алгоритм сортировки(любой простейший) содержимого вектора целых чисел, используя operator[].
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

	for (x = 0; x < v1.capacity(); x++) v1[x]=rand()%100;   //Запись вектора из 10 случайных чисел от 0 до 99.
   	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < v1.size(); x++) cout << v1[x] << " ";   //Вывод вектора
	cout << endl;

	cout << "___________ SORT _____________" << endl;       //Сортировка функцией sort()
	
	float t = clock();
	sort(v1.begin(), v1.end());
	for (x = 0; x < v1.size(); x++)
		cout << v1[x] << " ";
	cout << endl;

	t = clock()-t;                                      //Вывод времени в сек., которое заняла сортировка. 
	cout << "time = " << t / CLOCKS_PER_SEC<< " sec";
	_getch();
}