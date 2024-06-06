#pragma once

#ifndef _CONSOLE_OBJECT_HXX_
#define _CONSOLE_OBJECT_HXX_

#include "Color.Hxx"
#include "DynamicArray.Hxx"

class ConsoleObject {
protected:

	virtual void Initialize() = 0;
	virtual void Update() = 0;

	virtual void Rerender() = 0;

public:
	
	char**    Object          = new char*[0];
	__int16** ForeGroundColor = new __int16*[0];
	__int16** BackGroundColor = new __int16*[0];

	virtual unsigned GetSizeX() const = 0;
	virtual unsigned GetSizeY() const = 0;
	virtual void SetPosition(unsigned x, unsigned y) = 0;

	virtual unsigned GetPositionX() const = 0;
	virtual unsigned GetPositionY() const = 0;

	void InitializeBase();
	void UpdateBaes();

};


#endif