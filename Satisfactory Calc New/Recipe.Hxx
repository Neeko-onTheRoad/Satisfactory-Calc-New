#pragma once 

#ifndef _RECIPE_HXX_
#define _RECIPE_HXX_

#include <vector>

class Item;


class Recipe {

private:
	std::vector<Item*> input;
	std::vector<Item*> output;

	

};


#endif