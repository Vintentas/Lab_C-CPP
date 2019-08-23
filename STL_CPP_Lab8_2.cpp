//Лабораторная работа STL №8-2 "Functor"
//Ситникова В.А.
/*Задание:  Разработать программу, которая:

a.	Реализует иерархию геометрических фигур состоящую из:
	i.	Класс Shape. 
		1.	Содержит информацию о положении центра фигуры (координаты x и y).
		2.	Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее (определяется по положению центра) 
	чем фигура переданная в качестве аргумента
		3.	Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше (определяется по положению центра) 
	чем фигура переданная в качестве аргумента
		4.	Определяет чисто виртаульную функцию рисования Draw (каждая фигура в реализации этой функци должна выводить на стандартный вывод 
	свое название и положение цента)

	ii.	Класс Circle производный от класса Shape
		1.	Реализует Draw

	iii.	Класс Triangle производный от класса Shape
		1.	Реализует Draw

	iv.	Класс Square производный от класса Shape
		1.	Реализует Draw

b.	Содержит список list<Shape*>, заполенный указателями на различные фигуры

c.	С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры

d.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо (имется в виду, что в начале списка должны идти фигуры 
находящиеся левее, координата x ) и выводит фигуры (Draw)

e.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево и выводит фигуры

f.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз и выводит фигуры

g.	С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх и выводит фигуры
*/
//СПб, 18.03.2017 

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include <functional>
#include <list>

using namespace std;




//	класс - фигура, родительский
class Shape							
{
public:
	int x, y;						//координаты центра
	string name;
	
	Shape(): x(0), y(0) {}
	Shape(string m) : x(0), y(0), name(m) {}
	Shape(int a, int b): x(a), y(b) {}
	Shape(int a, int b, string m) : x(a), y(b), name(m) {}
	~Shape() {}

	bool IsMoreLeft(Shape S)			// расположена ли данная фигура левее, чем аргумент
	{
		bool i=0;
		if (x > S.x) i = 1;
		return i;
	}	
	
	bool IsUpper(Shape S)				// расположена ли данная фигура выше, чем аргумент
	{
		bool i = 0;
		if (y > S.y) i = 1;
		return i;
	}
	
	void Draw()							//вывод
	{
		cout << name << " x="<< x << ", y=" << y << endl;
	}
};

//	класс - круг
class Circle: public Shape
{
public:
	Circle() : Shape("Circle") {}
	Circle(int a, int b) : Shape(a, b, "Circle") {}
	~Circle() {}
};


//	класс - триугольник
class Triangle : public Shape
{
public:
	Triangle() : Shape("Triangle") {}
	Triangle(int a, int b) : Shape(a, b, "Triangle") {}
	~Triangle() {}
};


//	класс - квадрат
class Square : public Shape
{
public:
	Square() : Shape("Square") {}
	Square(int a, int b) : Shape(a, b, "Square") {}
	~Square() {}
};




void Sort_L_R(list <Shape*> figure)	//сортирует список по положению центра слева - направо и выводит фигуры
{
	list <Shape*>::iterator it_1;					//Итер. на первый эл-т
	list <Shape*>::iterator it_2;					
	list <Shape*>::iterator it_end= figure.end();	//итератор на следующий за последним эл-т
	
	it_end--;										//итератор на последний эл-т
	while (it_end!= figure.begin())
	{
											
		for (it_1 = figure.begin(); it_1 != it_end; it_1++)
		{
			it_2 = it_1;							//Итер. на первый эл-т
			it_2++;								//итерратор на второй эл-т
			//if ((**it_1).x > (**it_2).x)
			if ((**it_1).IsMoreLeft(**it_2) == 1)
			{
				Shape A = (**it_1);
				(**it_1) = (**it_2);
				(**it_2) = A;
			}
		}	
		it_end--;
	}
	for (it_1 = figure.begin(); it_1 != figure.end(); it_1++)	(**it_1).Draw();
}



void Sort_R_L(list <Shape*> figure)	//сортирует список по положению центра справа - налево и выводит фигуры
{
	list <Shape*>::iterator it_1;					
	list <Shape*>::iterator it_2;
	list <Shape*>::iterator it_end = figure.end();	

	it_end--;										
	while (it_end != figure.begin())
	{

		for (it_1 = figure.begin(); it_1 != it_end; it_1++)
		{
			it_2 = it_1;							
			it_2++;								
			//if ((**it_1).x < (**it_2).x)
			if ((**it_1).IsMoreLeft(**it_2)==0)
			{
				Shape A = (**it_1);
				(**it_1) = (**it_2);
				(**it_2) = A;
			}
		}
		it_end--;
	}
	for (it_1 = figure.begin(); it_1 != figure.end(); it_1++)	(**it_1).Draw();
}



void Sort_T_B(list <Shape*> figure)	//сортирует список по положению центра сверху - вниз и выводит фигуры
{
	list <Shape*>::iterator it_1;
	list <Shape*>::iterator it_2;
	list <Shape*>::iterator it_end = figure.end();

	it_end--;
	while (it_end != figure.begin())
	{

		for (it_1 = figure.begin(); it_1 != it_end; it_1++)
		{
			it_2 = it_1;
			it_2++;
			//if ((**it_1).y > (**it_2).y)
			if ((**it_1).IsUpper(**it_2) == 0)
			{
				Shape A = (**it_1);
				(**it_1) = (**it_2);
				(**it_2) = A;
			}
		}
		it_end--;
	}
	for (it_1 = figure.begin(); it_1 != figure.end(); it_1++)	(**it_1).Draw();
}



void Sort_B_T(list <Shape*> figure)	//сортирует список по положению центра снизу - вверх и выводит фигуры
{
	list <Shape*>::iterator it_1;
	list <Shape*>::iterator it_2;
	list <Shape*>::iterator it_end = figure.end();

	it_end--;
	while (it_end != figure.begin())
	{

		for (it_1 = figure.begin(); it_1 != it_end; it_1++)
		{
			it_2 = it_1;
			it_2++;
			if ((**it_1).IsUpper(**it_2) == 1)
			//if ((**it_1).y < (**it_2).y)
			{
				Shape A = (**it_1);
				(**it_1) = (**it_2);
				(**it_2) = A;
			}
		}
		it_end--;
	}
	for (it_1 = figure.begin(); it_1 != figure.end(); it_1++)	(**it_1).Draw();
}






void main(void)
{
	list <Shape*> figure;
	list <Shape*>:: iterator it;

	//создает и выводит фигуры.
	Circle C1, C2(10,20), C3 (7,14);
	Triangle T1(13, 8), T2 (7,-7), T3;
	Square S1(-13,18), S2(-11, 8), S3(-9,-12);

	figure.push_back(&C1); figure.push_back(&T1); figure.push_back(&S1);
	figure.push_back(&C2); figure.push_back(&T2); figure.push_back(&S2);
	figure.push_back(&C3); figure.push_back(&T3); figure.push_back(&S3);

	//Вывод
	cout << "------------Output of all figures------------" << endl << endl;
	for (it = figure.begin(); it!=figure.end(); it++)	(**it).Draw();
	
	//Сортировки через функции
	cout << "-------------from left to right-------------" << endl;
	Sort_L_R(figure);
	cout << "-------------from right to left-------------" << endl;
	Sort_R_L(figure);	
	cout << "-------------From top to bottom-------------" << endl;
	Sort_T_B(figure);	
	cout << "-------------From bottom to top-------------" << endl;
	Sort_B_T(figure);

	_getch();
}
