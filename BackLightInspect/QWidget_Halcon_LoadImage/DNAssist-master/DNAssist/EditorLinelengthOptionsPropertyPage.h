#pragma once


// CEditorLinelengthOptionsPropertyPage ��ܤ��

class CEditorLinelengthOptionsPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CEditorLinelengthOptionsPropertyPage)

public:
	CEditorLinelengthOptionsPropertyPage();
	virtual ~CEditorLinelengthOptionsPropertyPage();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITOR_LINELENGTH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
