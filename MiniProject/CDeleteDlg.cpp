// CDeleteDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CDeleteDlg.h"
#include "afxdialogex.h"
#include "CDeleteTab1.h"
#include "CDeleteTab2.h"
#include "CDeleteTab3.h"
#include "CDeleteTab4.h"



// CDeleteDlg 대화 상자

IMPLEMENT_DYNAMIC(CDeleteDlg, CDialogEx)

CDeleteDlg::CDeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DeleteDlg, pParent)
{

}

CDeleteDlg::~CDeleteDlg()
{
}

void CDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DeleteTab, m_Tab);
}


BEGIN_MESSAGE_MAP(CDeleteDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_DeleteTab, &CDeleteDlg::OnTcnSelchangeDeletetab)
END_MESSAGE_MAP()


// CDeleteDlg 메시지 처리기


BOOL CDeleteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_Tab.InsertItem(0,_T("scenario1"));
	m_Tab.InsertItem(1,_T("scenario2"));
	m_Tab.InsertItem(2,_T("scenario3"));
	m_Tab.InsertItem(3,_T("scenario4"));

	m_Tab.SetCurSel(0);

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	pDlg1 = new CDeleteTab1;
	pDlg1->Create(IDD_DeleteDlg1, &m_Tab);
	pDlg1->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg1->ShowWindow(SW_SHOW);

	pDlg2 = new CDeleteTab2;
	pDlg2->Create(IDD_DeleteDlg2, &m_Tab);
	pDlg2->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg2->ShowWindow(SW_HIDE);

	pDlg3 = new CDeleteTab3;
	pDlg3->Create(IDD_DeleteDlg3, &m_Tab);
	pDlg3->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg3->ShowWindow(SW_HIDE);

	pDlg4 = new CDeleteTab4;
	pDlg4->Create(IDD_DeleteDlg4, &m_Tab);
	pDlg4->MoveWindow(0, 20, rect.Width(), rect.Height());
	pDlg4->ShowWindow(SW_HIDE);



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDeleteDlg::OnTcnSelchangeDeletetab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int sel = m_Tab.GetCurSel();

	switch (sel) {
	case 0:
		pDlg1->ShowWindow(SW_SHOW);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		break;
	case 1:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_SHOW);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_HIDE);
		break;
	case 2:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_SHOW);
		pDlg4->ShowWindow(SW_HIDE);
		break;
	case 3:
		pDlg1->ShowWindow(SW_HIDE);
		pDlg2->ShowWindow(SW_HIDE);
		pDlg3->ShowWindow(SW_HIDE);
		pDlg4->ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}
