// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "I Don't Want Windows 10.h"
#include "DlgProxy.h"
#include "I Don't Want Windows 10Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// c_idk_winX_DlgProxy

IMPLEMENT_DYNCREATE(c_idk_winX_DlgProxy, CCmdTarget)

c_idk_winX_DlgProxy::c_idk_winX_DlgProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(c_idk_winX_dlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(c_idk_winX_dlg)))
		{
			m_pDialog = reinterpret_cast<c_idk_winX_dlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

c_idk_winX_DlgProxy::~c_idk_winX_DlgProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void c_idk_winX_DlgProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(c_idk_winX_DlgProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(c_idk_winX_DlgProxy, CCmdTarget)
END_DISPATCH_MAP()

// Note: we add support for IID_IIDontWantWindows10 to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .IDL file.

// {E8206924-CA90-446B-975E-3046833CEFD2}
static const IID IID_IIDontWantWindows10 =
{ 0xE8206924, 0xCA90, 0x446B, { 0x97, 0x5E, 0x30, 0x46, 0x83, 0x3C, 0xEF, 0xD2 } };

BEGIN_INTERFACE_MAP(c_idk_winX_DlgProxy, CCmdTarget)
	INTERFACE_PART(c_idk_winX_DlgProxy, IID_IIDontWantWindows10, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {0D95D5DE-11C8-4633-B8EE-11BFA190BAA3}
IMPLEMENT_OLECREATE2(c_idk_winX_DlgProxy, "IDontWantWindows10.Application", 0xd95d5de, 0x11c8, 0x4633, 0xb8, 0xee, 0x11, 0xbf, 0xa1, 0x90, 0xba, 0xa3)


// c_idk_winX_DlgProxy message handlers
