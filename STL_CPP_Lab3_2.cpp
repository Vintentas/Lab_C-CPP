//������������ ������ STL �3-2 "List"
//��������� �.�.
//�������: ������������ ���������, �������	
//		a.��������� list<int> 15 ���������� ���������� �� 1 �� 20, ������ ����� ��������� �� 0 �� 20 ��������.
//		b.������� ���������� ������ � ��������� ������� : ������ �������, ��������� �������, ������ �������, ������������� �������, ������ ������� � �.�.
//			�������� ���� ������ ��������: 1 2 3 4 5 6 7 8
//			�� ����� ����� ����� ���: 1 8 2 7 3 6 4 5
//���, 04.03.2017 


#include <iostream>
#include <conio.h>
#include <list>
#include <stdlib.h>

using namespace std;

void main(void)
{
	list <int> list_int, list_dop;
	list <int>::iterator iter_end, iter;
	list <int>::reverse_iterator iter_end_r;
	int i;

// ������� ����� �� 15 ��������� � ������� ���������
	cout << endl << "___________ Push back _____________" << endl << endl;
	for (i = 0; i < 15; i++) list_int.push_back( rand() % 20 + 1);	
	for (iter = list_int.begin(); iter != list_int.end(); iter++) cout << *iter<<" ";    

// ��������� �������� � ������� �����������.
	cout << endl << endl << "___________ SORT 1 _____________" << endl << endl;
	list_int.sort();
	for (iter = list_int.begin(); iter != list_int.end(); iter++) cout << *iter << " ";

//��������� �������� 2�� ��� �� �������
	cout << endl << endl << "___________ SORT 2 _____________" << endl << endl;



		iter = list_int.begin();				// �������� �� ������ �������
		iter_end = list_int.end();				//�������� �� ��������� �������
		
		while ( iter!=iter_end )
		{
			iter_end--;
			cout << *iter << " ";		
			if (iter != iter_end)
			{
				cout << *iter_end << " ";
				iter++;
			}
			else break;
		}

	_getch();
}