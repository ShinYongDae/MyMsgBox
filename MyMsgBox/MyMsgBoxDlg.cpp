
// MyMsgBoxDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyMsgBoxDlg ��ȭ ����



CMyMsgBoxDlg::CMyMsgBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MYMSGBOX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pMyMsg = NULL;
}

CMyMsgBoxDlg::~CMyMsgBoxDlg()
{
	CloseMyMsg();
}

void CMyMsgBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyMsgBoxDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyMsgBoxDlg::OnBnClickedButton1)
	ON_MESSAGE(WM_MYMSG_EXIT, OnMyMsgExit)
END_MESSAGE_MAP()


// CMyMsgBoxDlg �޽��� ó����

BOOL CMyMsgBoxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	InitMyMsg();

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMyMsgBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMyMsgBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMyMsgBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyMsgBoxDlg::ProcThrd(const LPVOID lpContext)
{
	CMyMsgBoxDlg* pMyMsgBoxDlg = reinterpret_cast<CMyMsgBoxDlg*>(lpContext);

	while (pMyMsgBoxDlg->ThreadIsAlive())
	{
		if (!pMyMsgBoxDlg->ProcDlg())
			break;
	}

	pMyMsgBoxDlg->ThreadEnd();
}

BOOL CMyMsgBoxDlg::ProcDlg()
{
	Sleep(1000);
	//return TRUE;

	MsgBox(_T("�˶��� �߻��Ͽ����ϴ�."));
	return FALSE;
}

void CMyMsgBoxDlg::ThreadStart()
{
	m_bThreadStateEnd = FALSE;
	m_bThreadAlive = TRUE;
	t1 = std::thread(ProcThrd, this);
}

void CMyMsgBoxDlg::ThreadStop()
{
	m_bThreadAlive = FALSE;
	MSG message;
	const DWORD dwTimeOut = 1000 * 60 * 3; // 3 Minute
	DWORD dwStartTick = GetTickCount();
	Sleep(30);
	while (!m_bThreadStateEnd)
	{
		if (GetTickCount() >= (dwStartTick + dwTimeOut))
		{
			AfxMessageBox(_T("WaitUntilThreadEnd() Time Out!!!", NULL, MB_OK | MB_ICONSTOP));
			return;
		}
		if (::PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&message);
			::DispatchMessage(&message);
		}
		Sleep(30);
	}
}

void CMyMsgBoxDlg::ThreadEnd()
{
	m_bThreadStateEnd = TRUE;
}

BOOL CMyMsgBoxDlg::ThreadIsAlive()
{
	return m_bThreadAlive;
}



void CMyMsgBoxDlg::CloseMyMsg()
{
	if (m_pMyMsg)
	{
		delete m_pMyMsg;
		m_pMyMsg = NULL;
	}
}

void CMyMsgBoxDlg::InitMyMsg()
{
	if (m_pMyMsg)
		CloseMyMsg();

	m_pMyMsg = new CMyMsg(this);
	m_pMyMsg->Create();
}

LRESULT CMyMsgBoxDlg::OnMyMsgExit(WPARAM wPara, LPARAM lPara)
{
	return 0L;
}

int CMyMsgBoxDlg::MsgBox(CString sMsg, int nIdx, int nType, int nTimOut, BOOL bEngave)
{
	int nRtnVal = -1; // Reply(-1) is None.

	if (m_pMyMsg)
		nRtnVal = m_pMyMsg->SyncMsgBox(sMsg, nIdx, nType, nTimOut);

	return nRtnVal;
}

void CMyMsgBoxDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ThreadStart();
	MsgBox(_T("���� �ϸ��� Lot�� �ٸ��ϴ�.\r\n�۾��� ��� �����Ͻðڽ��ϱ�?"), 0, MB_YESNO);
}


