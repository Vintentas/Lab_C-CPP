#pragma once


// ���������� ���� snake_options

class snake_options : public CDialogEx
{
	DECLARE_DYNAMIC(snake_options)

public:
	snake_options(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~snake_options();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = MY_OPTIONS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
};
