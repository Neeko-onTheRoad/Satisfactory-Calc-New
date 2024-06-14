#pragma once

#ifndef _TEXT_BUTTON_HXX_
#define _TEXT_BUTTON_HXX_

#include "ConsoleObject.Hxx"

#include "IReplaceable.Hxx"

class TextButton :
	public ConsoleObject,
	public IReplaceable
{

protected:

	void ConsoleObject::Initialize();
	void ConsoleObject::Update();
	

public:

	void Make(int _posX, int _posY, std::string _element);

};


#endif