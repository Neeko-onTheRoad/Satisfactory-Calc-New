#pragma once

#ifndef _I_REPLACEABLE_HXX_
#define _H_REPLACEABLE_HXX_

#include "IPosition.Hxx"

class IReplaceable : public IPosition {

public:
	void SetPositionX(int _x);
	void SetPositionY(int _y);

	void SetPosition(int _x, int _y);

};


#endif