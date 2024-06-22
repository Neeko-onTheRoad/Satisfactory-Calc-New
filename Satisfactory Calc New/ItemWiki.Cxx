#include "ItemWiki.Hxx"
#include "ItemWikiPage.Hxx"

std::string ItemWiki::GetTitle() const {
	return "Item Wiki";
}


void ItemWiki::Initialize() {

	// MakeCategoryLine



	// Make Item Buttons
	int y = 3;
	for (auto& item : Satisfactory::ItemList) {

		TextButton* buttonTemp = new TextButton;
		
		buttonTemp->Make(4, y++, item->Name);
		buttonTemp->Render = false;  
		buttonTemp->AdditionalKeyGuides.push_back({ Keys::BACK, "Category Select"});
		buttonTemp->SetBackCallBack([&]() {
			
			for (auto& nowItemButtons : itemButtons[nowScelectedCategory]) {
				nowItemButtons->Render = false;
			}

			for (auto& categoryButton : categoryButtons) {
				categoryButton->Render = true;
			}

			Selecting->UnSelect();
			Selecting = categoryButtons[0];
			Selecting->Select();

			NeedUpdate = true;

		});
		buttonTemp->SetCallBack([&]() {
			nowPage->Render = true;
			nowPage->Make(item, buttonTemp);

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

			for (auto& categoryButton : categoryButtons) {
				categoryButton->Render = false;
			}

			for (auto& targetItemButton : itemButtons[category.first]) {
				targetItemButton->Render = true;
			}

			nowScelectedCategory = category.first;

			Selecting->UnSelect();
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

void ItemWiki::drawInBuffer() {



	NeedUpdate = true;
}
