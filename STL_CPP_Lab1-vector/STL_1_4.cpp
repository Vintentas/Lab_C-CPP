//������������ ������ STL �1-4 "�������"
//��������� �.�.
//�������: ���������� �� ���������� ������ � ���������� ���������� �����, ���������� ������ � ������ ����� ������� ���� 
// (��� ������ � ���������� STL)
//���, 22.02.2017 


#include "vector"
#include "iostream"
#include "conio.h"
#include "fstream"   //�������� ����-�����


using namespace std;

void main(void)
{
	
	char m1[50];
	int x;

	ifstream cin("String.txt");   // ������ �� �����
	
	cin.getline(m1, 50,'\n');			//��������� �� ����� ������ 50 ��������.
	
	vector< char > v1(m1, m1+20);
	for (x = 0; x < v1.size(); x++) cout << v1[x];   //����� �������
	cout << endl;
	cin.close();

	
	_getch();
}