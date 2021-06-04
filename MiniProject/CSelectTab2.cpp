// CSelectTab2.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CSelectTab2.h"
#include "afxdialogex.h"
#include "CSelectDlg.h"

// CSelectTab2 대화 상자

IMPLEMENT_DYNAMIC(CSelectTab2, CDialogEx)

CSelectTab2::CSelectTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SelectDlg2, pParent)
{

}

CSelectTab2::~CSelectTab2()
{
}

void CSelectTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CSelectTab2, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CSelectTab2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSelectTab2 메시지 처리기


void CSelectTab2::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CSelectTab2::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg2 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CSelectTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CSelectDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Computer No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Room No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Floor"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Grade"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSelectTab2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;

	m_SelectList.DeleteAllItems();

	CString query = "SELECT C.COMNO, R.ROOMNO, R.FLOOR, C.GRADE FROM COMPUTER AS C, ROOM AS R WHERE C.ROOMNO=R.ROOMNO AND (C.GRADE='C' OR C.GRADE='F')";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 4; i++) {
		m_SelectList.InsertItem(i, m_Result[4 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[4 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[4 * i + 2], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 3, LVIF_TEXT, m_Result[4 * i + 3], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}
}
