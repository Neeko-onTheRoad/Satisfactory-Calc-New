#pragma once

#ifndef _I_BORDER_HXX_

enum class BorderType {
	NO_BORDER, GAP_ONLY, WITH_LINE
};

class IBorder {

private:
	BorderType borderType;

public:
	virtual void SetBorderType(BorderType _border) = 0;
	virtual void SetBorderColor(__int8 _color) = 0;

};


#endif