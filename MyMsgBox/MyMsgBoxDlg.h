
// MyMsgBoxDlg.h : ��� ����
//

#pragma once
#include "MyMsg.h"

#include <thread>

// CMyMsgBoxDlg ��ȭ ����
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

// �����Դϴ�.
public:
	CMyMsgBoxDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	~CMyMsgBoxDlg();

public:
	static void ProcThrd(const LPVOID lpContext);


// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMSGBOX_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.

protected:
	void ThreadEnd();
	BOOL ProcDlg();
	BOOL ThreadIsAlive();

// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg LRESULT OnMyMsgExit(WPARAM wPara, LPARAM lPara);
	afx_msg void OnBnClickedButton1();
};
