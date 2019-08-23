
// SnakeDlg.h : ���� ���������
//

#include "snake_info.h"
#include "My_Snake.h"

#include "vector"

#pragma once


// ���������� ���� CSnakeDlg
class CSnakeDlg : public CDialogEx
{
// ��������
public:
	CSnakeDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNAKE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	
public:
	afx_msg void OnBnClickedexet();
	afx_msg void OnBnClickednewgame();
	afx_msg void OnMy11();
	afx_msg void OnMy12();
	afx_msg void OnMy221();
	afx_msg void OnMy222();
	afx_msg void OnMy223();
	afx_msg void OnMy224();
	afx_msg void OnMy225();
	afx_msg void OnMy226();
	afx_msg void OnMy227();
	afx_msg void OnMy231();
	afx_msg void OnMy232();
	afx_msg void OnMy233();
	afx_msg void OnMy31();
	afx_msg void OnMy32();

	void set_timer_game();			//�-��� ������� �������
	void Snake_take_food();			//�-��� �������� - ����� �� ���� ���
	void Snake_take_snake();			//�-��� �������� - ����� �� ���� ����

	int _point;						//���� ������� �����
	snake_info S_info;				//����� ���� ����������
	CRect my_game_field;			//���������� �������� ����
	My_Snake Snake;					//����� ��� ������ �� �����
	int InstallTimer;				//���������� �������� ��������� �������

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	afx_msg BOOL PreTranslateMessage(MSG* pMsg);
};
