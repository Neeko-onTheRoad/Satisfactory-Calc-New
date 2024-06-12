#pragma once

#ifndef _I_REPLACEABLE_HXX_
#define _H_REPLACEABLE_HXX_


class IReplaceable {

public:
	virtual void SetPositionX(unsigned _x) = 0;
	virtual void SetPositionY(unsigned _y) = 0;

	void SetPosition(unsigned _x, unsigned _y) {
		SetPositionX(_x);
		SetPositionY(_y);
	}

};


#endif