#if !defined(AFX_LISTENSOCKET_H__A780FA3B_6310_4224_A0D0_33F10E59FF36__INCLUDED_)
#define AFX_LISTENSOCKET_H__A780FA3B_6310_4224_A0D0_33F10E59FF36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CListenSocket command target
#include "ClientSocketList.h"

class CListenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocketList CCSL;//�����׽�������
	CListenSocket();
	virtual ~CListenSocket();
    virtual void OnAccept(int nErrorCode);//�����麯��
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenSocket)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENSOCKET_H__A780FA3B_6310_4224_A0D0_33F10E59FF36__INCLUDED_)
