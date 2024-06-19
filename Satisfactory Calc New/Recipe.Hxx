#pragma once 

#ifndef _RECIPE_HXX_
#define _RECIPE_HXX_

#include <vector>

struct Item;

struct Recipe {

private:
	std::vector<Item*> input;
	std::vector<Item*> output;

	

};


#endif