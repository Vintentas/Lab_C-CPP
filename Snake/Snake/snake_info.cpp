// snake_info.cpp: ���� ����������
//

#include "stdafx.h"
#include "Snake.h"
#include "snake_info.h"
#include "afxdialogex.h"


// ���������� ���� snake_info

IMPLEMENT_DYNAMIC(snake_info, CDialogEx)

snake_info::snake_info(CWnd* pParent /*=NULL*/)
	: CDialogEx(MY_INFO, pParent)
{

}

snake_info::~snake_info()
{
}

void snake_info::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(snake_info, CDialogEx)

END_MESSAGE_MAP()


// ����������� ��������� snake_info


void snake_info::OnStnClickedBitmap2()
{
	// TODO: �������� ���� ��� ����������� �����������
}
