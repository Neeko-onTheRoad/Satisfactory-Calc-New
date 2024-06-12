#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include <vector>
#include "ConsoleObject.Hxx"

#include "IReplaceable.Hxx"

class TextBoxObject : public ConsoleObject, public IReplaceable {

private:

	unsigned sizeX = 0;
	unsigned sizeY = 0;

	unsigned positionX = 0;
	unsigned positionY = 0;


protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update();


public:

	void Make(int _posX, int _posY, std::string _element);

	void IReplaceable::SetPositionX(unsigned _x);
	void IReplaceable::SetPositionY(unsigned _y);
	
	unsigned ConsoleObject::GetSizeX() const;
	unsigned ConsoleObject::GetSizeY() const;

	unsigned ConsoleObject::GetPositionX() const;
	unsigned ConsoleObject::GetPositionY() const;

};


#endif