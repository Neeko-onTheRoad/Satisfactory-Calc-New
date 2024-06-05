#pragma once

#ifndef _CONSOLE_SCENE_HXX_
#define _CONSOLE_SCENE_HXX_

#define MAX_CONSOLE_HEIGHT 31
#define MAX_CONSOLE_WIDTH 104

#define TITLE_BAR_HEIGHT 3
#define BOTTOM_BAR_HEIGHT 3

#include <vector>

#include "ConsoleObject.Hxx"

class ConsoleScene {
private: 
	
	std::vector<ConsoleObject*> objects;

	char sceneRenderBuffer[MAX_CONSOLE_HEIGHT - TITLE_BAR_HEIGHT - BOTTOM_BAR_HEIGHT][MAX_CONSOLE_WIDTH];

protected:
	virtual void Initialize() = 0;
	virtual void Update()     = 0;

public:
	void InitializeBase();
	void UpdateBase();

};


#endif