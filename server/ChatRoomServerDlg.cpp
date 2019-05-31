// ChatRoomServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChatRoomServer.h"
#include "ChatRoomServerDlg.h"
#include "ListenSocket.h"

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg dialog

CChatRoomServerDlg::CChatRoomServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatRoomServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatRoomServerDlg)
	m_IDC_BUTTON_MESSAGE = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatRoomServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatRoomServerDlg)
	DDX_Control(pDX, IDC_USER, m_USER);
	DDX_Control(pDX, IDC_LIST1, m_ChatList);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_IDC_BUTTON_STOP);
	DDX_Control(pDX, IDC_BUTTON_START, m_IDC_BUTTON_START);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_IDC_BUTTON_SEND);
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_IDC_BUTTON_MESSAGE);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatRoomServerDlg, CDialog)
	//{{AFX_MSG_MAP(CChatRoomServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg message handlers

BOOL CChatRoomServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_IDC_BUTTON_STOP.EnableWindow(FALSE);//“停止”按钮最初是无效的
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatRoomServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatRoomServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChatRoomServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//开启服务器按钮
void CChatRoomServerDlg::OnButtonStart() 
{
    if (!ListenSocket.Create(6767))//绑定端口
    {
		AfxMessageBox("绑定端口失败！请确认该端口没有被其它程序占用！");
		return;
    }
	if (!ListenSocket.Listen())//服务器侦听
	{
		AfxMessageBox("侦听失败！");
		return;
	}
	m_IDC_BUTTON_START.EnableWindow(FALSE);//让开启按钮失效
	AfxMessageBox("服务器开启成功！");
	CString tTmep;
	tTmep="系统消息：服务器已开启成功！";
	m_ChatList.AddString(tTmep);
	m_IDC_BUTTON_STOP.EnableWindow(TRUE);//恢复停止按钮
}

void CChatRoomServerDlg::OnButtonStop() 
{
    m_IDC_BUTTON_STOP.EnableWindow(FALSE);
	char s[30]="聊天服务器停止工作了！！";
	ListenSocket.CCSL.Sends(s,30);//广播聊天服务器停止消息
	CClientSocket *p=ListenSocket.CCSL.Head;
	while (p)
	{
		p->Close();
		ListenSocket.CCSL.Del(p);//释放链表中的套接字
		p=ListenSocket.CCSL.Head;
	}
	ListenSocket.Close();
	m_USER.ResetContent();//清除服务器在线用户列表
	m_IDC_BUTTON_START.EnableWindow(TRUE);
}

void CChatRoomServerDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	int n;
	char message[1000];
	UpdateData(TRUE);
	if (m_IDC_BUTTON_MESSAGE=="")
	{
		MessageBox("请输入消息！！","提示",MB_OK);
	}
	else
	{
		m_IDC_BUTTON_MESSAGE="系统消息："+m_IDC_BUTTON_MESSAGE;
		n=m_IDC_BUTTON_MESSAGE.GetLength();
		sprintf(message,"%s",m_IDC_BUTTON_MESSAGE.GetBuffer(n));
		message[n]=0;
		ListenSocket.CCSL.Sends(message,1000);
	}
	m_IDC_BUTTON_MESSAGE="";
	UpdateData(FALSE);
}

void CChatRoomServerDlg::PlayMySound(UINT IDSoundRes)
{
	PlaySound(MAKEINTRESOURCE(IDSoundRes),NULL,SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
}
