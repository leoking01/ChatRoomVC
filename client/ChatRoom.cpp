// ChatRoom.cpp : Defines the class behaviors for the application.
// Download by http://www.codesc.net

#include "stdafx.h"
#include "ChatRoom.h"
#include "ChatRoomDlg.h"
#include "ClientSocket.h"

CClientSocket curSocket;//ȫ�ֱ���

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatRoomApp

BEGIN_MESSAGE_MAP(CChatRoomApp, CWinApp)
	//{{AFX_MSG_MAP(CChatRoomApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomApp construction

CChatRoomApp::CChatRoomApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CChatRoomApp object

CChatRoomApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CChatRoomApp initialization

BOOL CChatRoomApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif


	CChatRoomDlg dlg(&curSocket);
	m_pMainWnd = &dlg;
	curSocket.SetDlg(&dlg);


	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
