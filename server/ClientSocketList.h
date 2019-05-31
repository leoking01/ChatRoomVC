// ClientSocketList.h: interface for the CClientSocketList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_)
#define AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//连接套接字头文件
#include "ClientSocket.h"

class CClientSocketList  
{
public:
	CClientSocketList();
	virtual ~CClientSocketList();

	//成员函数
	BOOL Del(CClientSocket *d);//删除套接字函数
	BOOL OnlySend(char *buff,int n,int who);//私聊发送消息函数
	BOOL Sends(char *buff,int n);//发送消息函数
	BOOL Add(CClientSocket *add);//向套接字链表添加套接字的函数
	//成员变量
	CClientSocket *Head;


};

#endif // !defined(AFX_CLIENTSOCKETLIST_H__77687323_9352_4143_B974_61814CBD23FC__INCLUDED_)
