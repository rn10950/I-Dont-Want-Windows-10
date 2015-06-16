// VARIABLE DECLARATIONS
PVOID OldValue = NULL;

// system code to be run (after arch detection)
void mainCode(bool aMode)
	{
	system("wusa /uninstall /kb:3035583");
	system("TASKKILL /IM GWX.EXE /T /F");
	if(aMode == true)
		{
		// advanced mode code goes here
		// take ownership of %windir%\System32\GWX\ and delete contents

		system("takeown /f %windir%\\System32\\GWX\\ /R /D Y");
		system("ATTRIB -S %windir%\\System32\\GWX\\* /S /D");
		system("DEL /F /Q %windir%\\System32\\GWX\\* /S");
		system("ATTRIB +R %windir%\\System32\\GWX\\* /S /D");
		}
	}

// WoW64 Detection:
typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

LPFN_ISWOW64PROCESS fnIsWow64Process;

BOOL IsWow64()
{
	BOOL bIsWow64 = FALSE;

	//IsWow64Process is not available on all supported versions of Windows.
	//Use GetModuleHandle to get a handle to the DLL that contains the function
	//and GetProcAddress to get a pointer to the function if available.

	fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
		GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

	if(NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			//handle error
		}
	}
	return bIsWow64;
}
// main logic function (for both CMD and GUI use)
void run(bool aMode, bool gui)
	{
	// aMode is a boolean that determines advanced mode. Should be declared before calling run();
    OSVERSIONINFO osvi;
	BOOL bIsSupported;

	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);

	GetVersionEx(&osvi);

	bIsSupported = 
	   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 1) ||
	   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 2) ||
	   ( (osvi.dwMajorVersion == 6) && (osvi.dwMinorVersion == 3) )));
	// run code
	if(bIsSupported) // Windows 7 or Windows 8.1
		{
		if(IsWow64()) // 64-bit Windows (WoW64)
			{
		    if( Wow64DisableWow64FsRedirection(&OldValue) ) 
				{
					//  Anything in this block uses the system native files and not the WoW64 ones
					
					// put native WoW64 code here
					mainCode(aMode);
					
					//system("wusa /?"); // use this for testing

					//  Immediately re-enable redirection. Note that any resources
					//  associated with OldValue are cleaned up by this call.
					if ( FALSE == Wow64RevertWow64FsRedirection(OldValue) )
					{
						//  Failure to re-enable redirection should be considered
						//  a criticial failure and execution aborted.
					}
				}
			}
		else // 32-bit Windows (or native x64)
			{
			// actually run wusa
			mainCode(aMode);
			}
		}
	else 
		{
		// unsupported OS message box (XP/Vista/8 RTM) if being run from a gui
		// unsupported message in console if being run from CMD
		if(gui == true)
			{
			MessageBox(NULL, "This applicatiion requires Windows 7 SP1 or Windows 8.1", "Unsupported Operating System", MB_ICONWARNING | MB_OK);
			}
		else
			{
			printf("This applicatiion requires Windows 7 SP1 or Windows 8.1", L"Unsupported Operating System");
			}
		}
	}