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
				NeedUpdate = true;000
			}
		}
	}
}

void ConsoleScene::Rerender()
{
}
