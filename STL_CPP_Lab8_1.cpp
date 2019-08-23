//������������ ������ STL �8-1 "Functor"
//��������� �.�.
//�������:  ����������� ���������, �������, ��������� ������ ����������� ��������� � ��������, �������� ������ ������� ������ 
//����� � ���������  ������ �� ����� PI.
//���, 18.03.2017 

#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>


using namespace std;

class Functor						//	�������, ���������� �� ��
{
	int x;
	const float Pi = 3.14159;
public:
	void operator () (vector < float> &A)
	{
		for (x = 0; x < A.size(); x++) A[x] *= Pi;
	}
};


void main(void)
{
	vector< float > vect(10);
	int x;

	for (x = 0; x < vect.capacity(); x++) vect[x] = ((rand() % 1000)*0.01);   //������ ������� �� 10 ��������� �����.
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //����� �������
	cout << endl;

	cout << "---------------------Multiplication by Pi-----------------------" << endl << endl;      

	Functor F;
	F(vect);
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //����� �������
	cout << endl;

	_getch();
}
