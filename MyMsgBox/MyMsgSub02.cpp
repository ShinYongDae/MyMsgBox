// MyMsgSub02.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub02.h"


// CMyMsgSub02 ��ȭ �����Դϴ�.

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


// CMyMsgSub02 �޽��� ó�����Դϴ�.


void CMyMsgSub02::OnBnClickedBtn00()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	GetDlgItem(IDC_EDIT1)->SetWindowText(GetMsg());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
