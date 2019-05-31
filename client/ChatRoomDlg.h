// ChatRoomDlg.h : header file
//

#if !defined(AFX_CHATROOMDLG_H__DEADBB61_0724_451C_92D3_C4CD5F08E96A__INCLUDED_)
#define AFX_CHATROOMDLG_H__DEADBB61_0724_451C_92D3_C4CD5F08E96A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatRoomDlg dialog
#include "ClientSocket.h"

class CChatRoomDlg : public CDialog
{
// Construction
public:
	void PlayMySound(UINT IDSoundRes);
	CChatRoomDlg(CClientSocket *tmp,CWnd* pParent = NULL);	// standard constructor
    BOOL GetMessage();
	CClientSocket *myServerSocket;
// Dialog Data
	//{{AFX_DATA(CChatRoomDlg)
	enum { IDD = IDD_CHATROOM_DIALOG };
	CComboBoxEx	m_combox;
	CListCtrl	m_list;
	CListBox	m_hei;
	CButton	m_BNSend;
	CButton	m_BNExit;
	CButton m_BNLINK;
	CListBox	m_USER;
	CListBox	m_ChatList;
	CString	m_IDC_EDIT_NIKENAME;
	CString	m_IDC_EDIT_ADDRESS;
	CString	m_IDC_EDIT_MESSAGE;
	BOOL	m_SL;
	CString	m_edit2;
	CString	m_edit3;
	CString	m_edit4;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatRoomDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnectButton();
	afx_msg void OnSendButton();
	afx_msg void OnExitButton();
	afx_msg void Onselectfile();
	afx_msg void Onsendfile();
	afx_msg void Onlahei();
	afx_msg void OnButton4();
	afx_msg void Onjiemi();
	afx_msg void Onjia();
	afx_msg void Onjiajiami();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMDLG_H__DEADBB61_0724_451C_92D3_C4CD5F08E96A__INCLUDED_)
