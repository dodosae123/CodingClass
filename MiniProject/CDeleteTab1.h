#pragma once
class CDeleteDlg;

// CDeleteTab1 대화 상자

class CDeleteTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTab1)

public:
	CDeleteTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeleteTab1();

	CDeleteDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteDlg1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	CString m_strCount;
	CListCtrl m_SelectList;
	vector<CString> m_Result;
};
