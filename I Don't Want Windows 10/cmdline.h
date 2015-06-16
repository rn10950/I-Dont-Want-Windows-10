// NEW COMMAND-LINE INCLUDE
#include "stdafx.h"
#include "string.h"
#include "string"

class CNewCommandLineInfo : public CCommandLineInfo
{
public:
	CString m_sHostAddr;
	UINT    m_nPort;

	void ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast);
};

void CNewCommandLineInfo::ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast)
{
	if(bFlag) {
		CString sParam(lpszParam);
		if (sParam.Left(2) == "h:") {
			m_sHostAddr = sParam.Right(sParam.GetLength() - 2);
			return;
		}

		if (sParam.Left(2) == "p:") {
			CString sTemp;

			sTemp = sParam.Right(sParam.GetLength() - 2);
			m_nPort = atoi(sTemp);
			return;
		}
	}

	// Call the base class to ensure proper command line processing
	CCommandLineInfo::ParseParam(lpszParam, bFlag, bLast);
}
