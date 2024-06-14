#include "ConsoleManager.Hxx"

#undef _WIN32_WINNT
#define _WIN32_WINNT 0x0500

void ConsoleManager::ResetCursor() {
	HANDLE hOut;
	COORD position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(hOut, position);
}

void ConsoleManager::UseANSIEscapeCode() {
	DWORD consoleMode;
	HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (GetConsoleMode(outputHandle, &consoleMode)) {
		SetConsoleMode(outputHandle, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	}
}

void ConsoleManager::DisableResize() {
	HWND console = GetConsoleWindow();
	SetWindowLong(console, GWL_STYLE, GetWindowLong(console, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

	return;
}

void ConsoleManager::SetSize(unsigned w, unsigned h) {
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, w, h, TRUE);

	return;
}

void ConsoleManager::SetPosition(unsigned x, unsigned y) {
	HWND console = GetConsoleWindow();
	SetWindowPos(console, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	return;
}

void ConsoleManager::DisableUserSelection() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prevMode;

	GetConsoleMode(hInput, &prevMode);
	SetConsoleMode(hInput,
		ENABLE_EXTENDED_FLAGS |
		(prevMode & ~ENABLE_QUICK_EDIT_MODE)
	);

	return;
}

void ConsoleManager::SetCursorBlinking(bool status) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = status;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	return;
}

void ConsoleManager::DisableScrollBar() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	COORD new_size = {
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(hOut, new_size);

	return;
}

void ConsoleManager::SetCloseButton(bool status) {
	HWND hwnd = GetConsoleWindow();
	HMENU hmenu = GetSystemMenu(hwnd, FALSE);
	EnableMenuItem(hmenu, SC_CLOSE, status ? MF_ENABLED : MF_GRAYED);

	return;
}

void ConsoleManager::SetMinimizeButton(bool status) {
	HWND hwnd = GetConsoleWindow();
	SetWindowLong(hwnd, GWL_STYLE,
		status ? (GetWindowLong(hwnd, GWL_STYLE) | WS_MINIMIZEBOX) :
		(GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX)
	);

	return;
}

void ConsoleManager::SetVisible(bool status) {
	HWND hwnd;
	AllocConsole();
	hwnd = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(hwnd, status);

	return;
}

void ConsoleManager::SetTitle(std::string _title) {
	TCHAR newTitle[MAX_PATH] {};
	std::wstring newTitleStr = L"";

	newTitleStr.assign(_title.begin(), _title.end());

	StringCchPrintf(newTitle, MAX_PATH, newTitleStr.c_str());
	SetConsoleTitle(newTitle);

	return;
}

void ConsoleManager::SetFont(std::wstring fontName, unsigned fontSize) {
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize       = sizeof(consoleFont);
	consoleFont.nFont        = 0;
	consoleFont.dwFontSize.X = 0;
	consoleFont.dwFontSize.Y = fontSize;
	consoleFont.FontFamily   = FF_DONTCARE;
	consoleFont.FontWeight   = FW_NORMAL;

	wcscpy_s(consoleFont.FaceName, fontName.c_str());
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &consoleFont);
	return;
}

bool ConsoleManager::GetConsoleSelected() {
	return GetConsoleWindow() == GetForegroundWindow();
}
