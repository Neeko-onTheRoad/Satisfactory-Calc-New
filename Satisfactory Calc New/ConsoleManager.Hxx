#pragma once

#ifndef _NEEKOS_CONSOLE_CONTROL_HXX_
#define _NEEKOS_CONSOLE_CONTROL_HXX_

#include <string>
#include <conio.h>
#include <tchar.h>
#include <strsafe.h>
#include <Windows.h>

class ConsoleManager {
public: 
	static void ResetCursor();
	static void UseANSIEscapeCode();
	static void DisableResize();
	static void SetSize(unsigned w, unsigned h);
	static void SetPosition(unsigned x, unsigned y);
	static void DisableUserSelection();
	static void SetCursorBlinking(bool status);
	static void DisableScrollBar();
	static void SetCloseButton(bool status);
	static void SetMinimizeButton(bool status);
	static void SetVisible(bool status);
	static void SetTitle(std::string title);
	static void SetFont(std::wstring fontName, unsigned fontSize);
};


#endif