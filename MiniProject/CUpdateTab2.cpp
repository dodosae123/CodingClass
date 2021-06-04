// CUpdateTab2.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CUpdateTab2.h"
#include "afxdialogex.h"
#include "CUpdateDlg.h"


// CUpdateTab2 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTab2, CDialogEx)

CUpdateTab2::CUpdateTab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UpdateTab2, pParent)
	, m_Mentor(_T(""))
	, m_Stuno(_T(""))
	, m_Lectno(_T(""))
{

}

CUpdateTab2::~CUpdateTab2()
{
}

void CUpdateTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
	DDX_Text(pDX, IDC_EDIT1, m_Mentor);
	DDX_Text(pDX, IDC_EDIT2, m_Stuno);
	DDX_Text(pDX, IDC_EDIT3, m_Lectno);
}


BEGIN_MESSAGE_MAP(CUpdateTab2, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTab2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdateTab2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUpdateTab2 메시지 처리기


void CUpdateTab2::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();

	CDialogEx::OnClose();
}


void CUpdateTab2::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg2 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CUpdateTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CUpdateDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("My Grade"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Mentor No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Mentor Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Mentor's Grade"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUpdateTab2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);

	odbc.ExecuteQuery("UPDATE STUDENT SET MENTOR=" + m_Mentor + " WHERE STUNO=" + m_Stuno);
}


void CUpdateTab2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);
	m_SelectList.DeleteAllItems();

	CString query = "SELECT T.GRADE, T2.STUNO, S.STUNAME, T2.GRADE FROM TAKE_LEC AS T, TAKE_LEC AS T2, STUDENT AS S WHERE " + m_Stuno + "<>T2.STUNO AND S.STUNO=T2.STUNO AND T.STUNO=" + m_Stuno + " AND T.LECTNO=" + m_Lectno + " AND T2.LECTNO=" + m_Lectno + " AND T.GRADE<T2.GRADE AND S.STUNO NOT IN (SELECT S2.MENTOR FROM STUDENT AS S2 WHERE S2.MENTOR=S.STUNO);";
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
