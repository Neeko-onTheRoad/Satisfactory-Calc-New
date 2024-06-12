#include "ConsoleScene.Hxx"

void ConsoleScene::AddObject(ConsoleObject* _object, int _layer) {
	if (Objects.find(_layer) == Objects.end()) {
		Objects[_layer] = std::vector<ConsoleObject*>();
	}

	Objects[_layer].push_back(_object);
}

void ConsoleScene::InitializeBase() {

	Initialize();
	
	for (auto& layer : Objects) {
		for (auto& object : layer.second) {
			object->InitializeBase();
		}
	}

	for (unsigned y = 0; y < SCENE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			SceneRenderBuffer[y][x] = ' ';
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
		}
	}


	for (auto& layer : Objects) {
		for (auto& object : layer.second) {


			for (unsigned y = 0; y < object->GetSizeY(); y++) {
				for (unsigned x = 0; x < object->GetSizeX(); x++) {
					std::cout << object->Object[y][x];
				}
				std::cout << "\n";
			}


			for (unsigned y = 0; y < object->GetSizeY(); y++) {
				for (unsigned x = 0; x < object->GetSizeX(); x++) {

					unsigned renderY = y + object->GetPositionY();
					unsigned renderX = x + object->GetPositionX();

					if (
						renderY >= 0 &&
						renderX >= 0 &&
						renderY < SCENE_HEIGHT &&
						renderX < CONSOLE_WIDTH
					) {
						unsigned renderPositionY = renderY + object->GetPositionY();
						unsigned renderPositionX = renderX + object->GetPositionX();

						SceneRenderBuffer[renderPositionY][renderPositionX] = object->Object[renderY][renderX];
					}
				}
			}
		}
	}
	exit(1);
}
