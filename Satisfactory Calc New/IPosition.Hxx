#pragma once

#ifndef _I_POSITION_HXX_
#define _I_POSITION_HXX_


class IPosition {

protected:
	int positionX = 0;
	int positionY = 0;

public:
	unsigned GetPositionX() const;
	unsigned GetPositionY() const;

};


#endif