#pragma once

#ifndef _COLOR_HXX_
#define _COLOR_HXX_

#include <string>
#include <sstream>

class Color {
public:

	static std::string Foreground(unsigned __int8 color);
	static std::string Background(unsigned __int8 color);

	static const unsigned __int8 FullBlack                =   0;
	static const unsigned __int8 HilightedForegroundColor = 214;
	static const unsigned __int8 HilightedBackgroundColor = 235;
	static const unsigned __int8 DefaultBackgroundColor   = 236;
	static const unsigned __int8 DefaultForegroundColor   = 253;

};


#endif