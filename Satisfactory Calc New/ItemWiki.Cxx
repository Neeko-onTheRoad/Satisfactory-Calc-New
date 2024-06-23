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
		TextBoxObject* centerLine = new TextBoxObject;

		std::string lineStr = "";
		
		for (int y = 2; y < SCENE_HEIGHT; y++) {
			lineStr += Ascii::VT_BAR;
			lineStr += '\n';
		}

		centerLine->Make(CONSOLE_WIDTH / 2 - 10, 2, lineStr);

		AddObject(centerLine);
	}


	// Make Item Buttons
	int y = 3;
	ItemCategory prevCategory = ItemCategory::Ores;

	for (auto& item : Satisfactory::ItemList) {

		TextButton* buttonTemp = new TextButton;
	
		if (item->Category != prevCategory) y = 3;

		buttonTemp->Make(CONSOLE_WIDTH / 2 - 6, y++, item->Name);
		buttonTemp->Render = false;  
		buttonTemp->AdditionalKeyGuides.push_back({ Keys::BACK, "Category Select"});
		buttonTemp->SetBackCallBack([&]() {

			for (auto& itemButton : itemButtons[nowSelectedCategory]) {
				itemButton->Render = false;
			}

			for (auto& categoryButton : categoryButtons) {
				categoryButton->SetSelectedForegroundColor(Color::HilightedForegroundColor);
				categoryButton->UnSelect();
			}

			Selecting->UnSelect();
			Selecting = categoryButtons[0];
			Selecting->Select();

			NeedUpdate = true;

		});
		buttonTemp->SetCallBack([&]() {
			nowPage->Render = true;
			nowPage->Make(item, itemButtons[nowSelectedCategory][0]);

			Selecting->UnSelect();
			Selecting = nowPage;
			Selecting->Select();

			NeedUpdate = true;
		});

		itemButtons[item->Category].push_back(buttonTemp);
		AddObject(buttonTemp);

		prevCategory = item->Category;

	}

	y = 3;
	for (auto& category : itemButtons) {

		// Make Category Buttons
		TextButton* buttonTemp = new TextButton;
		
		buttonTemp->Make(4, y++, GetCategoriyName(category.first));
		buttonTemp->SetCallBack([&]() {

			for (auto& targetItemButton : itemButtons[category.first]) {
				targetItemButton->Render = true;
			}

			nowSelectedCategory = category.first;

			dynamic_cast<TextButton*>(Selecting)->SetSelectedForegroundColor(Color::DefaultForegroundColor);
			Selecting->Select();

			Selecting = itemButtons[category.first][0];
			Selecting->Select();

			NeedUpdate = true;
		});

		categoryButtons.push_back(buttonTemp);
		AddObject(buttonTemp);

		// Link Buttons
		for (auto& categoryButtons : itemButtons) {
			
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

	nowPage = new ItemWikiPage;
	AddObject(nowPage);

	Selecting = categoryButtons[0];

	NeedUpdate = true;
}


void ItemWiki::Update() {

}

void ItemWiki::rerender() {

}
