#include "MainScreen.Hxx"
#include <iostream>
void MainScreen::Initialize() {
	
	{ // Title

		title->Make(4, 2, Resources::ConsoleTitle, 1);
		title->SetForegroundColor(Color::HilightedForegroundColor);
		title->SetBackgroundColor(Color::HilightedBackgroundColor);
		

		for (unsigned x = 7u; x <= 12u; x++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, x, 6);
		}

		for (unsigned x = 15u; x <= 20u; x++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, x, 6);
		}

		for (unsigned x = 56u; x < title->GetSizeX(); x++) {
			title->SetForegroundColor(Color::DefaultForegroundColor, x, 5);
		}

		AddObject(title);
	}

	{ // Buttons

		itemWiki->      Make(7, 12, "Item Wiki");
		buildingWiki->  Make(7, 13, "Building Wiki");
		powerPlanner->  Make(7, 14, "Power Planner");
		producePlanner->Make(7, 15, "Produce Planner");
		credit->        Make(7, 17, "Credit");
		exit->          Make(7, 18, "Exit");

		itemWiki->      LinkUpper(exit);
		buildingWiki->  LinkUpper(itemWiki);
		powerPlanner->  LinkUpper(buildingWiki);
		producePlanner->LinkUpper(powerPlanner);
		credit->        LinkUpper(producePlanner);
		exit->          LinkUpper(credit);

		itemWiki->      LinkLower(buildingWiki);
		buildingWiki->  LinkLower(powerPlanner);
		powerPlanner->  LinkLower(producePlanner);
		producePlanner->LinkLower(credit);
		credit->        LinkLower(exit);
		exit->          LinkLower(itemWiki);

		exit->SetCallBack([](){
			std::exit(0);
		});

		AddObject(itemWiki);
		AddObject(buildingWiki);
		AddObject(powerPlanner);
		AddObject(producePlanner);
		AddObject(credit);
		AddObject(exit);

		Selecting = itemWiki;
	}

	{ // credit

		creditPopup->Make(0, 0, Resources::Credit);
		int creditX = static_cast<int>((CONSOLE_WIDTH / 2.) - (creditPopup->GetSizeX() / 2.));
		int creditY = static_cast<int>((SCENE_HEIGHT  / 2.) - (creditPopup->GetSizeY() / 2.));

		creditPopup->SetPosition(creditX, creditY);

		creditPopup->SetForegroundColor(Color::DefaultForegroundColor);
		creditPopup->SetBackgroundColor(Color::HilightedBackgroundColor);

		for (unsigned x = 0u; x < creditPopup->GetSizeX(); x++) {
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, x, 0u);
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, x, 7u);
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, x, 11u);
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, x, creditPopup->GetSizeY() - 1u);
		}

		for (unsigned y = 1u; y < creditPopup->GetSizeY() - 1; y++) {
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, 0u, y);
			creditPopup->SetForegroundColor(Color::HilightedForegroundColor, creditPopup->GetSizeX() - 1u, y);
		}

		ColorCode suAngRainbow[] = {
			196, 208, 220, 154, 1, 47, 51, 1, 33, 21, 57, 128, 163
		//  C    h    o    e    _  S   u   _  A   n   g   .    T
		};

		for (int x = 0; x < 13; x++) {
			creditPopup->SetForegroundColor(suAngRainbow[x], x + 22, 14);
		}

		AddObject(creditPopup, 1);

	}


}

void MainScreen::Update() {

	if (KeyManager::GetKeyPressed(Keys::DOWN)) {
		Selecting->UnSelect();
		Selecting = Selecting->GetLower();
		Selecting->Select();
		NeedUpdate = true;
	}
	else if (KeyManager::GetKeyPressed(Keys::UP)) {
		Selecting->UnSelect();
		Selecting = Selecting->GetUpper();
		Selecting->Select();
		NeedUpdate = true;
	}
	else if (KeyManager::GetKeyPressed(Keys::SELECT)) {
		if (TextButton* text = dynamic_cast<TextButton*>(Selecting)) {
			text->CallBack();
		}
	}

}

std::string MainScreen::GetTitle() const {
	return "Home";
}
