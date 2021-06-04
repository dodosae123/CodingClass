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
{

}

CDeleteTab1::~CDeleteTab1()
{
}

void CDeleteTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeleteTab1, CDialogEx)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDeleteTab1 메시지 처리기


BOOL CDeleteTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	parent = (CDeleteDlg*)AfxGetMainWnd();

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
