#pragma once

#ifndef _BUILDING_HXX_
#define _BUILDING_HXX_

#include <map>
#include <string>
#include <vector>
#include <climits>

enum class BuildingCategory {
	Extraction, Production, Generators, Special,
	Workstations, Storage, DockingStations, Towers
};


extern std::map<BuildingCategory, std::string> BuildingNameOfCategory;
extern std::map<std::string, BuildingCategory> BuildingCategoryByName;


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