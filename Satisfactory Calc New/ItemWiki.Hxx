#pragma once

#ifndef _ITEM_WIKI_HXX_
#define _ITEM_WIKI_HXX_

#include <algorithm>
#include "Item.Hxx"
#include "TextButton.Hxx"
#include "ConsoleScene.Hxx"
#include "Satisfactory.Hxx"

enum class ItemSortOption {
	NameA2Z, NameZ2A, Category
};

class ItemWiki : public ConsoleScene {

private:

	int scroll = 0;
	ItemSortOption sortOption = ItemSortOption::Category;

	std::map<char,         std::vector<Item*>> ItemSortedByNameA2Z;
	std::map<char,         std::vector<Item*>> ItemSortedByNameZ2A;
	std::map<ItemCategory, std::vector<Item*>> ItemSortedByCategory;

	std::map<int, TextButton> RenderTextButton;


	

protected:
	
	void ConsoleScene::Initialize();
	void ConsoleScene::Update();


public:
	
	std::string ConsoleScene::GetTitle() const;

};


#endif