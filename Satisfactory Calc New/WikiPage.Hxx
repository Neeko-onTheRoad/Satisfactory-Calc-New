#pragma once

#ifndef _WIKI_PAGE_HXX_
#define _WIKI_PAGE_HXX_

#include "Item.Hxx"
#include "ConsoleObject.Hxx"
#include "ConsoleWindow.Hxx"

class WikiPage :
	public ConsoleObject,
	public ISelectable
{

private:

	WikiPage();
	~WikiPage();

	ISelectable* Before;

protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update(ISelectable*& _selecting);

public:

	void Make(const Item* item, ISelectable* _before);
	
	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;
	
	int ConsoleObject::GetPositionX() const;
	int ConsoleObject::GetPositionY() const;

	KeyGuides ISelectable::GetKeyGuides() const;

	ISelectable* ISelectable::GetUpper() const {};
	ISelectable* ISelectable::GetLower() const {};
	ISelectable* ISelectable::GetLeft () const {};
	ISelectable* ISelectable::GetRight() const {};

	void ISelectable::LinkUpper(ISelectable* _upper) {};
	void ISelectable::LinkLower(ISelectable* _lower) {};
	void ISelectable::LinkLeft (ISelectable* _left ) {};
	void ISelectable::LinkRight(ISelectable* _right) {};

	void ISelectable::Select();
	void ISelectable::UnSelect();


};


#endif