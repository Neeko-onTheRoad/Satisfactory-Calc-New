#pragma once

#ifndef _COLOR_HXX_
#define _COLOR_HXX_

#include <string>

class Color {
public:

	static std::string Foreground(__int8 color);
	static std::string Background(__int8 color);

	static const __int16 DefaultBackgroundColor = 236;
	static const __int16 DefaultForegroundColor = 253;

};


#endif