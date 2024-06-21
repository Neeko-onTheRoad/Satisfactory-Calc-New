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
	TextBoxObject* orderBy = new TextBoxObject;
	orderBy->Make(3, 1, " Item Ordered By: \n");

	AddObject(orderBy);

	// Draw Order type Selection Button
	SelectBox<ItemSortOption>* orderByOptions = new SelectBox<ItemSortOption>;
	{
		std::vector<std::pair<ItemSortOption, std::string>> orderByOptionsElements;
		orderByOptionsElements.emplace_back(ItemSortOption::Category, "Category");
		orderByOptionsElements.emplace_back(ItemSortOption::NameA2Z, "Name (A~Z)");
		orderByOptionsElements.emplace_back(ItemSortOption::NameZ2A, "Name (Z~A)");

		orderByOptions->Make(orderBy->GetPositionX() + orderBy->GetSizeX(), 1, orderByOptionsElements);
	}

	AddObject(orderByOptions);

	Selecting = orderByOptions;
}




void ItemWiki::Update() {
	
}

void ItemWiki::drawInBuffer() {
	


}
