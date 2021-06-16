// CDeleteTab4.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CDeleteDlg.h"
#include "CDeleteTab4.h"
#include "afxdialogex.h"


// CDeleteTab4 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTab4, CDialogEx)

CDeleteTab4::CDeleteTab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DeleteDlg4, pParent)
	, m_strENo(_T(""))
	, m_strComNo(_T(""))
{

}

CDeleteTab4::~CDeleteTab4()
{
}

void CDeleteTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
	DDX_Text(pDX, IDC_EDIT2, m_strENo);
	DDX_Text(pDX, IDC_EDIT1, m_strComNo);
	DDX_Control(pDX, IDC_LIST2, m_SelectList2);
}


BEGIN_MESSAGE_MAP(CDeleteTab4, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTab4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteTab4::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDeleteTab4 메시지 처리기


BOOL CDeleteTab4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CDeleteDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Computer No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Grade"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Room No"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList.DeleteAllItems();

	CODBC odbc;
	CString query = "SELECT * FROM COMPUTER WHERE GRADE='F'";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 3; i++) {
		m_SelectList.InsertItem(i, m_Result[3 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList2.InsertColumn(0, _T("Equipment No"), LVCFMT_CENTER, -1, -1);
	m_SelectList2.InsertColumn(1, _T("Kinds"), LVCFMT_CENTER, -1, -1);
	m_SelectList2.InsertColumn(2, _T("Quality"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 3; i++) {
		m_SelectList2.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	m_SelectList2.DeleteAllItems();

	query = "SELECT ENO, KIND, QUALITY FROM EQUIPMENT WHERE QUALITY='F'";
	m_Result2 = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result2.size() / 3; i++) {
		m_SelectList2.InsertItem(i, m_Result2[3 * i]);
		m_SelectList2.SetItem(i, 1, LVIF_TEXT, m_Result2[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList2.SetItem(i, 2, LVIF_TEXT, m_Result2[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList2.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDeleteTab4::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg4 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


void CDeleteTab4::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CDeleteTab4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString query = "DELETE FROM COMPUTER WHERE COMNO="+m_strComNo;
	odbc.ExecuteQuery(query);

	m_SelectList.DeleteAllItems();

	query = "SELECT * FROM COMPUTER WHERE GRADE='F'";
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


void CDeleteTab4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString query = "DELETE FROM EQUIPMENT WHERE ENO=" + m_strENo;
	odbc.ExecuteQuery(query);

	m_SelectList2.DeleteAllItems();

	query = "SELECT ENO, KIND, QUALITY FROM EQUIPMENT WHERE QUALITY='F'";
	m_Result2 = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result2.size() / 3; i++) {
		m_SelectList2.InsertItem(i, m_Result2[3 * i]);
		m_SelectList2.SetItem(i, 1, LVIF_TEXT, m_Result2[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList2.SetItem(i, 2, LVIF_TEXT, m_Result2[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList2.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	UpdateData(FALSE);
}
