// ChatRoomDlg.cpp : implementation file
// Download by http://www.codesc.net

#include "stdafx.h"
#include "ChatRoom.h"
#include "ChatRoomDlg.h"

#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
CImageList m_ImageList;
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
// CChatRoomDlg dialog
//CClientSocket curSocket;
CChatRoomDlg::CChatRoomDlg(CClientSocket *tmp,CWnd* pParent /*=NULL*/)
	: CDialog(CChatRoomDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatRoomDlg)
	m_IDC_EDIT_NIKENAME = _T("");
	m_IDC_EDIT_ADDRESS = _T("127.0.0.1");
	m_IDC_EDIT_MESSAGE = _T("");
	m_SL = FALSE;
	m_edit2 = _T("");
	m_edit3 = _T("");
	m_edit4 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	myServerSocket =tmp;
}

void CChatRoomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatRoomDlg)
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_combox);
	DDX_Control(pDX, IDC_LIST4, m_list);
	DDX_Control(pDX, IDC_LIST2, m_hei);
	DDX_Control(pDX, IDC_SendButton, m_BNSend);
	DDX_Control(pDX, IDC_ExitButton, m_BNExit);
	DDX_Control(pDX, IDC_ConnectButton, m_BNLINK);
	DDX_Control(pDX, IDC_USER, m_USER);
	DDX_Control(pDX, IDC_LIST1, m_ChatList);
	DDX_Text(pDX, IDC_EDIT_NIKENAME, m_IDC_EDIT_NIKENAME);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_IDC_EDIT_ADDRESS);
	DDX_Text(pDX, IDC_EDIT_MESSAGE, m_IDC_EDIT_MESSAGE);
	DDX_Check(pDX, IDC_CHECK1, m_SL);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT4, m_edit4);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatRoomDlg, CDialog)
	//{{AFX_MSG_MAP(CChatRoomDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ConnectButton, OnConnectButton)
	ON_BN_CLICKED(IDC_SendButton, OnSendButton)
	ON_BN_CLICKED(IDC_ExitButton, OnExitButton)
	ON_BN_CLICKED(IDC_BUTTON1, Onselectfile)
	ON_BN_CLICKED(IDC_BUTTON2, Onsendfile)
	ON_BN_CLICKED(IDC_BUTTON3, Onlahei)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, Onjiemi)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomDlg message handlers

BOOL CChatRoomDlg::OnInitDialog()
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
	HICON myIcon[5];
	myIcon[0]=AfxGetApp()->LoadIcon(IDI_ICON1);
	myIcon[1]=AfxGetApp()->LoadIcon(IDI_ICON4);
	myIcon[2]=AfxGetApp()->LoadIcon(IDI_ICON5);
	myIcon[3]=AfxGetApp()->LoadIcon(IDI_ICON6);
	myIcon[4]=AfxGetApp()->LoadIcon(IDI_ICON7);
	m_ImageList.Create(32,32,ILC_COLOR8|ILC_MASK,4,4);
	for(int i=0;i<5;i++)
	{	m_ImageList.Add(myIcon[i]);}
	m_list.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_combox.SetImageList(&m_ImageList);
	for(int j=0;j<5;j++)
	{
		COMBOBOXEXITEM cbi={0};
		CString str;
		int nItem;
		cbi.mask=CBEIF_IMAGE|CBEIF_INDENT|CBEIF_OVERLAY|CBEIF_SELECTEDIMAGE|CBEIF_TEXT;
		cbi.iItem=j;
		str.Format(_T("#%d"),j);
		cbi.pszText=(LPTSTR)(LPCTSTR)str;
		cbi.cchTextMax=str.GetLength();
		cbi.iImage=j;
		cbi.iSelectedImage=j;
		cbi.iOverlay=2;
		cbi.iIndent=0;
		nItem=m_combox.InsertItem(&cbi);
		ASSERT(nItem==j);
	}
	m_combox.SetCurSel(0);
	m_BNSend.EnableWindow(FALSE);//初始化时禁用按钮
	m_BNExit.EnableWindow(FALSE);
	 // return TRUE  unless you set the focus to a control
	return TRUE;
}

void CChatRoomDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatRoomDlg::OnPaint() 
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
HCURSOR CChatRoomDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChatRoomDlg::OnConnectButton() //连接聊天室服务器
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	char *nikename;
	char *address;
	int n;
	if (!myServerSocket->Create())
	{
		myServerSocket->Close();
		AfxMessageBox("网络创建错误！！");
		return;
	}
	n=m_IDC_EDIT_ADDRESS.GetLength();
	address=new char(n+1);
	sprintf(address,"%s",m_IDC_EDIT_ADDRESS.GetBuffer(n));
	address[n]=0;
	n=m_IDC_EDIT_NIKENAME.GetLength();
	nikename=new char(n+1);
	sprintf(nikename,"%s",m_IDC_EDIT_NIKENAME.GetBuffer(n));
	nikename[n]=0;
	if (n==0)
	{
		myServerSocket->Close();
		AfxMessageBox("请输入你的昵称！");
		return;
	}
	else if (!myServerSocket->Connect(address,6767))//                端口
	{
		myServerSocket->Close();
		AfxMessageBox("网络连接错误，请检查服务器地址。");
	    return; 
	}
	m_BNSend.EnableWindow(TRUE);
	m_BNExit.EnableWindow(TRUE);
	myServerSocket->NikeName=nikename;
	//发送新用户昵称
	char message2[20];
	strcpy(message2,"NEW_USER|");
	strcat(message2,myServerSocket->NikeName);
	if (myServerSocket->Send(message2,20))//——————————连接聊天室服务器
	{
		AfxMessageBox("连接成功！！");
		m_BNLINK.EnableWindow(FALSE);
	}
	else
	{
		AfxMessageBox("网络错误！！！");
	}
}

void CChatRoomDlg::OnSendButton() 
{
	// TODO: Add your control notification handler code here
	int n;
	char message[1000];
	CString to_name;
	UpdateData(TRUE);
	if (m_IDC_EDIT_MESSAGE=="")
	{
		MessageBox("请输入要发送的消息！","提示",MB_OK);
	}
	else
	{
		if (m_SL==TRUE)//私聊
		{
			if (m_USER.GetCurSel()>=0)
			{
				m_USER.GetText(m_USER.GetCurSel(),to_name);
				m_IDC_EDIT_MESSAGE=myServerSocket->NikeName+"悄悄对"+to_name+"说:"+m_IDC_EDIT_MESSAGE;

				CChatRoomApp *pApp=(CChatRoomApp*)AfxGetApp();
				CChatRoomDlg *pDlg=(CChatRoomDlg*)pApp->m_pMainWnd;

				//在自己的窗口显示消息
				char title[1000];
				strcpy(title,"消息");
				title[4]=(char)((pDlg->m_ChatList.GetCount()%1000/100)+48);
				title[5]=(char)((pDlg->m_ChatList.GetCount()%100/10)+48);
				title[6]=(char)((pDlg->m_ChatList.GetCount()%10+1)+48);
				title[7]=':';
				title[8]=0;
				strcat(title,m_IDC_EDIT_MESSAGE);
				m_ChatList.AddString(title);

				m_IDC_EDIT_MESSAGE="PrivChat|"+to_name+"|"+m_IDC_EDIT_MESSAGE;
				n=m_IDC_EDIT_MESSAGE.GetLength();
				sprintf(message,"%s",m_IDC_EDIT_MESSAGE.GetBuffer(n));
				message[n]=0;
			}
			else
			{
				AfxMessageBox("请选择私聊对象！");
				return;
			}
		}
		else
		{
			m_IDC_EDIT_MESSAGE=myServerSocket->NikeName+"对大家说:"+m_IDC_EDIT_MESSAGE;
			n=m_IDC_EDIT_MESSAGE.GetLength();
			sprintf(message,"%s",m_IDC_EDIT_MESSAGE.GetBuffer(n));
			message[n]=0;
		}
		if (myServerSocket->Send(message,n+1))
		{
			m_IDC_EDIT_MESSAGE="";
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox("网络错误！");
		}
	}

}

void CChatRoomDlg::OnExitButton() 
{
	// TODO: Add your control notification handler code here
	char message2[20];
	strcpy(message2,"CLOSEUSE|");
	strcat(message2,myServerSocket->NikeName);
	if (myServerSocket->Send(message2,20))//————————离开聊天室
	{
	}
	else
	{
		AfxMessageBox("网络错误！下线信息未发送！");
	}
	CDialog::OnOK();
}

