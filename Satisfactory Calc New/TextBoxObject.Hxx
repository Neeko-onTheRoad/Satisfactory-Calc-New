#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include <vector>
#include "ConsoleObject.Hxx"

#include "IReplaceable.Hxx"

class TextBoxObject :
	public ConsoleObject,
	public IReplaceable
{

private:

	unsigned sizeX = 0u;
	unsigned sizeY = 0u;

	int positionX = 0;
	int positionY = 0;


protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update();


public:

	void Make(int _posX, int _posY, std::string _element, int _bottomMargin = 0);;

	void IReplaceable::SetPositionX(int _x);
	void IReplaceable::SetPositionY(int _y);

	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;

	int ConsoleObject::GetPositionX() const;
	int ConsoleObject::GetPositionY() const;

};


#endif