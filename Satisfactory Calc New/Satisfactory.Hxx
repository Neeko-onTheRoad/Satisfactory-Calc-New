#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include <sstream>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"
#include "ItemTable.Hxx"
#include "RecipeTable.Hxx"
#include "BuildingTable.Hxx"

#define NAME_OF(var) #var

namespace Satisfactory {

	extern std::vector<Item*>     ItemList; 
	extern std::vector<Building*> BuildingList;
	extern std::vector<Recipe*>   RecipeList;

	extern std::unordered_map<std::string, Item*>     ItemTable;
	extern std::unordered_map<std::string, Building*> BuildingTable;
	extern std::unordered_map<std::string, Recipe*>   RecipeTable;
	
	extern std::vector<Item*> PowerSources;
	
	extern Recipe* NullRecipe;

	void Initialize();

};


#endif