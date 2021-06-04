#pragma once
using namespace std;
#include <iostream>
#include <stdio.h>
#include <sqlext.h>
#include <Windows.h>
#include <sql.h>
#include <vector>

class CODBC
{
private :
	SQLHENV hEnv;
	SQLHDBC hDbc;
	SQLHSTMT hStmt;
public :
	CODBC();
	bool DBConnect();
	void DBDisconnect();
	void ExecuteQuery(CString _query);
	vector<CString> ExecuteSelectQuery(CString _query);
	SQLHENV GetHENV() { return hEnv; }
	SQLHDBC GetHDBC() { return hDbc; }
	SQLHSTMT GetHSTMT() { return hStmt; }
};

