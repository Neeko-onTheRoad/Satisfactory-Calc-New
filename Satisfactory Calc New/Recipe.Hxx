#pragma once 

#ifndef _RECIPE_HXX_
#define _RECIPE_HXX_

#include <vector>

typedef long double lDouble;

struct Item;
struct Building;

struct Recipe {

	std::string Name     = "";
	bool        IsAlt    = false;
	Building*   Building = nullptr;

	std::vector<std::tuple<Item*, lDouble, unsigned>> Input  = {};
	std::vector<std::tuple<Item*, lDouble, unsigned>> Output = {};

	void AddInput(Item* _item, lDouble _perMin, unsigned _amount) {
		if (_item) _item->Usages.push_back(this);
		Input.emplace_back(_item, _perMin, _amount);
	}

	void AddOutput(Item* _item, lDouble _perMin, unsigned _amount) {
		if (_item) _item->Recipes.push_back(this);
		Output.emplace_back(_item, _perMin, _amount);
	}

};


#endif