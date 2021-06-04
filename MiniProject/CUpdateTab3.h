#pragma once
class CUpdateDlg;


// CUpdateTab3 대화 상자

class CUpdateTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTab3)

public:
	CUpdateTab3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTab3();
	CUpdateDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateTab3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	CString m_Eno;
	CString m_Stuno;
	CString m_Insno;
	CListCtrl m_SelectList;
	vector<CString> m_Result;
	afx_msg void OnBnClickedButton1();
};
