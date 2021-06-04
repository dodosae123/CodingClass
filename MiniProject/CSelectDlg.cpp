// CSelectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CSelectDlg.h"
#include "afxdialogex.h"
#include "CSelectTab1.h"
#include "CSelectTab2.h"
#include "CSelectTab3.h"
#include "CSelectTab4.h"
#include "CSelectTab5.h"
#include "CSelectTab6.h"


// CSelectDlg 대화 상자

IMPLEMENT_DYNAMIC(CSelectDlg, CDialogEx)

CSelectDlg::CSelectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SelectDlg, pParent)
{

}

CSelectDlg::~CSelectDlg()
{
}

void CSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SelectTab, m_SelectTab);
}


BEGIN_MESSAGE_MAP(CSelectDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_SelectTab, &CSelectDlg::OnTcnSelchangeSelecttab)
END_MESSAGE_MAP()


// CSelectDlg 메시지 처리기


BOOL CSelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_SelectTab.InsertItem(0, _T("Scenario 1"));
	m_SelectTab.InsertItem(1, _T("Scenario 2"));
	m_SelectTab.InsertItem(2, _T("Scenario 3"));
	m_SelectTab.InsertItem(3, _T("Scenario 4"));
	m_SelectTab.InsertItem(4, _T("Scenario 5"));
	m_SelectTab.InsertItem(5, _T("Scenario 6"));

	m_SelectTab.SetCurSel(0);

	CRect rect;
	m_SelectTab.GetWindowRect(&rect);

	pDlg1 = new CSelectTab1;
	pDlg1->Create(IDD_SelectDlg1, &m_SelectTab);
	pDlg1->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg1->ShowWindow(SW_SHOW);

	pDlg2 = new CSelectTab2;
	pDlg2->Create(IDD_SelectDlg2, &m_SelectTab);
	pDlg2->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg2->ShowWindow(SW_HIDE);

	pDlg3 = new CSelectTab3;
	pDlg3->Create(IDD_SelectDlg3, &m_SelectTab);
	pDlg3->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg3->ShowWindow(SW_HIDE);

	pDlg4 = new CSelectTab4;
	pDlg4->Create(IDD_SelectDlg4, &m_SelectTab);
	pDlg4->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg4->ShowWindow(SW_HIDE);

	pDlg5 = new CSelectTab5;
	pDlg5->Create(IDD_SelectDlg5, &m_SelectTab);
	pDlg5->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg5->ShowWindow(SW_HIDE);

	pDlg6 = new CSelectTab6;
	pDlg6->Create(IDD_SelectDlg6, &m_SelectTab);
	pDlg6->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg6->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSelectDlg::OnTcnSelchangeSelecttab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_SelectTab.GetCurSel();

	switch (sel) {
	case 0:
		pDlg1->ShowWindow(SW_SHOW);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);
		break;
	case 1:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_SHOW);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);
		break;
	case 2:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_SHOW);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);
		break;
	case 3:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_SHOW);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_HIDE);
		break;
	case 4:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_SHOW);
		pDlg6->ShowWindow(SW_HIDE);
		break;
	case 5:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		pDlg5->ShowWindow(SW_HIDE);
		pDlg6->ShowWindow(SW_SHOW);
		break;
	}




	*pResult = 0;
}
