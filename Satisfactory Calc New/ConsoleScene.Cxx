#include "ConsoleScene.Hxx"

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

void ConsoleScene::Rerender() {

	for (auto& layer : Objects) {
		for (auto& object : layer.second) {

			for (unsigned y = 0; y < object->GetSizeY(); y++) {
				for (unsigned x = 0; x < object->GetSizeX(); x++) {

					unsigned renderY = y + object->GetPositionY();
					unsigned renderX = x + object->GetPositionX();

					if (
						renderY >= 0 &&
						renderX >= 0 &&
						renderY < CONSOLE_HEIGHT &&
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
}
