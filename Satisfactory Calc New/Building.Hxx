#pragma once

#ifndef _BUILDING_HXX_
#define _BUILDING_HXX_

#include <climits>

enum class BuildingCategory {
	Extraction, Production, Generators, Special,
	Workstations, Storage, DockingStations, Towers
};

#define AUTO_CASE(CAT) case BuildingCategory::##CAT: return #CAT;

static std::string GetCategoryName(BuildingCategory _category) {
	switch (_category) {
		AUTO_CASE(Extraction)
		AUTO_CASE(Production)
		AUTO_CASE(Generators)
		AUTO_CASE(Special)
		AUTO_CASE(Workstations)
		AUTO_CASE(Storage)
		AUTO_CASE(DockingStations)
		AUTO_CASE(Towers)
	}
}

#undef AUTO_CASE


struct Item;

struct Building {
	
	std::string                             Name            = "N\\A";
	BuildingCategory                        Category        = BuildingCategory::Extraction;
	std::vector<std::string>                Description     = {};
	std::vector<std::pair<Item*, unsigned>> Ingredients     = {};
	unsigned                                Width           = 0u;
	unsigned                                Length          = 0u;
	unsigned                                Height          = 0u;
	unsigned                                Input           = 0u;
	unsigned                                Output          = 0u;
							                
	#define                                 CASE_BY_CASE    UINT_MAX
	unsigned                                PowerUsed       = 0u;
	#define                                 INFINE          UINT_MAX
	unsigned                                PowerGeneration = 0u;


};


#endif