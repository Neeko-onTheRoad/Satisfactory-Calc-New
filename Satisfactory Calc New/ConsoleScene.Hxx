#pragma once

#ifndef _CONSOLE_SCENE_HXX_
#define _CONSOLE_SCENE_HXX_

#define CONSOLE_HEIGHT 31u
#define CONSOLE_WIDTH 105u

#define TITLE_BAR_HEIGHT 3u
#define BOTTOM_BAR_HEIGHT 4u
#define SCENE_HEIGHT CONSOLE_HEIGHT - TITLE_BAR_HEIGHT - BOTTOM_BAR_HEIGHT
#define BOTTOM_BAR_OFFSET TITLE_BAR_HEIGHT + SCENE_HEIGHT

#include <map>
#include <vector>

#include "ConsoleObject.Hxx"

class ConsoleScene {

protected:

	virtual void Initialize() = 0;
	virtual void Update()     = 0;

public:
	
	bool NeedUpdate = true;
	std::map<int, std::vector<ConsoleObject*>> Objects;
	char SceneRenderBuffer[SCENE_HEIGHT][CONSOLE_WIDTH];

	void InitializeBase();
	void UpdateBase();
	void Rerender();

};


#endif