BOOL CChatRoomDlg::GetMessage()//显示聊天信息
{
	char buff[2000];
	char name[20];
	int count;
	count=myServerSocket->Receive(buff,2000);
	buff[count]=0;
	char Flag[10];
	int i;
	for (  i=0;i<8;i++)
	{
		Flag[i]=buff[i];
	}

	CChatRoomApp *pApp=(CChatRoomApp*)AfxGetApp();
	CChatRoomDlg *pDlg=(CChatRoomDlg*)pApp->m_pMainWnd;


	Flag[8]=0;
    if (strcmp(Flag,"USERLIST")==0)//新用户昵称列表
    {
		int user_count=pDlg->m_USER.GetCount();//记录下当前用户数目

		m_USER.ResetContent();//清空列表
		CString sTemp;
		int j=8;

		for (i=8;buff[i]!=0;i++)
		{
			if (buff[i]=='|')//昵称分隔符号
			{
				int m;
				for (   m=0;j<i;j++,m++)
				{
					name[m]=buff[j];
				}
				name[m]='\0';
				sTemp.Format("%s",name);//昵称
				m_USER.AddString(sTemp);
				j=i+1;
			}
		}

		if(pDlg->m_USER.GetCount()>user_count)
			pDlg->PlayMySound(IDR_NEWUSER);//当用户数增加时，表明有新用户加入，播放欢迎音乐
		else
			pDlg->PlayMySound(IDR_LEAVE);//当用户数减少时，表明有用户离开，播放离开音乐
    }
	else if(strcmp(Flag,"sendfile")==0)    //接收文件
	{
		CString inside;
		CString filename2="";
		int j=8;
		char filein[1000];
		for(i=8;buff[i]!=0;i++)
		{
			if(buff[i]=='|')
			{
				int  m;
				for(    m=0;j<i;j++,m++)
				{
					filein[m]=buff[j];

				}
				filein[m]='\0';
				j=i+1;
			}
		}
		if(MessageBox("有人向你发送文件，是否要另存为在指定位置？","提示",MB_OKCANCEL)==IDOK)
		{
			CFileDialog dlg(false,""," ",OFN_ALLOWMULTISELECT,NULL);
			dlg.DoModal();
			filename2=dlg.GetFileName();
			CFile file2;
			file2.Open(filename2,CFile::modeCreate|CFile::modeReadWrite);
			file2.Write(filein,strlen(filein));
			file2.Close();
		}
	}
	else if(strcmp(Flag,"sendface")==0)
	{
		int inde;
		CString in;
		CString user;
		char ind[10];
		char user1[10];
		ind[0]=buff[8];
		user1[0]=buff[9];
		ind[1]=0;
		user.Format("%s",user1);
		in.Format("%s",ind);
		inde=atoi(ind);
		char mess[1000];
		strcpy(mess,user);
	char p[1000];
	strcpy(p,mess);
	p[1]='\0';
	LVITEM lvitem;
	lvitem.mask=LVIF_IMAGE|LVIF_TEXT;
	lvitem.iItem=inde;
	lvitem.pszText=p;
	lvitem.iImage=inde;
	lvitem.iSubItem=0;
	m_list.InsertItem(&lvitem);
		
	}
    else//聊天信息
	{
		pDlg->PlayMySound(IDR_MESSAGE);

		char title[1000];
		int h;
		CString sselet;
		CString stemp;
		strcpy(title,"消息");
		title[4]=(char)((pDlg->m_ChatList.GetCount()%1000/100)+48);
		title[5]=(char)((pDlg->m_ChatList.GetCount()%100/10)+48);
		title[6]=(char)((pDlg->m_ChatList.GetCount()%10+1)+48);
		title[7]=':';
		title[8]=0;
		strcat(title,buff);
		h=m_hei.GetCount();
		//sTemp.Format(title,buff);
        for(int i=0;i<h;i++)
			m_hei.GetText(i,name);
			sselet=buff[0];
			if(strcmp(sselet,name)!=0)
			{
				m_ChatList.AddString(title);
			}
	}
	return true;
}

void CChatRoomDlg::PlayMySound(UINT IDSoundRes)
{
	PlaySound(MAKEINTRESOURCE(IDSoundRes),NULL,SND_ASYNC|SND_RESOURCE|SND_NODEFAULT);
}

void CChatRoomDlg::Onselectfile() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE,"*"," ",OFN_ALLOWMULTISELECT,NULL);
	dlg.DoModal();
	CString str=dlg.GetPathName();
	SetDlgItemText(IDC_EDIT1,str);
}

void CChatRoomDlg::Onsendfile() 
{
	// TODO: Add your control notification handler code here
		CString filename1="";
	GetDlgItemText(IDC_EDIT1,filename1);
	CString filename2="";
//	dlg.DoModal();
//	filename2=dlg.GetFilename();
	CFile file1;
	file1.Open(filename1,CFile::modeReadWrite);
	char *c;
	c=new char[file1.GetLength()];
	file1.Read(c,file1.GetLength());
	file1.Close();

	int n;
	char message[1000];
	CString to_name;
	CString all;
	UpdateData(TRUE);

	if (m_USER.GetCurSel()>=0)
			{
				m_USER.GetText(m_USER.GetCurSel(),to_name);

				CChatRoomApp *pApp=(CChatRoomApp*)AfxGetApp();
			CChatRoomDlg *pDlg=(CChatRoomDlg*)pApp->m_pMainWnd;

				all="sendfile|"+to_name+"|"+c;
				n=all.GetLength();
				sprintf(message,"%s",all.GetBuffer(n));
				message[n-16]='\0';
		//		for(int i=n+1;i<1000;i++)
	//		{
	//				message[i]='.';
//	}
	}
		if (myServerSocket->Send(message,n+1))
		{
			//m_IDC_EDIT_MESSAGE="";
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox("网络错误！");
		}
}

