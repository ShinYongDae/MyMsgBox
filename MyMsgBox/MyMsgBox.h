
// MyMsgBox.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMyMsgBoxApp:
// �� Ŭ������ ������ ���ؼ��� MyMsgBox.cpp�� �����Ͻʽÿ�.
//

class CMyMsgBoxApp : public CWinApp
{
public:
	CMyMsgBoxApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMyMsgBoxApp theApp;