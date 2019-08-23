
//������������ ������ STL �1-3 "�������"
//��������� �.�.
//�������: �������� �������� ����������(����� ����������) ����������� ������� ����� �����, ��������� ��� ������� � ����������� 
//������� ������ ���������. ��� ������ � ����������� ��������� ������������ ������ ��������� ��������� �������� �������� 
//� �������� � ����������(���������, ����� ��������� ����� ��������� ������������ �� ��������� �������)
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
	//int x;
	vector<int>::iterator iter, i, j;

	for (iter = v1.begin(); iter != v1.end(); iter++) *iter = rand() % 100;   // ������ ������� �� 10 ��������� ����� �� 0 �� 99
	cout << endl << "The vector of 10 random numbers: ";
	for (iter = v1.begin(); iter != v1.end(); iter++) cout << *iter << " ";      // ����� �������
	cout << endl;

	cout << "___________ SORT _____________" << endl;             // ���������� ��������, ����������� � ������

																  //sort(v1.begin(), v1.end());
	float t = clock();
	for (i = v1.end(); i > v1.begin(); i--)              // ������� ���� ����������
	{
		for (j = v1.begin(); j < i - 1; j++)        // ���������� ���� ����������
		{
			if (*j > *(j + 1))
			{
				int tmp = *(j);
				*(j) = *(j + 1);
				*(j + 1) = tmp;
			}
		}
	}

	for (iter = v1.begin(); iter != v1.end(); iter++) cout << *iter << " ";      //����� ���������������� �������
	cout << endl;

	t = clock()-t;                                      //����� ������� � ���., ������� ������ ���������. 
	cout << "time = " << t / CLOCKS_PER_SEC << " sec";
	_getch();
}