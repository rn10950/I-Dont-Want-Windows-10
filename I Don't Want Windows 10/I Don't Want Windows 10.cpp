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

PVOID OldValue = NULL;

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

// WoW64 Detection:
typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
		GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

	if(NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}
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
		
		    OSVERSIONINFO osvi;
			BOOL bIsSupported;

			ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
			osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

			GetVersionEx(&osvi);

			bIsSupported = 
			   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 1) ||
			   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 2) ||
			   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 3) )));
			// run code
			if(bIsSupported) // Windows 7 or Windows 8.1
				{
				if(IsWow64()) // 64-bit Windows (WoW64)
					{
				    if( Wow64DisableWow64FsRedirection(&OldValue) ) 
						{
							//  Anything in this block uses the system native files and not the WoW64 ones
							
							// put native WoW64 code here
							system("wusa /uninstall /kb:3035583");
							//system("wusa /?"); // use this for testing

							//  Immediately re-enable redirection. Note that any resources
							//  associated with OldValue are cleaned up by this call.
							if ( FALSE == Wow64RevertWow64FsRedirection(OldValue) )
							{
								//  Failure to re-enable redirection should be considered
								//  a criticial failure and execution aborted.
								return 0;
							}
						}
					}
				else // 32-bit Windows (or native x64)
					{
					// actually run wusa
					system("wusa /uninstall /kb:3035583");
					}
				}
			else {
				// if I ever get MessageBox to work, uncomment line below and remove line below it
				//MessageBox(NULL, L"This applicatiion requires Windows 7 SP1 or Windows 8.1", L"TEST", MB_ICONWARNING | MB_OK);
				system("cls & @echo off & title I Don't Want Windows 10 & echo This application needs Windows 7 or Windows 8.1 & echo. & pause");
			}

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
