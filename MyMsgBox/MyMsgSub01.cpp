// MyMsgSub01.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgSub01.h"


// CMyMsgSub01 ��ȭ �����Դϴ�.

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


// CMyMsgSub01 �޽��� ó�����Դϴ�.


void CMyMsgSub01::OnBnClickedBtn00()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickYes();
}


void CMyMsgSub01::OnBnClickedBtn01()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	GetDlgItem(IDC_EDIT1)->SetWindowText(GetMsg());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
