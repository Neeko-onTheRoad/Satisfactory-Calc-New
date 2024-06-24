#include "Satisfactory.Hxx"

namespace Satisfactory {

	std::vector<Item*>     ItemList;
	std::vector<Building*> BuildingList;
	std::vector<Recipe*>   RecipeList;

	std::unordered_map<std::string, Item*> ItemTable;
	std::unordered_map<std::string, Building*> BuildingTable;
	std::unordered_map<std::string, Recipe*> RecipeTable;

	std::vector<Item*> PowerSources;

	Recipe* NullRecipe;

	void Initialize() {
	
		NullRecipe = new Recipe;
		NullRecipe->Name = "No Recipe";
		NullRecipe->Building = new Building;

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
					for (int i = 0; input[i] == ' ' || input[i] == '\t'; i++) inputOffset++;
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
					else if (slicedInput.starts_with("\\eng")) {
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

				ItemList.push_back(targetItem);
				ItemTable[target] = targetItem;

			}
			itemDataFile.close();
		}

		{
			buildingDataFile.open(".\\res\\Initialize\\BuildingInit.nkdt");

			while (!buildingDataFile.eof()) {

				std::getline(buildingDataFile, input);

				if (!input.compare("")) continue;
				if (input.starts_with("//")) continue;

				std::string target = input;
				Building* targetBuilding = new Building;

				while (true) {

					std::getline(buildingDataFile, input);

					if (!input.compare("")) continue;
					if (input.starts_with("//")) continue;

					if (!input.compare("\\end")) break;


					int inputOffset = 0;
					for (int i = 0; input[i] == ' ' || input[i] == '\t'; i++) inputOffset++;

					std::string slicedInput = input.substr(inputOffset);
					std::string sliced = input.substr(inputOffset + 5);

					if (slicedInput.starts_with("\\nme")) {
						targetBuilding->Name = sliced;
					}
					else if (slicedInput.starts_with("\\des")) {
						targetBuilding->Description.push_back(sliced);
					}
					else if (slicedInput.starts_with("\\cat")) {
						targetBuilding->Category = BuildingCategoryByName[sliced];
					}
					else if (slicedInput.starts_with("\\ing")) {
						std::istringstream iss(sliced);
						std::string tempItemName;
						unsigned    tempItemCount;

						iss >> tempItemName >> tempItemCount;
						targetBuilding->Ingredients.emplace_back(ItemTable[tempItemName], tempItemCount);
					}
					else if (slicedInput.starts_with("\\siz")) {
						std::istringstream iss(sliced);
						unsigned tempWidth;
						unsigned tempLength;
						unsigned tempHeight;

						iss >> tempWidth >> tempLength >> tempHeight;
						targetBuilding->Width  = tempWidth;
						targetBuilding->Length = tempLength;
						targetBuilding->Height = tempHeight;

					}
					else if (slicedInput.starts_with("\\ios")) {
						std::istringstream iss(sliced);
						unsigned tempInput;
						unsigned tempOutput;

						iss >> tempInput >> tempOutput;
						targetBuilding->Input  = tempInput;
						targetBuilding->Output = tempOutput;
					}
					else if (slicedInput.starts_with("\\pwu")) {
						if (!sliced.compare("CBC")) {
							targetBuilding->PowerUsed = CASE_BY_CASE;
						}
						else targetBuilding->PowerUsed = std::stoi(sliced);
					}
					else if (slicedInput.starts_with("\\pwg")) {
						if (!sliced.compare("INF")) {
							targetBuilding->PowerUsed = INFINE;
						}
						else targetBuilding->PowerGeneration = std::stoi(sliced);
					}

				}

				BuildingList.push_back(targetBuilding);
				BuildingTable[target] = targetBuilding;
			}

			buildingDataFile.close();
		}

		{
			recipeDataFile.open(".\\res\\Initialize\\RecipeInit.nkdt");

			while (!recipeDataFile.eof()) {

				std::getline(recipeDataFile, input);

				if (!input.compare("")) continue;
				if (input.starts_with("//")) continue;

				std::string target = input;
				Recipe* targetRecipe = new Recipe;

				while (true) {

					std::getline(recipeDataFile, input);

					if (!input.compare("")) continue;
					if (input.starts_with("//")) continue;

					if (!input.compare("\\end")) break;

					int inputOffset = 0;
					for (int i = 0; input[i] == ' ' || input[i] == '\t'; i++) inputOffset++;

					std::string slicedInput = input.substr(inputOffset);

					if (slicedInput.starts_with("\\alt")) {
						targetRecipe->IsAlt = true;
						continue;
					}

					std::string sliced = input.substr(inputOffset + 5);

					if (slicedInput.starts_with("\\nme")) {
						targetRecipe->Name = (targetRecipe->IsAlt ? "Alternate: " : "") + sliced;
					}
					else if (slicedInput.starts_with("\\bdg")) {
						targetRecipe->Building = BuildingTable[sliced];
					}
					else if (slicedInput.starts_with("\\inn")) {
						std::istringstream iss(sliced);

						std::string tempItem;
						lDouble     tempPerMin;
						unsigned    tempAmount;

						iss >> tempItem >> tempPerMin >> tempAmount;
						targetRecipe->AddInput(ItemTable[tempItem], tempPerMin, tempAmount);

					}
					else if (slicedInput.starts_with("\\out")) {
						std::istringstream iss(sliced);

						std::string tempItem;
						lDouble     tempPerMin;
						unsigned    tempAmount;

						iss >> tempItem >> tempPerMin >> tempAmount;
						targetRecipe->AddOutput(ItemTable[tempItem], tempPerMin, tempAmount);
					}

				}

				RecipeList.push_back(targetRecipe);
				RecipeTable[target] = targetRecipe;

			}

			recipeDataFile.close();
		}

	}
}
