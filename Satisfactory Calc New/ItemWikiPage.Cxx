#include "ItemWikiPage.Hxx"

ItemWikiPage::ItemWikiPage() {
	Render = false;
	Before = nullptr;

	Object = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, ' ');
	ForegroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::HilightedBackgroundColor);
}

ItemWikiPage::~ItemWikiPage() {
	Delete2DimDynamicArray(Object, SCENE_HEIGHT);
	Delete2DimDynamicArray(ForegroundColor, SCENE_HEIGHT);
	Delete2DimDynamicArray(BackgroundColor, SCENE_HEIGHT);
}

void ItemWikiPage::Initialize() {

}

void ItemWikiPage::Update(ISelectable*& _selecting) {

	if (_selecting == this) {
		if (KeyManager::GetKeyPressed(Keys::BACK)) {
			UnSelect();
			_selecting  = Before;

			Render = false;
			NeedUpdate = true;

			return;
		}
	}

}

void ItemWikiPage::Make(const Item* item, ISelectable* _before) {
	
	Before = _before;

}

unsigned ItemWikiPage::GetSizeX() const {
	return CONSOLE_WIDTH;
}

unsigned ItemWikiPage::GetSizeY() const {
	return SCENE_HEIGHT;
}

int ItemWikiPage::GetPositionX() const {
	return 0;
}

int ItemWikiPage::GetPositionY() const {
	return 0;
}

KeyGuides ItemWikiPage::GetKeyGuides() const {
	return KeyGuides();
}

void ItemWikiPage::Select() {
	Render = true;
	NeedUpdate = true;
}

void ItemWikiPage::UnSelect() {
	Render = false;	
	NeedUpdate = true;
}
