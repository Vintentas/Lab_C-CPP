
// Snake.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSnakeApp:
// � ���������� ������� ������ ��. Snake.cpp
//

class CSnakeApp : public CWinApp
{
public:
	CSnakeApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSnakeApp theApp;