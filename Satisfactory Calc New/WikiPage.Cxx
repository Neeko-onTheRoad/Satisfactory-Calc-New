#include "WikiPage.Hxx"

WikiPage::WikiPage() {
	Render = false;
	Before = nullptr;

	Object = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, ' ');
	ForegroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(SCENE_HEIGHT, CONSOLE_WIDTH, Color::DefaultBackgroundColor);
}

WikiPage::~WikiPage() {
	Delete2DimDynamicArray(Object, SCENE_HEIGHT);
	Delete2DimDynamicArray(ForegroundColor, SCENE_HEIGHT);
	Delete2DimDynamicArray(BackgroundColor, SCENE_HEIGHT);
}

void WikiPage::Initialize() {
	
}

void WikiPage::Update(ISelectable*& _selecting) {

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

void WikiPage::Make(const Item* item, ISelectable* _before) {
	
	Before = _before;

}

unsigned WikiPage::GetSizeX() const {
	return CONSOLE_WIDTH;
}

unsigned WikiPage::GetSizeY() const {
	return SCENE_HEIGHT;
}

int WikiPage::GetPositionX() const {
	return 0;
}

int WikiPage::GetPositionY() const {
	return 0;
}

KeyGuides WikiPage::GetKeyGuides() const {

}

void WikiPage::Select() {
	Render = true;
	NeedUpdate = true;
}

void WikiPage::UnSelect() {
	Render = false;	
	NeedUpdate = true;
}
