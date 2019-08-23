
// SnakeDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Snake.h"
#include "SnakeDlg.h"
#include "afxdialogex.h"

#include "snake_info.h"
#include "My_Snake.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
public:

//	afx_msg void OnDestroy();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)


//	ON_WM_DESTROY()
END_MESSAGE_MAP()


// ���������� ���� CSnakeDlg



CSnakeDlg::CSnakeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SNAKE_DIALOG, pParent)
	, _point(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);				//������ ������ ���������� �� ����.
}

void CSnakeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CSnakeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(my_exet, &CSnakeDlg::OnBnClickedexet)
	ON_BN_CLICKED(my_new_game, &CSnakeDlg::OnBnClickednewgame)
	ON_COMMAND(my_1_1, &CSnakeDlg::OnMy11)
	ON_COMMAND(my_1_2, &CSnakeDlg::OnMy12)
	ON_COMMAND(my_2_2_1, &CSnakeDlg::OnMy221)
	ON_COMMAND(my_2_2_2, &CSnakeDlg::OnMy222)
	ON_COMMAND(my_2_2_3, &CSnakeDlg::OnMy223)
	ON_COMMAND(my_2_2_4, &CSnakeDlg::OnMy224)
	ON_COMMAND(my_2_2_5, &CSnakeDlg::OnMy225)
	ON_COMMAND(my_2_2_6, &CSnakeDlg::OnMy226)
	ON_COMMAND(my_2_2_7, &CSnakeDlg::OnMy227)
	ON_COMMAND(my_2_3_1, &CSnakeDlg::OnMy231)
	ON_COMMAND(my_2_3_2, &CSnakeDlg::OnMy232)
	ON_COMMAND(my_2_3_3, &CSnakeDlg::OnMy233)
	ON_COMMAND(my_3_1, &CSnakeDlg::OnMy31)
	ON_COMMAND(my_3_2, &CSnakeDlg::OnMy32)

	ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_KEYDOWN()
END_MESSAGE_MAP()


// ����������� ��������� CSnakeDlg

