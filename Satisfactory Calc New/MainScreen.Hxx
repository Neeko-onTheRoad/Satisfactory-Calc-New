#pragma once

#ifndef _MAIN_SCREEN_HXX_
#define _MAIN_SCREEN_HXX_

#include "ConsoleScene.Hxx"
#include "TextBoxObject.Hxx"
#include "ResourceManager.Hxx"

class MainScreen : public ConsoleScene {

protected:

	void Initialize();
	void Update();

public:
	std::string GetTitle() const;

};


#endif