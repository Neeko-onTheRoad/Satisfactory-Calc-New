#pragma once

#ifndef _ITEM_WIKI_PAGE_HXX_
#define _ITEM_WIKI_PAGE_HXX_

#include "Item.Hxx"
#include "ConsoleObject.Hxx"
#include "ConsoleWindow.Hxx"

class ItemWikiPage :
	public ConsoleObject,
	public ISelectable
{

private:

	ISelectable* Before;



protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update(ISelectable*& _selecting);

public:

	ItemWikiPage();
	~ItemWikiPage();

	void Make(const Item* item, ISelectable* _before);
	
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