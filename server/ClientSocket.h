#if !defined(AFX_CLIENTSOCKET_H__CE29608D_C52C_49A9_8CC9_F2A072CE859F__INCLUDED_)
#define AFX_CLIENTSOCKET_H__CE29608D_C52C_49A9_8CC9_F2A072CE859F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//

//把类重新声明下
class CClientSocketList;
class CChatRoomServerDlg;


/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:
    CChatRoomServerDlg *myDlg;//指向对话框的对象
// Operations
public:
	CClientSocket();
	CClientSocket(CClientSocketList *);//重载函数
	virtual ~CClientSocket();

// Overrides
public:
	BOOL SetDlg(CChatRoomServerDlg *tmp);//成员函数
    virtual void OnReceive(int nErrorCode);//重载虚函数
	//virtual void OnClose(int nErrorCode);


    CClientSocketList *List;
	CClientSocket *Front;
	CClientSocket *Next;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__CE29608D_C52C_49A9_8CC9_F2A072CE859F__INCLUDED_)
