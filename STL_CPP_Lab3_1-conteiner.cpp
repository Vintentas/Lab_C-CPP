//Лабораторная работа STL №3-1 "Class"
//Ситникова В.А.
//Задание: Реолизовать класс, используя list или deque.Объяснить свой выбор. 
//		   Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.

//		В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета(low, normal, high)
//элементы из очереди извлекаются в соответствии с их приоритетами(сначала извлекаются элементы с приоритетом high, потом normal, потом low), 
//		элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления.
//		В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают 
//свой приоритет до high и «обгоняют» элементы с приоритетом normal.
//
//СПб, 04.03.2017 


#include <deque>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

using namespace std;

// перечисление приоритетов
typedef enum                           
{	LOW,
	NORMAL,
	HIGH
} ElementPriority;

// Структура, определяющая элемент
typedef struct
{	string name;				
} QueueElement;


//Класс очереди с приоритетами, реолизация
class QueueWithPriority
{
	deque <QueueElement> elem_1, elem_2, elem_3; // 3 очереди с разными приоритерами.
		
public:
	// Конструктор, создает пустую очередь
	QueueWithPriority() {}

	// Деструктор
	~QueueWithPriority() {}

	// Добавить в очередь элемент element с приоритетом priority
	void PutElementToQueue(const QueueElement& element, ElementPriority priority)
	{
		switch (priority)
		{
		case LOW:							//заполнение очереди с низким приоритетом
			{elem_3.push_back(element);
			break; }
	
		case NORMAL:						//заполнение очереди со средним приоритетои
			{elem_2.push_back(element);
			break; }

		case HIGH:							//заполнение очереди с высоким приоритетом
			{elem_1.push_back(element);
			break; }
		
		default: break;
		}
	}

	// Получить элемент из очереди
	// метод должен возвращать элемент с наибольшим приоритетом, который был
	// добавлен в очередь раньше других
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

	// Выполнить акселерацию
	void Accelerate()
	{
		if (elem_3.empty() == 0) 
		{
			for (int i = 0; i != elem_3.size(); i++) elem_1.push_back(elem_3[i]);
			elem_3.clear();
		}
	}

	// Вывод всех элементов для проверки
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

	//Вывод всех элементов
	cout << "The presence of elements in the queue." << endl;
	my_deque.GetElementAll();
	
	//Заполнение деки и вывод по приоритеру
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

	//Вывод всех элементов
	cout << "--------------------------------------" << endl;
	cout << "The presence of elements in the queue." << endl;
	my_deque.GetElementAll();

	//Акселирация. Вывод всех элементов
	my_deque.Accelerate();
	cout << "--------------------------------------" << endl;
	cout << "The presence of elements after acceleration in the queue." << endl;
	my_deque.GetElementAll();


	
	


	_getch();
}


