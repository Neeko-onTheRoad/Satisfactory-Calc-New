#pragma once

#ifndef _ITEM_WIKI_HXX_
#define _ITEM_WIKI_HXX_

#include <algorithm>
#include "Item.Hxx"
#include "AsciiMap.Hxx"
#include "SelectBox.Hxx"
#include "TextButton.Hxx"
#include "ConsoleScene.Hxx"
#include "Satisfactory.Hxx"
#include "TextBoxObject.Hxx"

class ItemWikiPage;
class ItemWiki : public ConsoleScene {

private:

	int scroll = 0;

	TextBoxObject* nowTitle;
	ItemWikiPage*  nowPage;

	ItemCategory nowSelectedCategory = ItemCategory::Ores;
	std::vector<TextButton*> categoryButtons;
	std::map<ItemCategory, std::vector<TextButton*>> itemButtons;

	void rerender();
	

protected:
	
	void ConsoleScene::Initialize();
	void ConsoleScene::Update();


public:
	
	std::string ConsoleScene::GetTitle() const;

};


#endif