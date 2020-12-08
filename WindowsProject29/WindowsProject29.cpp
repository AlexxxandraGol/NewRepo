#define _AFXDLL
#include <afxwin.h>
#include <afxwin.h>
#include "dialog.h""
#include "ids.h""
char name[] = "SampleDialog";
CMainWin::CMainWin()
{
	Create(NULL, "Demonstrate Dialog Boxes",
		WS_OVERLAPPEDWINDOW, rectDefault,
		NULL, "DialogMenu");
	if (!LoadAccelTable("DialogMenu"))
		MessageBox("Cannot Load Accelerators", "Error");
}
BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_COMMAND(IDM_DIALOG, OnDialog)
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_COMMAND(IDM_HELP, OnHelp)
END_MESSAGE_MAP()
afx_msg void CMainWin::OnDialog()
{
	CSampleDialog diagOb(name, this);
	diagOb.DoModal();
}
afx_msg void CMainWin::OnExit()
{
	int response;
	response = MessageBox("Quit the Program?", "Exit", MB_YESNO);
	if (response == IDYES)
		SendMessage(WM_CLOSE);
}
afx_msg void CMainWin::OnHelp()
{
	MessageBox("Dialog Demo", "Help");
}
BEGIN_MESSAGE_MAP(CSampleDialog, CDialog)
	ON_COMMAND(IDD_RED, OnRed)
	ON_COMMAND(IDD_GREEN, OnGreen)
END_MESSAGE_MAP()
	afx_msg void CSampleDialog::OnRed()
{
	MessageBox("Red", "Color Selected");
}
afx_msg void CSampleDialog::OnGreen()
{
	MessageBox("Green", "Color Selected");
}