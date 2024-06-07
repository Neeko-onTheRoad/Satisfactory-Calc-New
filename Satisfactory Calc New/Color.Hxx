#pragma once

#ifndef _COLOR_HXX_
#define _COLOR_HXX_

#include <string>

class Color {
public:

	static std::string Foreground(unsigned __int8 color);
	static std::string Background(unsigned __int8 color);

	static const unsigned __int8 DefaultBackgroundColor = 236;
	static const unsigned __int8 DefaultForegroundColor = 253;

};


#endif