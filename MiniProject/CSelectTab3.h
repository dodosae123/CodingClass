#pragma once
class CSelectDlg;

// CSelectTab3 대화 상자

class CSelectTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTab3)

public:
	CSelectTab3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectTab3();

	CSelectDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CListCtrl m_SelectList;
private:
	vector<CString> m_Result;
};
