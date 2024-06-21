#pragma once

#ifndef _ITEM_WIKI_HXX_
#define _ITEM_WIKI_HXX_

#include <algorithm>
#include "Item.Hxx"
#include "WikiPage.Hxx"
#include "SelectBox.Hxx"
#include "TextButton.Hxx"
#include "ConsoleScene.Hxx"
#include "Satisfactory.Hxx"
#include "TextBoxObject.Hxx"

enum class ItemSortOption {
	NameA2Z, NameZ2A, Category
};

class ItemWiki : public ConsoleScene {

private:

	int scroll = 0;
	ItemSortOption sortOption = ItemSortOption::Category;

	std::map<char,         std::vector<Item*>> itemSortedByNameA2Z;
	std::map<char,         std::vector<Item*>> itemSortedByNameZ2A;
	std::map<ItemCategory, std::vector<Item*>> itemSortedByCategory;

	std::vector<TextButton*> renderedTextButtonNameA2Z;
	std::vector<TextButton*> renderedTextButtonNameZ2A;
	std::vector<TextButton*> renderedTextButtonCategory;

	std::map<int, TextButton*> renderBuffer;

	void drawInBuffer();
	void rerender();
	

protected:
	
	void ConsoleScene::Initialize();
	void ConsoleScene::Update();


public:
	
	std::string ConsoleScene::GetTitle() const;

};


#endif