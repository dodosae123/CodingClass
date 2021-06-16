// CDeleteTab2.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CDeleteDlg.h"
#include "CDeleteTab2.h"
#include "afxdialogex.h"


// CDeleteTab2 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTab2, CDialogEx)

CDeleteTab2::CDeleteTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DeleteDlg2, pParent)
	, m_strStuNo(_T(""))
{

}

CDeleteTab2::~CDeleteTab2()
{
}

void CDeleteTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
	DDX_Text(pDX, IDC_EDIT1, m_strStuNo);
}


BEGIN_MESSAGE_MAP(CDeleteTab2, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTab2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteTab2 메시지 처리기


BOOL CDeleteTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CDeleteDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Student No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Student Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Phone"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Mentor No"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList.DeleteAllItems();

	CODBC odbc;
	CString query = "SELECT * FROM STUDENT";
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
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDeleteTab2::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg2 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


void CDeleteTab2::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CDeleteTab2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString query = "UPDATE STUDENT SET MENTOR=NULL WHERE MENTOR=" + m_strStuNo;
	odbc.ExecuteQuery(query);

	query = "DELETE FROM STUDENT WHERE STUNO=" + m_strStuNo;
	odbc.ExecuteQuery(query);

	m_SelectList.DeleteAllItems();

	query = "SELECT * FROM STUDENT";
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
	UpdateData(FALSE);
}