void CChatRoomDlg::Onlahei() 
{
	// TODO: Add your control notification handler code here
	CString badname;
	CString badlist;
	if(m_USER.GetCurSel()>=0)
	{
		m_USER.GetText(m_USER.GetCurSel(),badname);
		badlist.Format("%s",badname);
		m_USER.DeleteString(m_USER.GetCurSel());
		m_hei.AddString(badlist);
	}
	else
	{
		AfxMessageBox("请选择拉黑对象！");
	}
}

void CChatRoomDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString str;
	CString str1;
	CString to_name;
	int m_Num;
	int n;
	char message[1000];
	m_Num=m_combox.GetCurSel();
	str.Format("%d",m_Num);
	m_USER.GetText(m_USER.GetCurSel(),to_name);
	str1=myServerSocket->NikeName+"悄悄对"+to_name+"说:"+str;

	CChatRoomApp *pApp=(CChatRoomApp*)AfxGetApp();
	CChatRoomDlg *pDlg=(CChatRoomDlg*)pApp->m_pMainWnd;

	str1="sendface|"+to_name+"|"+str1;
	n=str1.GetLength();
	sprintf(message,"%s",str1.GetBuffer(n));
	message[n]=0;
	if (myServerSocket->Send(message,n+1))
	{
		AfxMessageBox("发送成功！");
	}
	else
	{
		AfxMessageBox("网络错误！");
	}

	char mess[200];
	CString str2="我发送给";
	strcpy(mess,str2);
	strcat(mess,to_name);
	char p[1000];
	strcpy(p,mess);
	LVITEM lvitem;
	lvitem.mask=LVIF_IMAGE|LVIF_TEXT;
	lvitem.iItem=m_Num;
	lvitem.pszText=p;
	lvitem.iImage=m_Num;
	lvitem.iSubItem=0;
	m_list.InsertItem(&lvitem);
}

void CChatRoomDlg::Onjiemi() 
{
	// TODO: Add your control notification handler code here
	CString g2;
	CString g3;
	CString g5;
	CString xian;
	int m,n,p;
	char c[100];
	GetDlgItemText(IDC_EDIT2,g2);
	GetDlgItemText(IDC_EDIT3,g3);m=atoi(g3);
	GetDlgItemText(IDC_EDIT5,g5);p=atoi(g5);
	n=g2.GetLength();
	for(int i=0;i<n;i++){
	c[i]=g2.GetAt(i);c[i]=c[i]-m;
	}c[n-p-1]='\0';
	xian=c;
	SetDlgItemText(IDC_EDIT4,xian);
}

void CChatRoomDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CString to_name;char message[1000];
	m_USER.GetText(m_USER.GetCurSel(),to_name);
	CString g3;
	CString g4;CString g5;
	GetDlgItemText(IDC_EDIT3,g3);
		GetDlgItemText(IDC_EDIT_MESSAGE,g4);
	GetDlgItemText(IDC_EDIT5,g5);
	CString xian;
	int m,n,p;
	char c[100];
	m=atoi(g3);
	p=atoi(g5);
	n=g4.GetLength();
	for(int i=0;i<n;i++){
		c[i]=g4.GetAt(i);c[i]=c[i]+m;}c[n+p+1]='\0';
	xian=c;
				m_IDC_EDIT_MESSAGE=myServerSocket->NikeName+"悄悄对"+to_name+"说:"+xian;

				CChatRoomApp *pApp=(CChatRoomApp*)AfxGetApp();
				CChatRoomDlg *pDlg=(CChatRoomDlg*)pApp->m_pMainWnd;

				//在自己的窗口显示消息
				char title[1000];
				strcpy(title,"消息");
				title[4]=(char)((pDlg->m_ChatList.GetCount()%1000/100)+48);
				title[5]=(char)((pDlg->m_ChatList.GetCount()%100/10)+48);
				title[6]=(char)((pDlg->m_ChatList.GetCount()%10+1)+48);
				title[7]=':';
				title[8]=0;
				strcat(title,m_IDC_EDIT_MESSAGE);
				m_ChatList.AddString(title);

				m_IDC_EDIT_MESSAGE="PrivChat|"+to_name+"|"+m_IDC_EDIT_MESSAGE;
				n=m_IDC_EDIT_MESSAGE.GetLength();
				sprintf(message,"%s",m_IDC_EDIT_MESSAGE.GetBuffer(n));
				message[n]=0;
				if (myServerSocket->Send(message,n+1))
		{
			m_IDC_EDIT_MESSAGE="";
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox("网络错误！");
		}
}
