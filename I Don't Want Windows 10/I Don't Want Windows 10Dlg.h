// I Don't Want Windows 10Dlg.h : header file
//

#pragma once

class c_idk_winX_DlgProxy;


// c_idk_winX_dlg dialog
class c_idk_winX_dlg : public CDialog
{
	DECLARE_DYNAMIC(c_idk_winX_dlg);
	friend class c_idk_winX_DlgProxy;

// Construction
public:
	c_idk_winX_dlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~c_idk_winX_dlg();

// Dialog Data
	enum { IDD = IDD_IDONTWANTWINDOWS10_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	c_idk_winX_DlgProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnEnChangeEdit1();
public:
	afx_msg void OnBnClickedCheck1();
};
