#pragma once


// CTxtDlg dialog

class CTxtDlg : public CDialog
{
	DECLARE_DYNAMIC(CTxtDlg)

public:
	CTxtDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTxtDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_TEXT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_text;
	CEdit m_txtEdit;
	virtual void OnOK();
};
