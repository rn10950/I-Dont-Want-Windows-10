// I Don't Want Windows 10.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "windows.h"
#include "I Don't Want Windows 10.h"
#include "I Don't Want Windows 10Dlg.h"
#include "tchar.h"
#include "winuser.h"
#pragma comment (lib, "user32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// c_idk_winX

BEGIN_MESSAGE_MAP(c_idk_winX, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// c_idk_winX construction

c_idk_winX::c_idk_winX()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only c_idk_winX object

c_idk_winX theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0xFE361118, 0x8EF9, 0x4CC3, { 0x93, 0xFA, 0xBA, 0xC7, 0x1A, 0x79, 0x59, 0xB4 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// WoW64 Message Box
int WoWMessage()
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Resource not available\nDo you want to try again?",
			(LPCWSTR)L"Account Details",
			MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		);

		switch (msgboxID)
		{
		case IDCANCEL:
			// TODO: add code
			break;
		case IDTRYAGAIN:
			// TODO: add code
			break;
		case IDCONTINUE:
			// TODO: add code
			break;
		}

		return msgboxID;
	}
// Unsupported OS Message Box
int XPMessage()
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"Resource not available\nDo you want to try again?",
			(LPCWSTR)L"Account Details",
			MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2
		);

		switch (msgboxID)
		{
		case IDCANCEL:
			// TODO: add code
			break;
		case IDTRYAGAIN:
			// TODO: add code
			break;
		case IDCONTINUE:
			// TODO: add code
			break;
		}

		return msgboxID;
	}
// c_idk_winX initialization

BOOL c_idk_winX::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}


	c_idk_winX_dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		//  Place code here to handle when the dialog is
		//  dismissed with OK

		//
	}
	else if (nResponse == IDCANCEL)
	{
		// cancel button (I don't agree), application should close so nothing really goes here
	}


	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
