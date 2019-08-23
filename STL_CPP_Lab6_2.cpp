//Лабораторная работа STL №6-2 "Algorithm"
//Ситникова В.А.
/*Задание: Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью стандартных алгоритмов):

a.	Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пяти угольником. 
Структура описывающая геометрическую фигуру  определена ниже,
b.	Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
c.	Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
d.	Удаляет все пятиугольники
e.	На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент 
этого вектора содержит координаты одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
f.	Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
g.	Распечатывает вектор после каждого этапа работы
*/
//СПб, 04.03.2017 

#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"
#include "stdlib.h" 

using namespace std;

typedef struct
{
	int x, y;
} Point;

typedef  struct
{
	int vertex_num;				// количество вершин, для треугольника 3, для квадрата и прямоугольника 4, для пяти угольника 5.
	vector <Point> vertexes;		// вектор содержащий координаты вершин фигуры. 
} Shape;


Shape NewShape(int a)				// Функ-ция для создания фигуры
{
	Shape New;
	Point coord;
	New.vertex_num = a;
	for (int i = 0; i < a; i++)
	{
		coord.x = rand() % 100;
		coord.y = rand() % 100;
		New.vertexes.push_back(coord);
	}
	return New;
}

Shape NewSquare()				// Функ-ция для создания квадрата
{
	Shape New;
	Point coord;
	New.vertex_num = 4;
	int a = 10;

	coord.x = rand() % 100; 
	coord.y = rand() % 100;
		New.vertexes.push_back(coord);
	coord.x += a;	
		New.vertexes.push_back(coord);
	coord.y += a;
		New.vertexes.push_back(coord);
	coord.x -= a;	
		New.vertexes.push_back(coord);
	return New;
}




