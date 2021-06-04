#pragma once
class CDeleteDlg;


// CDeleteTab4 대화 상자

class CDeleteTab4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTab4)

public:
	CDeleteTab4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeleteTab4();
	CDeleteDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DeleteDlg4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
};
