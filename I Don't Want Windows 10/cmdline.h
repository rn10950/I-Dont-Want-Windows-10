// portions of this code (most of it) obtained from here:
// http://forums.codeguru.com/showthread.php?386406-MFC-General-How-to-process-command-line-arguments-in-a-MFC-application
// information on how to implement the class is also located there

class CCustomCommandLineInfo : public CCommandLineInfo
{
public:
  CCustomCommandLineInfo()
  {
    //m_bExport = m_bOpen = m_bWhatever = FALSE;
    m_bNoGUI = m_baMode = FALSE;
  }

  // for convenience maintain 3 variables to indicate the param passed. 
  BOOL m_bNoGUI;			//for /nogui (No GUI; Command-line)
  BOOL m_baMode;		    //for /adv (Advanced Mode)
 // BOOL m_bWhatever;       //for /whatever (3rd switch - for later date)
 
  //public methods for checking these.
public:
  BOOL NoGUI() { return m_bNoGUI; };
  BOOL aModeCmd() { return m_baMode; };
  //BOOL IsWhatever() { return m_bWhatever; };
   
  virtual void ParseParam(const char* pszParam, BOOL bFlag, BOOL bLast)
  {
    if(0 == strcmp(pszParam, "/nogui"))
    {
      m_bNoGUI = TRUE;
    } 
    else if(0 == strcmp(pszParam, "/adv"))
    {
      m_baMode = TRUE;
    }
   // else if(0 == strcmp(pszParam, "/whatever"))
    //{
    //  m_bWhatever = TRUE;
   // }
  }
};