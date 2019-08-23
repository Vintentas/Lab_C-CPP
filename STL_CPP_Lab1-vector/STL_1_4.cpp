//Лабораторная работа STL №1-4 "Вектора"
//Ситникова В.А.
//Задание: Прочитайте во встроенный массив С содержимое текстового файлы, скопируйте данные в вектор одной строкой кода 
// (без циклов и алгоритмов STL)
//СПб, 22.02.2017 


#include "vector"
#include "iostream"
#include "conio.h"
#include "fstream"   //файловый ввод-вывод


using namespace std;

void main(void)
{
	
	char m1[50];
	int x;

	ifstream cin("String.txt");   // чтение из файла
	
	cin.getline(m1, 50,'\n');			//прочитать из файла первые 50 символов.
	
	vector< char > v1(m1, m1+20);
	for (x = 0; x < v1.size(); x++) cout << v1[x];   //Вывод вектора
	cout << endl;
	cin.close();

	
	_getch();
}