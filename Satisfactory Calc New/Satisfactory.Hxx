#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include <map>
#include <fstream>
#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"
#include "ItemTable.Hxx"
#include "RecipeTable.Hxx"
#include "BuildingTable.Hxx"

#define NAME_OF(var) #var

namespace Satisfactory {

	extern std::map<std::string, Item*>     ItemList;
	extern std::map<std::string, Recipe*>   RecipeList;
	extern std::map<std::string, Building*> BuildingList;

	extern std::vector<Item*> PowerSources;
	
	extern Recipe* NullRecipe;

	void Initialize();

};


#endif