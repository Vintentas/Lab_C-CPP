//Лабораторная работа STL №7 "Functor"
//Ситникова В.А.
/*Задание:  Необходимо выполнить следующее задание:
1.	Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500). 
Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:

a.	Максимальное число в последовательности
b.	Минимальное число в последовательности
c.	Среднее число в последовательности
d.	Количество положительных чисел
e.	Количество отрицательных чисел
f.	Сумму нечетных элементов последовательности
g.	Сумму четных элементов последовательности
h.	Совпадают ли первый и последний элементы последовательности.

Проверить работу программы на случайно сгенерированных последовательностях.
*/
//СПб, 18.03.2017 

#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>


using namespace std;

class Functor						//	Функтор
{	
	vector <int>:: iterator X, Y;
public:
	void operator () (vector < int > &A)
	{
		X=max_element(A.begin(), A.end());						// Максимальный эл-т
		cout << "Max element = "  << *X << endl;

		Y = min_element(A.begin(), A.end());					// Минимальный эл-т
		cout << "Min element = " << *Y << endl;

		float m = (*X+*Y)/2;									// Средний эл-т
		cout <<"average value = " << m << endl;

		int n=0;
		for (X = A.begin(); X != A.end(); X++) if (*X > 0) n++;	//Количество положительных элементов
		cout << "kol. + elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X < 0) n++;	//Количество отрицательных элементов
		cout << "kol. - elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X%2==0) n+=*X;	//Сумма четных элементов
		cout << "sum even elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X!=0) n+=*X;	//Сумма нечетных элементов
		cout << "sum not even elements = " << n << endl;

		X = A.begin();
		Y = A.end() - 1;

		cout <<"first = "<< *X << " ? " <<"last="<<*Y << endl;
		if (*X==*Y) cout << "Elements are equal" << n << endl;
		else if (*X > *Y) cout << "first > last" << n << endl;
		else cout << "first < last"  << endl;
	}
};


void main(void)
{
		vector< int > vect(10);
		int x;

	for (x = 0; x < vect.capacity(); x++) vect[x] = rand() % 1001-500;   //Запись вектора из 10 случайных чисел от 0 до 99.
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //Вывод вектора
	cout << endl;

	cout << "--------------------------------------------" << endl << endl;       

	Functor F;
	F (vect);


	_getch();
}
