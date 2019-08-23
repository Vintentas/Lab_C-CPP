//������������ ������ STL �1-5 "�������"
//��������� �.�.
//�������: �������� ���������, ����������� � ������� �����, ���������� �� ������������ ����� (���������� ����� �������� ����� 0).
//������� ��� ��������, ������� ������� �� 2 (�� ����������� ����������� ��������� STL), ���� ��������� ����� 1. 
//���� ��������� ����� 2, �������� ����� ������� ����� ������� ������� �� 3 ��� �������.
//���, 22.02.2017 


#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"


using namespace std;

void main(void)
{
	vector< int > v1(100);
	int x, a, y;   // x - ���-�� ��������� � �������
				   // �, y - ��������� �����������

				   // ������ ������� �� ������ �� ������� ������������ 0.
	cout << "Enter integer numbers. The program considers the number to the first \"0\"." << endl;
	cin >> a;
	for (x = 0; (x < v1.capacity() && a != 0); x++)
	{
		v1[x] = a;
		cin >> a;
	}

	cout << endl << "The enter vector: " << endl;                //����� ����������� �������.
	for (y = 0; y < x; y++) cout << v1[y] << " ";
	//cout << fixed << setprecision(1) << v1[y] << " ";
	cout << endl;

	cout << "-----------------------------------------" << endl;

	if (v1[x - 1] == 1)											//���� ��������� ������� = 1, ������� ��� ������ ��������
	{
		for (y = 0; y < x; y++)
		{
			if (v1[y] % 2 == 0)
			{
				v1.erase(v1.begin() + y);
				x--;
			}
		}
		cout << "Last element=1. Deleted if // 2" << endl;
	}

	else if (v1[x - 1] == 2)									//���� ��������� ������� = 2, ��������� 3 � ������� �����, ������� ������� �� 3
	{
		for (y = 0; y < x; y++)
		{
			if (v1[y] % 3 == 0) v1[y] = v1[y]*1000+111;
		}
		cout << "Last element=2. Add +3 if // 3" << endl;
	}

	else cout << "No changes!" << endl;				//����� �� ���������� ������� ���������.

	cout << endl << "The modified vector: " << endl;                //����� ����������������� ������� �������.
	for (y = 0; y < x; y++) cout << v1[y] << " ";
	cout << endl;

	_getch();
}