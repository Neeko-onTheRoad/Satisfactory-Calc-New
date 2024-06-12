#pragma once

#ifndef _ITEM_HXX_
#define _ITEM_HXX_

#include <string>
#include <vector>

struct Recipe;

struct Item {

	std::string	Name;
	unsigned    SinkPoint;
	unsigned    MaxStackSize;

	std::vector<Recipe*> Recipes;
	std::vector<Recipe*> Usages;

	

};


#endif