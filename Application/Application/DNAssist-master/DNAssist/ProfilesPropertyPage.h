#pragma once


// CProfilesPropertyPage ��ܤ��

class CProfilesPropertyPage : public CPropertyPage
{
	DECLARE_DYNAMIC(CProfilesPropertyPage)

public:
	CProfilesPropertyPage();
	virtual ~CProfilesPropertyPage();

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPERTIES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

	DECLARE_MESSAGE_MAP()
	CString m_hpb;
	CString m_hpl;
	CString m_a;
public:
	virtual void OnOK();
};
