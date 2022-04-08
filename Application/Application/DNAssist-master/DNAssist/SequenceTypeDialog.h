#pragma once
#include "afxwin.h"


// CSequenceTypeDialog ��ܤ��

class CSequenceTypeDialog : public CDialog
{
	DECLARE_DYNAMIC(CSequenceTypeDialog)

public:
	CSequenceTypeDialog(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CSequenceTypeDialog();
	inline char GetSeqType()
	{
		switch (m_currSel) {
			case 1: return 'G';
			case 2: return 'D';
			case 3: return 'R';
			case 4: return 'P';
			default: return 0;
		}
	}

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEQUENCETYPE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()
	int m_currSel;
};
