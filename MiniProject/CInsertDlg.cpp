// CInsertDlg.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CInsertDlg.h"
#include "afxdialogex.h"


// CInsertDlg 대화 상자

IMPLEMENT_DYNAMIC(CInsertDlg, CDialogEx)

CInsertDlg::CInsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InsertDlg, pParent), m_SelectedRadio(0)
	, m_Text1(_T(""))
	, m_Text2(_T(""))
	, m_Text3(_T(""))
	, m_Text4(_T(""))
	, m_Text5(_T(""))
	, m_Text6(_T(""))
{

}

CInsertDlg::~CInsertDlg()
{
}

void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Radio(pDX, IDC_RADIO1, (int&)m_SelectedRadio);
	DDX_Control(pDX, IDC_Input1, m_Input1);
	DDX_Control(pDX, IDC_Input2, m_Input2);
	DDX_Control(pDX, IDC_Input3, m_Input3);
	DDX_Control(pDX, IDC_Input4, m_Input4);
	DDX_Control(pDX, IDC_Input5, m_Input5);
	DDX_Control(pDX, IDC_Input6, m_Input6);
	DDX_Text(pDX, IDC_Text1, m_Text1);
	DDX_Text(pDX, IDC_Text2, m_Text2);
	DDX_Text(pDX, IDC_Text3, m_Text3);
	DDX_Text(pDX, IDC_Text4, m_Text4);
	DDX_Text(pDX, IDC_Text5, m_Text5);
	DDX_Text(pDX, IDC_Text6, m_Text6);
}


