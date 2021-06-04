// CSelectTab1.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CSelectTab1.h"
#include "afxdialogex.h"
#include "CSelectDlg.h"

// CSelectTab1 대화 상자

IMPLEMENT_DYNAMIC(CSelectTab1, CDialogEx)

CSelectTab1::CSelectTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SelectDlg1, pParent)
	, m_StrLectno(_T(""))
{

}

CSelectTab1::~CSelectTab1()
{
}

void CSelectTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StrLectno);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CSelectTab1, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CSelectTab1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSelectTab1 메시지 처리기


void CSelectTab1::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg1 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


void CSelectTab1::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL CSelectTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CSelectDlg*)AfxGetMainWnd();

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Student No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Student Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Lecture No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Grade"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSelectTab1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);
	if (_ttoi(m_StrLectno) > 0) {
		m_SelectList.DeleteAllItems();

		CString query = "SELECT S.STUNO, S.STUNAME, T.LECTNO, T.GRADE FROM STUDENT AS S, TAKE_LEC AS T WHERE S.STUNO=T.STUNO AND T.LECTNO="+m_StrLectno+" ORDER BY T.GRADE DESC";
		m_Result = odbc.ExecuteSelectQuery(query);

		for (int i = 0; i < m_Result.size()/4; i++) {
			m_SelectList.InsertItem(i, m_Result[4*i]);
			m_SelectList.SetItem(i, 1, LVIF_TEXT, m_Result[4*i + 1], 0, 0, 0, NULL);
			m_SelectList.SetItem(i, 2, LVIF_TEXT, m_Result[4*i + 2], 0, 0, 0, NULL);
			m_SelectList.SetItem(i, 3, LVIF_TEXT, m_Result[4*i + 3], 0, 0, 0, NULL);
		}

		for (int i = 0; i < 4; i++) {
			m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
		}
	}

}
