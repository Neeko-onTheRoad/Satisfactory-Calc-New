#include "ItemWikiPage.Hxx"

ItemWikiPage::ItemWikiPage() {
	Render = false;
	Before = nullptr;

	Object = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, ' ');
	ForegroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::DefaultBackgroundColor);
}

ItemWikiPage::~ItemWikiPage() {
	Delete2DimDynamicArray(Object, SCENE_HEIGHT);
	Delete2DimDynamicArray(ForegroundColor, SCENE_HEIGHT);
	Delete2DimDynamicArray(BackgroundColor, SCENE_HEIGHT);
}

void ItemWikiPage::Initialize() {

}

void ItemWikiPage::Update(ISelectable*& _selecting) {

	if (_selecting == this) {
		if (KeyManager::GetKeyPressed(Keys::BACK)) {
			UnSelect();
			_selecting = Before;
			_selecting->Select();

			Render = false;
			NeedUpdate = true;

			return;
		}
	}

}

void ItemWikiPage::Make(const Item* item, ISelectable* _before) {

	Before = _before;

	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < CONSOLE_WIDTH; x++) {
			Object[y][x] = ' ';
			ForegroundColor[y][x] = Color::DefaultForegroundColor;
			BackgroundColor[y][x] = Color::DefaultBackgroundColor;
		}
	}

	unsigned upperBarEndPoint = static_cast<unsigned>(item->Description.size()) + 4u;

	// Name and Description
	for (unsigned y = 1; y < upperBarEndPoint; y++) {
		for (unsigned x = 2; x < CONSOLE_WIDTH - 3; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	for (unsigned x = 0; x < item->Name.size(); x++) {
		Object[2][x + 5] = item->Name[x];
		ForegroundColor[2][x + 5] = Color::HilightedForegroundColor;
	}

	for (unsigned y = 0; y < item->Description.size(); y++) {
		for (unsigned x = 0; x < item->Description[y].size(); x++) {
			Object[y + 3][x + 6] = item->Description[y][x];
		}
	}

	// Info Bar

	std::string Category    = "Category";
	std::string StackSize   = "Stack Size";
	std::string SinkPoints  = "Sink Points";
	std::string Energy      = "Energy";
	std::string PowerUse    = "Power Use";
	std::string Radioactive = "Radioactive";

	unsigned maxStrLength      = static_cast<unsigned>(SinkPoints.size());
	unsigned infoBarEndPoint   = upperBarEndPoint + 6;
	unsigned infoBarRightPoint = 0;

	if (!item->Radioactive.compare("")) {
		maxStrLength = static_cast<unsigned>(Radioactive.size());
	}

	int informationY = 2;
	{
		for (int x = 0; x < Category.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Category[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string CategoryElement = GetCategoriyName(item->Category);
		if (CategoryElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(CategoryElement.size());

		for (int x = 0; x < CategoryElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = CategoryElement[x];
		}

		informationY++;
	}

	{
		for (int x = 0; x < StackSize.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = StackSize[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string StackSizeElement = std::to_string(item->MaxStackSize) + " Unit";
		if (StackSizeElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(StackSizeElement.size());

		for (int x = 0; x < StackSizeElement.size(); x++) {;
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = StackSizeElement[x];
		}

		informationY++;
	}

	{
		for (int x = 0; x < SinkPoints.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = SinkPoints[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string SinkPointElement = std::to_string(item->SinkPoint) + " Point";
		if (SinkPointElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(SinkPointElement.size());

		for (int x = 0; x < SinkPointElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = SinkPointElement[x];
		}

		informationY++;
	}

	if (item->Energy != 0) {
		infoBarEndPoint++;

		for (int x = 0; x < Energy.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Energy[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string EnergyElement = std::to_string(item->Energy) + " MJ";
		if (EnergyElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(EnergyElement.size());
		for (int x = 0; x < EnergyElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = EnergyElement[x];
		}

		informationY++;
	}

	if (item->PowerUseAvrg) {
		infoBarEndPoint++;

		for (int x = 0; x < PowerUse.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = PowerUse[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string EnergyElement = "";
		EnergyElement += std::to_string(item->PowerUseMin) + " ~ " + std::to_string(item->PowerUseMin) + "MV";
		EnergyElement += " (" + std::to_string(item->PowerUseAvrg) + "MV)";

		if (EnergyElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(EnergyElement.size());
		for (int x = 0; x < EnergyElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = EnergyElement[x];
		}

		informationY++;
	}

	if (item->Radioactive.compare("")) {
		infoBarEndPoint++;

		for (int x = 0; x < Radioactive.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Radioactive[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string RadioactiveElement = item->Radioactive;
		if (RadioactiveElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(RadioactiveElement.size());
		for (int x = 0; x < RadioactiveElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = RadioactiveElement[x];
		}

		informationY++;
	}

	infoBarRightPoint += 11 + maxStrLength;

	for (unsigned y = upperBarEndPoint + 1; y < infoBarEndPoint; y++) {
		for (unsigned x = 2; x < infoBarRightPoint; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	// Recipes

	unsigned recipeEndPoint = upperBarEndPoint + 5u;

	std::string InputItem  = "Input Item";
	std::string OutputItem = "Output Item";

	int inputIndex = 6;
	int outputIndex = 43;

	for (unsigned x = 0; x < InputItem.size(); x++) {
		Object[upperBarEndPoint + 2][x + infoBarRightPoint + inputIndex] = InputItem[x];
		ForegroundColor[upperBarEndPoint + 2][x + infoBarRightPoint + inputIndex] = Color::HilightedForegroundColor;
	}

	for (unsigned x = 0; x < OutputItem.size(); x++) {
		Object[upperBarEndPoint + 2][x + infoBarRightPoint + outputIndex] = OutputItem[x];
		ForegroundColor[upperBarEndPoint + 2][x + infoBarRightPoint + outputIndex] = Color::HilightedForegroundColor;
	}

	for (unsigned x = infoBarRightPoint + 4; x < CONSOLE_WIDTH - 4; x++) {
		Object[upperBarEndPoint + 3][x] = Ascii::HZ_BAR;
		ForegroundColor[upperBarEndPoint + 3][x] = Color::HilightedForegroundColor;
	}

	for (auto& recipe : item->Recipes) {
		
		bool inputIsBigger = false;
		int maxHeight = 0;
		int minHeight = 0;


		if (recipe->Input.size() > recipe->Output.size()) {
			inputIsBigger = true;
			maxHeight = static_cast<int>(recipe->Input.size());
			minHeight = static_cast<int>(recipe->Output.size());
		}
		else {
			maxHeight = static_cast<int>(recipe->Output.size());
			minHeight = static_cast<int>(recipe->Input.size());
		}


		for (unsigned x = 0; x < recipe->Name.size(); x++) {

			Object[recipeEndPoint][x + infoBarRightPoint + inputIndex] = recipe->Name[x];
			ForegroundColor[recipeEndPoint][x + infoBarRightPoint + inputIndex] = Color::HilightedForegroundColor;

		}

		std::string building = " (" + recipe->Building->Name + ")";
		for (unsigned x = 0; x < building.size(); x++) {
			Object[recipeEndPoint][x + infoBarRightPoint + inputIndex + recipe->Name.size()] = building[x];
			ForegroundColor[recipeEndPoint][x + infoBarRightPoint + inputIndex + recipe->Name.size()] = Color::LightForegroundColor;
		}

		recipeEndPoint++;

		for (int i = 0; i < minHeight; i++) {
			std::string inputStr  = std::get<0>(recipe->Input [i])->Name + " x";
			std::string outputStr = std::get<0>(recipe->Output[i])->Name + " x";
			inputStr  += std::to_string(std::get<2>(recipe->Input [i])) + " (";
			outputStr += std::to_string(std::get<2>(recipe->Output[i])) + " (";
			inputStr  += std::format("{}", std::get<1>(recipe->Input [i])) + "/min)";
			outputStr += std::format("{}", std::get<1>(recipe->Output[i])) + "/min)";

			for (int x = 0; x < inputStr.size(); x++) {
				Object[recipeEndPoint + i][x + infoBarRightPoint + inputIndex + 2] = inputStr[x];
			}

			for (int x = 0; x < outputStr.size(); x++) {
				Object[recipeEndPoint + i][x + infoBarRightPoint + outputIndex + 2] = outputStr[x];
			}
		}

		for (int i = minHeight; i < maxHeight; i++) {

			std::string str = "";

			if (inputIsBigger) {
				
				str += std::get<0>(recipe->Input[i])->Name + " x";
				str += std::to_string(std::get<2>(recipe->Input[i])) + " (";
				str += std::format("{}", std::get<1>(recipe->Input[i])) + "/min)";

				for (int x = 0; x < str.size(); x++) {
					Object[recipeEndPoint + i][x + infoBarRightPoint + inputIndex + 2] = str[x];
				}

			}
			else {

				str += std::get<0>(recipe->Output[i])->Name + " x";
				str += std::to_string(std::get<2>(recipe->Output[i])) + " (";
				str += std::format("{}", std::get<1>(recipe->Output[i])) + "/min)";

				for (int x = 0; x < str.size(); x++) {
					Object[recipeEndPoint + i][x + infoBarRightPoint + outputIndex + 2] = str[x];
				}

			}

		}


		recipeEndPoint += maxHeight + 1 ;

	}

	for (unsigned y = upperBarEndPoint + 1; y < recipeEndPoint; y++) {
		for (unsigned x = infoBarRightPoint + 3; x < CONSOLE_WIDTH - 3; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}



}

unsigned ItemWikiPage::GetSizeX() const {
	return CONSOLE_WIDTH;
}

unsigned ItemWikiPage::GetSizeY() const {
	return SCENE_HEIGHT;
}

int ItemWikiPage::GetPositionX() const {
	return 0;
}

int ItemWikiPage::GetPositionY() const {
	return 0;
}

KeyGuides ItemWikiPage::GetKeyGuides() const {
	return { { Keys::BACK, "Close" }};
}

void ItemWikiPage::Select() {
	Render = true;
	NeedUpdate = true;
}

void ItemWikiPage::UnSelect() {
	Render = false;	
	NeedUpdate = true;
}
