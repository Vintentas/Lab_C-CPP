//������������ ������ STL �1-1 "�������"
//��������� �.�.
//�������: �������� �������� ����������(����� ����������) ����������� ������� ����� �����, ��������� operator[].
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

	for (x = 0; x < v1.capacity(); x++) v1[x]=rand()%100;   //������ ������� �� 10 ��������� ����� �� 0 �� 99.
   	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < v1.size(); x++) cout << v1[x] << " ";   //����� �������
	cout << endl;

	cout << "___________ SORT _____________" << endl;       //���������� �������� sort()
	
	float t = clock();
	sort(v1.begin(), v1.end());
	for (x = 0; x < v1.size(); x++)
		cout << v1[x] << " ";
	cout << endl;

	t = clock()-t;                                      //����� ������� � ���., ������� ������ ����������. 
	cout << "time = " << t / CLOCKS_PER_SEC<< " sec";
	_getch();
}