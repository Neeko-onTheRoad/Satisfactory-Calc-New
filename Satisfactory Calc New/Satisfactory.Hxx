#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"

namespace Sat {

	void Initialize();

	std::vector<Item*>     ItemList;
	std::vector<Recipe*>   RecipeList;
	std::vector<Building*> BuildingList;

	namespace Items {

		// Ores
		Item* LimeStone;

		//
	}

	#undef AUTO_ITEM

}

#endif