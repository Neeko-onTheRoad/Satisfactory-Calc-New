#include "ItemWiki.Hxx"

std::string ItemWiki::GetTitle() const {
	return "Item Wiki";
}

void ItemWiki::Initialize() {

	// Push Elements in A2Z, Z2A-Sorted Map (Not Dictionary-Ordered)
	for (auto& item : Satisfactory::ItemList) {
		ItemSortedByNameA2Z[item->Name[0]].push_back(item);
	}

	// Dictionary Order Every Elements in A2Z-Sorted Map
	for (auto& A2Z : ItemSortedByNameA2Z) {
		std::sort(A2Z.second.begin(), A2Z.second.end());
	}

	// Dictionary Order Eveny Elements in Z2A-Sorted Map
	for (auto& Z2A : ItemSortedByNameZ2A) {
		std::sort(Z2A.second.rbegin(), Z2A.second.rend());
	}

}

void ItemWiki::Update() {

}