BEGIN_MESSAGE_MAP(CInsertDlg, CDialogEx)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO7, RadioCtrl)
	ON_BN_CLICKED(IDC_BUTTON1, &CInsertDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CInsertDlg 메시지 처리기

void CInsertDlg::RadioCtrl(UINT id) {
	InvisibleAll();
	UpdateData(TRUE);

	switch (m_SelectedRadio)
	{
	case 0:
		currentTable = "INSTRUCTOR";
		m_Text1 = "Instructor No";
		m_Text2 = "Instructor Name";
		m_Text3 = "Salary";
		m_Text4 = "Phone";
		m_Text5 = "Program Language";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		m_Input4.ShowWindow(SW_NORMAL);
		m_Input5.ShowWindow(SW_NORMAL);
		break;
	case 1:
		currentTable = "STUDENT";
		m_Text1 = "Student No";
		m_Text2 = "Student Name";
		m_Text3 = "Phone";
		m_Text4 = "Mentor";
		m_Text5 = "";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		m_Input4.ShowWindow(SW_NORMAL);
		break;
	case 2:
		currentTable = "ROOM";
		m_Text1 = "Room No";
		m_Text2 = "Floor";
		m_Text3 = "Practice Room(1/0)";
		m_Text4 = "";
		m_Text5 = "";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		break;
	case 3:
		currentTable = "LECTURE";
		m_Text1 = "Lecture No";
		m_Text2 = "Lecture Name";
		m_Text3 = "Lecture Time";
		m_Text4 = "Fee";
		m_Text5 = "Lecture Room";
		m_Text6 = "Instructor No";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		m_Input4.ShowWindow(SW_NORMAL);
		m_Input5.ShowWindow(SW_NORMAL);
		m_Input6.ShowWindow(SW_NORMAL);
		break;
	case 4:
		currentTable = "COMPUTER";
		m_Text1 = "Computer No";
		m_Text2 = "Grade";
		m_Text3 = "Room No";
		m_Text4 = "";
		m_Text5 = "";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		break;
	case 5:
		currentTable = "EQUIPMENT";
		m_Text1 = "Equipment No";
		m_Text2 = "Kinds of";
		m_Text3 = "Quality";
		m_Text4 = "Student No";
		m_Text5 = "Instructor No";
		m_Text6 = "Due Date";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		m_Input4.ShowWindow(SW_NORMAL);
		m_Input5.ShowWindow(SW_NORMAL);
		m_Input6.ShowWindow(SW_NORMAL);
		break;
	case 6:
		currentTable = "AWARD";
		m_Text1 = "Student No";
		m_Text2 = "Award Name";
		m_Text3 = "Award Date";
		m_Text4 = "Ranking";
		m_Text5 = "Scholarship";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		m_Input4.ShowWindow(SW_NORMAL);
		m_Input5.ShowWindow(SW_NORMAL);
		break;
	case 7:
		currentTable = "TAKE_LEC";
		m_Text1 = "Student No";
		m_Text2 = "Lecture No";
		m_Text3 = "Grade";
		m_Text4 = "";
		m_Text5 = "";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		m_Input3.ShowWindow(SW_NORMAL);
		break;
	case 8:
		currentTable = "PROGRAM";
		m_Text1 = "Computer No";
		m_Text2 = "Program Name";
		m_Text3 = "";
		m_Text4 = "";
		m_Text5 = "";
		m_Text6 = "";
		m_Input1.ShowWindow(SW_NORMAL);
		m_Input2.ShowWindow(SW_NORMAL);
		break;
	default:
		break;
	}
	cout << currentTable << endl;
	
	UpdateData(FALSE);
	//AfxMessageBox(currentTable);
}



void CInsertDlg::InvisibleAll()
{
	// TODO: 여기에 구현 코드 추가.
	m_Text1 = "";
	m_Text2 = "";
	m_Text3 = "";
	m_Text4 = "";
	m_Text5 = "";
	m_Text6 = "";
	m_Input1.ShowWindow(SW_HIDE);
	m_Input2.ShowWindow(SW_HIDE);
	m_Input3.ShowWindow(SW_HIDE);
	m_Input4.ShowWindow(SW_HIDE);
	m_Input5.ShowWindow(SW_HIDE);
	m_Input6.ShowWindow(SW_HIDE);
	m_Input1.SetWindowTextA("");
	m_Input2.SetWindowTextA("");
	m_Input3.SetWindowTextA("");
	m_Input4.SetWindowTextA("");
	m_Input5.SetWindowTextA("");
	m_Input6.SetWindowTextA("");
}


BOOL CInsertDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	currentTable = "INSTRUCTOR";
	m_Text1 = "Instructor No";
	m_Text2 = "Instructor Name";
	m_Text3 = "Salary";
	m_Text4 = "Phone";
	m_Text5 = "Program Language";
	m_Text6 = "";
	m_Input1.ShowWindow(SW_NORMAL);
	m_Input2.ShowWindow(SW_NORMAL);
	m_Input3.ShowWindow(SW_NORMAL);
	m_Input4.ShowWindow(SW_NORMAL);
	m_Input5.ShowWindow(SW_NORMAL);
	m_Input6.ShowWindow(SW_HIDE);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInsertDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString tmp1;
	CString tmp2;
	CString tmp3;
	CString tmp4;
	CString tmp5;
	CString tmp6;
	CODBC odbc;
	CString query;

	m_Input1.GetWindowTextA(tmp1);
	m_Input2.GetWindowTextA(tmp2);
	m_Input3.GetWindowTextA(tmp3);
	m_Input4.GetWindowTextA(tmp4);
	m_Input5.GetWindowTextA(tmp5);
	m_Input6.GetWindowTextA(tmp6);

	switch (m_SelectedRadio) {
	case 0:
		query = "INSERT INTO INSTRUCTOR VALUES(" + tmp1 + ",'" + tmp2 + "'," + tmp3 + ",'" + tmp4 + "','" + tmp5 + "')";
		break;
	case 1:
		query = "INSERT INTO STUDENT VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp4 + ")";
		if (tmp4.IsEmpty()) {
			cout << "ss";
			query = "INSERT INTO STUDENT (STUNO, STUNAME, PHONE) VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "')";
		}
		break;
	case 2:
		query = "INSERT INTO ROOM VALUES(" + tmp1 + "," + tmp2 + "," + tmp3 + ")";
		break;
	case 3:
		query = "INSERT INTO LECTURE VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp4 + "," + tmp5 + ","+tmp6+")";
		break;
	case 4:
		query = "INSERT INTO COMPUTER VALUES(" + tmp1 + ",'" + tmp2 + "'," + tmp3 + ")";
		break;
	case 5:
		if (tmp6.MakeUpper().Compare("NULL") != 0) tmp6 = "'" + tmp6 + "'";
		query = "INSERT INTO EQUIPMENT VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp4 + "," + tmp5 + "," + tmp6 + ")";
		if (tmp4.IsEmpty() && tmp5.IsEmpty()) {
			query = "INSERT INTO EQUIPMENT (ENO, KIND, QUALITY, DUEDATE) VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp6 + ")";
		}
		else if (tmp4.IsEmpty()) {
			cout << "ss";
			query = "INSERT INTO EQUIPMENT (ENO, KIND, QUALITY, INSNO, DUEDATE) VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp5 + "," + tmp6 + ")";
		}
		else if (tmp5.IsEmpty()) {
			cout << "ss";
			query = "INSERT INTO EQUIPMENT (ENO, KIND, QUALITY, STUNO, DUEDATE) VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp4 +  "," + tmp6 + ")";
		}
		break;
	case 6:
		query = "INSERT INTO AWARD VALUES(" + tmp1 + ",'" + tmp2 + "','" + tmp3 + "'," + tmp4 + "," + tmp5 + ")";
		break;
	case 7:
		query = "INSERT INTO TAKE_LEC VALUES(" + tmp1 + "," + tmp2 + "," + tmp3 + ")";
		break;
	case 8:
		if (tmp6.MakeUpper().Compare("NULL") != 0) tmp2 = "'" + tmp2 + "'";
		query = "INSERT INTO PROGRAM VALUES(" + tmp1 + ",'" + tmp2 + "')";
		break;
	default:
		return;
		break;
	}
	odbc.ExecuteQuery(query);
}