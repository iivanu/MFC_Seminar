
// FesbDoc.h : interface of the CFesbDoc class
//


#pragma once


class CFesbDoc : public CDocument
{
protected: // create from serialization only
	CFesbDoc() noexcept;
	DECLARE_DYNCREATE(CFesbDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CFesbDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

// dodano
public:
	CString m_text;
	CPoint m_pos;
	int m_thickness;
	int m_distance;
	int m_angle;

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
