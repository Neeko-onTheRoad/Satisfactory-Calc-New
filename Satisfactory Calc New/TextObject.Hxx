#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include "ConsoleObject.Hxx"

class TextObject : public ConsoleObject {

private:

	unsigned sizeX;
	unsigned sizeY;

	unsigned positionX;
	unsigned positionY;

protected:

	void Initialize();
	void Update();

public:
	
	unsigned GetSizeX();
	unsigned GetSizeY();
	void SetSizeX(unsigned x);
	void SetSizeY(unsigned y);

	unsigned GetPositionX();
	unsigned GetPositionY();
	void SetPositionX(unsigned x);
	void SetPositionY(unsigned y);

};


#endif