// I Don't Want Windows 10.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// c_idk_winX:
// See I Don't Want Windows 10.cpp for the implementation of this class
//

class c_idk_winX : public CWinApp
{
public:
	c_idk_winX();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern c_idk_winX theApp;