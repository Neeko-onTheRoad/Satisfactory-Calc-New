#pragma once

#ifndef _KEY_GUIDE_HXX_
#define _KEY_GUIDE_HXX_

#include <vector>
#include <string>

struct KeyGuide {
	
	Keys Key = Keys::UP;
	std::string Action = "N\\A";

};

typedef std::vector<KeyGuide> KeyGuides;


#endif