// DlgProxy.h: header file
//

#pragma once

class c_idk_winX_dlg;


// c_idk_winX_DlgProxy command target

class c_idk_winX_DlgProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(c_idk_winX_DlgProxy)

	c_idk_winX_DlgProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	c_idk_winX_dlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

// Implementation
protected:
	virtual ~c_idk_winX_DlgProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(c_idk_winX_DlgProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

