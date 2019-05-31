; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChatRoomServerDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ChatRoomServer.h"

ClassCount=5
Class1=CChatRoomServerApp
Class2=CChatRoomServerDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CListenSocket
Class5=CClientSocket
Resource3=IDD_CHATROOMSERVER_DIALOG

[CLS:CChatRoomServerApp]
Type=0
HeaderFile=ChatRoomServer.h
ImplementationFile=ChatRoomServer.cpp
Filter=N

[CLS:CChatRoomServerDlg]
Type=0
HeaderFile=ChatRoomServerDlg.h
ImplementationFile=ChatRoomServerDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CChatRoomServerDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=ChatRoomServerDlg.h
ImplementationFile=ChatRoomServerDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHATROOMSERVER_DIALOG]
Type=1
Class=CChatRoomServerDlg
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_LIST1,listbox,1352728835
Control3=IDC_STATIC,button,1342177287
Control4=IDC_USER,listbox,1352728835
Control5=IDC_BUTTON_START,button,1342242816
Control6=IDC_BUTTON_STOP,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_MESSAGE,edit,1350631552
Control9=IDC_BUTTON_SEND,button,1342242816

[CLS:CListenSocket]
Type=0
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp
BaseClass=CSocket
Filter=N

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N

