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
	static void Clear();
	static void UseANSIEscapeCode();
	static void DisableResize();
	static void SetSize(int w, int h);
	static void SetPosition(int x, int y);
	static void DisableUserSelection();
	static void SetCursorBlinking(bool status);
	static void DisableScrollBar();
	static void SetCloseButton(bool status);
	static void SetMinimizeButton(bool status);
	static void SetVisible(bool status);
	static void SetTitle(std::string title);
	static void SetFont(std::string fontName, int fontSize);
};


#endif