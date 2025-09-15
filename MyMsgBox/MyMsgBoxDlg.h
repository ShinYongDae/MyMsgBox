
// MyMsgBoxDlg.h : 헤더 파일
//

#pragma once
#include "MyMsg.h"

#include <thread>

// CMyMsgBoxDlg 대화 상자
class CMyMsgBoxDlg : public CDialog
{

	BOOL m_bThreadAlive, m_bThreadStateEnd;
	std::thread t1;
	void ThreadStart();
	void ThreadStop();

	CMyMsg* m_pMyMsg;

	void InitMyMsg();
	void CloseMyMsg();
	int MsgBox(CString sMsg, int nIdx = 0, int nType = MB_OK, int nTimOut = DEFAULT_TIME_OUT, BOOL bEngave = TRUE);		// SyncMsgBox

// 생성입니다.
public:
	CMyMsgBoxDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	~CMyMsgBoxDlg();

public:
	static void ProcThrd(const LPVOID lpContext);


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMSGBOX_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

protected:
	void ThreadEnd();
	BOOL ProcDlg();
	BOOL ThreadIsAlive();

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg LRESULT OnMyMsgExit(WPARAM wPara, LPARAM lPara);
	afx_msg void OnBnClickedButton1();
};
