#pragma once

#ifndef _I_SELECTABLE_HXX_
#define _I_SELECTABLE_HXX_


class ISelectable {

protected:
	


public:
	virtual void Selected() = 0;
	virtual void UnSelected() = 0;

	virtual void LinkUpper(ISelectable* _upper) = 0;
	virtual void LinkLower(ISelectable* _lower) = 0;
	virtual void LinkLeft (ISelectable* _left)  = 0;
	virtual void LinkRight(ISelectable* _right) = 0;

};


#endif