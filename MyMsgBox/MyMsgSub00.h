#pragma once
#include "MyMsg.h"


// CMyMsgSub00 ��ȭ �����Դϴ�.

class CMyMsgSub00 : public CMyMsg
{
	DECLARE_DYNAMIC(CMyMsgSub00)

	CRect* m_pRect;
	HWND m_hParentWnd;
	CWnd* m_pParent;

public:
	CMyMsgSub00(CWnd* pParent = NULL, int nIDD = IDD);   // ǥ�� �������Դϴ�.
	virtual ~CMyMsgSub00();

// ��ȭ ���� �������Դϴ�.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_MSG_SUB00 };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
