
// FesbView.cpp : implementation of the CFesbView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Fesb.h"
#endif

#include "FesbDoc.h"
#include "FesbView.h"
#include "TxtDlg.h"
#include "CParrDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFesbView

IMPLEMENT_DYNCREATE(CFesbView, CView)

BEGIN_MESSAGE_MAP(CFesbView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
//	ON_WM_MBUTTONDOWN()
	ON_COMMAND(ID_EDIT_NOVITEXT, &CFesbView::OnEditNovitext)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_EDIT_PARAMETRI, &CFesbView::OnEditParametri)
END_MESSAGE_MAP()

// CFesbView construction/destruction

CFesbView::CFesbView() noexcept
{
	// TODO: add construction code here

}

CFesbView::~CFesbView()
{
}

BOOL CFesbView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFesbView drawing

void CFesbView::OnDraw(CDC* pDC)
{
	CFesbDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

	//ispisi text
	pDC->SetTextColor(m_txtColor);
	pDC->TextOut(pDoc->m_pos.x, pDoc->m_pos.y, pDoc->m_text);

	CRect r;
	GetClientRect(&r);
	CPen pen;
	pen.CreatePen(PS_SOLID, pDoc->m_thickness, m_penColor);
	CPen *oldpen = pDC->SelectObject(&pen);

	const int distance = pDoc->m_distance;
	int i = 0;
	float j = 0;

	if(pDoc->m_angle <= 17)		//prvi slucaj
	{
		float fsp = r.top + (r.Height() - (r.Width() * tan(pDoc->m_angle * 3.14 / 180)));
		float ssp = r.Width() * tan(pDoc->m_angle * 3.14 / 180);

		while (r.left + i < r.Width() - distance)
		{
			pDC->MoveTo(r.left + i, r.bottom);
			j = i * tan(pDoc->m_angle * 3.14 / 180);
			pDC->LineTo(r.right, r.top + fsp + j);
			i += distance;
		}

		j = distance * tan(pDoc->m_angle * 3.14 / 180);
		while (j < r.Height() - r.Width() * tan(pDoc->m_angle * 3.14 / 180))
		{
			pDC->MoveTo(r.left, r.bottom - j);
			pDC->LineTo(r.right, fsp - j);
			j += (distance * tan(pDoc->m_angle * 3.14 / 180));
		}

		i = distance;
		while (r.right - i > r.left+ distance)
		{
			j = i * tan(pDoc->m_angle * 3.14 / 180);
			pDC->MoveTo(r.left, ssp - j);
			pDC->LineTo(r.right-i, r.top);
			i += distance;
		}
	}

	pDC->SelectObject(oldpen);

}


// CFesbView printing

BOOL CFesbView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFesbView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFesbView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFesbView diagnostics

#ifdef _DEBUG
void CFesbView::AssertValid() const
{
	CView::AssertValid();
}

void CFesbView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFesbDoc* CFesbView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFesbDoc)));
	return (CFesbDoc*)m_pDocument;
}
#endif //_DEBUG


// CFesbView message handlers


void CFesbView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CFesbDoc* pDoc = GetDocument();
	CPoint curr_pos = pDoc->m_pos;
	switch (nChar)
	{
	case VK_UP: curr_pos.y--; break;
	case VK_DOWN: curr_pos.y++; break;
	case VK_LEFT: curr_pos.x--; break;
	case VK_RIGHT: curr_pos.x++; break;
	}
	// osiguraj se da je ispis u klijentovom prozoru
	CRect r;
	GetClientRect(&r);
	if (curr_pos.y > r.top && curr_pos.y < r.bottom)
		pDoc->m_pos.y = curr_pos.y;
	if (curr_pos.x > r.left && curr_pos.x < r.right)
		pDoc->m_pos.x = curr_pos.x;
	Invalidate(); // poruka da se treba obnoviti crtanje View-a

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CFesbView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CFesbDoc* pDoc = GetDocument();
	pDoc->m_pos = point; // point sadrži koordinate miša
	Invalidate(); // poruka da se treba obnoviti crtanje View-a

	CView::OnLButtonDown(nFlags, point);
}

void CFesbView::OnEditNovitext()
{
	// TODO: Add your command handler code here
	CFesbDoc* pDoc = GetDocument();
	CTxtDlg dlg; // deklariranje dijaloga
	int response = dlg.DoModal(); //poziv dijaloga
	if (IDOK == response) // samo ako je pritisnut botun OK
	{
		// dobavi txt iz dijaloga
		if (dlg.m_text.IsEmpty()) // ako je prazan
			AfxMessageBox(_T("Unijeli ste prazan tekst"));
		else
			pDoc->m_text = dlg.m_text; // stavi tekst u dokument
	}
	Invalidate();
}



void CFesbView::OnEditParametri()
{
	// TODO: Add your command handler code here
	CFesbDoc* pDoc = GetDocument();
	CParrDlg dlg; // deklariranje dijaloga
	int response = dlg.DoModal(); //poziv dijaloga
	if (IDOK == response) // samo ako je pritisnut botun OK
	{

		// dobavi debljinu i udaljenost iz dijaloga
		if (dlg.m_thickness.IsEmpty() && dlg.m_distance.IsEmpty() &&dlg.m_angle.IsEmpty()) // ako su oba prazna
			AfxMessageBox(_T("Nije unesen niti jedan parametar!!"));
		else
		{
			if (!dlg.m_thickness.IsEmpty())
			{
				int conv1 = _ttoi(dlg.m_thickness);
				pDoc->m_thickness = conv1; // stavi debljinu u dokument
			}
			if (!dlg.m_distance.IsEmpty())
			{
				int conv2 = _ttoi(dlg.m_distance);
				pDoc->m_distance = conv2; // stavi udaljenost u dokument
			}
			if (!dlg.m_angle.IsEmpty())
			{
				int conv3 = _ttoi(dlg.m_angle);
				if (conv3 <= 0 || conv3 >= 18)
					AfxMessageBox(_T("Niste unijeli kut u rasponu od 0 do 18"));
				else
					pDoc->m_angle = conv3; //stavi kut u dokument
			}	
		}
	}

	Invalidate();
}
