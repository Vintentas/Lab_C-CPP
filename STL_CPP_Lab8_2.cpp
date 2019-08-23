//������������ ������ STL �8-2 "Functor"
//��������� �.�.
/*�������:  ����������� ���������, �������:

a.	��������� �������� �������������� ����� ��������� ��:
	i.	����� Shape. 
		1.	�������� ���������� � ��������� ������ ������ (���������� x � y).
		2.	�������� ����� IsMoreLeft, ����������� ���������� ����������� �� ������ ������ ����� (������������ �� ��������� ������) 
	��� ������ ���������� � �������� ���������
		3.	�������� ����� IsUpper, ����������� ���������� ����������� �� ������ ������ ���� (������������ �� ��������� ������) 
	��� ������ ���������� � �������� ���������
		4.	���������� ����� ����������� ������� ��������� Draw (������ ������ � ���������� ���� ������ ������ �������� �� ����������� ����� 
	���� �������� � ��������� �����)

	ii.	����� Circle ����������� �� ������ Shape
		1.	��������� Draw

	iii.	����� Triangle ����������� �� ������ Shape
		1.	��������� Draw

	iv.	����� Square ����������� �� ������ Shape
		1.	��������� Draw

b.	�������� ������ list<Shape*>, ���������� ����������� �� ��������� ������

c.	� ������� ����������� ���������� � ��������� ������� (Draw) ��� ������

d.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ �����-������� (������ � ����, ��� � ������ ������ ������ ���� ������ 
����������� �����, ���������� x ) � ������� ������ (Draw)

e.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ ������-������ � ������� ������

f.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ ������-���� � ������� ������

g.	� ������� ����������� ���������� � ��������� ��������� ������ �� ��������� ������ �����-����� � ������� ������
*/
//���, 18.03.2017 

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>
#include <functional>
#include <list>

using namespace std;




//	����� - ������, ������������
class Shape							
{
public:
	int x, y;						//���������� ������
	string name;
	
	Shape(): x(0), y(0) {}
	Shape(string m) : x(0), y(0), name(m) {}
	Shape(int a, int b): x(a), y(b) {}
	Shape(int a, int b, string m) : x(a), y(b), name(m) {}
	~Shape() {}

	bool IsMoreLeft(Shape S)			// ����������� �� ������ ������ �����, ��� ��������
	{
		bool i=0;
		if (x > S.x) i = 1;
		return i;
	}	
	
	bool IsUpper(Shape S)				// ����������� �� ������ ������ ����, ��� ��������
	{
		bool i = 0;
		if (y > S.y) i = 1;
		return i;
	}
	
	void Draw()							//�����
	{
		cout << name << " x="<< x << ", y=" << y << endl;
	}
};

//	����� - ����
class Circle: public Shape
{
public:
	Circle() : Shape("Circle") {}
	Circle(int a, int b) : Shape(a, b, "Circle") {}
	~Circle() {}
};


//	����� - �����������
class Triangle : public Shape
{
public:
	Triangle() : Shape("Triangle") {}
	Triangle(int a, int b) : Shape(a, b, "Triangle") {}
	~Triangle() {}
};


//	����� - �������
class Square : public Shape
{
public:
	Square() : Shape("Square") {}
	Square(int a, int b) : Shape(a, b, "Square") {}
	~Square() {}
};




void Sort_L_R(list <Shape*> figure)	//��������� ������ �� ��������� ������ ����� - ������� � ������� ������
{
	list <Shape*>::iterator it_1;					//����. �� ������ ��-�
	list <Shape*>::iterator it_2;					
	list <Shape*>::iterator it_end= figure.end();	//�������� �� ��������� �� ��������� ��-�
	
	it_end--;										//�������� �� ��������� ��-�
	while (it_end!= figure.begin())
	{
											
		for (it_1 = figure.begin(); it_1 != it_end; it_1++)
		{
			it_2 = it_1;							//����. �� ������ ��-�
			it_2++;								//��������� �� ������ ��-�
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



void Sort_R_L(list <Shape*> figure)	//��������� ������ �� ��������� ������ ������ - ������ � ������� ������
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



void Sort_T_B(list <Shape*> figure)	//��������� ������ �� ��������� ������ ������ - ���� � ������� ������
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



void Sort_B_T(list <Shape*> figure)	//��������� ������ �� ��������� ������ ����� - ����� � ������� ������
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

	//������� � ������� ������.
	Circle C1, C2(10,20), C3 (7,14);
	Triangle T1(13, 8), T2 (7,-7), T3;
	Square S1(-13,18), S2(-11, 8), S3(-9,-12);

	figure.push_back(&C1); figure.push_back(&T1); figure.push_back(&S1);
	figure.push_back(&C2); figure.push_back(&T2); figure.push_back(&S2);
	figure.push_back(&C3); figure.push_back(&T3); figure.push_back(&S3);

	//�����
	cout << "------------Output of all figures------------" << endl << endl;
	for (it = figure.begin(); it!=figure.end(); it++)	(**it).Draw();
	
	//���������� ����� �������
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
