#pragma once
class CUpdateDlg;


// CUpdateTab1 대화 상자

class CUpdateTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTab1)

public:
	CUpdateTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTab1();
	CUpdateDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UpdateTab1 };
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
	CString m_Str;
	afx_msg void OnDblclkUpdatelist1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_iItem;
	int m_iSubitem;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
