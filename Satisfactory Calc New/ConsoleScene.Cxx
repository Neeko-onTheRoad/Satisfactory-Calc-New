#include "ConsoleScene.Hxx"

void ConsoleScene::AddObject(ConsoleObject* _object, int _layer) {
	Objects[_layer].push_back(_object);
}

void ConsoleScene::InitializeBase() {

	Initialize();
	
	for (auto& layer : Objects) {
		for (auto& object : layer.second) {
			object->InitializeBase();
		}
	}
}

void ConsoleScene::UpdateBase() {

	Update();

	for (auto& layer : Objects) {
		for (auto& object : layer.second) {
			object->UpdateBaes();
			
			if (object->NeedUpdate) {
				NeedUpdate = true;
				object->NeedUpdate = false;
			}
		}
	}
}
#include <iostream>

void ConsoleScene::Rerender() {

	for (unsigned y = 0; y < SCENE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			SceneRenderBuffer[y][x] = ' ';
			SceneBackgroundColor[y][x] = Color::DefaultBackgroundColor;
			SceneForegroundColor[y][x] = Color::HilightedForegroundColor;
		}
	}


	for (auto& layer : Objects) {
		for (auto& object : layer.second) {

			for (unsigned y = 0; y < object->GetSizeY(); y++) {
				for (unsigned x = 0; x < object->GetSizeX(); x++) {

					int renderY = y + object->GetPositionY();
					int renderX = x + object->GetPositionX();

					if (
						renderY >= 0 &&
						renderX >= 0 &&
						renderY < SCENE_HEIGHT &&
						renderX < CONSOLE_WIDTH
					) {
						SceneRenderBuffer   [renderY][renderX] = object->Object[y][x];
						SceneForegroundColor[renderY][renderX] = object->ForegroundColor[y][x];
						SceneBackgroundColor[renderY][renderX] = object->BackgroundColor[y][x];
					}
				}
			}
		}
	}
}
