================================================================================
    MICROSOFT FOUNDATION CLASS LIBRARY : I Don't Want Windows 10 Project Overview
===============================================================================

The application wizard has created this I Don't Want Windows 10 application for 
you.  This application not only demonstrates the basics of using the Microsoft 
Foundation Classes but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your I Don't Want Windows 10 application.

I Don't Want Windows 10.vcproj
    This is the main project file for VC++ projects generated using an application wizard. 
    It contains information about the version of Visual C++ that generated the file, and 
    information about the platforms, configurations, and project features selected with the
    application wizard.

I Don't Want Windows 10.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    c_idk_winX application class.

I Don't Want Windows 10.cpp
    This is the main application source file that contains the application
    class c_idk_winX.

I Don't Want Windows 10.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
    Visual C++. Your project resources are in 1033.

res\I Don't Want Windows 10.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file I Don't Want Windows 10.rc.

res\IDontWantWindows10.rc2
    This file contains resources that are not edited by Microsoft 
    Visual C++. You should place all resources not editable by
    the resource editor in this file.

I Don't Want Windows 10.reg
    This is an example .reg file that shows you the kind of registration
    settings the framework will set for you.  You can use this as a .reg
    file to go along with your application.

IDontWantWindows10.idl
    This file contains the Interface Description Language source code for the
    type library of your application.


/////////////////////////////////////////////////////////////////////////////

The application wizard creates one dialog class and automation proxy class:

I Don't Want Windows 10Dlg.h, I Don't Want Windows 10Dlg.cpp - the dialog
    These files contain your c_idk_winX_dlg class.  This class defines
    the behavior of your application's main dialog.  The dialog's template is
    in I Don't Want Windows 10.rc, which can be edited in Microsoft Visual C++.

DlgProxy.h, DlgProxy.cpp - the automation object
    These files contain your c_idk_winX_DlgProxy class.  This class
    is called the Automation proxy class for your dialog, because it
    takes care of exposing the Automation methods and properties that
    Automation controllers can use to access your dialog.  These methods
    and properties are not exposed from the dialog class directly, because
    in the case of a modal dialog-based MFC application it is cleaner and
    easier to keep the Automation object separate from the user interface.


/////////////////////////////////////////////////////////////////////////////

Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named I Don't Want Windows 10.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

I Don't Want Windows 10.manifest
	Application manifest files are used by Windows XP to describe an applications 
	dependency on specific versions of Side-by-Side assemblies. The loader uses this 
	information to load the appropriate assembly from the assembly cache or private 
	from the application. The Application manifest  maybe included for redistribution 
	as an external .manifest file that is installed in the same folder as the application 
	executable or it may be included in the executable in the form of a resource. 
/////////////////////////////////////////////////////////////////////////////

Other notes:

The application wizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, you will need 
to redistribute the MFC DLLs. If your application is in a language 
other than the operating system's locale, you will also have to 
redistribute the corresponding localized resources MFC80XXX.DLL. 
For more information on both of these topics, please see the section on 
redistributing Visual C++ applications in MSDN documentation. 

/////////////////////////////////////////////////////////////////////////////
