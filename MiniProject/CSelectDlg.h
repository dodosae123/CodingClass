#pragma once
class CSelectTab1;
class CSelectTab2;
class CSelectTab3;
class CSelectTab4;
class CSelectTab5;
class CSelectTab6;

// CSelectDlg 대화 상자

class CSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectDlg)

public:
	CSelectDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectDlg();

	CSelectTab1 *pDlg1;
	CSelectTab2 *pDlg2;
	CSelectTab3 *pDlg3;
	CSelectTab4 *pDlg4;
	CSelectTab5 *pDlg5;
	CSelectTab6 *pDlg6;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_SelectTab;
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeSelecttab(NMHDR *pNMHDR, LRESULT *pResult);
};
