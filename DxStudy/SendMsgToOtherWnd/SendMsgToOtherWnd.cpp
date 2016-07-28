// SendMsgToOtherWnd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

static HWND s_hwnd = NULL;
void SendKey(HWND hWnd ,DWORD dwVk);


BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lparam)
{
	wchar_t lpWinTitle[256]; 
	::GetWindowText(hwnd,lpWinTitle,256-1); 
	std::wstring strTitle = lpWinTitle;
	if (std::wstring::npos != strTitle.find(L"xx"))
	{
		//MessageBox(NULL, L"find", L"find", MB_YESNOCANCEL | MB_ICONQUESTION);
		s_hwnd = hwnd;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//EnumWindows
	EnumWindows(EnumWindowsProc, 0);


	//HWND hWnd = (HWND)FindWindow(NULL, L"xx");
	///HWND hWnd = (HWND)FindWindow(NULL, L"xx");
	//SendInput();s
	//::PostMessage(hWnd, WM_CLOSE, 0, 0);
	//::PostMessage(hWnd, WM_DESTROY, 0, 0);
	//::ShowWindow(hWnd, SW_MINIMIZE);
	if (s_hwnd)
	{
		//BringWindowToTop(s_hwnd);
		//::SetForegroundWindow(s_hwnd);
		//::SetActiveWindow(s_hwnd);
		//SwitchToThisWindow(s_hwnd, true);
// 		AttachThreadInput(
// 			//::GetWindowThreadProcessId(::GetForegroundWindow(),NULL),  //当前焦点窗口的线程ID
// 			::GetWindowThreadProcessId(s_hwnd,NULL),  //当前焦点窗口的线程ID
// 			//::GetCurrentThreadId(),  //自己的线程ID
// 			0,
// 			TRUE);
// 		AttachThreadInput(
// 			::GetCurrentThreadId(),  //自己的线程ID
// 			::GetWindowThreadProcessId(::GetForegroundWindow(),NULL),  //当前焦点窗口的线程ID
// 			TRUE);

		::PostMessage(s_hwnd, WM_KEYDOWN, VK_RETURN, 0);
		Sleep(100);
		::PostMessage(s_hwnd, WM_KEYDOWN, 0x41, 0);
		::PostMessage(s_hwnd, WM_KEYDOWN, 0x41, 0);
		::PostMessage(s_hwnd, WM_KEYDOWN, 0x41, 0);
		::PostMessage(s_hwnd, WM_KEYDOWN, 0x42, 0);
		Sleep(100);
		::PostMessage(s_hwnd, WM_KEYDOWN, VK_RETURN, 0);
		//SendKey(s_hwnd, 0x4f);//'o' 键
	}
	
	return 0;
}

void SendKey(HWND hWnd ,DWORD dwVk)
{
	Sleep(5000);
	INPUT inputs[2];
	SecureZeroMemory(inputs, sizeof(inputs));

	inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = static_cast<WORD>(dwVk);
	inputs[1] = inputs[0];
	inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

	if (hWnd)
	{
		SendInput(_countof(inputs), inputs, sizeof(INPUT));
	}
}