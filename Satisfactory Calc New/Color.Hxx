#pragma once

#ifndef _COLOR_HXX_
#define _COLOR_HXX_

#include <string>
#include <sstream>

typedef unsigned __int8 ColorCode;

class Color {
public:

	static std::string Foreground(ColorCode color);
	static std::string Background(ColorCode color);

	static const ColorCode NoColor                  =   0;
	static const ColorCode HilightedForegroundColor = 214;
	static const ColorCode HilightedBackgroundColor = 235;
	static const ColorCode DefaultBackgroundColor   = 236;
	static const ColorCode DefaultForegroundColor   = 253;
	static const ColorCode LightForegroundColor     = 244;

};


#endif