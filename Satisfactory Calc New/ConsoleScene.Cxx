#include "ConsoleScene.Hxx"

void ConsoleScene::InitializeBase() {

	Initialize();
	
	for (auto i : objects) {
		i->InitializeBase();
	}

}

void ConsoleScene::UpdateBase() {

	Update();

	for (auto i : objects) {
		i->UpdateBaes();


	}
}