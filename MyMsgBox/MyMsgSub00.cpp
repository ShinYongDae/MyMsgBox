// MyMsgSub00.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub00.h"


// CMyMsgSub00 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyMsgSub00, CDialog)

CMyMsgSub00::CMyMsgSub00(CWnd* pParent /*=NULL*/, int nIDD)
	: CMyMsg(pParent, nIDD)
{
	m_pParent = pParent;
	m_hParentWnd = pParent->GetSafeHwnd();

}

CMyMsgSub00::~CMyMsgSub00()
{
}

void CMyMsgSub00::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyMsgSub00, CDialog)
END_MESSAGE_MAP()


// CMyMsgSub00 메시지 처리기입니다.
