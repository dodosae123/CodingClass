// CDeleteTab3.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CDeleteDlg.h"
#include "CDeleteTab3.h"
#include "afxdialogex.h"


// CDeleteTab3 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTab3, CDialogEx)

CDeleteTab3::CDeleteTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DeleteDlg3, pParent)
	, m_strInsNo(_T(""))
{

}

CDeleteTab3::~CDeleteTab3()
{
}

void CDeleteTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strInsNo);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CDeleteTab3, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTab3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteTab3 메시지 처리기


BOOL CDeleteTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CDeleteDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Instructor No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Instructor Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Salary"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Major"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList.DeleteAllItems();

	CODBC odbc;
	CString query = "SELECT I.INSNO, I.INSNAME, I.SALARY, I.PROGRAMLAN FROM INSTRUCTOR AS I WHERE I.INSNO NOT IN (SELECT L.INSNO FROM LECTURE AS L GROUP BY L.INSNO)";
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


void CDeleteTab3::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg3 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


void CDeleteTab3::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CDeleteTab3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString query = "DELETE FROM INSTRUCTOR WHERE INSNO=" + m_strInsNo;
	odbc.ExecuteQuery(query);

	m_SelectList.DeleteAllItems();
	query = "SELECT I.INSNO, I.INSNAME, I.SALARY, I.PROGRAMLAN FROM INSTRUCTOR AS I WHERE I.INSNO NOT IN (SELECT L.INSNO FROM LECTURE AS L GROUP BY L.INSNO)";
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
