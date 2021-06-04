#include "pch.h"
#include "CODBC.h"


CODBC::CODBC()
{
}

bool CODBC::DBConnect()
{
	// TODO: 여기에 구현 코드 추가.
	SQLRETURN Ret;

	// Allocate the Environment Handle (hEnv)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
	{
		return false;
	}

	// Set attributes of the Environment Handle (hEnv)
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
	{
		return false;
	}

	// Allocate the Connection Handle (hDbc)
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
	{
		return false;
	}

	// Connect to the SQL Sever with ODBC name, ID, and PW
	Ret = SQLConnect(hDbc, (SQLCHAR *)"CodingClass", SQL_NTS, (SQLCHAR *)"KIM", SQL_NTS, (SQLCHAR *)"1234", SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}

	return true;
}


void CODBC::DBDisconnect()
{
	// TODO: 여기에 구현 코드 추가.
	SQLDisconnect(hDbc);					// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);	// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);	// Free the Environment Handle
}


void CODBC::ExecuteQuery(CString _query)
{
	// TODO: 여기에 구현 코드 추가.
	if (DBConnect() == true) {
		static SQLCHAR query[100];
		SQLHSTMT hStmt;
		SQLRETURN ret;

		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, _query);
			ret = SQLExecDirect(hStmt, query, SQL_NTS);
			if (ret == SQL_ERROR || ret == SQL_NO_DATA_FOUND) {
				AfxMessageBox("Error");
				return;
			}


			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}

		//Disconnect from the SQL Server
		DBDisconnect();
	}
	else {
		cout << "Fail to Connect!!\n";
	}
}



vector<CString> CODBC::ExecuteSelectQuery(CString _query)
{
	vector<CString> result;
	// TODO: 여기에 구현 코드 추가.
	if (DBConnect() == true) {
		static SQLCHAR query[500];
		SQLSMALLINT colCount = -1;
		SQLCHAR data[50][50];
		SQLLEN nulldata[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS) {
			sprintf((char*)query, _query);
			SQLRETURN ret = SQLExecDirect(hStmt, query, SQL_NTS);
			if (ret == SQL_ERROR || ret == SQL_NO_DATA_FOUND) {
				AfxMessageBox("Error");
				return result;
			}
			ret = SQLNumResultCols(hStmt, &colCount);
			
			for (int i = 0; i < colCount; i++) {
				SQLBindCol(hStmt, i + 1, SQL_C_CHAR, data[i], sizeof(data[i]), &nulldata[i]);
			}
			while (SQLFetch(hStmt) != SQL_NO_DATA) {
				for (int i = 0; i < colCount; i++) {
					if (nulldata[i] == SQL_NULL_DATA) result.push_back("NULL");
					else result.push_back((CString)data[i]);
				}
			}
			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}
		DBDisconnect();
	}
	else {
		cout << "Fail to Connect!!\n";
	}

	return result;
}
