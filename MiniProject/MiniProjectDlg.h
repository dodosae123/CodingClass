
// MiniProjectDlg.h: 헤더 파일
//

#pragma once


// CMiniProjectDlg 대화 상자
class CMiniProjectDlg : public CDialogEx
{
// 생성입니다.
public:
	CMiniProjectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MINIPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSchemabtn();
	afx_msg void OnBnClickedSelectquerybtn();
	afx_msg void OnBnClickedInsertquerybtn();
	afx_msg void OnBnClickedDeletequerybtn();
	afx_msg void OnBnClickedUpdatequerybtn();
	afx_msg void OnBnClickedCustomquerybtn();
};
