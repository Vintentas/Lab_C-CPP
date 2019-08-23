//������������ ������ STL �1-6 "�������"
//��������� �.�.
//�������: �������� ������� void fillRandom(double* array, int size) ����������� ������ ���������� ���������� � ��������� 
// �� -1.0 �� 1.0. ��������� � ������� �������� ������� ������� �������� 5,10,25,50,100 � ������������ ��� ���������� 
// (� ������� ������ �������������� ����� ��������� ����������������� ��� ���������� �������������� �����) 
//���, 22.02.2017 

#include "vector"
#include "algorithm"
#include "iostream"
#include "conio.h"
#include "stdlib.h"    //���������� ��� rand()

using namespace std;

void fillRandom(double* array, int size);
void sortirovka (double* array, int size);

void main(void)
{
	vector< double > v5(5), v10(10), v25(25), v50(50), v100(100);

	fillRandom(&v5.front(), 5);
	fillRandom(&v10.front(), 10);
	fillRandom(&v25.front(), 25);
	fillRandom(&v50.front(), 50);
	fillRandom(&v100.front(), 100);

	cout << endl << "___________ SORT _____________" << endl;       //����������

	sortirovka(&v5.front(), 5);
	sortirovka(&v10.front(), 10);
	sortirovka(&v25.front(), 25);
	sortirovka(&v50.front(), 50);
	sortirovka(&v100.front(), 100);
	
	_getch();
}

void fillRandom(double* array, int size)					    	 //�������, ������� ��������� ������ ������� �� -1 �� 1
{	
	int x;
	for (x = 0; x < size; x++) array[x] = (0.1*(rand() % 21-10));		//������ ������� �� c�������� �����
	cout << endl << "The vector of "<< size << " random numbers: ";
	for (x = 0; x < size; x++) cout <<array[x] << " ";    
	cout << endl;
}

void sortirovka(double* array, int size)							 //���������� ��������
{	
	int x,i,j;
	
	for (i = size; i > 0; i--)									     // ��������� ���������� ��������
	{
		for (j = 0; j < i - 1; j++)        
		{
			if (array[j] > array[j + 1])
			{
				double tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}

		cout << endl << "Sorted vector size of "<< size << " :" << endl;
	for (x = 0; x < size; x++) cout <<array[x] << " ";    //����� �������
	cout << endl;
}
