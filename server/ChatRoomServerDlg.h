// ChatRoomServerDlg.h : header file
//

#if !defined(AFX_CHATROOMSERVERDLG_H__FC07C698_5331_4CB4_968E_41A053DF5A4E__INCLUDED_)
#define AFX_CHATROOMSERVERDLG_H__FC07C698_5331_4CB4_968E_41A053DF5A4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg dialog
#include "ListenSocket.h"

class CChatRoomServerDlg : public CDialog
{
// Construction
public:
	CChatRoomServerDlg(CWnd* pParent = NULL);	// standard constructor
    CListenSocket ListenSocket;//´´½¨ÕìÌýÌ×½Ó×Ö

	void PlayMySound(UINT IDSoundRes);//²¥·ÅÉùÒô

// Dialog Data
	//{{AFX_DATA(CChatRoomServerDlg)
	enum { IDD = IDD_CHATROOMSERVER_DIALOG };
	CListBox	m_USER;
	CListBox	m_ChatList;
	CButton	m_IDC_BUTTON_STOP;
	CButton	m_IDC_BUTTON_START;
	CButton	m_IDC_BUTTON_SEND;
	CString	m_IDC_BUTTON_MESSAGE;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatRoomServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMSERVERDLG_H__FC07C698_5331_4CB4_968E_41A053DF5A4E__INCLUDED_)
