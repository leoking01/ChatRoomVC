// ClientSocketList.h: interface for the CClientSocketList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_)
#define AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//�����׽���ͷ�ļ�
#include "ClientSocket.h"

class CClientSocketList  
{
public:
	CClientSocketList();
	virtual ~CClientSocketList();

	//��Ա����
	BOOL Del(CClientSocket *d);//ɾ���׽��ֺ���
	BOOL OnlySend(char *buff,int n,int who);//˽�ķ�����Ϣ����
	BOOL Sends(char *buff,int n);//������Ϣ����
	BOOL Add(CClientSocket *add);//���׽�����������׽��ֵĺ���
	//��Ա����
	CClientSocket *Head;


};

#endif // !defined(AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_)
