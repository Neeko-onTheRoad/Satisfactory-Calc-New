#pragma once

#ifndef _CONSOLE_SCENE_HXX_
#define _CONSOLE_SCENE_HXX_


#include <map>
#include <vector>

#include "SelectBox.Hxx"
#include "ISelectable.Hxx"
#include "ConsoleObject.Hxx"

constexpr unsigned CONSOLE_HEIGHT = 33u;
constexpr unsigned CONSOLE_WIDTH = 122u;
		  
constexpr unsigned TITLE_BAR_HEIGHT = 3u;
constexpr unsigned BOTTOM_BAR_HEIGHT = 4u;
constexpr unsigned SCENE_HEIGHT = (CONSOLE_HEIGHT - TITLE_BAR_HEIGHT - BOTTOM_BAR_HEIGHT);
constexpr unsigned BOTTOM_BAR_OFFSET = (TITLE_BAR_HEIGHT + SCENE_HEIGHT);

class ConsoleScene {

protected:

	virtual void Initialize() = 0;
	virtual void Update() = 0;

	void AddObject(ConsoleObject* _object, int layer = 0);

public:
	
	bool NeedUpdate = true;
	int  NeedToChangeScene = 0;

	std::map<int, std::vector<ConsoleObject*>> Objects;
	ISelectable* Selecting = nullptr;

	KeyGuides AdditionalKeyGuides;
	KeyGuides GetAllKeyGuides();

	char      SceneRenderBuffer   [SCENE_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode SceneForegroundColor[SCENE_HEIGHT][CONSOLE_WIDTH] = {};
	ColorCode SceneBackgroundColor[SCENE_HEIGHT][CONSOLE_WIDTH] = {};

	virtual std::string GetTitle() const = 0;

	void InitializeBase();
	void UpdateBase();
	void Rerender();

};


#endif