//Лабораторная работа STL №3-2 "List"
//Ситникова В.А.
//Задание: Разработайте программу, которая	
//		a.Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений.
//		b.Выводит содержимое списка в следующем порядке : первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.
//			Например если список содержит: 1 2 3 4 5 6 7 8
//			то вывод будет иметь вид: 1 8 2 7 3 6 4 5
//СПб, 04.03.2017 


#include <iostream>
#include <conio.h>
#include <list>
#include <stdlib.h>

using namespace std;

void main(void)
{
	list <int> list_int, list_dop;
	list <int>::iterator iter_end, iter;
	list <int>::reverse_iterator iter_end_r;
	int i;

// Создаем спиок из 15 элементов и выводим результат
	cout << endl << "___________ Push back _____________" << endl << endl;
	for (i = 0; i < 15; i++) list_int.push_back( rand() % 20 + 1);	
	for (iter = list_int.begin(); iter != list_int.end(); iter++) cout << *iter<<" ";    

// Сортируем элементы в порядке возрастания.
	cout << endl << endl << "___________ SORT 1 _____________" << endl << endl;
	list_int.sort();
	for (iter = list_int.begin(); iter != list_int.end(); iter++) cout << *iter << " ";

//Сортируем элементы 2ой раз по заданию
	cout << endl << endl << "___________ SORT 2 _____________" << endl << endl;



		iter = list_int.begin();				// итератор на первый элемент
		iter_end = list_int.end();				//итератор на последний элемент
		
		while ( iter!=iter_end )
		{
			iter_end--;
			cout << *iter << " ";		
			if (iter != iter_end)
			{
				cout << *iter_end << " ";
				iter++;
			}
			else break;
		}

	_getch();
}