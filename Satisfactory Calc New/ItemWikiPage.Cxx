#include "ItemWikiPage.Hxx"

void ItemWikiPage::rerenderRecipe(std::map<int, std::vector<ConsoleObject*>>& _objects, int _layer) {

	for (int y = upperBarEndPoint + 4; y < SCENE_HEIGHT - 2; y++) {
		for (int x = infoBarRightPoint + 2; x < CONSOLE_WIDTH - 3; x++) {
			Object[y][x] = ' ';
			ForegroundColor[y][x] = Color::DefaultForegroundColor;
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	if (recipeSelect->GetElement() == Satisfactory::NullRecipe) {
		return;
	}

	std::string inputItemStr = "Input Item";
	std::string outputItemStr = "Output Item";

	int indexY = upperBarEndPoint + 5;

	for (int x = 0; x < inputItemStr.size(); x++) {
		Object[indexY][x + infoBarRightPoint + 6] = inputItemStr[x];
		ForegroundColor[indexY][x + infoBarRightPoint + 6] = Color::HilightedForegroundColor;
	}

	indexY++;

	int maxItemStrLen = 20;
	for (int i = 0; i < recipeSelect->GetElement()->Input.size(); i++) {
		
		std::string strBuffer = "";
		strBuffer += std::get<0>(recipeSelect->GetElement()->Input[i])->Name + " x";
		strBuffer += std::to_string(std::get<2>(recipeSelect->GetElement()->Input[i])) + " (";
		strBuffer += std::format("{}", std::get<1>(recipeSelect->GetElement()->Input[i])) + "/min)";

		if (strBuffer.size() > maxItemStrLen) maxItemStrLen = static_cast<int>(strBuffer.size());

		for (int x = 0; x < strBuffer.size(); x++) {
			Object[indexY][x + infoBarRightPoint + 8] = strBuffer[x];
			ForegroundColor[indexY][x + infoBarRightPoint + 8] = Color::LightForegroundColor;
		}
		for (int x = 0; x < std::get<0>(recipeSelect->GetElement()->Input[i])->Name.size(); x++) {
			ForegroundColor[indexY][x + infoBarRightPoint + 8] = Color::DefaultForegroundColor;
		}

		indexY++;
		}

	indexY++;

	for (int x = 0; x < outputItemStr.size(); x++) {
		Object[indexY][x + infoBarRightPoint + 6] = outputItemStr[x];
		ForegroundColor[indexY][x + infoBarRightPoint + 6] = Color::HilightedForegroundColor;
	}

	indexY++;


	for (int i = 0; i < recipeSelect->GetElement()->Output.size(); i++) {

		std::string strBuffer = "";
		strBuffer += std::get<0>(recipeSelect->GetElement()->Output[i])->Name + " x";
		strBuffer += std::to_string(std::get<2>(recipeSelect->GetElement()->Output[i])) + " (";
		strBuffer += std::format("{}", std::get<1>(recipeSelect->GetElement()->Output[i])) + "/min)";

		if (strBuffer.size() > maxItemStrLen) maxItemStrLen = static_cast<int>(strBuffer.size());

		for (int x = 0; x < strBuffer.size(); x++) {
			Object[indexY][x + infoBarRightPoint + 8] = strBuffer[x];
			ForegroundColor[indexY][x + infoBarRightPoint + 8] = Color::LightForegroundColor;
		}
		for (int x = 0; x < std::get<0>(recipeSelect->GetElement()->Output[i])->Name.size(); x++) {
			ForegroundColor[indexY][x + infoBarRightPoint + 8] = Color::DefaultForegroundColor;
		}

		indexY++;
	}

	indexY = upperBarEndPoint + 5;
	int indexX = maxItemStrLen + infoBarRightPoint + 15;

	for (int y = indexY - 1; y < SCENE_HEIGHT - 2; y++) {
		Object[y][indexX - 4] = Ascii::VT_BAR;
		ForegroundColor[y][indexX - 4] = Color::LightForegroundColor;
	}
	for (int x = infoBarRightPoint + 8; x < CONSOLE_WIDTH - 8; x++) {
		Object[indexY - 2][x] = Ascii::HZ_BAR;
	}
	Object[indexY - 2][indexX - 4] = Ascii::BT_BAR;

	{
		std::string productTimeStrOrg = "Product Time: ";
		std::string energyUseStrOrg = "";
		std::string productTimeStr = productTimeStrOrg;
		std::string energyUseStr;

		{
			
			auto target = (
				recipeSelect->GetElement()->Input.size() != 0 ?
				recipeSelect->GetElement()->Output[0] :
				recipeSelect->GetElement()->Input [0]
			);

			lDouble productTime = 0.;

			productTime  = std::get<1>(target);
			productTime /= std::get<2>(target);
			productTime  = 60.L / productTime;

			int floor = static_cast<int>(productTime * 100000);
			productTime = floor / 100000.L;

			productTimeStr += std::format("{} sec", productTime);

			for (int x = 0; x < productTimeStr.size(); x++) {
				Object[indexY][x + indexX] = productTimeStr[x];
			}

			for (int x = 0; x < productTimeStrOrg.size(); x++) {
				ForegroundColor[indexY][x + indexX] = Color::HilightedForegroundColor;
			} 

			lDouble energyUse = 0.;
			energyUse = (
				recipeSelect->GetElement()->Building->PowerUsed -
				recipeSelect->GetElement()->Building->PowerGeneration
				);

			if (energyUse > 0) {
				energyUseStrOrg = "Energy Usage: ";
				energyUseStr = energyUseStrOrg;

				energyUse *= productTime;

				energyUse /= std::get<1>(recipeSelect->GetElement()->Input[0]);

				int floor = static_cast<int>(energyUse * 100000);
				energyUse = floor / 100000.L;
				energyUseStr += std::format("{} MJ", energyUse);
				indexY++;

				for (int x = 0; x < energyUseStr.size(); x++) {
					Object[indexY][x + indexX] = energyUseStr[x];
				}

				for (int x = 0; x < energyUseStrOrg.size(); x++) {
					ForegroundColor[indexY][x + indexX] = Color::HilightedForegroundColor;
				}
			}
		}
	}


	indexY++;
	{
		std::string productAtStrOrg = "Product At: ";
		std::string productAtStr = productAtStrOrg + recipeSelect->GetElement()->Building->Name;

		for (int x = 0; x < productAtStr.size(); x++) {
			Object[indexY][x + indexX] = productAtStr[x];
		}

		for (int x = 0; x < productAtStrOrg.size(); x++) {
			ForegroundColor[indexY][x + indexX] = Color::HilightedForegroundColor;
		}

	}

}

ItemWikiPage::ItemWikiPage() {
	recipeSelect = new SelectBox<Recipe*>;
	nowSelect = recipeSelect;

	Render = false;
	before = nullptr;

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

	if (isSelected) {

		recipeSelect->UpdateBaes(nowSelect);

		if (KeyManager::GetKeyPressed(Keys::BACK)) {
			UnSelect();
			_selecting = before;
			_selecting->Select();

			Render = false;
			NeedUpdate = true;

			return;
		}

	}

}

void ItemWikiPage::Make(
	Item* _item, 
	ISelectable* _before,
	std::map<int, std::vector<ConsoleObject*>>& _objects,
	ISelectable* _selecting,
	int _layer
) {

	before = _before;
	itemSelected = _item;

	for (auto& layer : _objects) {
		auto iterator = std::find(layer.second.begin(), layer.second.end(), recipeSelect);
		if (iterator != layer.second.end()) layer.second.erase(iterator);
	}

	for (int y = 0; y < SCENE_HEIGHT; y++) {
		for (int x = 0; x < CONSOLE_WIDTH; x++) {
			Object[y][x] = ' ';
			ForegroundColor[y][x] = Color::DefaultForegroundColor;
			BackgroundColor[y][x] = Color::DefaultBackgroundColor;
		}
	}

	unsigned upperBarEndPoint = static_cast<unsigned>(_item->Description.size()) + 4u;

	// Name and Description
	for (unsigned y = 1; y < upperBarEndPoint; y++) {
		for (unsigned x = 2; x < CONSOLE_WIDTH - 3; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	for (unsigned x = 0; x < _item->Name.size(); x++) {
		Object[2][x + 5] = _item->Name[x];
		ForegroundColor[2][x + 5] = Color::HilightedForegroundColor;
	}

	for (unsigned y = 0; y < _item->Description.size(); y++) {
		for (unsigned x = 0; x < _item->Description[y].size(); x++) {
			Object[y + 3][x + 6] = _item->Description[y][x];
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
	unsigned infoBarEndPoint   = upperBarEndPoint + 4;
	unsigned infoBarRightPoint = 0;

	if (!_item->Radioactive.compare("")) {
		maxStrLength = static_cast<unsigned>(Radioactive.size());
	}

	int informationY = 2;

	{
		for (int x = 0; x < Category.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Category[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string CategoryElement = ItemNameOfCategory[_item->Category];
		if (CategoryElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(CategoryElement.size());

		for (int x = 0; x < CategoryElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = CategoryElement[x];
		}

		informationY++;
	}

	if (_item->MaxStackSize) {
		for (int x = 0; x < StackSize.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = StackSize[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string StackSizeElement = std::to_string(_item->MaxStackSize) + " Unit";
		if (StackSizeElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(StackSizeElement.size());

		for (int x = 0; x < StackSizeElement.size(); x++) {;
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = StackSizeElement[x];
		}

		informationY++;
		infoBarEndPoint++;
	}

	{
		for (int x = 0; x < SinkPoints.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = SinkPoints[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string SinkPointElement = "";
		
		if (_item->SinkPoint) {
			SinkPointElement = std::to_string(_item->SinkPoint) + " Point";
		}
		else {
			SinkPointElement = "Refusal";
		}

		if (SinkPointElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(SinkPointElement.size());

		for (int x = 0; x < SinkPointElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = SinkPointElement[x];
		}

		informationY++;
	}

	if (_item->Energy != 0) {
		infoBarEndPoint++;

		for (int x = 0; x < Energy.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Energy[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string EnergyElement = std::to_string(_item->Energy) + " MJ";
		if (EnergyElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(EnergyElement.size());
		for (int x = 0; x < EnergyElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = EnergyElement[x];
		}

		informationY++;
	}

	if (_item->PowerUseAvrg) {
		infoBarEndPoint++;

		for (int x = 0; x < PowerUse.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = PowerUse[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string EnergyElement = "";
		EnergyElement += std::to_string(_item->PowerUseMin) + " ~ " + std::to_string(_item->PowerUseMin) + "MV";
		EnergyElement += " (" + std::to_string(_item->PowerUseAvrg) + "MV)";

		if (EnergyElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(EnergyElement.size());
		for (int x = 0; x < EnergyElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = EnergyElement[x];
		}

		informationY++;
	}

	if (_item->Radioactive.compare("")) {
		infoBarEndPoint++;

		for (int x = 0; x < Radioactive.size(); x++) {
			Object[upperBarEndPoint + informationY][x + 5] = Radioactive[x];
			ForegroundColor[upperBarEndPoint + informationY][x + 5] = Color::HilightedForegroundColor;
		}

		std::string RadioactiveElement = _item->Radioactive;
		if (RadioactiveElement.size() > infoBarRightPoint) infoBarRightPoint = static_cast<unsigned>(RadioactiveElement.size());
		for (int x = 0; x < RadioactiveElement.size(); x++) {
			Object[upperBarEndPoint + informationY][maxStrLength + x + 7] = RadioactiveElement[x];
		}

		informationY++;
	}

	infoBarRightPoint += 11 + maxStrLength;

	for (unsigned y = upperBarEndPoint + 1; y < infoBarEndPoint + 1; y++) {
		for (unsigned x = 2; x < infoBarRightPoint; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	for (unsigned y = upperBarEndPoint + 1; y < SCENE_HEIGHT - 1; y++) {
		for (unsigned x = infoBarRightPoint + 2; x < CONSOLE_WIDTH - 3; x++) {
			BackgroundColor[y][x] = Color::HilightedBackgroundColor;
		}
	}

	{
		std::string recipeStr = "Recipe: ";
		for (int x = 0; x < recipeStr.size(); x++) {
			Object[upperBarEndPoint + 2][x + infoBarRightPoint + 6] = recipeStr[x];
			ForegroundColor[upperBarEndPoint + 2][x + infoBarRightPoint + 6] = Color::HilightedForegroundColor;
		}

		int rsX = static_cast<int>(recipeStr.size()) + infoBarRightPoint + 6;
		int rsY = upperBarEndPoint + 2;

		std::vector<std::pair<Recipe*, std::string>> rsOptions;

		for (auto& recipe : _item->Recipes) {
			rsOptions.emplace_back(recipe, recipe->Name);
		}

		if (rsOptions.size() == 0) {
			rsOptions.emplace_back(Satisfactory::NullRecipe, "No Recipe");
		}

		recipeSelect->SetSelectedBackgroundColor(Color::HilightedForegroundColor);
		recipeSelect->SetSelectedForegroundColor(Color::HilightedBackgroundColor);
		recipeSelect->SetOptionBackgroundColor(Color::DefaultBackgroundColor);
		recipeSelect->Make(rsX, rsY, rsOptions, _objects, _layer + 1);
		recipeSelect->SetCallBack([&]() { isSelected = false; });
		recipeSelect->SetBackCallBack([&]() { 
			isSelected = true;
			rerenderRecipe(_objects, _layer);
		});

		recipeSelect->Render = false;
		_objects[_layer].push_back(recipeSelect);

		for (int x = infoBarRightPoint + 4; x < CONSOLE_WIDTH - 5; x++) {
			Object[rsY + 1][x] = Ascii::HZ_BAR;
			ForegroundColor[rsY + 1][x] = Color::LightForegroundColor;
		}
	}

	this->upperBarEndPoint  = upperBarEndPoint;
	this->infoBarRightPoint = infoBarRightPoint;

	nowSelect = recipeSelect;
	nowSelect->Select();

	rerenderRecipe(_objects, _layer);
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
	recipeSelect->Render = true;

	isSelected = true;
	Render = true;
	NeedUpdate = true;
}

void ItemWikiPage::UnSelect() {
	recipeSelect->Render = false;

	isSelected = false;
	Render = false;	
	NeedUpdate = true;
}
