// TxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Fesb.h"
#include "TxtDlg.h"
#include "afxdialogex.h"


// CTxtDlg dialog

IMPLEMENT_DYNAMIC(CTxtDlg, CDialog)

CTxtDlg::CTxtDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1_TEXT, pParent)
{

}

CTxtDlg::~CTxtDlg()
{
}

void CTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_txtEdit);
}


BEGIN_MESSAGE_MAP(CTxtDlg, CDialog)
END_MESSAGE_MAP()


// CTxtDlg message handlers


void CTxtDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	m_txtEdit.GetWindowText(m_text);
	CDialog::OnOK();
}
