#pragma once

#ifndef _I_SELECTABLE_HXX_
#define _I_SELECTABLE_HXX_


class ISelectable {

public:
	virtual void Select() = 0;
	virtual void UnSelect() = 0;

	virtual ISelectable* GetUpper() const = 0;
	virtual ISelectable* GetLower() const = 0;
	virtual ISelectable* GetLeft () const = 0;
	virtual ISelectable* GetRight() const = 0;

	virtual void LinkUpper(ISelectable* _upper) = 0;
	virtual void LinkLower(ISelectable* _lower) = 0;
	virtual void LinkLeft (ISelectable* _left)  = 0;
	virtual void LinkRight(ISelectable* _right) = 0;

};


#endif