#pragma once

class ServerSession;
using ServerSessionRef = shared_ptr<class ServerSession>;

// CChatClientDlg 대화 상자
class CChatClientDlg : public CDialogEx
{
// 생성입니다.
public:
	CChatClientDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHATCLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void	OnBnClickedSendBtn();
	void			AddEventString(const WCHAR* ap_string);
	CListBox		chatList;
	CListBox		roomList;
	CEdit			chatName;

public:
	afx_msg void OnBnClickedConnectBtn();
	afx_msg void OnEnChangeServerIp();
	afx_msg void OnEnChangeChatName();
	afx_msg void OnLbnSelchangeChatList();
	afx_msg void OnEnChangeChatEdit();
	afx_msg void OnEnChangeServerPort();

public:
	bool				_isConnected = false;
	ServerSessionRef	_serverSession;
};
