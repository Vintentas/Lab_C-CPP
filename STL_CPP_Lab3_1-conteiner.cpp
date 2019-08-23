//������������ ������ STL �3-1 "Class"
//��������� �.�.
//�������: ����������� �����, ��������� list ��� deque.��������� ���� �����. 
//		   ������������� ���������, �������� ���������� �����, ������������, ���  ����� �������� ���������.

//		� ������� ����� ���� ��������� ��������, ������� �������� ��� ���������� ������������� ���� �� ���� ������� ����������(low, normal, high)
//�������� �� ������� ����������� � ������������ � �� ������������(������� ����������� �������� � ����������� high, ����� normal, ����� low), 
//		�������� � ����������� ������������ ����������� �� ������� � ������� �� �����������.
//		� ������� ����� ����� ����������� �������� ����������� � ��� �������� � ����������� low ����������� � ������ ����������� � ������� ����������� 
//���� ��������� �� high � ��������� �������� � ����������� normal.
//
//���, 04.03.2017 


#include <deque>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// ������������ �����������
typedef enum                           
{	LOW,
	NORMAL,
	HIGH
} ElementPriority;

// ���������, ������������ �������
typedef struct
{	string name;				
} QueueElement;


//����� ������� � ������������, ����������
class QueueWithPriority
{
	deque <QueueElement> elem_1, elem_2, elem_3; // 3 ������� � ������� ������������.
		
public:
	// �����������, ������� ������ �������
	QueueWithPriority() {}

	// ����������
	~QueueWithPriority() {}

	// �������� � ������� ������� element � ����������� priority
	void PutElementToQueue(const QueueElement& element, ElementPriority priority)
	{
		switch (priority)
		{
		case LOW:							//���������� ������� � ������ �����������
			{elem_3.push_back(element);
			break; }
	
		case NORMAL:						//���������� ������� �� ������� �����������
			{elem_2.push_back(element);
			break; }

		case HIGH:							//���������� ������� � ������� �����������
			{elem_1.push_back(element);
			break; }
		
		default: break;
		}
	}

	// �������� ������� �� �������
	// ����� ������ ���������� ������� � ���������� �����������, ������� ���
	// �������� � ������� ������ ������
	QueueElement GetElementFromQueue()
	{
		QueueElement el;
		if (elem_1.empty() == 1)
		{
			if (elem_2.empty() == 1)
			{
				if (elem_3.empty() == 1) cout << "No elements in the queue." << endl;
				else el=elem_3[0];
			}
			else el= elem_2[0];	
		}
		else el= elem_1[0];
		return el;
	}

	// ��������� �����������
	void Accelerate()
	{
		if (elem_3.empty() == 0) 
		{
			for (int i = 0; i != elem_3.size(); i++) elem_1.push_back(elem_3[i]);
			elem_3.clear();
		}
	}

	// ����� ���� ��������� ��� ��������
	void GetElementAll()
	{
		if (elem_1.empty() == 1 && elem_2.empty() == 1 && elem_3.empty() == 1) cout << "No elements in the queue." << endl;
		else 
		{
			cout << "elements HIGH: " << endl;
			if (elem_1.empty() == 0) for (int i = 0; i != elem_1.size(); i++) cout << elem_1[i].name << endl;

			cout << endl << "elements NORMAL: " << endl;
			if (elem_2.empty() == 0) for (int i = 0; i != elem_2.size(); i++) cout << elem_2[i].name << endl;

			cout << endl << "elements LOW: " << endl;
			if (elem_3.empty() == 0) for (int i = 0; i != elem_3.size(); i++) cout << elem_3[i].name << endl;
		}		
	}
};

void main(void)
{
	QueueWithPriority my_deque;
	QueueElement str;

	//����� ���� ���������
	cout << "The presence of elements in the queue." << endl;
	my_deque.GetElementAll();
	
	//���������� ���� � ����� �� ����������
	cout << "--------------------------------------" << endl;
	cout << endl << "Elements output by priority:" << endl;

	str.name = "number1";
	my_deque.PutElementToQueue(str, LOW);
	cout << "Enter: 'number1', LOW" << endl;
	cout << "Priority: " << my_deque.GetElementFromQueue().name << endl << endl;

	str.name = "number2";
	my_deque.PutElementToQueue(str, NORMAL);
	cout << "Enter: 'number2', NORMAL" << endl;
	cout << "Priority: " << my_deque.GetElementFromQueue().name << endl << endl;

	str.name = "number3";
	my_deque.PutElementToQueue(str, HIGH);
	cout << "Enter: 'number3', HIGH" << endl;
	cout << "Priority: " << my_deque.GetElementFromQueue().name << endl << endl;

	str.name = "number4";
	my_deque.PutElementToQueue(str, HIGH);
	cout << "Enter: 'number4', HIGH" << endl;
	cout << "Priority: " << my_deque.GetElementFromQueue().name << endl << endl;

	str.name = "number5";
	my_deque.PutElementToQueue(str, LOW);
	cout << "Enter: 'number5', LOW" << endl;
	cout << "Priority: " << my_deque.GetElementFromQueue().name << endl << endl;

	//����� ���� ���������
	cout << "--------------------------------------" << endl;
	cout << "The presence of elements in the queue." << endl;
	my_deque.GetElementAll();

	//�����������. ����� ���� ���������
	my_deque.Accelerate();
	cout << "--------------------------------------" << endl;
	cout << "The presence of elements after acceleration in the queue." << endl;
	my_deque.GetElementAll();


	
	


	_getch();
}


