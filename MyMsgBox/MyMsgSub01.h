#pragma once
#include "MyMsg.h"


// CMyMsgSub01 ��ȭ �����Դϴ�.

class CMyMsgSub01 : public CMyMsg
{
	DECLARE_DYNAMIC(CMyMsgSub01)

	CRect* m_pRect;
	HWND m_hParentWnd;
	CWnd* m_pParent;

	void ClickYes();
	void ClickNo();

public:
	CMyMsgSub01(CWnd* pParent = NULL, int nIDD = IDD);   // ǥ�� �������Դϴ�.
	virtual ~CMyMsgSub01();

// ��ȭ ���� �������Դϴ�.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_MSG_SUB01 };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtn00();
	afx_msg void OnBnClickedBtn01();
	virtual BOOL OnInitDialog();
};
