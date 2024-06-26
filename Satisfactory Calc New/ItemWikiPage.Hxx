#pragma once

#ifndef _ITEM_WIKI_PAGE_HXX_
#define _ITEM_WIKI_PAGE_HXX_

#include <tuple>
#include <format>
#include "Item.Hxx"
#include "AsciiMap.Hxx"
#include "SelectBox.Hxx"
#include "ConsoleObject.Hxx"
#include "ConsoleWindow.Hxx"

class ItemWikiPage :
	public ConsoleObject,
	public ISelectable
{

private:

	bool isSelected = false;
	Item* itemSelected = nullptr;
	ISelectable* before;
	ISelectable* nowSelect;

	int upperBarEndPoint = 0;
	int infoBarRightPoint = 0;

	SelectBox<Recipe*>* recipeSelect;

	void rerenderRecipe(std::map<int, std::vector<ConsoleObject*>>& _objects, int _layer);

protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update(ISelectable*& _selecting);

public:

	ItemWikiPage();
	~ItemWikiPage();

	void Make(
		Item* _item, ISelectable* _before,
		std::map<int, std::vector<ConsoleObject*>>& _objects,
		ISelectable* _selecting,
		int _layer
	);
	
	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;
	
	int ConsoleObject::GetPositionX() const;
	int ConsoleObject::GetPositionY() const;

	KeyGuides ISelectable::GetKeyGuides() const;

	ISelectable* ISelectable::GetUpper() const { return nullptr; };
	ISelectable* ISelectable::GetLower() const { return nullptr; };
	ISelectable* ISelectable::GetLeft () const { return nullptr; };
	ISelectable* ISelectable::GetRight() const { return nullptr; };

	void ISelectable::LinkUpper(ISelectable* _upper) {};
	void ISelectable::LinkLower(ISelectable* _lower) {};
	void ISelectable::LinkLeft (ISelectable* _left ) {};
	void ISelectable::LinkRight(ISelectable* _right) {};

	void ISelectable::Select();
	void ISelectable::UnSelect();


};


#endif