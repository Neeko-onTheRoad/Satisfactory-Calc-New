#pragma once

#ifndef _CONSOLE_WINDOW_HXX_
#define _CONSOLE_WINDOW_HXX_

#include <thread>
#include <cstdio>
#include <functional>

#include "Color.Hxx"
#include "AsciiMap.Hxx"
#include "KeyManager.Hxx"
#include "ConsoleScene.Hxx"
#include "ConsoleManager.Hxx"
#include "ResourceManager.Hxx"

#include "ItemWiki.Hxx"
#include "MainScreen.Hxx"
#include "EmptyScene.Hxx"

class ConsoleWindow {

private:

	unsigned nowSceneIndex = 0u;
	ConsoleScene* nowScene = new EmptyScene;
	std::vector<ConsoleScene*> scenes;

	ISelectable* selecting = nullptr;

	char      titleBar               [TITLE_BAR_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode titleBarForegroundColor[TITLE_BAR_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode titleBarBackgroundColor[TITLE_BAR_HEIGHT][CONSOLE_WIDTH] = {};

	char      bottomBar               [BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode bottomBarForegroundColor[BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode bottomBarBackgroundColor[BOTTOM_BAR_HEIGHT][CONSOLE_WIDTH] = {};

	std::string displayBuffer;
	char        renderBuffer   [CONSOLE_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode   foregroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode   backgroundColor[CONSOLE_HEIGHT][CONSOLE_WIDTH] = {};

	void RenderDefault();

	void RerenderTitleBar();
	void RerenderBottomBar();

	void Rerender();
	void Display();


public:

	bool PotatoMode = false;

	void ChangeScene(unsigned index);
	void Initialize();
	void Run();

};


#endif