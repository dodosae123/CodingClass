// CDeleteTab1.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CDeleteTab1.h"
#include "CDeleteDlg.h"
#include "afxdialogex.h"


// CDeleteTab1 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTab1, CDialogEx)

CDeleteTab1::CDeleteTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DeleteDlg1, pParent)
	, m_strCount(_T(""))
{

}

CDeleteTab1::~CDeleteTab1()
{
}

void CDeleteTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strCount);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CDeleteTab1, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTab1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteTab1 메시지 처리기


BOOL CDeleteTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CDeleteDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Lecture No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Lecture Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("# of Students"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList.DeleteAllItems();

	CODBC odbc;
	CString query = "SELECT L.LECTNO, L.LECTNAME, COUNT(L.LECTNO) FROM TAKE_LEC AS T, LECTURE AS L WHERE T.LECTNO=L.LECTNO GROUP BY L.LECTNO, L.LECTNAME";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 3; i++) {
		m_SelectList.InsertItem(i, m_Result[3 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDeleteTab1::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg1 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


void CDeleteTab1::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CDeleteTab1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString query = "DELETE FROM LECTURE WHERE (SELECT COUNT(T.LECTNO) FROM TAKE_LEC AS T WHERE T.LECTNO=LECTURE.LECTNO GROUP BY T.LECTNO)<" + m_strCount;
	odbc.ExecuteQuery(query);

	m_SelectList.DeleteAllItems();

	query = "SELECT L.LECTNO, L.LECTNAME, COUNT(L.LECTNO) FROM TAKE_LEC AS T, LECTURE AS L WHERE T.LECTNO=L.LECTNO GROUP BY L.LECTNO, L.LECTNAME";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 3; i++) {
		m_SelectList.InsertItem(i, m_Result[3 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}
	UpdateData(FALSE);
}
