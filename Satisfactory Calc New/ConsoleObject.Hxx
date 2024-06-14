#pragma once

#ifndef _CONSOLE_OBJECT_HXX_
#define _CONSOLE_OBJECT_HXX_

#include <stdexcept>
#include "Color.Hxx"
#include "DynamicArray.Hxx"

class ConsoleObject {
protected:

	virtual void Initialize() = 0;
	virtual void Update() = 0;

public:

	bool NeedUpdate = true;

	char**      Object          = new char*[0];
	ColorCode** ForegroundColor = new ColorCode*[0];
	ColorCode** BackgroundColor = new ColorCode*[0];

	virtual unsigned GetSizeX() const = 0;
	virtual unsigned GetSizeY() const = 0;

	virtual int GetPositionX() const = 0;
	virtual int GetPositionY() const = 0;

	void SetForegroundColor(ColorCode _color);
	void SetBackgroundColor(ColorCode _color);

	void SetForegroundColor(ColorCode _color, unsigned _x, unsigned _y);
	void SetBackgroundColor(ColorCode _color, unsigned _x, unsigned _y);

	void InitializeBase();
	void UpdateBaes();

};


#endif