// CCustomDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CCustomDlg.h"
#include "afxdialogex.h"


// CCustomDlg 대화 상자

IMPLEMENT_DYNAMIC(CCustomDlg, CDialogEx)

CCustomDlg::CCustomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CustomDlg, pParent)
	, m_Query(_T(""))
{

}

CCustomDlg::~CCustomDlg()
{
}

void CCustomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Query);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}


BEGIN_MESSAGE_MAP(CCustomDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCustomDlg 메시지 처리기


void CCustomDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	cout << m_Query <<endl;
	CString kindsOf = m_Query.MakeUpper().Left(6);
	cout << m_Query << endl;
	vector<CString> columnList;
	SQLSMALLINT numCols = -1;
	CODBC odbc;
	if (kindsOf.Compare("SELECT")==0) {
		while (m_SelectList.GetHeaderCtrl()->GetItemCount() > 0) {
			m_SelectList.DeleteColumn(0);
		}
		m_SelectList.DeleteAllItems();
		if (odbc.DBConnect() == true) {
			SQLHSTMT hStmt;
			SQLCHAR query[100];
			SQLCHAR ColumnName[30][30];
			SQLSMALLINT ColumnNameLen[30];
			SQLSMALLINT ColumnDataType[30];
			SQLULEN ColumnDataSize[30];
			SQLSMALLINT ColumnDataDigits[30];
			SQLSMALLINT ColumnDataNullable[30];

			if (SQLAllocHandle(SQL_HANDLE_STMT, odbc.GetHDBC(), &hStmt) == SQL_SUCCESS) {
				sprintf((char *)query, m_Query);
				SQLRETURN temp = SQLExecDirect(hStmt, query, SQL_NTS);
				if (temp == SQL_ERROR || temp == SQL_NO_DATA_FOUND){
					AfxMessageBox("Error");
					return;
				}
				SQLNumResultCols(hStmt, &numCols);
				cout << numCols;
				for (int i = 0; i < numCols; i++) {
					SQLDescribeCol(
						hStmt,
						i + 1,
						ColumnName[i],
						30,
						&ColumnNameLen[i],
						&ColumnDataType[i],
						&ColumnDataSize[i],
						&ColumnDataDigits[i],
						&ColumnDataNullable[i]);

					m_SelectList.InsertColumn(i, (char*)ColumnName[i], LVCFMT_CENTER, -1, -1);
				}

				SQLCloseCursor(hStmt);
				SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			}

			odbc.DBDisconnect();
		}
		else {
			cout << "Fail to Connect!!" << endl;
		}

		m_Result = odbc.ExecuteSelectQuery(m_Query);
		for (int i = 0; i < m_Result.size() / numCols; i++) {
			m_SelectList.InsertItem(i, m_Result[numCols * i]);
			for (int j = 1; j < numCols; j++) {
				m_SelectList.SetItem(i, j, LVIF_TEXT, m_Result[numCols*i + j], 0, 0, 0, NULL);
			}
		}
		for (int i = 0; i < numCols; i++) {
			m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
		}
		
	}
	else if (kindsOf.Compare("INSERT")==0|| kindsOf.Compare("DELETE") == 0|| kindsOf.Compare("UPDATE") == 0) {
		while (m_SelectList.GetHeaderCtrl()->GetItemCount() > 0) {
			m_SelectList.DeleteColumn(0);
		}
		m_SelectList.DeleteAllItems();
		odbc.ExecuteQuery(m_Query);
	}

	m_Query = "";
	UpdateData(TRUE);
	UpdateData(FALSE);
}


BOOL CCustomDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	/*m_SelectList.InsertColumn(0, _T("Student No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Student Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Lecture No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Grade"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}*/

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
