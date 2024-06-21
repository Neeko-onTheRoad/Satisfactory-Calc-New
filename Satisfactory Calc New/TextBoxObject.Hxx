#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include <vector>
#include "ConsoleObject.Hxx"

#include "ISelectable.Hxx"
#include "IReplaceable.Hxx"

class TextBoxObject :
	public ConsoleObject,
	public IReplaceable,
	public ISelectable
{

private:

	unsigned sizeX = 0u;
	unsigned sizeY = 0u;

	int positionX = 0;
	int positionY = 0;

	KeyGuides keyGuides;

	ISelectable* upper = nullptr;
	ISelectable* lower = nullptr;
	ISelectable* left  = nullptr;
	ISelectable* right = nullptr;

	void rebuildKeyGuides();


protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update(ISelectable*& _selecting);


public:

	void Make(int _posX, int _posY, std::string _element, int _bottomMargin = 0);

	void Select();
	void UnSelect();

	KeyGuides AdditionalKeyGuides;
	KeyGuides ISelectable::GetKeyGuides() const;

	ISelectable* GetUpper() const;
	ISelectable* GetLower() const;
	ISelectable* GetLeft () const;
	ISelectable* GetRight() const;

	void LinkUpper(ISelectable* _upper);
	void LinkLower(ISelectable* _lower);
	void LinkLeft (ISelectable* _left);
	void LinkRight(ISelectable* _right);

	void IReplaceable::SetPositionX(int _x);
	void IReplaceable::SetPositionY(int _y);

	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;

	int ConsoleObject::GetPositionX() const;
	int ConsoleObject::GetPositionY() const;

};


#endif