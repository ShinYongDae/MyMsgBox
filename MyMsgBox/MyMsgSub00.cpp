// MyMsgSub00.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub00.h"


// CMyMsgSub00 ��ȭ �����Դϴ�.

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


// CMyMsgSub00 �޽��� ó�����Դϴ�.
