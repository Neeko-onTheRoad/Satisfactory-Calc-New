#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include "ConsoleObject.Hxx"
#include "ConsoleScene.Hxx"

class TextObject : public ConsoleObject {

private:
	
	unsigned positionX;
	unsigned positionY;

	unsigned sizeX;
	unsigned sizeY;


protected:
	void Initialize();
	void Update();


public:

	TextObject(unsigned posX, unsigned posY, unsigned sizeX, unsigned sizeY);

	unsigned GetSizeX() const;
	unsigned GetSizeY() const;

	unsigned GetPositionX() const;
	unsigned GetPositionY() const;

};


#endif