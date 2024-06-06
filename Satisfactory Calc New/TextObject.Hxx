#pragma once

#ifndef _TEXT_OBJECT_HXX_
#define _TEXT_OBJECT_HXX_

#include "ConsoleObject.Hxx"
#include "ConsoleScene.Hxx"

class TextObject : public ConsoleObject {

protected:
	void Initialize();
	void Update();

	void Rerender();


public:
	
	int GetSizeX();
	int GetSizeY();

	int GetPositionX();
	int GetPositionY();

};


#endif