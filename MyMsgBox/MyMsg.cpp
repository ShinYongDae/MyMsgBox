// MyMsg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsg.h"

#include "MyMsgSub00.h"
#include "MyMsgSub01.h"
#include "MyMsgSub02.h"


// CMyMsg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyMsg, CDialog)

CMyMsg::CMyMsg(CWnd* pParent /*=NULL*/, int nIDD)
	: CDialog(nIDD, pParent)
{
	m_pParent = pParent;
	m_hParentWnd = pParent->GetSafeHwnd();
	
	m_pMyMsg = NULL;
	m_pMyMsgSub01 = NULL;
	m_pMyMsgSub02 = NULL;
}

CMyMsg::~CMyMsg()
{
	if (m_pMyMsg)
	{
		delete m_pMyMsg;
		m_pMyMsg = NULL;
	}

	if (m_arMyMsg.GetSize() > 0)
		m_arMyMsg.RemoveAll();
}

void CMyMsg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyMsg, CDialog)
	ON_MESSAGE(WM_MYMSG_EXIT, OnMyMsgExit)
END_MESSAGE_MAP()


// CMyMsg 메시지 처리기입니다.


BOOL CMyMsg::Create()
{
	return CDialog::Create(CMyMsg::IDD);
}

LRESULT CMyMsg::OnMyMsgExit(WPARAM wPara, LPARAM lPara)
{
	if (m_pMyMsg)
	{
		if (m_pMyMsg->IsWindowVisible())
			m_pMyMsg->ShowWindow(SW_HIDE);
	}

	return 0L;
}

int CMyMsg::SyncMsgBox(CString sMsg, int nIdx, int nType, int nTimOut)
{
	int nRtnVal = -1; // Reply(-1) is None.
	CMyMsg*		pMyMsg = NULL;
	CMyMsgSub00* pMyMsgSub00 = NULL;
	CMyMsgSub01* pMyMsgSub01 = NULL;
	CMyMsgSub02* pMyMsgSub02 = NULL;

	if (MB_TIME_OUT == nType)
	{
		if (m_pMyMsg)
		{
			m_pMyMsg->SetMsg(sMsg, nIdx, nType, nTimOut);
			if (!m_pMyMsg->IsWindowVisible())
				m_pMyMsg->ShowWindow(SW_SHOW);
			m_pMyMsg->RedrawWindow();
		}
		else
		{
			m_pMyMsg = new CMyMsgSub00(this);

			m_pMyMsg->SetMsg(sMsg, nIdx, nType, nTimOut);
			m_pMyMsg->Create();
			if (!m_pMyMsg->IsWindowVisible())
				m_pMyMsg->ShowWindow(SW_SHOW);
			m_pMyMsg->RedrawWindow();
		}

		return nRtnVal;
	}
	else if (MB_YESNO == nType)
	{
		pMyMsgSub01 = new CMyMsgSub01(this);
		pMyMsg = (CMyMsg*)pMyMsgSub01;
		m_pMyMsgSub01 = pMyMsgSub01;
	}
	else if (MB_OK == nType)
	{
		pMyMsgSub02 = new CMyMsgSub02(this);
		pMyMsg = (CMyMsg*)pMyMsgSub02;
		m_pMyMsgSub02 = pMyMsgSub02;
	}

	//stMyMsg stData(sMsg, nIdx, nType, nTimOut);
	//m_arMyMsgSync.Add(stData);

	pMyMsg->SetMsg(sMsg, nIdx, nType, nTimOut);
	pMyMsg->DoModal();

	nRtnVal = pMyMsg->GetRtnVal(nIdx);

	delete pMyMsg;
	pMyMsg = NULL;
	m_pMyMsgSub01 = NULL;
	m_pMyMsgSub02 = NULL;

	//int nCount = m_arMyMsgSync.GetSize();
	//if (nCount > 0)
	//	m_arMyMsgSync.RemoveAt(nCount - 1);

	::PostMessage(m_hParentWnd, WM_MYMSG_EXIT, (WPARAM)NULL, (LPARAM)NULL);

	return nRtnVal;
}

CString CMyMsg::GetMsg()
{
	int nCount = m_arMyMsg.GetSize();
	if (nCount <= 0)
		return _T("");

	stMyMsg stDispMsg;
	stDispMsg = m_arMyMsg.GetAt(0);
	CString sMsg = stDispMsg.strMsg;

	return sMsg;
}

void CMyMsg::SetMsg(CString strMsg, int nIdx, int nType, int nTimeOut)
{
	CString sLocalMsg = strMsg;
	int nLocalThreadIdx = nIdx;
	int nLocalType = nType;
	int nLocalTimeOut = nTimeOut;

	stMyMsg stData(sLocalMsg, nLocalThreadIdx, nLocalType, nLocalTimeOut);
	m_arMyMsg.Add(stData);
}

void CMyMsg::SetRtnVal(int nVal)
{
	m_arMyMsgRtn.Add(nVal);
}

int CMyMsg::GetRtnVal(int nIdx)
{
	int i = 0;
	int nRtn = -1;
	int nCount = m_arMyMsgRtn.GetSize();
	if (nCount > 0)
	{
		stMyMsg stDispMsg;
		for (i = 0; i < nCount; i++)
		{
			stDispMsg = m_arMyMsg.GetAt(i);
			CString sMsg = stDispMsg.strMsg;
			int MsgIdx = stDispMsg.nIdx;
			if (nIdx == MsgIdx)
			{
				nRtn = m_arMyMsgRtn.GetAt(i);
				m_arMyMsgRtn.RemoveAt(i);
				break;
			}
		}
	}

	return nRtn; // m_nRtnVal;
}
