#pragma once


// CProgressDialog ��ܤ��

class CProgressDialog : public CDialog
{
	DECLARE_DYNAMIC(CProgressDialog)

public:
	CProgressDialog(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CProgressDialog();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRESSDIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
};
