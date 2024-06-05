#pragma once

#ifndef _CONSOLE_WINDOW_HXX_
#define _CONSOLE_WINDOW_HXX_

#include "Color.Hxx"
#include "ConsoleScene.Hxx"
#include "ConsoleManager.Hxx"

class ConsoleWindow {

private:

	ConsoleScene* nowScene;

	char titleBar [TITLE_BAR_HEIGHT ][MAX_CONSOLE_WIDTH];
	char bottomBar[BOTTOM_BAR_HEIGHT][MAX_CONSOLE_WIDTH];

	char    renderBuffer   [MAX_CONSOLE_HEIGHT][MAX_CONSOLE_WIDTH];
	__int16 foregroundColor[MAX_CONSOLE_HEIGHT][MAX_CONSOLE_WIDTH];
	__int16 backgroundColor[MAX_CONSOLE_HEIGHT][MAX_CONSOLE_WIDTH];

	void Rerender();


public:

	bool needUpdate = true;

	void ChangeScene(ConsoleScene* scene);
	void Initialize(ConsoleScene* startScene);
	void Run();

};


#endif