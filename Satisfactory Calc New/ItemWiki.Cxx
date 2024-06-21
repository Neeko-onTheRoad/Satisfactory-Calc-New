#include "ItemWiki.Hxx"

std::string to_string(ItemSortOption _orderBy) {
	switch (_orderBy) {
		case ItemSortOption::Category: return "Category";
		case ItemSortOption::NameA2Z:  return "Name (A ~ Z)";
		case ItemSortOption::NameZ2A:  return "Name (Z ~ A)";
	}
}

std::string ItemWiki::GetTitle() const {
	return "Item Wiki";
}

void ItemWiki::Initialize() {

	// Push Elements in List
	for (auto& item : Satisfactory::ItemList) {
		ItemSortedByCategory[item->Category].push_back(item);
		ItemSortedByNameA2Z [item->Name[0]] .push_back(item);
		ItemSortedByNameZ2A [item->Name[0]] .push_back(item);
	}

	// Dictionary Order Every Elements in A2Z-Sorted Map
	for (auto& A2Z : ItemSortedByNameA2Z) {
		std::sort(A2Z.second.begin(), A2Z.second.end());
	}

	// Dictionary Order Eveny Elements in Z2A-Sorted Map
	for (auto& Z2A : ItemSortedByNameZ2A) {
		std::sort(Z2A.second.rbegin(), Z2A.second.rend());
	}


	// Draw Order type Button
	{
		TextBoxObject* OrderBy = new TextBoxObject;
		OrderBy->Make(3, 1, " Item Ordered By: \n");
		OrderBy->SetForegroundColor(Color::HilightedForegroundColor);
		OrderBy->SetBackgroundColor(Color::HilightedBackgroundColor);

		AddObject(OrderBy);

	}

	SelectBox<int>* sb1 = new SelectBox<int>;
	std::vector<std::pair<int, std::string>> sb1ls;
	sb1ls.emplace_back(1, "Tst1One");
	sb1ls.emplace_back(2, "Tst1Twofewfewa");
	sb1ls.emplace_back(2, "Tst1Twofewffewaewa");
	sb1ls.emplace_back(2, "Tst1Twofeffwfewa");
	sb1ls.emplace_back(2, "Tst1Twofewfewa");

	sb1->Make(4, 3, sb1ls);


	SelectBox<int>* sb2 = new SelectBox<int>;
	std::vector<std::pair<int, std::string>> sb2ls;
	sb2ls.emplace_back(1, "Tst2One");
	sb2ls.emplace_back(2, "Tst2Twofeeafw");

	sb2->Make(4, 4, sb2ls);
	sb2->LinkUpper(sb1);
	sb2->LinkLower(sb1);
	sb1->LinkUpper(sb2);
	sb1->LinkLower(sb2);

	AddObject(sb1);
	AddObject(sb2);

	for (auto& i : sb1->Options) {
		AddObject(i, 1);
	}
	for (auto& i : sb2->Options) {
		AddObject(i, 1);
	}

	Selecting = sb1;
}

void ItemWiki::Update() {

}

void ItemWiki::drawInBuffer() {
	


}
