// ProgressDialog.cpp : ��@��
//

#include "stdafx.h"
#include "DNAssist.h"
#include "ProgressDialog.h"



// CProgressDialog ��ܤ��

IMPLEMENT_DYNAMIC(CProgressDialog, CDialog)

CProgressDialog::CProgressDialog(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PROGRESSDIALOG, pParent)
{

}

CProgressDialog::~CProgressDialog()
{
}

void CProgressDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProgressDialog, CDialog)
END_MESSAGE_MAP()


// CProgressDialog �T���B�z�`��
