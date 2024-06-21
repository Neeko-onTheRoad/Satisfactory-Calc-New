#include "Satisfactory.Hxx"

void Satisfactory::InitializeItems() {

	using namespace Items;

	{ //==============================================================================================| Ores

		Limestone = new Item;
		Limestone->Name = "Limestone";
		Limestone->Description.push_back("Used for crafting.");
		Limestone->Description.push_back("Basic resource mainly used for stable foundations.");
		Limestone->Category = ItemCategory::Ores;
		Limestone->MaxStackSize = 100;
		Limestone->SinkPoint = 2;
		ItemList.push_back(Limestone);
	} {
		IronOre = new Item;
		IronOre->Name = "Iron Ore";
		IronOre->Description.push_back("Used for crafting.");
		IronOre->Description.push_back("The most essential basic resource.");
		IronOre->Category = ItemCategory::Ores;
		IronOre->MaxStackSize = 100;
		IronOre->SinkPoint = 1;
		ItemList.push_back(IronOre);
	} {
		CopperOre = new Item;
		CopperOre->Name = "Copper Ore";
		CopperOre->Description.push_back("Used for crafting.");
		CopperOre->Description.push_back("Basic resource mainly used for electricity.");
		CopperOre->Category = ItemCategory::Ores;
		CopperOre->MaxStackSize = 100;
		CopperOre->SinkPoint = 3;
		ItemList.push_back(CopperOre);
	} {
		CateriumOre = new Item;
		CateriumOre->Name = "Caterium Ore";
		CateriumOre->Description.push_back("Caterium Ore is smelted into Caterium Ingots.");
		CateriumOre->Description.push_back("Caterium Ingots are mostly used for advanced electronics.");
		CateriumOre->Category = ItemCategory::Ores;
		CateriumOre->MaxStackSize = 100;
		CateriumOre->SinkPoint = 7;
		ItemList.push_back(CateriumOre);
	} {
		Coal = new Item;
		Coal->Name = "Coal";
		Coal->Description.push_back("Mainly used as vehicles & coal generators and for steel production.");
		Coal->Category = ItemCategory::Ores;
		Coal->MaxStackSize = 100;
		Coal->Energy = 300;
		Coal->SinkPoint = 3;
		ItemList.push_back(Coal);
		PowerSources.push_back(Coal);
	} {
		RawQuartz = new Item;
		RawQuartz->Name = "Raw Quartz";
		RawQuartz->Description.push_back("Raw Quartz can be processed into Quartz Crystals and Silica,");
		RawQuartz->Description.push_back("which both offer a variety of applications.");
		RawQuartz->Category = ItemCategory::Ores;
		RawQuartz->MaxStackSize = 100;
		RawQuartz->SinkPoint = 15;
		ItemList.push_back(RawQuartz);
	} {
		Sulfur = new Item;
		Sulfur->Name = "Sulfur";
		Sulfur->Description.push_back("Sulfur is primarily used for Black Powder.");
		Sulfur->Category = ItemCategory::Ores;
		Sulfur->MaxStackSize = 100;
		Sulfur->SinkPoint = 11;
		ItemList.push_back(Sulfur);
	} {
		Bauxite = new Item;
		Bauxite->Name = "Bauxite";
		Bauxite->Description.push_back("Bauxite is used to produce Alumina,");
		Bauxite->Description.push_back("which can be further refined into the Aluminum Scrap required to produce Aluminum Ingots");
		Bauxite->Category = ItemCategory::Ores;
		Bauxite->MaxStackSize = 100;
		Bauxite->SinkPoint = 8;
		ItemList.push_back(Bauxite);
	} {
		SAMOre = new Item;
		SAMOre->Name = "S.A.M. Ore";
		SAMOre->Description.push_back("Stange Alien Metal that glistens with new possibilities.");
		SAMOre->Category = ItemCategory::Ores;
		SAMOre->MaxStackSize = 50;
		SAMOre->SinkPoint = 0;
		ItemList.push_back(SAMOre);
	} {
		Uranium = new Item;
		Uranium->Name = "Uranium";
		Uranium->Description.push_back("Uranium is a radioactive element.");
		Uranium->Description.push_back("Used to produce Encased Uranium Cells for Uranium Fuel Rods.");
		Uranium->Description.push_back("");
		Uranium->Description.push_back("Caution: Moderately Radioactive.");
		Uranium->Category = ItemCategory::Ores;
		Uranium->MaxStackSize = 100;
		Uranium->SinkPoint = 35;
		ItemList.push_back(Uranium);
	}

}