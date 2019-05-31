// ClientSocketList.cpp: implementation of the CClientSocketList class.
// Download by http://www.codesc.net
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ChatRoomServer.h"
#include "ClientSocketList.h"
#include "ClientSocket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientSocketList::CClientSocketList()
{
    Head=0;
}

CClientSocketList::~CClientSocketList()
{

}

//��Socket�������������
BOOL CClientSocketList::Add(CClientSocket *add)
{
	CClientSocket *tmp=Head;
	if (!Head)
	{
		Head=add;
		return false;
	}

	while (tmp->Next)
	{
		tmp=tmp->Next;
	}
	tmp->Next=add;
	return true;
}

//�����������ɾ��Socket
BOOL CClientSocketList::Del(CClientSocket *d)
{
	CClientSocket *p1=Head;
	CClientSocket *p2;
	if (!Head)
	{
		return false;
	}

	if (Head==d)
	{
		Head=p1->Next;
		p1->Close();
		delete p1;
		return true;
	}

	for (;p1->Next!=NULL;p1=p1->Next)
	{
		if (p1->Next==d)
		{
			p2=p1->Next;
			p1->Next=p2->Next;
			p2->Close();
			delete p2;
			return true;
		}
	}
	return false;
}

//�������û�������Ϣ
BOOL CClientSocketList::Sends(char *buff,int n)
{
	CClientSocket *curr=Head;
	while (curr)
	{
		curr->Send(buff,n);
		curr=curr->Next;
	}
	return true;
}

//������˽���û�who������Ϣ
BOOL CClientSocketList::OnlySend(char *buff,int n,int who)
{
	CClientSocket *curr=Head;
	while (curr && who>0)
	{
		curr=curr->Next;
		who--;
	}
	curr->Send(buff,n);
	return true;
}