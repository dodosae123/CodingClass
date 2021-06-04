#pragma once


// CInsertDlg 대화 상자

class CInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertDlg)

public:
	CInsertDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsertDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InsertDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString currentTable;
	int m_SelectedRadio;
	afx_msg void RadioCtrl(UINT id);

	CEdit m_Input1;
	CEdit m_Input2;
	CEdit m_Input3;
	CEdit m_Input4;
	CEdit m_Input5;
	CEdit m_Input6;
	CString m_Text1;
	CString m_Text2;
	CString m_Text3;
	CString m_Text4;
	CString m_Text5;
	CString m_Text6;
	void InvisibleAll();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
};
