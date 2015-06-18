// portions of this code (most of it) obtained from here:
// http://forums.codeguru.com/showthread.php?386406-MFC-General-How-to-process-command-line-arguments-in-a-MFC-application
// information on how to implement the class is also located there

#include "stdafx.h"
#include <iostream>
using namespace std;

class CCustomCommandLineInfo : public CCommandLineInfo
{
public:
  CCustomCommandLineInfo()
  {
    //m_bExport = m_bOpen = m_bWhatever = FALSE;
    m_bNoGUI = m_baMode = m_bHelp = FALSE;
  }

  // for convenience maintain 3 variables to indicate the param passed. 
  BOOL m_bNoGUI;			//for /nogui (No GUI; Command-line)
  BOOL m_baMode;		    //for /adv (Advanced Mode)
  BOOL m_bHelp;				//for /? (Help)
 
  //public methods for checking these.
public:
  BOOL NoGUI() { return m_bNoGUI; };
  BOOL aModeCmd() { return m_baMode; };
  BOOL Help() { return m_bHelp; };
   
  virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
  {
    if(0 == strcmp(pszParam, "nogui"))
    {
      m_bNoGUI = TRUE;
    } 
    else if(0 == strcmp(pszParam, "adv"))
    {
      m_baMode = TRUE;
    }
   else if(0 == strcmp(pszParam, "?"))
    {
    m_bHelp = TRUE;
    }
  }
};

// SHOW HELP FUNCTION

void showHelp()
	{
	cout << " " << endl;
	cout << " I Don't Want Windows 10 Help" << endl;
	cout << " ============================" << endl;
	cout << " " << endl;
	cout << " Removes the \"Get Windows 10\" Update (KB3035583) from your system." << endl;
	cout << " " << endl;
	cout << " Syntax: \"I Dont Want Windows 10.exe\" /nogui ~OR~ /adv" << endl;
	cout << " " << endl;
	cout << " Flags:" << endl;
	cout << " " << endl;
	cout << " /nogui   Run the utility as you would normally, but without a GUI" << endl;
	cout << " /adv     Run the utility in Advanced Mode (Experienced Users Only)" << endl;
	cout << " " << endl;
	cout << " WARNING: Only include ONE command-line flag at a time. /adv implies /nogui." << endl;
	cout << " " << endl;
	cout << " Advanced Mode:" << endl;
	cout << " ==============" << endl;
	cout << " " << endl;
	cout << " Advanced Mode will:" << endl;
	cout << " - Make you (the Administrator) owner of C:\\WINDOWS\\System32\\GWX\\" << endl;
	cout << " - Delete all contents of C:\\WINDOWS\\System32\\GWX\\" << endl;
	cout << " - Mark C:\\WINDOWS\\System32\\GWX\\ as read-only" << endl;
	cout << " " << endl;
	cout << " Only proceed with Advanced Mode if you understand the possible" << endl;
	cout << " repercussions of using it." << endl;
	cout << " " << endl;
	//system("pause"); // uncomment for CMD window testing
	}