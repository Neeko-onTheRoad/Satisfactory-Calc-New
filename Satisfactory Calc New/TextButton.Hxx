#pragma once

#ifndef _TEXT_BUTTON_HXX_
#define _TEXT_BUTTON_HXX_

#include <functional>
#include "AsciiMap.Hxx"
#include "ISelectable.Hxx"
#include "IReplaceable.Hxx"
#include "ConsoleObject.Hxx"

class TextButton :
	public IReplaceable,
	public ISelectable,
	public ConsoleObject
{

private:

	unsigned sizeX = 0u;
	unsigned sizeY = 0u;

	int positionX = 0;
	int positionY = 0;

	std::string stringElement;

	std::function<void()> callBack = [](){};

	KeyGuides keyGuides;

	ISelectable* upper = nullptr;
	ISelectable* lower = nullptr;
	ISelectable* left  = nullptr;
	ISelectable* right = nullptr;

	ColorCode foregroundColor = Color::DefaultForegroundColor;
	ColorCode backgroundColor = Color::DefaultBackgroundColor;
	ColorCode selectedForegroundColor = Color::HilightedForegroundColor;
	ColorCode selectedBackgroundColor = Color::HilightedBackgroundColor;

	void RebuildKeyGuides();

protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update();
	

public:

	virtual ~TextButton() {};

	void Make(int _posX, int _posY, std::string _element);
	void SetCallBack(std::function<void()> _func);
	void CallBack();

	void ISelectable::Select();
	void ISelectable::UnSelect();

	void SetForegroundColor(ColorCode _color);
	void SetBackgroundColor(ColorCode _color);
	void SetSelectedForegroundColor(ColorCode _color);
	void SetSelectedBackgroundColor(ColorCode _color);

	KeyGuides AdditionalKeyGuides;
	KeyGuides ISelectable::GetKeyGuides() const;

	ISelectable* ISelectable::GetUpper() const;
	ISelectable* ISelectable::GetLower() const;
	ISelectable* ISelectable::GetLeft()  const;
	ISelectable* ISelectable::GetRight() const;

	void ISelectable::LinkUpper(ISelectable* _upper);
	void ISelectable::LinkLower(ISelectable* _lower);
	void ISelectable::LinkLeft (ISelectable* _left);
	void ISelectable::LinkRight(ISelectable* _right);

	void IReplaceable::SetPositionX(int _x);
	void IReplaceable::SetPositionY(int _y);

	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;

	int ConsoleObject::GetPositionX() const;
	int ConsoleObject::GetPositionY() const;

};


#endif