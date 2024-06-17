#pragma once

#ifndef _MAIN_SCREEN_HXX_
#define _MAIN_SCREEN_HXX_

#include "KeyManager.Hxx"
#include "TextButton.Hxx"
#include "ConsoleScene.Hxx"
#include "TextBoxObject.Hxx"
#include "ConsoleObject.Hxx"
#include "ResourceManager.Hxx"

class MainScreen : public ConsoleScene {

private:

	TextBoxObject* title       = new TextBoxObject;
	TextBoxObject* creditPopup = new TextBoxObject;

	TextButton* itemWiki       = new TextButton;
	TextButton* buildingWiki   = new TextButton;
	TextButton* powerPlanner   = new TextButton;
	TextButton* producePlanner = new TextButton;
	TextButton* credit         = new TextButton;
	TextButton* exit           = new TextButton;

protected:

	void Initialize();
	void Update();

public:

	std::string GetTitle() const;

};


#endif