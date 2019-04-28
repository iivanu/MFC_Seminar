// CParrDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Fesb.h"
#include "CParrDlg.h"
#include "afxdialogex.h"


// CParrDlg dialog

IMPLEMENT_DYNAMIC(CParrDlg, CDialogEx)

CParrDlg::CParrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_PARAMETRI, pParent)
{

}

CParrDlg::~CParrDlg()
{
}

void CParrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_thicknessEdit);
	DDX_Control(pDX, IDC_EDIT3, m_distanceEdit);
	DDX_Control(pDX, IDC_EDIT1, m_angleEdit);
}


BEGIN_MESSAGE_MAP(CParrDlg, CDialogEx)
END_MESSAGE_MAP()


// CParrDlg message handlers


void CParrDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class
	m_thicknessEdit.GetWindowText(m_thickness);
	m_distanceEdit.GetWindowText(m_distance);
	m_angleEdit.GetWindowText(m_angle);
	CDialogEx::OnOK();
}
