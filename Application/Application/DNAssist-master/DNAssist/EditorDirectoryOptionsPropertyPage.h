#pragma once


// CEditorDirectoryOptionsPropertyPage ��ܤ��

class CEditorDirectoryOptionsPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CEditorDirectoryOptionsPropertyPage)

public:
	CEditorDirectoryOptionsPropertyPage();
	virtual ~CEditorDirectoryOptionsPropertyPage();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITOR_DIRECTORIES };
#endif

protected:
	CString m_sequenceDirectory;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedEditorSequencesBrowse();
	virtual void OnOK();
};
