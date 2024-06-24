#include "Item.Hxx"

#define AUTO_CASE(CAT) { ItemCategory::##CAT, #CAT }
std::map<ItemCategory, std::string> ItemNameOfCategory = {
	AUTO_CASE(Ores),
	AUTO_CASE(Ingots),
	AUTO_CASE(Minerals),
	AUTO_CASE(Aliens),
	AUTO_CASE(Liquids),
	AUTO_CASE(Gas),
	AUTO_CASE(StandardParts),
	AUTO_CASE(IndustrialParts),
	AUTO_CASE(Electronics),
	AUTO_CASE(Communications),
	AUTO_CASE(Containers),
	AUTO_CASE(Fuels),
	AUTO_CASE(Consumed),
	AUTO_CASE(Ammos),
	AUTO_CASE(Nuclear),
	AUTO_CASE(Waste),
	AUTO_CASE(Special)
};
#undef AUTO_CASE

#define AUTO_CASE(CAT) { #CAT, ItemCategory::##CAT }
std::map<std::string, ItemCategory> ItemCategoryByName = {
	AUTO_CASE(Ores),
	AUTO_CASE(Ingots),
	AUTO_CASE(Minerals),
	AUTO_CASE(Aliens),
	AUTO_CASE(Liquids),
	AUTO_CASE(Gas),
	AUTO_CASE(StandardParts),
	AUTO_CASE(IndustrialParts),
	AUTO_CASE(Electronics),
	AUTO_CASE(Communications),
	AUTO_CASE(Containers),
	AUTO_CASE(Fuels),
	AUTO_CASE(Consumed),
	AUTO_CASE(Ammos),
	AUTO_CASE(Nuclear),
	AUTO_CASE(Waste),
	AUTO_CASE(Special)
};
#undef AUTO_CASE