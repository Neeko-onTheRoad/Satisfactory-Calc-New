#pragma once

#ifndef _SATISFACTORY_HXX_
#define _SATISFACTORY_HXX_

#include "Item.Hxx"
#include "Recipe.Hxx"
#include "Building.Hxx"

namespace Satisfactory {

	void Initialize();

	static std::vector<Item*>     ItemList;
	static std::vector<Recipe*>   RecipeList;
	static std::vector<Building*> BuildingList;

	namespace Items {

		// Ores
		static Item* Limestone;
		static Item* Ironore;
		static Item* CopperOre;
		static Item* CateriumOre;
		static Item* Coal;
		static Item* RawQuartz;
		static Item* Sulfur;
		static Item* Bauxite;
		static Item* SAMOre;
		static Item* Uranium;

		// Ingots
		static Item* IronIngot;
		static Item* CopperIngot;
		static Item* CateriumIngot;
		static Item* SteelIngot;
		static Item* AluminumIngot;

		// Minerals
		static Item* Concrete;
		static Item* QuartzCrystal;
		static Item* Silica;
		static Item* CopperPowder;
		static Item* PolymerResin;
		static Item* PetroleumCoke;
		static Item* AluminumScrap;

		// Ailiens

		// Liquids

		// Gas

		// Standard Parts

		// Industrial Parts

		// Electronics

		// Communications

		// Containers

		// Fuels

		// Consumed

		// Ammos

		// Nuclear

		// Waste

		// Special
	}

}

#endif