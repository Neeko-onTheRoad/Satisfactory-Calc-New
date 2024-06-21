#include "ConsoleScene.Hxx"

void ConsoleScene::AddObject(ConsoleObject* _object, int _layer) {
	
	//if (SelectBox<void*>* selectBox = dynamic_cast<SelectBox<void*>*>(_object)) {
	//	
	//}

	Objects[_layer].push_back(_object);
	NeedUpdate = true;
}

KeyGuides ConsoleScene::GetAllKeyGuides() {

	// Add Key Guide of Scene and Selecting Object and return
	KeyGuides result;

	for (auto& keyGuide : AdditionalKeyGuides) {
		result.push_back(keyGuide);
	}

	if (Selecting) {
		for (auto& keyGuide : Selecting->GetKeyGuides()) {
			result.push_back(keyGuide);
		}
	}

	return result;
}

void ConsoleScene::InitializeBase() {

	Initialize();

	// Shared Key Guides of all Scene (except from home screen)
	AdditionalKeyGuides.push_back({ "ESC",    "Go Home"});
	AdditionalKeyGuides.push_back({ "LShift", "Left Scene"});
	AdditionalKeyGuides.push_back({ "RShift", "Right Scene"});
	
	for (auto& layer : Objects) {
		for (auto& object : layer.second) {
			object->InitializeBase();
		}
	}

	if (Selecting != nullptr) {
		Selecting->Select();
	}
}

void ConsoleScene::UpdateBase() {


	// Update all Object
	for (auto& layer : Objects) {
		for (auto& object : layer.second) {
			object->UpdateBaes(Selecting);
			
			if (object->NeedUpdate) {
				NeedUpdate = true;
				object->NeedUpdate = false;
			}
		}
	}

	// Move Logic
	if (KeyManager::GetKeyPressed(Keys::UP)) {
		if (Selecting->GetUpper()) {
			Selecting->UnSelect();
			Selecting = Selecting->GetUpper();
			Selecting->Select();
			NeedUpdate = true;

			return;
		}
	}
	else if (KeyManager::GetKeyPressed(Keys::DOWN)) {
		if (Selecting->GetLower()) {
			Selecting->UnSelect();
			Selecting = Selecting->GetLower();
			Selecting->Select();
			NeedUpdate = true;

			return;
		}
	}
	else if (KeyManager::GetKeyPressed(Keys::LEFT)) {
		if (Selecting->GetLeft()) {
			Selecting->UnSelect();
			Selecting = Selecting->GetLeft();
			Selecting->Select();
			NeedUpdate = true;
			
			return;
		}
	}
	else if (KeyManager::GetKeyPressed(Keys::RIGHT)) {
		if (Selecting->GetRight()) {
			Selecting->UnSelect();
			Selecting = Selecting->GetRight();
			Selecting->Select();
			NeedUpdate = true;

			return;
		}
	}

	Update();
}

void ConsoleScene::Rerender() {

	// Initialize element Render Buffer
	for (unsigned y = 0u; y < SCENE_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			SceneRenderBuffer[y][x] = ' ';
			SceneBackgroundColor[y][x] = Color::DefaultBackgroundColor;
			SceneForegroundColor[y][x] = Color::HilightedForegroundColor;
		}
	}


	// Draw all Object in Render Buffer
	for (auto& layer : Objects) {
		for (auto& object : layer.second) {

			if (!object->Render) continue;

			for (unsigned y = 0u; y < object->GetSizeY(); y++) {
				for (unsigned x = 0u; x < object->GetSizeX(); x++) {

					int renderY = y + object->GetPositionY();
					int renderX = x + object->GetPositionX();

					// Check pixel is in Screen
					if (
						renderY >= 0 &&
						renderX >= 0 &&
						renderY < SCENE_HEIGHT &&
						renderX < CONSOLE_WIDTH
					) {
						SceneRenderBuffer [renderY][renderX] = object->Object [y][x];
						if (object->ForegroundColor[y][x]) SceneForegroundColor[renderY][renderX] = object->ForegroundColor[y][x];
						if (object->BackgroundColor[y][x]) SceneBackgroundColor[renderY][renderX] = object->BackgroundColor[y][x];
					}
				}
			}
		}
	}
}
