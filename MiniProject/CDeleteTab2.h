#pragma once
class CDeleteDlg;


// CDeleteTab2 대화 상자

class CDeleteTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTab2)

public:
	CDeleteTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeleteTab2();
	CDeleteDlg *parent;


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteDlg2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_SelectList;
	vector<CString> m_Result;
	CString m_strStuNo;
};
