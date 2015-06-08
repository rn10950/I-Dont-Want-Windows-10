// I Don't Want Windows 10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "I Don't Want Windows 10.h"
#include "I Don't Want Windows 10Dlg.h"
#include "DlgProxy.h"
#include "windows.h"
#pragma comment (lib, "user32.lib")
#include "idw_winX_logic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// c_idk_winX_dlg dialog




IMPLEMENT_DYNAMIC(c_idk_winX_dlg, CDialog);

c_idk_winX_dlg::c_idk_winX_dlg(CWnd* pParent /*=NULL*/)
	: CDialog(c_idk_winX_dlg::IDD, pParent)
	, aModeCB(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

c_idk_winX_dlg::~c_idk_winX_dlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;
}

void c_idk_winX_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_ADVHELP_CB, aModeCB);
}

BEGIN_MESSAGE_MAP(c_idk_winX_dlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &c_idk_winX_dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_ADVHELP_CB, &c_idk_winX_dlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// c_idk_winX_dlg message handlers

BOOL c_idk_winX_dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void c_idk_winX_dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR c_idk_winX_dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void c_idk_winX_dlg::OnClose()
{
	if (CanExit())
		CDialog::OnClose();
}

void c_idk_winX_dlg::OnOK()
{
	if (CanExit())
		CDialog::OnOK();
}

void c_idk_winX_dlg::OnCancel()
{
	if (CanExit())
		CDialog::OnCancel();
}

BOOL c_idk_winX_dlg::CanExit()
{
	// If the proxy object is still around, then the automation
	//  controller is still holding on to this application.  Leave
	//  the dialog around, but hide its UI.
	if (m_pAutoProxy != NULL)
	{
		ShowWindow(SW_HIDE);
		return FALSE;
	}

	return TRUE;
}


void c_idk_winX_dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
	//MessageBox(L"TEST");
	// determine if the advanced mode checkbox is set and call run() accordingly
	if (aModeCB == true)
		{
		// checkbox checked, run adv. mode
		bool aMode = true;
		run(aMode);
		}
	else
		{
		// checkbox unchecked, no adv. mode
		bool aMode = false;
		run(aMode);
		}
}

void c_idk_winX_dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	
}

void c_idk_winX_dlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	CDialog aboutDlg(IDD_ADVHELP);
	// Create and show the dialog box
   INT_PTR nRet = -1;
   nRet = aboutDlg.DoModal();
   
   // Handle the return value from DoModal 
   switch (nRet)
   {
      case -1: 
         AfxMessageBox(_T("Dialog box could not be created!"));
         break;
      case IDABORT:
		    {
			 // Do something 
			 CButton* pBtn = (CButton*) GetDlgItem(IDC_ADVHELP_CB);
			 pBtn->SetCheck(0);// uncheck it
			 break;
			}
      case IDOK:
			{
			 // Do something 
			 CButton* pBtn = (CButton*) GetDlgItem(IDC_ADVHELP_CB);
			 pBtn->SetCheck(1);// check it
			 break;
			}
      case IDCANCEL:
			{
			 // Do something 
			 CButton* pBtn = (CButton*) GetDlgItem(IDC_ADVHELP_CB);
			 pBtn->SetCheck(0);// uncheck it
			 break;
			}
      default:
		     {
			 // Do something 
			 CButton* pBtn = (CButton*) GetDlgItem(IDC_ADVHELP_CB);
			 pBtn->SetCheck(0);// uncheck it
			 break;
			 }
   };
}
