#pragma once
#include <vector>


// CSchemaDlg 대화 상자

class CSchemaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSchemaDlg)

public:
	CSchemaDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSchemaDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SchemaDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CODBC odbc;
	CComboBox m_CBTable;
	vector<CString> m_strTable;
	vector<CString> m_strColumn;
	virtual BOOL OnInitDialog();
	CListCtrl m_SchemaList;
	CString m_curTable;
	afx_msg void OnCbnSelchangeTablelist();
};
