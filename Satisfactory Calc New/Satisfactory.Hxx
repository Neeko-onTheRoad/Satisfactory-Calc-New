#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"
#include "ItemTable.Hxx"
#include "RecipeTable.Hxx"
#include "BuildingTable.Hxx"

namespace Satisfactory {

	void Initialize();

	void InitializeItems();
	void InitializeRecipes();
	void InitializeBuildings();

	extern std::vector<Item*>     ItemList;
	extern std::vector<Recipe*>   RecipeList;
	extern std::vector<Building*> BuildingList;
	
	extern std::vector<Item*> PowerSources;

}

#endif