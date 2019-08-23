//������������ ������ STL �5 "Algorithm"
//��������� �.�.
/*�������:  �������� ���������, ������� ��������� ��������� �������� :

		a.��������� vector<DataStruct> ����������� DataStruct, ��� ���� key1 � key2, ������������ ��������� ������� � ��������� �� - 5 �� 5, 
	str ����������� �� �������(������� �������� 10 ������������ �����, ������ ������ ������������ ��������� �������)
		b.������� ���������� ������ �� ������
		c.��������� ������ ��������� ������� :
			i.�� ����������� key1
			ii.���� key1 ����������, �� �� ����������� key2
			iii.���� key1 � key2 ����������, �� �� ����������� ������ ������ str
		d.������� ���������� ������ �� ������

DataStruct ���������� ��������� ������� :
typedef struct
{
	int       key1;
	int       key2;
	string  str;
} DataStruct;
*/
//���, 04.03.2017 


#include "string"
#include <vector>
#include <iostream>
#include <conio.h>
#include <algorithm>

#define Kol_vo 30						// ��������� ���-�� ��������� � �������

using namespace std;

typedef struct
{
	int     key1;
	int     key2;
	string	str;
} DataStruct;

typedef struct							// ��������� - ������� ��� ���������� DataStruct.str
{
	string	str_0=("AAAAA");
	string	str_1 = ("BB");
	string	str_2 = ("CCCCCCC");
	string	str_3 = ("DDDDD");
	string	str_4 = ("EEEEEEE");
	string	str_5 = ("FFFF");
	string	str_6 = ("GGGGG");
	string	str_7 = ("HHH");
	string	str_8 = ("II");
	string	str_9 = ("JJJJ");
} TableString;

void My_Swap(DataStruct* A, DataStruct* B)			// ������� ������
{
	DataStruct DStr = *A;
	*A = *B;
	*B = DStr;
}

void main(void)
{
	vector <DataStruct> VectorString;
	int i, j;

	//���������� �������
	for (i = 0; i < Kol_vo; i++)
	{
		DataStruct DStr;
		TableString TabStr;
		int namber;

		DStr.key1 = (rand() % 11 - 5);
		DStr.key2 = (rand() % 11 - 5);
		namber = (rand() % 10);
		switch (namber)
		{
		case 0: DStr.str = TabStr.str_0; break;
		case 1: DStr.str = TabStr.str_1; break;
		case 2: DStr.str = TabStr.str_2; break;
		case 3: DStr.str = TabStr.str_3; break;
		case 4: DStr.str = TabStr.str_4; break;
		case 5: DStr.str = TabStr.str_5; break;
		case 6: DStr.str = TabStr.str_6; break;
		case 7: DStr.str = TabStr.str_7; break;
		case 8: DStr.str = TabStr.str_8; break;
		case 9: DStr.str = TabStr.str_9; break;		
		default: break;
		}		
		VectorString.push_back(DStr);
	}

	cout << "--------------Output--------------" << endl << endl;
	//����� �������
	for (i = 0; i < VectorString.size(); i++)					
	{
		cout << i+1 << ".\tkey1=" << VectorString[i].key1 << "\tkey2=" << VectorString[i].key2 << "\tstr=" << VectorString[i].str<<endl;
	}

	//����������
	for (i = VectorString.size(); i >0; i--) // ������� ���� ����������
	{
		for (j = 0; j < i - 1; j++)        // ���������� ���� ����������
		{
			if (VectorString[j].key1 > VectorString[j+1].key1)
				My_Swap(&VectorString[j], &VectorString[j+1]);			// �����
	
			if ((VectorString[j].key1 == VectorString[j + 1].key1)&& (VectorString[j].key2 > VectorString[j + 1].key2))
				My_Swap(&VectorString[j], &VectorString[j + 1]);					
				
			if ((VectorString[j].key1 == VectorString[j + 1].key1) && (VectorString[j].key2 == VectorString[j + 1].key2) && (VectorString[j].str > VectorString[j + 1].str))
				My_Swap(&VectorString[j], &VectorString[j + 1]);	
		}
	}


	cout << endl << "--------------Output after sorting--------------" << endl << endl;
	//����� �������
	for (i = 0; i < VectorString.size(); i++)
	{
		cout << i + 1 << ".\tkey1=" << VectorString[i].key1 << "\tkey2=" << VectorString[i].key2 << "\tstr=" << VectorString[i].str << endl;
	}

	_getch();
}