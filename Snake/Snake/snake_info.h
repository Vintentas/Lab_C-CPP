#pragma once


// ���������� ���� snake_info

class snake_info : public CDialogEx
{
	DECLARE_DYNAMIC(snake_info)

public:
	snake_info(CWnd* pParent = NULL);   // ����������� �����������
	virtual ~snake_info();

// ������ ����������� ����
#ifdef AFX_DESIGN_TIME
	enum { IDD = MY_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedBitmap2();
};
