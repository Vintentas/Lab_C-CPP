//������������ ������ STL �6-2 "Algorithm"
//��������� �.�.
/*�������: �������� ���������, ������� ��������� ��������� �������� (��� �������� ������ ����������� � ������� ����������� ����������):

a.	��������� ������ ��������������� ��������. �������������� ������ ����� ���� �������������, ���������, ��������������� ��� ���� ����������. 
��������� ����������� �������������� ������  ���������� ����,
b.	������������ ����� ���������� ������ ���� ����� ������������ � ������� (��� ����������� ��������� � ������ ����� 3, ������� 4 � �.�.)
c.	������������ ���������� �������������, ��������� � ��������������� � �������
d.	������� ��� �������������
e.	�� ��������� ����� ������� ������� vector<Point>, ������� �������� ���������� ����� �� ������ (�����) ������ ������, �.�. ������ ������� 
����� ������� �������� ���������� ����� �� ������� ������ ������, ������ ������� ����� ������� �������� ���������� ����� �� ������� ������ ������ � �.�.
f.	�������� ������ ���, ����� �� �������� � ������ ��� ������������, ����� ��� ��������, � ����� ��������������.
g.	������������� ������ ����� ������� ����� ������
*/
//���, 04.03.2017 

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
	int vertex_num;				// ���������� ������, ��� ������������ 3, ��� �������� � �������������� 4, ��� ���� ��������� 5.
	vector <Point> vertexes;		// ������ ���������� ���������� ������ ������. 
} Shape;


Shape NewShape(int a)				// ����-��� ��� �������� ������
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

Shape NewSquare()				// ����-��� ��� �������� ��������
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
	
	//���������� �������
	// 1. �����������
	MyShape.push_back(NewShape(3));
	// 2. �������������
	MyShape.push_back(NewShape(4));
	// 3. ������������
	MyShape.push_back(NewShape(5));
	// 4. �������
	MyShape.push_back(NewSquare());
	// 5. ������������
	MyShape.push_back(NewShape(5));
	// 6. �������
	MyShape.push_back(NewSquare());
	// 7. �����������
	MyShape.push_back(NewShape(3));
	// 8. �����������
	MyShape.push_back(NewShape(3));
	// 9. �������������
	MyShape.push_back(NewShape(4));
	
	//����� ������� 1
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


	//������� ���-�� ������
	cout << endl << "--------------Sum of vertices--------------" << endl << endl;	
	kol = 0;
	for (int i = 0; i < MyShape.size(); i++) kol += MyShape[i].vertex_num;
	cout << "Sum of vertices=" << kol << endl;

	
	//������� ���-�� �������������, ��������� � ��������������
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

	
	//������� �������������
	for (int i = 0; i < MyShape.size(); i++) if (MyShape[i].vertex_num==5) MyShape.erase(MyShape.begin()+i);
	
	//����� ������� 2
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

	//�������� ������ �� ������ ������
	cout << endl << "--------------New shapes from vertices--------------" << endl << endl;

	vector<Point> BigPoint;
	for (int i = 0; i < MyShape.size(); i++) BigPoint.push_back(MyShape[i].vertexes[0]);
	for (int i = 0; i < BigPoint.size(); i++) cout << 'x' << i << '=' << BigPoint[i].x << " y" << i << '=' << BigPoint[i].y << ", ";
	cout << endl;


	//��������� ������� � ������������ � ��������� ��������
	
	vector <Shape> Sss;

	// ������������
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
	
	//��������������
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

	//��������
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