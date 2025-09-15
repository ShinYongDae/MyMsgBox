#pragma once
#include "MyMsg.h"


// CMyMsgSub00 대화 상자입니다.

class CMyMsgSub00 : public CMyMsg
{
	DECLARE_DYNAMIC(CMyMsgSub00)

	CRect* m_pRect;
	HWND m_hParentWnd;
	CWnd* m_pParent;

public:
	CMyMsgSub00(CWnd* pParent = NULL, int nIDD = IDD);   // 표준 생성자입니다.
	virtual ~CMyMsgSub00();

// 대화 상자 데이터입니다.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_MSG_SUB00 };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
