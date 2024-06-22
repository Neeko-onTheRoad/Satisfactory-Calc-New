#pragma once 

#ifndef _RECIPE_HXX_
#define _RECIPE_HXX_

#include <vector>

typedef long double lDouble;

struct Item;
struct Building;

struct Recipe {

	std::string name     = "";
	bool        isAlt    = false;
	Building*   building = nullptr;

	std::vector<std::tuple<Item*, lDouble, unsigned>> input  = {};
	std::vector<std::tuple<Item*, lDouble, unsigned>> output = {};

	void AddInput(Item* _item, lDouble _perMin, unsigned _amount) {
		_item->Usages.push_back(this);
		input.emplace_back(_item, _perMin, _amount);
	}

	void AddOutput(Item* _item, lDouble _perMin, unsigned _amount) {
		_item->Recipes.push_back(this);
		input.emplace_back(_item, _perMin, _amount);
	}

};


#endif