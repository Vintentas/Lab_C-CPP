//Лабораторная работа STL №8-1 "Functor"
//Ситникова В.А.
//Задание:  Разработать программу, которая, используя только стандартные алгоритмы и функторы, умножает каждый элемент списка 
//чисел с плавающей  точкой на число PI.
//СПб, 18.03.2017 

#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>


using namespace std;

class Functor						//	Функтор, умножающий на пи
{
	int x;
	const float Pi = 3.14159;
public:
	void operator () (vector < float> &A)
	{
		for (x = 0; x < A.size(); x++) A[x] *= Pi;
	}
};


void main(void)
{
	vector< float > vect(10);
	int x;

	for (x = 0; x < vect.capacity(); x++) vect[x] = ((rand() % 1000)*0.01);   //Запись вектора из 10 случайных чисел.
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //Вывод вектора
	cout << endl;

	cout << "---------------------Multiplication by Pi-----------------------" << endl << endl;      

	Functor F;
	F(vect);
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //Вывод вектора
	cout << endl;

	_getch();
}
