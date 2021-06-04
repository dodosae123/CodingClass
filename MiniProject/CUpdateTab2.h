#pragma once
class CUpdateDlg;


// CUpdateTab2 대화 상자

class CUpdateTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTab2)

public:
	CUpdateTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTab2();
	CUpdateDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateTab2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	CListCtrl m_SelectList;
	CString m_Mentor;
	CString m_Stuno;
	CString m_Lectno;
	vector<CString> m_Result;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
