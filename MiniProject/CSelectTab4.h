#pragma once
class CSelectDlg;

// CSelectTab4 대화 상자

class CSelectTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTab4)

public:
	CSelectTab4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectTab4();

	CSelectDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_SelectList;
private:
	vector<CString> m_Result;
};
