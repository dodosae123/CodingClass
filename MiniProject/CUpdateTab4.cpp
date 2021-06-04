// CUpdateTab4.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CUpdateTab4.h"
#include "afxdialogex.h"
#include "CUpdateDlg.h"


// CUpdateTab4 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTab4, CDialogEx)

CUpdateTab4::CUpdateTab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UpdateTab4, pParent)
{

}

CUpdateTab4::~CUpdateTab4()
{
}

void CUpdateTab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CUpdateTab4, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTab4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUpdateTab4 메시지 처리기


void CUpdateTab4::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CUpdateTab4::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg4 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CUpdateTab4::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CUpdateDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Computer No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Grade"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Room No"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	CODBC odbc;
	m_SelectList.DeleteAllItems();

	CString query = "SELECT * FROM COMPUTER WHERE COMPUTER.ROOMNO IS NULL";
	m_Result = odbc.ExecuteSelectQuery(query);

	for (int i = 0; i < m_Result.size() / 3; i++) {
		m_SelectList.InsertItem(i, m_Result[3 * i]);
		m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[3 * i + 1], 0, 0, 0, NULL);
		m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[3 * i + 2], 0, 0, 0, NULL);
	}

	for (int i = 0; i < 3; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUpdateTab4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
