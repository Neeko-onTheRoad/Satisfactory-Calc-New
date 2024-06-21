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

	static std::vector<Item*>     ItemList;
	static std::vector<Recipe*>   RecipeList;
	static std::vector<Building*> BuildingList;
	
	static std::vector<Item*> PowerSources;

}

#endif