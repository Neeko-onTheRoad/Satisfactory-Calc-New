#pragma once

#ifndef _I_SELECTABLE_HXX_
#define _I_SELECTABLE_HXX_


class ISelectable {

protected:
	


public:
	virtual void Selected() = 0;
	virtual void UnSelected() = 0;

	void LinkUpper(ISelectable* _upper);
	void LinkLower(ISelectable* _lower);
	void LinkLeft (ISelectable* _left);
	void LinkRight(ISelectable* _right);

	void Link();

};


#endif