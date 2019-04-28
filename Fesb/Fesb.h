
// Fesb.h : main header file for the Fesb application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFesbApp:
// See Fesb.cpp for the implementation of this class
//

class CFesbApp : public CWinApp
{
public:
	CFesbApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFesbApp theApp;
