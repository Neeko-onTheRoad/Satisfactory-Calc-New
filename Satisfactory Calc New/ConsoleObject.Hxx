#pragma once

#ifndef _CONSOLE_OBJECT_HXX_
#define _CONSOLE_OBJECT_HXX_

#include "Color.Hxx"
#include "DynamicArray.Hxx"

class ConsoleObject {
protected:

	virtual void Initialize() = 0;
	virtual void Update() = 0;

public:

	bool NeedUpdate = true;

	char**            Object          = new char*[0];
	unsigned __int8** ForeGroundColor = new unsigned __int8*[0];
	unsigned __int8** BackGroundColor = new unsigned __int8*[0];

	virtual unsigned GetSizeX() const = 0;
	virtual unsigned GetSizeY() const = 0;
	virtual void SetSizeX(unsigned x) = 0;
	virtual void SetSizeY(unsigned y) = 0;
	void SetSize(unsigned x, unsigned y);

	virtual unsigned GetPositionX() const = 0;
	virtual unsigned GetPositionY() const = 0;
	virtual void SetPositionX(unsigned x) = 0;
	virtual void SetPositionY(unsigned y) = 0;
	void SetPosition(unsigned x, unsigned y);

	void InitializeBase();
	void UpdateBaes();

};


#endif