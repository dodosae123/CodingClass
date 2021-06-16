// CSchemaDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CSchemaDlg.h"
#include "afxdialogex.h"


// CSchemaDlg 대화 상자

IMPLEMENT_DYNAMIC(CSchemaDlg, CDialogEx)

CSchemaDlg::CSchemaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SchemaDlg, pParent)
	, m_curTable(_T(""))
{
	
}

CSchemaDlg::~CSchemaDlg()
{
}

void CSchemaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TableList, m_CBTable);
	DDX_Control(pDX, IDC_LIST1, m_SchemaList);
	DDX_CBString(pDX, IDC_TableList, m_curTable);
}


BEGIN_MESSAGE_MAP(CSchemaDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_TableList, &CSchemaDlg::OnCbnSelchangeTablelist)
END_MESSAGE_MAP()


// CSchemaDlg 메시지 처리기


BOOL CSchemaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	m_strTable = odbc.ExecuteSelectQuery("select TABLE_NAME from INFORMATION_SCHEMA.TABLES;");
	for (int i = 0; i < m_strTable.size(); i++) {
		cout << m_strTable[i] << endl;
		m_CBTable.AddString(m_strTable[i]);
	}
	m_CBTable.SetCurSel(0);
	m_CBTable.GetLBText(0,m_curTable);

	m_SchemaList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SchemaList.InsertColumn(0, _T("   Column Name   "), LVCFMT_CENTER, -1, -1);
	m_SchemaList.InsertColumn(1, _T("Column Name Len"), LVCFMT_CENTER, -1, -1);
	m_SchemaList.InsertColumn(2, _T("SQL Data Type"), LVCFMT_CENTER, -1, -1);
	m_SchemaList.InsertColumn(3, _T("Data Size"), LVCFMT_CENTER, -1, -1);
	m_SchemaList.InsertColumn(4, _T("Data Nullable"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 5; i++) {
		m_SchemaList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CSchemaDlg::OnCbnSelchangeTablelist()
{
	UpdateData(TRUE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (odbc.DBConnect() == true) {
		SQLHSTMT hStmt;
		SQLCHAR query[100];
		SQLCHAR ColumnName[30][30];
		SQLSMALLINT ColumnNameLen[30];
		SQLSMALLINT ColumnDataType[30];
		SQLULEN ColumnDataSize[30];
		SQLSMALLINT ColumnDataDigits[30];
		SQLSMALLINT ColumnDataNullable[30];

		SQLSMALLINT numCols = -1;

		m_SchemaList.DeleteAllItems();

		if (SQLAllocHandle(SQL_HANDLE_STMT, odbc.GetHDBC(), &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, "select * from " + m_curTable);
			SQLExecDirect(hStmt, query, SQL_NTS);	

			SQLNumResultCols(hStmt, &numCols);
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

				CString temp;
				m_SchemaList.InsertItem(i, (char *)ColumnName[i]);
				temp.Format(_T("%d"), (int)ColumnNameLen[i]);
				m_SchemaList.SetItem(i, 1, LVIF_TEXT, temp, 0, 0, 0, NULL);
				switch ((int)ColumnDataType[i])
				{
				case 1:
					temp = "CHAR";
					break;
				case 4:
					temp = "INTEGER";
					break;
				case 12:
					temp = "VARCHAR";
					break;
				case -7:
					temp = "BIT";
					break;
				}
				m_SchemaList.SetItem(i, 2, LVIF_TEXT, temp, 0, 0, 0, NULL);
				temp.Format(_T("%d"), (int)ColumnDataSize[i]);
				m_SchemaList.SetItem(i, 3, LVIF_TEXT, temp, 0, 0, 0, NULL);
				if ((int)ColumnDataNullable[i] == 0) temp = "NOT NULL";
				else temp = "NULL";
				m_SchemaList.SetItem(i, 4, LVIF_TEXT, temp, 0, 0, 0, NULL);

				printf("\nColumn : %d\n", i + 1);
				printf("Column Name : %s\n Column Name Len : %d\n SQL Data Type : %d\n Data Size : %d\n Data Nullable : %d\n",
					ColumnName[i], (int)ColumnNameLen[i], (int)ColumnDataType[i], (int)ColumnDataSize[i], (int)ColumnDataNullable[i]);
			}

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		odbc.DBDisconnect();
	}
	else {
		cout << "Fail to Connect!!" << endl;
	}
}

