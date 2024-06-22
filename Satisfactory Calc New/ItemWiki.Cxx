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
	for (auto& item : Satisfactory::ItemList) {

		TextButton* buttonTemp = new TextButton;
		
		buttonTemp->Make(CONSOLE_WIDTH / 2 - 6, y++, item->Name);
		buttonTemp->Render = false;  
		buttonTemp->AdditionalKeyGuides.push_back({ Keys::BACK, "Category Select"});
		buttonTemp->SetBackCallBack([&]() {

			for (auto& itemButtons : itemButtons[nowSelectedCategory]) {
				itemButtons->Render = false;
			}

			Selecting->UnSelect();
			Selecting = categoryButtons[0];
			categoryButtons[0]->SetSelectedForegroundColor(Color::HilightedForegroundColor);
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
		for (auto& itemButton : itemButtons) {
			
			for (int i = 0; i < itemButton.second.size(); i++) {
				if (i == 0) {
					itemButton.second[i]->LinkUpper(itemButton.second[itemButton.second.size() - 1]);
					itemButton.second[i]->LinkLower(itemButton.second[i + 1]);
				}
				else if (i == itemButton.second.size() - 1) {
					itemButton.second[i]->LinkUpper(itemButton.second[i - 1]);
					itemButton.second[i]->LinkLower(itemButton.second[0]);
				}
				else {
					itemButton.second[i]->LinkUpper(itemButton.second[i - 1]);
					itemButton.second[i]->LinkLower(itemButton.second[i + 1]);
				}
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
