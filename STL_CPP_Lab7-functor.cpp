//������������ ������ STL �7 "Functor"
//��������� �.�.
/*�������:  ���������� ��������� ��������� �������:
1.	����������� �������, ����������� �������� ���������� � ������������������ ����� ����� (������ ����� ��������� ����� �� -500 �� 500). 
������� ����� ��������� ������������������ ���������� for_each ������ ������������� ��������� ����������:

a.	������������ ����� � ������������������
b.	����������� ����� � ������������������
c.	������� ����� � ������������������
d.	���������� ������������� �����
e.	���������� ������������� �����
f.	����� �������� ��������� ������������������
g.	����� ������ ��������� ������������������
h.	��������� �� ������ � ��������� �������� ������������������.

��������� ������ ��������� �� �������� ��������������� �������������������.
*/
//���, 18.03.2017 

#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>


using namespace std;

class Functor						//	�������
{	
	vector <int>:: iterator X, Y;
public:
	void operator () (vector < int > &A)
	{
		X=max_element(A.begin(), A.end());						// ������������ ��-�
		cout << "Max element = "  << *X << endl;

		Y = min_element(A.begin(), A.end());					// ����������� ��-�
		cout << "Min element = " << *Y << endl;

		float m = (*X+*Y)/2;									// ������� ��-�
		cout <<"average value = " << m << endl;

		int n=0;
		for (X = A.begin(); X != A.end(); X++) if (*X > 0) n++;	//���������� ������������� ���������
		cout << "kol. + elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X < 0) n++;	//���������� ������������� ���������
		cout << "kol. - elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X%2==0) n+=*X;	//����� ������ ���������
		cout << "sum even elements = " << n << endl;

		n = 0;
		for (X = A.begin(); X != A.end(); X++) if (*X!=0) n+=*X;	//����� �������� ���������
		cout << "sum not even elements = " << n << endl;

		X = A.begin();
		Y = A.end() - 1;

		cout <<"first = "<< *X << " ? " <<"last="<<*Y << endl;
		if (*X==*Y) cout << "Elements are equal" << n << endl;
		else if (*X > *Y) cout << "first > last" << n << endl;
		else cout << "first < last"  << endl;
	}
};


void main(void)
{
		vector< int > vect(10);
		int x;

	for (x = 0; x < vect.capacity(); x++) vect[x] = rand() % 1001-500;   //������ ������� �� 10 ��������� ����� �� 0 �� 99.
	cout << endl << "The vector of 10 random numbers: ";
	for (x = 0; x < vect.size(); x++) cout << vect[x] << " ";   //����� �������
	cout << endl;

	cout << "--------------------------------------------" << endl << endl;       

	Functor F;
	F (vect);


	_getch();
}
