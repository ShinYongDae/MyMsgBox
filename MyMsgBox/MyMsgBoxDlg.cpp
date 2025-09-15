
// MyMsgBoxDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MyMsgBox.h"
#include "MyMsgBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMyMsgBoxDlg 대화 상자



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


// CMyMsgBoxDlg 메시지 처리기

BOOL CMyMsgBoxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	InitMyMsg();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyMsgBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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

	MsgBox(_T("알람이 발생하였습니다."));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ThreadStart();
	MsgBox(_T("상면과 하면의 Lot가 다릅니다.\r\n작업을 계속 진행하시겠습니까?"), 0, MB_YESNO);
}


