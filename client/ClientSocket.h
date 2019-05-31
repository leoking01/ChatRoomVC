#if !defined(AFX_CLIENTSOCKET_H__D56E757B_A1B5_4522_BFBC_75A295C5ED08__INCLUDED_)
#define AFX_CLIENTSOCKET_H__D56E757B_A1B5_4522_BFBC_75A295C5ED08__INCLUDED_
class CChatRoomDlg;
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:
   CChatRoomDlg *myDlg;//添加数据成员
   CString NikeName; 
   BOOL SetDlg(CChatRoomDlg *tmp);//添加成员函数
// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();
    virtual void OnReceive(int nErrorCode);//重载的虚成员函数OnReceive
// Overrides
public:
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

#endif // !defined(AFX_CLIENTSOCKET_H__D56E757B_A1B5_4522_BFBC_75A295C5ED08__INCLUDED_)
