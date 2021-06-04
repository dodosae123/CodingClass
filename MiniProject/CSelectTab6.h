#pragma once
class CSelectDlg;

// CSelectTab6 대화 상자

class CSelectTab6 : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTab6)

public:
	CSelectTab6(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectTab6();

	CSelectDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	CListCtrl m_SelectList;
	vector<CString> m_Result;
	afx_msg void OnBnClickedButton1();
};
