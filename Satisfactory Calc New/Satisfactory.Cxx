#include "Satisfactory.Hxx"

using namespace Satisfactory;

void Satisfactory::Initialize() {

	using namespace Items;

	//================================================================================================| Item
	//==================================================================| Ores
	{ 
		Limestone = new Item();
		Limestone->Name = "Limestone";
		Limestone->Description.push_back("Used for crafting.");
		Limestone->Description.push_back("Basic resource mainly used for stable foundations.");
		Limestone->Category = ItemCategory::Ores;
		Limestone->MaxStackSize = 100;
		Limestone->SinkPoint = 2;
		ItemList.push_back(Limestone);
	} {
		
	}


}