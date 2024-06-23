#include "Satisfactory.Hxx"
#include <iostream>

namespace Satisfactory {

	std::map<std::string, Item*>     ItemList;
	std::map<std::string, Building*> BuildingList;
	std::map<std::string, Recipe*>   RecipeList;

	std::vector<Item*> PowerSources;

	void Initialize() {
	


		std::string input;
			
		std::ifstream itemDataFile;
		std::ifstream buildingDataFile;
		std::ifstream recipeDataFile;

		{
			itemDataFile.open(".\\res\\Initialize\\ItemInit.nkdt");
			while (!itemDataFile.eof()) {

				std::getline(itemDataFile, input);

				if (!input.compare("")) continue;
				if (input.starts_with("//")) continue;

				std::string target = input;
				Item* targetItem = new Item;

				while(true) {

					std::getline(itemDataFile, input);

					if (!input.compare("")) continue;
					if (input.starts_with("//")) continue;

					if (!input.compare("\\end")) break;

					int inputOffset = 0;
					for (int i = 0; input[i] == ' ' || input[i] == '\t'; i++) {
						inputOffset++;
					}
					std::string slicedInput = input.substr(inputOffset);
					std::string sliced = input.substr(inputOffset + 5);

					if (slicedInput.starts_with("\\nme")) {
						targetItem->Name = sliced;
					}
					else if (slicedInput.starts_with("\\des")) {
						targetItem->Description.push_back(sliced);
					}
					else if (slicedInput.starts_with("\\cat")) {
						targetItem->Category = ItemCategoryByName[sliced];
					}
					else if (slicedInput.starts_with("\\stk")) {
						targetItem->MaxStackSize = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\snk")) {
						targetItem->SinkPoint = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\ene")) {
						targetItem->Energy = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\pmi")) {
						targetItem->PowerUseMin = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\pmx")) {
						targetItem->PowerUseMax = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\pav")) {
						targetItem->PowerUseAvrg = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\rad")) {
						targetItem->Radioactive = sliced;
					}

				}

				ItemList[target] = targetItem;

			}
			itemDataFile.close();
		}

		Building* t = new Building;
		t->Name = "AS";
		BuildingList["Assembler"] = t;

		Recipe* test = new Recipe;
		test->Name = "Text One";
		test->Building = BuildingList["Assembler"];
		test->AddInput(ItemList["Limestone"], 30., 1);
		test->AddOutput(ItemList["Limestone"], 60., 2);

		Satisfactory::RecipeList["F"] = test;

		Recipe* tes2 = new Recipe;
		tes2->Name = "Text One";
		tes2->IsAlt = true;
		tes2->Building = BuildingList["Assembler"];
		tes2->AddInput(ItemList["Limestone"], 30., 1);
		tes2->AddInput(ItemList["Limestone"], 30., 1);
		tes2->AddInput(ItemList["Limestone"], 30., 1);
		tes2->AddOutput(ItemList["Limestone"], 60., 2);

		Satisfactory::RecipeList["F2"] = test;
	}
}
