#include "MainScreen.Hxx"
#include <iostream>

void MainScreen::Initialize() {
	
	{ // Title

		TextBoxObject* title = new TextBoxObject;
		title->Make(4, 2, Resources::ConsoleTitle, 1);
		title->SetForegroundColor(Color::HilightedForegroundColor);
		title->SetBackgroundColor(Color::HilightedBackgroundColor);

		for (int i = 7; i <= 12; i++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, i, 6);
		}

		for (int i = 15; i <= 20; i++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, i, 6);
		}

		for (unsigned i = 56; i < title->GetSizeX(); i++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, i, 5);
		}

		AddObject(title, 0);
	}
}

void MainScreen::Update() {


}

std::string MainScreen::GetTitle() const {
	return "Home";
}
