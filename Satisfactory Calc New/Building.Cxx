#include "Building.Hxx"



#define AUTO_CASE(CAT) { BuildingCategory::##CAT, #CAT }
std::map<BuildingCategory, std::string> BuildingNameOfCategory = {
	AUTO_CASE(Extraction),
	AUTO_CASE(Production),
	AUTO_CASE(Generators),
	AUTO_CASE(Special),
	AUTO_CASE(Workstations),
	AUTO_CASE(Storage),
	AUTO_CASE(DockingStations),
	AUTO_CASE(Towers)
};
#undef AUTO_CASE


#define AUTO_CASE(CAT) { #CAT, BuildingCategory::##CAT }
std::map<std::string, BuildingCategory> BuildingCategoryByName = {
	AUTO_CASE(Extraction),
	AUTO_CASE(Production),
	AUTO_CASE(Generators),
	AUTO_CASE(Special),
	AUTO_CASE(Workstations),
	AUTO_CASE(Storage),
	AUTO_CASE(DockingStations),
	AUTO_CASE(Towers)
};
#undef AUTO_CASE