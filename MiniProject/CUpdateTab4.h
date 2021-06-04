#pragma once
class CUpdateDlg;

// CUpdateTab4 대화 상자

class CUpdateTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTab4)

public:
	CUpdateTab4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTab4();
	CUpdateDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateTab4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	CListCtrl m_SelectList;
	afx_msg void OnBnClickedButton1();
	vector<CString> m_Result;
};
