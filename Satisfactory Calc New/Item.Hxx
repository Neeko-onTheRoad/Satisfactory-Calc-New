#pragma once

#ifndef _ITEM_HXX_
#define _ITEM_HXX_

#include <string>
#include <vector>

typedef std::vector<std::string> Strings;

enum class ItemCategory {
	Ores, Ingots, Minerals, Ailiens, Liquids, Gas,
	StandardParts, IndustrialParts, Electronics, Communications,
	Containers, Fuels, Consumed, Ammos, Nuclear, Waste, Spectial
};

#define AUTO_CASE(CAT) case ItemCategory::##CAT: return #CAT;

static std::string GetCategoriyName(ItemCategory _category) {
	switch (_category) {
		AUTO_CASE(Ores);
		AUTO_CASE(Ingots);
		AUTO_CASE(Minerals);
		AUTO_CASE(Ailiens);
		AUTO_CASE(Liquids);
		AUTO_CASE(Gas);
		AUTO_CASE(Containers);
		AUTO_CASE(Fuels);
		AUTO_CASE(Consumed);
		AUTO_CASE(Ammos);
		AUTO_CASE(Nuclear);
		AUTO_CASE(Waste);
		AUTO_CASE(Spectial);
		default: return "N\\A";
	}
}

#undef AUTO_CASE

struct Recipe;

struct Item {

	std::string  Name         = "N\\A";
	Strings      Description  = { "N\\A" };
	ItemCategory Category     = ItemCategory::Ores;
	unsigned     MaxStackSize = 0;
	unsigned     SinkPoint    = 0;

	std::vector<const Recipe*> Recipes = {};
	std::vector<const Recipe*> Usages  = {};

};


#endif