// ClientSocket.cpp : implementation file
// Download by http://www.codesc.net

#include "stdafx.h"
#include "ChatRoomServer.h"
#include "ClientSocket.h"
#include "ClientSocketList.h"
#include "ChatRoomServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
	myDlg=0;
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

//�����Ĺ��캯��
CClientSocket::CClientSocket(CClientSocketList *tmp)
{
	Front =0;
	Next =0;
	List=tmp;
}

//��ȡ�Ի���ָ��
BOOL CClientSocket::SetDlg(CChatRoomServerDlg *tmp)
{
	myDlg=tmp;
	return true;
}

//���ص��麯��
void CClientSocket::OnReceive(int nErrorCode)
{
	char buff[1000];
	char all_user[2000];
	char name[20];
	char file[1000];
	char pic[1000];
	char pro[1000];
	int n;
	int m;
	n=this->Receive(buff,1000);
	char pp[2];
	char ppp[2];
	ppp[0]=buff[11];
	ppp[1]=0;
	pp[0]=buff[22];
	pp[1]=0;
	buff[n]=0;
	char Flag[10];
	int i;
	for (  i=0;i<8;i++)
	{
		Flag[i]=buff[i];
	}
	Flag[8]=0;

	//�������д���������ȡ�Ի���ָ��
	CChatRoomServerApp *pApp=(CChatRoomServerApp*)AfxGetApp();
	CChatRoomServerDlg *pDlg=(CChatRoomServerDlg*)pApp->m_pMainWnd;


	
	if (strcmp(Flag,"NEW_USER")==0)//���û�����
	{
		pDlg->PlayMySound(IDR_NEWUSER);
		CString sTemp;
		for (i=9;buff[i]!=0;i++)
		{
			buff[i-9]=buff[i];
		}
		buff[i-9]=0;
		sTemp.Format("%s",buff);//���û��ǳ�
		pDlg->m_USER.AddString(sTemp);
		//���µ������û��ǳ��������������û�
		m=pDlg->m_USER.GetCount();
		strcpy(all_user,"USERLIST");
		for (i=0;i<m;i++)
		{
			pDlg->m_USER.GetText(i,name);
			strcat(all_user,name);
			strcat(all_user,"|");
		}
		strcat(buff,"����������");
		List->Sends(all_user,strlen(all_user));
	}
	else
	{
		pDlg->PlayMySound(IDR_LEAVE);
		if (strcmp(Flag,"CLOSEUSE")==0)//�û��˳�
		{
			CString sTemp;
			for (i=9;buff[i]!=0;i++)
			{
				buff[i-9]=buff[i];
			}
			buff[i-9]=0;
			sTemp.Format("%s",buff);//�����û��ǳ�
			m=pDlg->m_USER.GetCount();
			for (i=0;i<m;i++) //���������û����б���������
			{
				pDlg->m_USER.GetText(i,name);
				if (strcmp(name,buff)==0)//�Ƚ��ַ���name��buff���൱ʱ����Ϊ��,����Ϊ�����ʱ�Ĳ���
				{
					pDlg->m_USER.DeleteString(i);//ɾ���������
				}
			}
			
			//���µ������û��ǳ��������������û�
			m=pDlg->m_USER.GetCount();
			strcpy(all_user,"USERLIST");//��˵���ǽ�USERLIST���Ƶ�all_user��
			for (i=0;i<m;i++)
			{
				pDlg->m_USER.GetText(i,name);
				strcat(all_user,name);
				strcat(all_user,"|");//��˵���ǽ���|����ӵ�all_user�����
			}
			strcat(buff,"�뿪�����ң�");
			List->Sends(all_user,strlen(all_user));//strlen()�����Ǽ����ַ������ȵ�
			List->Del(this);
		}
		else if (strcmp(Flag,"PrivChat")==0)//˽��
		{
			pDlg->PlayMySound(IDR_MESSAGE);
			CString sTemp;
			for (i=9;buff[i]!='|';i++)
			{
				buff[i-9]=buff[i];
			}
			buff[i-9]=0;
			sTemp.Format("%s",buff);//˽�Ķ����ǳ�
			int k;
			for (  k=i+1;buff[k]!=0;k++)
			{
				buff[k-i-1]=buff[k];
			}
			buff[k-i-1]=0;
			m=pDlg->m_USER.GetCount();
			for (i=0;i<m;i++)//���������û����б���������
			{
				pDlg->m_USER.GetText(i,name);
				if (strcmp(name,sTemp)==0)
				{
					List->OnlySend(buff,strlen(buff),i);
				}
			}
		}
		else if (strcmp(Flag,"sendface")==0)     //     ���ͱ���
		{
			
			CString sTemp;
			for (i=9;buff[i]!='|';i++)
			{
				buff[i-9]=buff[i];
			}
			buff[i-9]=0;
			sTemp.Format("%s",buff);
			int k;
			for (  k=i+1;buff[k]!=0;k++)
			{
				buff[k-i-1]=buff[k];
			}
			buff[k-i-1]=0;
			m=pDlg->m_USER.GetCount();
			for (i=0;i<m;i++)//���������û����б���������
			{
				pDlg->m_USER.GetText(i,name);
				if (strcmp(name,sTemp)==0)
				{
					strcpy(pic,"sendface");
					strcat(pic,pp);
					strcat(pic,ppp);
					pic[10]='\0';
					List->OnlySend(pic,strlen(pic),i);
				}
			}
		}
		else if(strcmp(Flag,"sendfile")==0)           //�����ļ�
		{
			CString sTemp;
			for(i=9;buff[i]!='|';i++)
			{
				buff[i-9]=buff[i];
			}
			buff[i-9]=0;
			sTemp.Format("%s",buff);
			int k;
			for (  k=i+1;buff[k]!=0;k++)
			{
				buff[k-i-1]=buff[k];
			}
			buff[k-i-1]=0;
			m=pDlg->m_USER.GetCount();
			for (i=0;i<m;i++)//���������û����б���������
			{
				pDlg->m_USER.GetText(i,name);
				if (strcmp(name,sTemp)==0)
				{
					strcpy(file,"sendfile");
					strcat(file,buff);
					strcat(file,"|");
					strcat(file,sTemp);
					List->OnlySend(file,strlen(file),i);
				}
			}
		}
		else
		{
			pDlg->PlayMySound(IDR_MESSAGE);
			List->Sends(buff,n);//��������ϢȺ���������û�
		}
	}
	CString sTemp;
	char title[1000];
	strcpy(title,"��Ϣ");
	title[4]=(char)((pDlg->m_ChatList.GetCount()%1000/100)+48);
	title[5]=(char)((pDlg->m_ChatList.GetCount()%100/10)+48);
	title[6]=(char)((pDlg->m_ChatList.GetCount()%10)+48);
	title[7]=':';
	title[8]=0;
	strcat(title,buff);
	sTemp.Format(title,buff);
	//sTemp.Format("��Ϣ��%s",buff);
	pDlg->m_ChatList.AddString(sTemp);
	pDlg->m_ChatList.SetTopIndex(pDlg->m_ChatList.GetCount()-1);
	CSocket::OnReceive(nErrorCode);
}
