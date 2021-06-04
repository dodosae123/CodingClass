// CUpdateTab3.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CUpdateTab3.h"
#include "afxdialogex.h"
#include "CUpdateDlg.h"


// CUpdateTab3 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTab3, CDialogEx)

CUpdateTab3::CUpdateTab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UpdateTab3, pParent)
	, m_Eno(_T(""))
	, m_Stuno(_T(""))
	, m_Insno(_T(""))
{

}

CUpdateTab3::~CUpdateTab3()
{
}

void CUpdateTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Eno);
	DDX_Text(pDX, IDC_EDIT2, m_Stuno);
	DDX_Text(pDX, IDC_EDIT3, m_Insno);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CUpdateTab3, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTab3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUpdateTab3 메시지 처리기


void CUpdateTab3::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();

	CDialogEx::OnClose();
}


void CUpdateTab3::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg3 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CUpdateTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CUpdateDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Equipment No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Kinds"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Quality"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Student No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(4, _T("Instructor No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(5, _T("Due Date"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 6; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	CODBC odbc;
	m_SelectList.DeleteAllItems();

	CString query = "SELECT * FROM EQUIPMENT";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 6; i++) {
		m_SelectList.InsertItem(i, m_Result[6 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[6 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[6 * i + 2], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 3, LVIF_TEXT, m_Result[6 * i + 3], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 4, LVIF_TEXT, m_Result[6 * i + 4], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 5, LVIF_TEXT, m_Result[6 * i + 5], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 6; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUpdateTab3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	CString date;
	CTime time = CTime::GetCurrentTime()+CTimeSpan(7,0,0,0);
	date= time.Format("%Y-%m-%d");
	if (odbc.ExecuteSelectQuery("SELECT STUNO FROM EQUIPMENT WHERE ENO=" + m_Eno + "AND STUNO IS NOT NULL").size() == 0) {
		odbc.ExecuteQuery("UPDATE EQUIPMENT SET STUNO=" + m_Stuno + ", INSNO=" + m_Insno + ", DUEDATE='"+date+"' WHERE ENO=" + m_Eno);
	}
	else {
		AfxMessageBox("해당 기기는 다른 사람이 사용중이며 동일인이어도 연장은 불가능합니다.");
	}
	
}
