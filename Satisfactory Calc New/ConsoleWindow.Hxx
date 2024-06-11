#pragma once

#ifndef _CONSOLE_WINDOW_HXX_
#define _CONSOLE_WINDOW_HXX_

#include "Color.Hxx"
#include "ConsoleScene.Hxx"
#include "ConsoleManager.Hxx"

class ConsoleWindow {

private:

	ConsoleScene* nowScene;

	char titleBar [TITLE_BAR_HEIGHT ][CONSOLE_WIDTH];
	char bottomBar[BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH];

	std::string     displayBuffer;
	char            renderBuffer   [CONSOLE_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 foregroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 backgroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH];

	void Rerender();
	void Display();


public:

	void ChangeScene(ConsoleScene* scene);
	void Initialize(ConsoleScene* startScene);
	void Run();

};


#endif