// MyMsgSub02.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub02.h"


// CMyMsgSub02 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyMsgSub02, CDialog)

CMyMsgSub02::CMyMsgSub02(CWnd* pParent /*=NULL*/, int nIDD)
	: CMyMsg(pParent, nIDD)
{
	m_pParent = pParent;
	m_hParentWnd = pParent->GetSafeHwnd();
}

CMyMsgSub02::~CMyMsgSub02()
{
}

void CMyMsgSub02::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyMsgSub02, CDialog)
	ON_BN_CLICKED(IDC_BTN_00, &CMyMsgSub02::OnBnClickedBtn00)
END_MESSAGE_MAP()


// CMyMsgSub02 메시지 처리기입니다.


void CMyMsgSub02::OnBnClickedBtn00()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ClickOk();
}

void CMyMsgSub02::ClickOk()
{
	SetRtnVal(IDOK);
	OnOK();
}


BOOL CMyMsgSub02::OnInitDialog()
{
	CMyMsg::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_EDIT1)->SetWindowText(GetMsg());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
