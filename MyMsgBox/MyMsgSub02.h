#pragma once
#include "MyMsg.h"


// CMyMsgSub02 ��ȭ �����Դϴ�.

class CMyMsgSub02 : public CMyMsg
{
	DECLARE_DYNAMIC(CMyMsgSub02)

	CRect* m_pRect;
	HWND m_hParentWnd;
	CWnd* m_pParent;

	void ClickOk();

public:
	CMyMsgSub02(CWnd* pParent = NULL, int nIDD = IDD);   // ǥ�� �������Դϴ�.
	virtual ~CMyMsgSub02();

// ��ȭ ���� �������Դϴ�.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_MSG_SUB02 };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn00();
	virtual BOOL OnInitDialog();
};
