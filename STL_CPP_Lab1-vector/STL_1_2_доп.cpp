//������������ ������ STL �1-2 "�������"
//��������� �.�.
//�������: �������� �������� ���������� (����� ����������) ����������� ������� ����� �����, ��������� ����� at() � � ��������� �����������.
//���, 22.02.2017 

//#include "stdafx.h"
#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"
#include "stdlib.h"    //���������� ��� rand()
#include "time.h"      //���������� ��� cloc()

using namespace std;

void main(void)
{
	vector< int > v1(10);
	int x;

	for (x = 0; x < v1.capacity(); x++) v1.at(x) = rand() % 100;   // ������ ������� �� 10 ��������� ����� �� 0 �� 99
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < v1.size(); x++) cout << v1.at(x) << " ";      // ����� �������
	cout << endl;

	cout << "___________ SORT _____________" << endl;             // ���������� ��������, ����������� � ������

	float t = clock();
	
	for (int i = v1.size(); i > 0; i--)              // ������� ���� ����������
	{
		for (int j = 0; j < i-1; j++)        // ���������� ���� ����������
		{
			if (v1.at(j) > v1.at(j+1))
			{
				int tmp = v1.at(j);
				v1.at(j) = v1.at(j+1);
				v1.at(j+1) = tmp;
			}
		}		
	}

	
	for (x = 0; x < v1.size(); x++)                      //����� ���������������� �������
		cout << v1.at(x) << " ";
	cout << endl;

	t = clock()-t;                                      //����� ������� � ���., ������� ������ ���������. 
	cout << "time = " << t / CLOCKS_PER_SEC << " sec";
	_getch();
}