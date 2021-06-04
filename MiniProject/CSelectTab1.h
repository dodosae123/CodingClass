#pragma once
class CSelectDlg;

// CSelectTab1 대화 상자

class CSelectTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTab1)

public:
	CSelectTab1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectTab1();

	CSelectDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual void PostNcDestroy();
public:
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	CString m_StrLectno;
	afx_msg void OnBnClickedButton1();
	CListCtrl m_SelectList;
private:
	vector<CString> m_Result;
};
