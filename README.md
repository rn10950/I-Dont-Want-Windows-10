# I Don't Want Windows 10
A graphical uninstaller for the "Get Windows 10" update (KB3035583) that is installed on Windows 7 and Windows 8.1 systems.

I uploaded a pre-compiled zip file to the Internet on 6/2/2015, a day after KB3035583 (I will refer to it as the GWX update from now on) was activated, and I got mixed reactions. Much of the negative criticism was that people would not know if this was secure. I have decided to release the source code here so anyone can both verify it's integrity and improve the utility for the good of everyone. Many people have also noted it would be easier to just run *WUSA /UNINSTALL /KB:3035583* in a command prompt or batch file, or just uninstall the GWX update through the Control Panel, and while I understand that this is much easier, I decided to make this utility for the average user to be able to just run it without the hassle of the command prompt or selecting the proper update to uninstall in the Control Panel.

## The Project

I created this in Visual Studio 2005. (yes, I know, it's all I had) To launch the project in Visual Studio, just click on idw_winX.sln. The main C++ file is */I Don't Want Windows 10/I Don't Want Windows 10.cpp*.

## How it Works
In the main C++ file, the program makes sure it's not being run on any Windows other than Windows 7 and Windows 8.1, and makes sure that if it's being run under WoW64 to disable file system redirection. The program then executes a system() call to *wusa /uninstall /kb:3035583* to finally uninstall the GWX update.

## Command-Line Flags

You can now start I Don't Want Windows 10 from the Command Prompt! Here is how you would go about doing that. Be sure to read the issues section before you use this utility from the console.

**Syntax:** `"I Dont Want Windows 10.exe" /nogui ~OR~ /adv`

**Flags:**

`/nogui` - Run the utility as you would normally, but without a GUI

`/adv` - Run the utility in Advanced Mode (Experienced Users Only)

**WARNING:** Only include *ONE* command-line flag at a time. `/adv` implies `/nogui`.

## Issues
The MessageBox problem from before is now fixed, but now we have command-line problems. I can't get anything echoed out in a console, the flags still work though. You can also only specify one command-line flag at a time. This should be fixed in a v3.0.x bug-fix release or v4.0.

## The Future
I am currently planning or working on the following features:
* Hiding the update after uninstall
* Enhancing command-line support
* Removing multiple bad updates at once.
