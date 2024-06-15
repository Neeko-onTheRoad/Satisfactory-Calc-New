#pragma once

#ifndef _I_REPLACEABLE_HXX_
#define _H_REPLACEABLE_HXX_


class IReplaceable {

public:
	virtual void SetPositionX(int _x) = 0;
	virtual void SetPositionY(int _y) = 0;

	void SetPosition(int _x, int _y) {
		SetPositionX(_x);
		SetPositionY(_y);
	}

};


#endif