﻿#pragma once
class CSelectDlg;

// CSelectTab2 대화 상자

class CSelectTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectTab2)

public:
	CSelectTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelectTab2();

	CSelectDlg *parent;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SelectDlg2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	virtual void PostNcDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	vector<CString> m_Result;
	CListCtrl m_SelectList;
};
