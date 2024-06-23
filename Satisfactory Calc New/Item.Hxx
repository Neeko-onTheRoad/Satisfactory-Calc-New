#pragma once

#ifndef _ITEM_HXX_
#define _ITEM_HXX_

#include <map>
#include <string>
#include <vector>

enum class ItemCategory {
	Ores, Ingots, Minerals, Aliens, Liquids, Gas,
	StandardParts, IndustrialParts, Electronics, Communications,
	Containers, Fuels, Consumed, Ammos, Nuclear, Waste, Spectial
};


extern std::map<ItemCategory, std::string> ItemNameOfCategory;
extern std::map<std::string, ItemCategory> ItemCategoryByName;


struct Recipe;

struct Item {

	std::string              Name         = "N\\A";
	std::vector<std::string> Description  = {};
	ItemCategory             Category     = ItemCategory::Ores;
	unsigned                 MaxStackSize = 0;
	unsigned                 SinkPoint    = 0;
				             
	unsigned                 Energy       = 0;
	unsigned                 PowerUseMin  = 0;
	unsigned                 PowerUseAvrg = 0;
	unsigned                 PowerUseMax  = 0;
	std::string              Radioactive  = "";

	std::vector<Recipe*> Recipes = {};
	std::vector<Recipe*> Usages  = {};

};


#endif