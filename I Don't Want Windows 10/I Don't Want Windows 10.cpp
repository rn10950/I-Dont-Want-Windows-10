// I Don't Want Windows 10.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "windows.h"
#include "I Don't Want Windows 10.h"
#include "I Don't Want Windows 10Dlg.h"
#include "tchar.h"
#include "winuser.h"
//#include "idw_winX_logic.h"
#pragma comment (lib, "user32.lib")
#pragma comment (lib, "shell32.lib")
#include "cmdline.h"

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

// HELP COMMAND
//void show_help()
//	{
//		printf("TODO: ADD CMD HELP");
//	}

// c_idk_winX initialization

BOOL c_idk_winX::InitInstance()
{
	OutputDebugString("Output can be written!\n"); // test Debug output
	BOOL aModeCmd = false;
	BOOL NoGUI = false;
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
	// parse command line (cmdline.h)
	CCustomCommandLineInfo oInfo;
	ParseCommandLine(oInfo);
		if(oInfo.NoGUI())
		  {
			// Do something
			OutputDebugString("No GUI Set. \n"); // output the fact that /nogui is used
		  }
		else if(oInfo.aModeCmd())
		  {
			// Do whatever
			OutputDebugString("Advanced Mode set. \n"); // output the same for adv. mode
		  }

	// start executing dialog
	//if(aModeCmd == false && NoGUI == false)
		//{
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
		//}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
