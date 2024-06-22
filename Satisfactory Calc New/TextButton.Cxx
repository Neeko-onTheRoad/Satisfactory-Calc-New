#include "TextButton.Hxx"

void TextButton::Initialize() {}
void TextButton::Update(ISelectable*& _selecting) {
	if (_selecting == this) {

		// CallBack Logic
		if (KeyManager::GetKeyPressed(Keys::SELECT)) {
			CallBack();
			NeedUpdate = true;

			return;
		}

		if (KeyManager::GetKeyPressed(Keys::BACK)) {
			BackCallBack();
			NeedUpdate = true;

			return;
		}

	}
}

void TextButton::rebuildKeyGuides() {
	keyGuides.clear();

	// Initialize Default Key Guides
	keyGuides.push_back({ Keys::SELECT, "Select" });
	if (upper) keyGuides.push_back({ Keys::UP,    "Go Up"    });
	if (lower) keyGuides.push_back({ Keys::DOWN,  "Go Down"  });
	if (left)  keyGuides.push_back({ Keys::LEFT,  "Go Left"  });
	if (right) keyGuides.push_back({ Keys::RIGHT, "Go Right" });
}

void TextButton::Make(int _posX, int _posY, const std::string& _element, bool _bar) {

	// Delete All Element
	Delete2DimDynamicArray(Object, sizeY);
	Delete2DimDynamicArray(ForegroundColor, sizeY);
	Delete2DimDynamicArray(BackgroundColor, sizeY);

	bar       = _bar;
	positionX = _posX;
	positionY = _posY;

	stringElement = _element;

	// Calculate object width by size of lement
	// Add 4 because button's element will be " - Element "
	// Add 2 if Bar is not enabled. element will be " Element "
	sizeX = static_cast<unsigned>(_element.size()) + (bar ? 4u : 2u);
	sizeY = 1;

	// Initialize Render Buffer
	Object          = Make2DimDynamicArray(1, sizeX, ' ');
	ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);


	// Draw Element in Render Buffer, Same with Upper, offset will be 3
	for (unsigned x = 0u; x < _element.size(); x++) {
		Object[0][x + (bar ? 3u : 1u)] = _element[x];
	}

	// Draw front bar if Need
	if (bar) {
		Object[0][1] = '-';
		ForegroundColor[0][1] = Color::HilightedForegroundColor;
	}

	UnSelect();
	rebuildKeyGuides();
	NeedUpdate = true;

}

void TextButton::SetForegroundColor(ColorCode _color) {
	foregroundColor = _color;
	NeedUpdate = true;
}

void TextButton::SetBackgroundColor(ColorCode _color) {
	backgroundColor = _color;
	NeedUpdate = true;
}

void TextButton::SetSelectedForegroundColor(ColorCode _color) {
	selectedForegroundColor = _color;
	NeedUpdate = true;
}

void TextButton::SetSelectedBackgroundColor(ColorCode _color) {
	selectedBackgroundColor = _color;
	NeedUpdate = true;
}

void TextButton::Select() {

	// Change Bar
	if (bar) Object[0][1] = '>';

	// Recolor element
	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = selectedForegroundColor;
		BackgroundColor[0][x] = selectedBackgroundColor;
	}

}

void TextButton::UnSelect() {

	// Change Bar
	if (bar) Object[0][1] = '-';

	// Recolor element
	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = foregroundColor;
		BackgroundColor[0][x] = backgroundColor;
	}

	if (bar) ForegroundColor[0][1] = selectedForegroundColor;

}

KeyGuides TextButton::GetKeyGuides() const {
	
	// Add Original Key Guides and Additional Key Guide and return
	KeyGuides result;

	for (const auto& keyGuide : keyGuides) {
		result.push_back(keyGuide);
	}

	for (const auto& keyGuide : AdditionalKeyGuides) {
		result.push_back(keyGuide);
	}

	return result;
}

ISelectable* TextButton::GetUpper() const {
	return upper;
}

ISelectable* TextButton::GetLower() const {
	return lower;
}

ISelectable* TextButton::GetLeft() const {
	return left;
}

ISelectable* TextButton::GetRight() const {
	return right;
}

void TextButton::LinkUpper(ISelectable* _upper) {
	upper = _upper;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkLower(ISelectable* _lower) {
	lower = _lower;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkLeft(ISelectable* _left) {
	left = _left;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkRight(ISelectable* _right) {
	right = _right;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::SetPositionX(int _x) {
	positionX = _x;
	NeedUpdate = true;
}

void TextButton::SetPositionY(int _y) {
	positionY = _y;
	NeedUpdate = true;
}

unsigned TextButton::GetSizeX() const {
	return sizeX;
}

unsigned TextButton::GetSizeY() const {
	return sizeY;
}

int TextButton::GetPositionX() const {
	return positionX;
}

int TextButton::GetPositionY() const {
	return positionY;
}