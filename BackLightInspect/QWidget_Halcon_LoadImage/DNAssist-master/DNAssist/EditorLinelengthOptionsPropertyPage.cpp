// EditorLinelengthOptionsPropertyPage.cpp : ��@��
//

#include "stdafx.h"
#include "DNAssist.h"
#include "EditorLinelengthOptionsPropertyPage.h"



// CEditorLinelengthOptionsPropertyPage ��ܤ��

IMPLEMENT_DYNAMIC(CEditorLinelengthOptionsPropertyPage, CPropertyPage)

CEditorLinelengthOptionsPropertyPage::CEditorLinelengthOptionsPropertyPage()
	: CPropertyPage(IDD_EDITOR_LINELENGTH)
{

}

CEditorLinelengthOptionsPropertyPage::~CEditorLinelengthOptionsPropertyPage()
{
}

void CEditorLinelengthOptionsPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITOR_LINELENGTH, theApp.numberOfGroups);
}


BEGIN_MESSAGE_MAP(CEditorLinelengthOptionsPropertyPage, CPropertyPage)
END_MESSAGE_MAP()


// CEditorLinelengthOptionsPropertyPage �T���B�z�`��
