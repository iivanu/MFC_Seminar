#pragma once


// CParrDlg dialog

class CParrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CParrDlg)

public:
	CParrDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CParrDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_PARAMETRI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString m_thickness;
	CString m_distance;
	CString m_angle;
	CEdit m_thicknessEdit;
	CEdit m_distanceEdit;
	CEdit m_angleEdit;
	virtual void OnOK();
};
