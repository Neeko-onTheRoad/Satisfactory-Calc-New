#include "ItemWiki.Hxx"
#include "ItemWikiPage.Hxx"

std::string ItemWiki::GetTitle() const {
	return "Item Wiki";
}

void ItemWiki::Initialize() {

	{
		TextBoxObject* line = new TextBoxObject;

		std::string lineStr = "";

		for (int x = 0; x < CONSOLE_WIDTH; x++) {
			lineStr += ' ';
		}
		lineStr += "\n";
		for (int x = 0; x < CONSOLE_WIDTH; x++) {
			lineStr += Ascii::HZ_BAR;
		}
		lineStr += "\n";

		line->Make(0, 0, lineStr);
		line->SetBackgroundColor(Color::HilightedBackgroundColor);

		AddObject(line);
	}

	{
		TextBoxObject* categoryBackground = new TextBoxObject;

		std::string categoryBgStr = "";
		
		for (int y = 2; y < SCENE_HEIGHT; y++) {
			for (int x = 0; x < CONSOLE_WIDTH / 5; x++) {
				categoryBgStr += " ";
			}

			categoryBgStr += '\n';
		}

		categoryBackground->Make(0, 2, categoryBgStr);
		categoryBackground->SetBackgroundColor(Color::HilightedBackgroundColor);

		AddObject(categoryBackground);
	}


	// Make Item Buttons
	int y = 3;
	ItemCategory prevCategory = ItemCategory::Ores;

	for (auto& item : Satisfactory::ItemList) {

		TextButton* buttonTemp = new TextButton;
	
		if (item.second->Category != prevCategory) y = 3;

		buttonTemp->Make(CONSOLE_WIDTH / 5 + 3, y++, item.second->Name);
		buttonTemp->Render = false;  
		buttonTemp->AdditionalKeyGuides.push_back({ Keys::BACK, "Category Select"});
		buttonTemp->SetBackCallBack([&]() {

			for (auto& itemButton : itemButtons[nowSelectedCategory]) {
				itemButton->Render = false;
			}

			for (auto& categoryButton : categoryButtons) {
				categoryButton->SetSelectedBackgroundColor(Color::HilightedForegroundColor);
				categoryButton->UnSelect();
			}

			Selecting->UnSelect();
			Selecting = categoryButtons[0];
			Selecting->Select();

			NeedUpdate = true;

		});
		buttonTemp->SetCallBack([&]() {
			nowPage->Render = true;
			nowPage->Make(item.second, itemButtons[nowSelectedCategory][0], Objects, Selecting, 2);

			Selecting->UnSelect();
			Selecting = nowPage;
			Selecting->Select();

			NeedUpdate = true;
		});

		itemButtons[item.second->Category].push_back(buttonTemp);
		AddObject(buttonTemp);

		prevCategory = item.second->Category;


	}

	y = 3;
	for (auto& category : itemButtons) {

		// Make Category Buttons
		TextButton* buttonTemp = new TextButton;
		
		buttonTemp->SetBackgroundColor(Color::HilightedBackgroundColor);
		buttonTemp->SetSelectedForegroundColor(Color::HilightedBackgroundColor);
		buttonTemp->SetSelectedBackgroundColor(Color::HilightedForegroundColor);
		buttonTemp->Make(4, y++, ItemNameOfCategory[category.first], false);
		buttonTemp->SetCallBack([&]() {

			for (auto& targetItemButton : itemButtons[category.first]) {
				targetItemButton->Render = true;
			}

			nowSelectedCategory = category.first;

			dynamic_cast<TextButton*>(Selecting)->SetSelectedBackgroundColor(Color::DefaultForegroundColor);
			Selecting->Select();

			Selecting = itemButtons[category.first][0];
			Selecting->Select();

			NeedUpdate = true;
		});

		categoryButtons.push_back(buttonTemp);
		AddObject(buttonTemp);

		// Link Buttons
		for (auto& categoryButtons : itemButtons) {
			
			if (categoryButtons.second.size() == 1) continue;

			for (int i = 0; i < categoryButtons.second.size(); i++) {
				if (i == 0) {
					categoryButtons.second[i]->LinkUpper(categoryButtons.second[categoryButtons.second.size() - 1]);
					categoryButtons.second[i]->LinkLower(categoryButtons.second[i + 1]);
				}
				else if (i == categoryButtons.second.size() - 1) {
					categoryButtons.second[i]->LinkUpper(categoryButtons.second[i - 1]);
					categoryButtons.second[i]->LinkLower(categoryButtons.second[0]);
				}
				else {
					categoryButtons.second[i]->LinkUpper(categoryButtons.second[i - 1]);
					categoryButtons.second[i]->LinkLower(categoryButtons.second[i + 1]);
				}
			}

		}
	}

	if (categoryButtons.size() != 1) {
		for (int i = 0; i < categoryButtons.size(); i++) {
			if (i == 0) {
				categoryButtons[i]->LinkUpper(categoryButtons[categoryButtons.size() - 1]);
				categoryButtons[i]->LinkLower(categoryButtons[i + 1]);
			}
			else if (i == categoryButtons.size() - 1) {
				categoryButtons[i]->LinkUpper(categoryButtons[i - 1]);
				categoryButtons[i]->LinkLower(categoryButtons[0]);
			}
			else {
				categoryButtons[i]->LinkUpper(categoryButtons[i - 1]);
				categoryButtons[i]->LinkLower(categoryButtons[i + 1]);
			}
		}
	}

	nowPage = new ItemWikiPage;
	AddObject(nowPage);

	Selecting = categoryButtons[0];

	NeedUpdate = true;

}


void ItemWiki::Update() {
}

void ItemWiki::rerender() {

}
