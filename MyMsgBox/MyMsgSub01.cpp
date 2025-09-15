// MyMsgSub01.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub01.h"


// CMyMsgSub01 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyMsgSub01, CDialog)

CMyMsgSub01::CMyMsgSub01(CWnd* pParent /*=NULL*/, int nIDD)
	: CMyMsg(pParent, nIDD)
{
	m_pParent = pParent;
	m_hParentWnd = pParent->GetSafeHwnd();

}

CMyMsgSub01::~CMyMsgSub01()
{
}

void CMyMsgSub01::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyMsgSub01, CDialog)
	ON_BN_CLICKED(IDC_BTN_00, &CMyMsgSub01::OnBnClickedBtn00)
	ON_BN_CLICKED(IDC_BTN_01, &CMyMsgSub01::OnBnClickedBtn01)
END_MESSAGE_MAP()


// CMyMsgSub01 메시지 처리기입니다.


void CMyMsgSub01::OnBnClickedBtn00()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ClickYes();
}


void CMyMsgSub01::OnBnClickedBtn01()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ClickNo();
}

void CMyMsgSub01::ClickYes()
{
	SetRtnVal(IDYES);
	OnOK();
}

void CMyMsgSub01::ClickNo()
{
	SetRtnVal(IDNO);
	OnCancel();
}

BOOL CMyMsgSub01::OnInitDialog()
{
	CMyMsg::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_EDIT1)->SetWindowText(GetMsg());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
