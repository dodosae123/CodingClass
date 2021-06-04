// CUpdateTab1.cpp: 구현 파일
//

#include "pch.h"
#include "MiniProject.h"
#include "CUpdateTab1.h"
#include "afxdialogex.h"
#include "CUpdateDlg.h"


// CUpdateTab1 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTab1, CDialogEx)

CUpdateTab1::CUpdateTab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_UpdateTab1, pParent)
	, m_Str(_T(""))
{

}

CUpdateTab1::~CUpdateTab1()
{
}

void CUpdateTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_UpdateList1, m_SelectList);
	DDX_Text(pDX, IDC_EDIT1, m_Str);
}


BEGIN_MESSAGE_MAP(CUpdateTab1, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTab1::OnBnClickedButton1)
	ON_NOTIFY(NM_DBLCLK, IDC_UpdateList1, &CUpdateTab1::OnDblclkUpdatelist1)
END_MESSAGE_MAP()


// CUpdateTab1 메시지 처리기


void CUpdateTab1::OnClose()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	this->DestroyWindow();
	CDialogEx::OnClose();
}


void CUpdateTab1::PostNcDestroy()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	parent->pDlg1 = NULL;

	delete this;
	CDialogEx::PostNcDestroy();
}


BOOL CUpdateTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CUpdateDlg*)AfxGetMainWnd();

	GetDlgItem(IDC_EditGrade)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);

	m_SelectList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	m_SelectList.InsertColumn(0, _T("Student No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(1, _T("Lecture No"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(2, _T("Lecture Name"), LVCFMT_CENTER, -1, -1);
	m_SelectList.InsertColumn(3, _T("Grade"), LVCFMT_CENTER, -1, -1);

	for (int i = 0; i < 4; i++) {
		m_SelectList.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CUpdateTab1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CODBC odbc;
	UpdateData(TRUE);
	m_SelectList.DeleteAllItems();

	CString query = "SELECT T.STUNO, T.LECTNO, L.LECTNAME, T.GRADE FROM TAKE_LEC AS T, LECTURE AS L WHERE T.LECTNO=L.LECTNO AND T.LECTNO=" + m_Str;
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


void CUpdateTab1::OnDblclkUpdatelist1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	LPNMITEMACTIVATE pNMITEM = (LPNMITEMACTIVATE)pNMHDR;

	m_iItem = pNMITEM->iItem;
	m_iSubitem = pNMITEM->iSubItem;

	if (pNMITEM->iItem != -1 && m_iSubitem > 2)
	{
		CRect rect;

		if (pNMITEM->iSubItem == 0)
		{
			m_SelectList.GetItemRect(pNMITEM->iItem, rect, LVIR_BOUNDS);
			rect.right = rect.left + m_SelectList.GetColumnWidth(0);
		}
		else
		{
			m_SelectList.GetSubItemRect(pNMITEM->iItem, pNMITEM->iSubItem, LVIR_BOUNDS, rect);
		}

		m_SelectList.ClientToScreen(rect);
		this->ScreenToClient(rect);

		GetDlgItem(IDC_EditGrade)->SetWindowText(m_SelectList.GetItemText(pNMITEM->iItem, pNMITEM->iSubItem));
		GetDlgItem(IDC_EditGrade)->SetWindowPos(NULL, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, SWP_SHOWWINDOW);
		GetDlgItem(IDC_EditGrade)->SetFocus();
	}

	*pResult = 0;
}


BOOL CUpdateTab1::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		UINT nChar = pMsg->wParam;
		if (nChar == VK_RETURN)
		{
			int nFocusCtrl = GetFocus()->GetDlgCtrlID();

			//printf("input code : %d\n", nChar);
			if (nFocusCtrl == IDC_EditGrade)
			{
				if (nChar == VK_RETURN)
				{
					if (pMsg->hwnd == GetDlgItem(IDC_EditGrade)->GetSafeHwnd())
					{
						CString str;
						GetDlgItemText(IDC_EditGrade, str);
						m_SelectList.SetItemText(m_iItem, m_iSubitem, str);
						CString stuno = m_SelectList.GetItemText(m_iItem, 0);
						CODBC odbc;
						odbc.ExecuteQuery("UPDATE TAKE_LEC SET GRADE="+ str +" WHERE STUNO="+ stuno +" AND LECTNO=" + m_Str);

						GetDlgItem(IDC_EditGrade)->SetWindowPos(NULL, 0, 0, 0, 0, SWP_HIDEWINDOW);
					}

					return TRUE;                // Do not process further
				}
			}
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
