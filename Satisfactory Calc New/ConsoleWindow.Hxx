#pragma once

#ifndef _CONSOLE_WINDOW_HXX_
#define _CONSOLE_WINDOW_HXX_

#include <thread>
#include <iostream>
#include <functional>

#include "Color.Hxx"
#include "AsciiMap.Hxx"
#include "KeyManager.Hxx"
#include "ConsoleScene.Hxx"
#include "ConsoleManager.Hxx"
#include "ResourceManager.Hxx"

#include "Wiki.Hxx"
#include "MainScreen.Hxx"

class ConsoleWindow {

private:

	unsigned nowSceneIndex = 0;
	ConsoleScene* nowScene;
	std::vector<ConsoleScene*> scenes;

	char            titleBar               [TITLE_BAR_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 titleBarForegroundColor[TITLE_BAR_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 titleBarBackgroundColor[TITLE_BAR_HEIGHT][CONSOLE_WIDTH];

	char            bottomBar               [BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 bottomBarForegroundColor[BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 bottomBarBackgroundColor[BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH];

	std::string     displayBuffer;
	char            renderBuffer   [CONSOLE_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 foregroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH];
	unsigned __int8 backgroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH];

	void RenderDefault();

	void RerenderTitleBar();
	void RerenderBottomBar();

	void Rerender();
	void Display();


public:

	void ChangeScene(unsigned index);
	void Initialize();
	void Run();

};


#endif