void main(void)
{
	vector <Shape> MyShape;
	int kol = 0;
	
	//Заполнение вектора
	// 1. треугольник
	MyShape.push_back(NewShape(3));
	// 2. прямоугольник
	MyShape.push_back(NewShape(4));
	// 3. Пятиугольник
	MyShape.push_back(NewShape(5));
	// 4. Квадрат
	MyShape.push_back(NewSquare());
	// 5. Пятиугольник
	MyShape.push_back(NewShape(5));
	// 6. Квадрат
	MyShape.push_back(NewSquare());
	// 7. треугольник
	MyShape.push_back(NewShape(3));
	// 8. треугольник
	MyShape.push_back(NewShape(3));
	// 9. прямоугольник
	MyShape.push_back(NewShape(4));
	
	//Вывод вектора 1
	cout << "--------------New shapes--------------" << endl << endl;
	for (int i = 0; i <  MyShape.size(); i++)
	{
		cout << i + 1 << ". ";
		switch (MyShape[i].vertex_num)
		{
		case 3: cout << "Triangle:\t"; break;
		case 4: cout << "Rectangle or Square:\t"; break;
		case 5: cout << "Pentagon:\t"; break;		
		default: break;
		}
		cout << endl;
		for (int j = 0; j < MyShape[i].vertex_num; j++) cout <<'x'<<j<<'=' <<MyShape[i].vertexes[j].x << " y" << j << '=' << MyShape[i].vertexes[j].y << ", ";
		cout << endl;
	}


	//Подсчет кол-ва вершин
	cout << endl << "--------------Sum of vertices--------------" << endl << endl;	
	kol = 0;
	for (int i = 0; i < MyShape.size(); i++) kol += MyShape[i].vertex_num;
	cout << "Sum of vertices=" << kol << endl;

	
	//Подсчет кол-ва треугольников, квадратов и пятиугольников
	cout << endl << "--------------Sum of shape--------------" << endl << endl;
	kol = 0;
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 3) kol ++;
	cout << "Sum of Triangle=" << kol << endl;
	kol = 0;
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 4) kol++;
	cout << "Sum of Rectangle=" << kol << endl;
	kol = 0;
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 5) kol++;
	cout << "Sum of Pentagon=" << kol << endl;

	
	//Удаляем пятиугольники
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num==5) MyShape.erase(MyShape.begin()+i);
	
	//Вывод вектора 2
	cout << "--------------New shapes--------------" << endl << endl;
	for (int i = 0; i < MyShape.size(); i++)
	{
		cout << i + 1 << ". ";
		switch (MyShape[i].vertex_num)
		{
		case 3: cout << "Triangle:\t"; break;
		case 4: cout << "Rectangle or Square:\t"; break;
		case 5: cout << "Pentagon:\t"; break;
		default: break;
		}
		cout << endl;
		for (int j = 0; j < MyShape[i].vertex_num; j++) cout << 'x' << j << '=' << MyShape[i].vertexes[j].x << " y" << j << '=' << MyShape[i].vertexes[j].y << ", ";
		cout << endl;
	}

	//Создание фигуры из первых вершин
	cout << endl << "--------------New shapes from vertices--------------" << endl << endl;

	vector<Point> BigPoint;
	for (int i = 0; i < MyShape.size(); i++) BigPoint.push_back(MyShape[i].vertexes[0]);
	for (int i = 0; i < BigPoint.size(); i++) cout << 'x' << i << '=' << BigPoint[i].x << " y" << i << '=' << BigPoint[i].y << ", ";
	cout << endl;


	//Изменение вектора в соответствии с последним заданием
	
	vector <Shape> Sss;

	// Треугольники
	cout << endl << "--------------New vector of triangle--------------" << endl << endl;
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 3) Sss.push_back(MyShape[i]);
	
	for (int i = 0; i < Sss.size(); i++)
	{
		cout << i + 1 << ". ";
		switch (Sss[i].vertex_num)
		{
		case 3: cout << "Triangle:\t"; break;
		case 4: cout << "Rectangle or Square:\t"; break;
		case 5: cout << "Pentagon:\t"; break;
		default: break;
		}
		cout << endl;
		for (int j = 0; j < Sss[i].vertex_num; j++) cout << 'x' << j << '=' << Sss[i].vertexes[j].x << " y" << j << '=' << Sss[i].vertexes[j].y << ", ";
		cout << endl;
	}	
	Sss.clear();
	
	//Прямоугольники
	cout << endl << "--------------New vector of rectangle--------------" << endl << endl;
	
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 4) Sss.push_back(MyShape[i]);

	for (int i = 0; i < Sss.size(); i++)
	{
		cout << i + 1 << ". ";
		switch (Sss[i].vertex_num)
		{
		case 3: cout << "Triangle:\t"; break;
		case 4: cout << "Rectangle or Square:\t"; break;
		case 5: cout << "Pentagon:\t"; break;
		default: break;
		}
		cout << endl;
		for (int j = 0; j < Sss[i].vertex_num; j++) cout << 'x' << j << '=' << Sss[i].vertexes[j].x << " y" << j << '=' << Sss[i].vertexes[j].y << ", ";
		cout << endl;
	}
	Sss.clear();

	Sss.clear();

	//Квадраты
	cout << endl << "--------------New vector of squares--------------" << endl << endl;
	
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num == 4 && ((MyShape[i].vertexes[1].x - MyShape[i].vertexes[0].x)== (MyShape[i].vertexes[3].y - MyShape[i].vertexes[0].y))) Sss.push_back(MyShape[i]);

	for (int i = 0; i < Sss.size(); i++)
	{
		cout << i + 1 << ". ";
		switch (Sss[i].vertex_num)
		{
		case 3: cout << "Triangle:\t"; break;
		case 4: cout << "Rectangle or Square:\t"; break;
		case 5: cout << "Pentagon:\t"; break;
		default: break;
		}
		cout << endl;
		for (int j = 0; j < Sss[i].vertex_num; j++) cout << 'x' << j << '=' << Sss[i].vertexes[j].x << " y" << j << '=' << Sss[i].vertexes[j].y << ", ";
		cout << endl;
	}
	Sss.clear();
	

	_getch();
}