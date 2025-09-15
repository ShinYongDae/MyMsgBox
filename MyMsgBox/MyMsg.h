#pragma once


// CMyMsg 대화 상자입니다.

#define WM_MYMSG_EXIT				(WM_USER+34)

#define DEFAULT_TIME_OUT			120000		// [mSec]
#define MB_TIME_OUT					-1

typedef struct tagMyMsg
{
	CString strMsg;
	int nIdx;
	int nType;
	int nTimOut;
	BOOL bRepeat;

	void Init()
	{
		strMsg = _T("");
		nIdx = 0;
		nType = MB_OK;
		nTimOut = DEFAULT_TIME_OUT;
		bRepeat = TRUE;
	}

	tagMyMsg()
	{
		Init();
	}

	tagMyMsg(CString sMsg, int MsgId, int Type, int TimOut, BOOL Repeat = TRUE)
	{
		strMsg = sMsg;
		nIdx = MsgId;
		nType = Type;
		nTimOut = TimOut;
		bRepeat = Repeat;
	}

}stMyMsg;
typedef CArray <stMyMsg, stMyMsg> CArMyMsg;
typedef CArray <int, int> CArMyMsgRtn;


class CMyMsg : public CDialog
{
	DECLARE_DYNAMIC(CMyMsg)

	CWnd* m_pParent;
	HWND m_hParentWnd;
	CMyMsg* m_pMyMsg;			// CMyMsgSub00 or CMyMsgSub01 or CMyMsgSub02
	CArMyMsg  m_arMyMsg;
	CArMyMsgRtn  m_arMyMsgRtn;

public:
	CMyMsg(CWnd* pParent = NULL, int nIDD = IDD);   // 표준 생성자입니다.
	virtual ~CMyMsg();

public:
	void* m_pMyMsgSub01; // CMyMsgSub01
	void* m_pMyMsgSub02; // CMyMsgSub02

public:
	BOOL Create();
	int SyncMsgBox(CString sMsg, int nIdx = 0, int nType = MB_OK, int nTimOut = DEFAULT_TIME_OUT);
	void SetMsg(CString strMsg, int nIdx = 0, int nType = MB_TIME_OUT, int nTimeOut = DEFAULT_TIME_OUT);
	CString GetMsg();
	int GetRtnVal(int nIdx = 0);
	void SetRtnVal(int nVal);

public:
	afx_msg LRESULT OnMyMsgExit(WPARAM wPara, LPARAM lPara);


// 대화 상자 데이터입니다.
//#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_MSG };
//#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
