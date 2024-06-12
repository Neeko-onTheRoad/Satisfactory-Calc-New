#include "MainScreen.Hxx"

void MainScreen::Initialize() {

	TextBoxObject* title = new TextBoxObject;
	title->Make(0, 0, Resources::ConsoleTitle);
	AddObject(title, 0);
	
}

void MainScreen::Update() {
}

std::string MainScreen::GetTitle() const {
	return "Home";
}