BOOL CSnakeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();									 //----��������� �������

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// ��TODO: �������� �������������� �������������
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	
	//---------------------------������� ����------------------------//
	//------------�������������� ���������� �������� ����------------//
	
	CWnd * uk_my_game_field = GetDlgItem(my_field);
	uk_my_game_field->GetWindowRect(&my_game_field);
	ScreenToClient(&my_game_field);
	my_game_field.DeflateRect(10,10,10,10);
	

	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CSnakeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSnakeDlg::OnPaint()			//������� ��������������� ����
{
	CPaintDC dc(this);	// �������� �������� ����������
	
	////�����
	//CPoint A;
	//CPen New_pen(PS_SOLID, 1, RGB(0, 200, 200));
	//dc.SelectObject(New_pen);
	//for (int i = my_game_field.TopLeft().x; i < my_game_field.BottomRight().x; i+=10)
	//{
	//	A.x = i;
	//	A.y = my_game_field.TopLeft().y;
	//	dc.MoveTo(A);
	//	A.y = my_game_field.BottomRight().y;
	//	dc.LineTo(A);
	//}
	//for (int i = my_game_field.TopLeft().y; i < my_game_field.BottomRight().y; i += 10)
	//{
	//	A.y = i;
	//	A.x = my_game_field.TopLeft().x;
	//	dc.MoveTo(A);
	//	A.x = my_game_field.BottomRight().x;
	//	dc.LineTo(A);
	//}

	//CPen New_pen2(PS_SOLID, 1, RGB(200, 0, 200));
	//dc.SelectObject(New_pen2);

	//A = my_game_field.CenterPoint();
	//A.x = my_game_field.TopLeft().x;
	//dc.MoveTo(A);
	//A.x = my_game_field.BottomRight().x;
	//dc.LineTo(A);

	//A = my_game_field.CenterPoint();
	//A.y = my_game_field.TopLeft().y;
	//dc.MoveTo(A);
	//A.y = my_game_field.BottomRight().y;
	//dc.LineTo(A);





	if (*Snake.game == 1)						//�������� ����� ����
	{
		dc.SelectObject(Snake.My_Pen_Snake);			//���� ����
		Snake.New_snake(my_game_field.CenterPoint());	//���������� ���� �� �����������
		for (int i = 0; i < Snake.coord.size(); dc.MoveTo(Snake.coord[i]), dc.LineTo(Snake.coord[i]), i++);
		Snake.Go_game();

	}
	
	else if (*Snake.game == 2)					//��������������� � �������� ����
	{
		//������ ����
		dc.SelectObject(Snake.My_Pen_Snake);
		for (int i = 0; i < Snake.coord.size(); dc.MoveTo(Snake.coord[i]), dc.LineTo(Snake.coord[i]), i++);

		//������ ���
		CPen New_pen(PS_SOLID, 7, RGB(0, 0, 0));
		dc.SelectObject(New_pen);
		
		if (*Snake.have_food == 0)			//�������� ������� ��� �� ����
		{
			CPoint B = my_game_field.TopLeft();
			int X = rand() % 32;
			int Y = rand() % 40;
			B.x += X * 10;
			B.y += Y * 10;
			dc.MoveTo(Snake.New_food(B));
			dc.LineTo(B);
		}
		else
		{
			dc.MoveTo(Snake.Food);
			dc.LineTo(Snake.Food);
		}
	}
	else if (*Snake.game == 3)					//����� ����
	{
		CString S;
		S.Format("�� ������� %d �����", _point);

		dc.TextOut(150, 200, "GAME OVER");
		dc.TextOut(125, 230, S);
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSnakeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSnakeDlg::OnBnClickedexet()				//������ - �����
{
	
	
	int iResults;
	iResults = MessageBox("�� �������, ��� ������ �����?",
		"�����?",
		MB_YESNO + MB_ICONQUESTION);

	if (iResults == IDYES)
	{
		OnOK();
	}
}


void CSnakeDlg::OnBnClickednewgame()			//������ - ����� ����
{
	_point = 0;
	Snake.New_game();
	Snake.Eat_food();
	set_timer_game();
	Invalidate();

}


void CSnakeDlg::OnMy11()			//����� ����
	{ OnBnClickednewgame(); }


void CSnakeDlg::OnMy12()			//�����
	{ OnBnClickedexet(); }


void CSnakeDlg::OnMy221()			//���� ������
{ 
	Snake.color_black();
	Invalidate();
}


void CSnakeDlg::OnMy222()			//���� �����
	{ 
	Snake.color_blue();
    Invalidate();
    }


void CSnakeDlg::OnMy223()			//���� �������
{
	Snake.color_red();
	Invalidate();
}


void CSnakeDlg::OnMy224()			//���� �������
{
	Snake.color_green();
	Invalidate();
}


void CSnakeDlg::OnMy225()			//���� ���������
{ 
	Snake.color_purple(); 
	Invalidate();
}


void CSnakeDlg::OnMy226()			//���� �������
{
	Snake.color_cyan(); 
	Invalidate();
}


void CSnakeDlg::OnMy227()			//���� ������
{
	Snake.color_yelloy(); 
	Invalidate();
}


void CSnakeDlg::OnMy231()			//�������� 1
{
	Snake.set_speed(1);
	if (*Snake.game == 2) set_timer_game();
}


void CSnakeDlg::OnMy232()			//�������� 2
{
	Snake.set_speed(2);
	if (*Snake.game == 2) set_timer_game();
}


void CSnakeDlg::OnMy233()			//�������� 3
{ 
	Snake.set_speed(3);
	if (*Snake.game == 2) set_timer_game();
}



void CSnakeDlg::OnMy31()			//���������� � ����
	{ S_info.DoModal(); }


void CSnakeDlg::OnMy32()			//���������� � ���������	
{	//������� ������ ������ CAboutDlg
	CAboutDlg dlg;	
	//������� ���������� ������ About
	dlg.DoModal();
}


void CSnakeDlg::Snake_take_food()	//�������� - ����� �� ���� ���
{
	CPoint A;

	for (int i = Snake.coord[0].x-5; i < Snake.coord[0].x + 5; i++)
	{
		for (int j = Snake.coord[0].y - 5; j < Snake.coord[0].y + 5; j++)
		{
			A.x = i; A.y = j;
			if (Snake.Food == A)
			{
				Snake.coord.push_back(Snake.coord.back());
				Snake.Eat_food();
				
				switch (*Snake.speed)
				{
				case 1:
					_point += 10;
					break;
				case 2:
					_point += 50;
					break;
				case 3:
					_point += 100;
					break;
				}
								
				break;
			}
		}
	}
}


void CSnakeDlg::Snake_take_snake()	//�������� - ����� �� ���� ���� - ����� ����
{
	CPoint A;
	for (int k = 1; k < Snake.coord.size(); k++)
	{		
		for (int i = Snake.coord[0].x - 5; i < Snake.coord[0].x + 5; i++)
		{
			for (int j = Snake.coord[0].y - 5; j < Snake.coord[0].y + 5; j++)
			{
				A.x = i; A.y = j;
				if (Snake.coord[0] == Snake.coord[k])
				{
					Snake.Game_over();
					KillTimer(1);
					break;
				}
			}
		}
	}
}

void CSnakeDlg::set_timer_game()	//�������� ������� ��������
{

	if (InstallTimer == TRUE)
	{
		KillTimer(1);
	}

	if (*Snake.speed == 1)
	{
		InstallTimer = SetTimer(1, 100, NULL);
	}

	else if (*Snake.speed == 2)
	{ 
		InstallTimer = SetTimer(1, 60, NULL);
	}

	else
	{
		InstallTimer = SetTimer(1, 20, NULL);
	}
}


void CSnakeDlg::OnTimer(UINT_PTR nIDEvent)		
{
	
	switch (*Snake.move)				//������������ ����
	{
	case 0:	//�������� �����
		{
		CPoint B(0, -10);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
			{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
			}
		else
			{
			B = my_game_field.BottomRight();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].y = B.y-1;
			}
		break;
		}

	case 1:	//�������� ������
		{
		CPoint B(10, 0);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			B = my_game_field.TopLeft();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].x = B.x;
		}
		break;
		}
		
	case 2:	//�������� ����
		{
		CPoint B(0, 10);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			B = my_game_field.TopLeft();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].y = B.y;
		}
		break;
		}
		
	case 3:	//�������� �����
		{
		CPoint B(-10, 0);
		CPoint A = Snake.coord[0] + B;
		if (my_game_field.PtInRect(A))
		{
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0] = Snake.coord[1] + B;
		}
		else
		{
			CPoint B = my_game_field.BottomRight();
			for (int i = (int)Snake.coord.size() - 1; i > 0; Snake.coord[i] = Snake.coord[i - 1], i--);
			Snake.coord[0].x = B.x-1;
		}
		break;
		}
	}
	
	Snake_take_food();		//�������� ���
	Snake_take_snake();		//�������� ����� ����

	Invalidate();
	CDialogEx::OnTimer(nIDEvent);
}



void CSnakeDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	KillTimer(1);
	// TODO: �������� ���� ��� ����������� ���������
}


BOOL CSnakeDlg::PreTranslateMessage(MSG* pMsg)				//������ OnKeyDown - ���������� ����
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RIGHT:
			if (*Snake.move != 3)
				Snake.Go_riglt();
			break;
		case VK_DOWN:
			if (*Snake.move != 0)
				Snake.Go_bottom();
			break;
		case VK_LEFT:
			if (*Snake.move != 1)
				Snake.Go_left();
			break;
		case VK_UP:
			if (*Snake.move != 2)
				Snake.Go_up();
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}

