# I Don't Want Windows 10
A graphical uninstaller for the "Get Windows 10" update (KB3035583) that is installed on Windows 7 and Windows 8.1 systems.

I uploaded a pre-compiled zip file to the Internet on 6/2/2015, a day after KB3035583 (I will refer to it as the GWX update from now on) was released, and I got mixed reactions. Much of the negative criticism was that people would not know if this was secure. I have decided to release the source code here so anyone can both verify it's integrity and improve the utility for the good of everyone. Many people have also noted it would be easier to just run *WUSA /UNINSTALL /KB:3035583* in a command prompt or batch file, or just uninstall the GWX update through the Control Panel, and while I understand that this is much easier, I decided to make this utility for the average user to be able to just run it without the hassle of the command prompt or selecting the proper update to install in the Control Panel.

## The Project

I created this in Visual Studio 2005. (yes, I know, it's all I had) To launch the project in Visual Studio, just click on idw_winX.sln. The main C++ file is */I Don't Want Windows 10/I Don't Want Windows 10.cpp*.

## How it Works
In the main C++ file, the program makes sure it's not being run on any Windows other than Windows 7 and Windows 8.1, and makes sure it's not being run under WoW64 in 64-bit Windows. (See issues section of this readme) The program then executes a system() call to *wusa /uninstall /kb:3035583* to finally uninstall the GWX update.

## Issues
The two major issues I have encountered with this code is that it can't run under WoW64 because for some reason, *%windir%\sysnative\wusa.exe* does not exist. The solution for this is that we have to ship both x86 and x64 bianaries, but I will continue to try to fix this so we only have to ship x86 bianaries. The other main issue I've been having is that for the life of me I can't get a message box to spawn. The two main scenarios where we would want a message box to spawn would be when the x86 bianary is being run from x64 or if the user is using an unsupported version of Windows. As a tempoary solution, I just echoed the message into a cmd window, but we should try to get this fixed as soon as possible.
