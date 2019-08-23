#pragma once
#include "vector"


class My_Snake
{
	int XY;								//����������� �����������: 0-�����, 1-������, 2-����, 3-�����															
	int My_speed;							//�������� ������, 1 - 3, 0 - ���� �� �����
	int My_game;							//����	0 - ������ �� ����������
										//		1 - ������ ����
										//		2 - ���� � ��������
										//		3 - ���� ���������
	
	CPen pen_color_black;				// ���� ���������
	CPen pen_color_red;
	CPen pen_color_blue;
	CPen pen_color_green;
	CPen pen_color_purple;
	CPen pen_color_cyan;
	CPen pen_color_yelloy;

	int Where_Food;						//��������: 1 - ��� �� ����, 0 - ��� ��� �� ����

public:
	CPen *My_Pen_Snake;
	CPoint Food;					//���������� ���
	std::vector <CPoint> coord;		//������, �������� ����� ������ ���� ������, ������ ������� ���������� ����� ������
	const int *const move = &XY;	//����������� ��������� �� ����������
	const int *const speed = &My_speed;
	const int *const game = &My_game;
	const int *const have_food = &Where_Food;

	My_Snake();
	~My_Snake();
	
	void New_snake(CPoint);			//�-��� ����� ������
	void Nothing();					//������ �� ����������
	void New_game();				//��������� ����� ����
	void Go_game();					//���� � ��������
	void Game_over();				//����� ����

	void Go_riglt();				//��������� �����������
	void Go_left();
	void Go_up();
	void Go_bottom();

	void color_black();				//��������� ����� ����
	void color_red();
	void color_blue();
	void color_green();
	void color_purple();
	void color_cyan();
	void color_yelloy();

	void set_speed(int);			//��������� �������� ����

	CPoint New_food(CPoint);		//��� �� ����
	void Eat_food();				//��� �������


};




