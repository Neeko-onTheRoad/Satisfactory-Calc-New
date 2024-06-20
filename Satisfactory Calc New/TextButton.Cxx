#include "TextButton.Hxx"

void TextButton::Initialize() {}
void TextButton::Update() {}

void TextButton::RebuildKeyGuides() {
	keyGuides.clear();

	// Initialize Default Key Guides
	           keyGuides.push_back({ "Enter",       "Select" });
	if (upper) keyGuides.push_back({ "Arrow Up",    "Go Up"    });
	if (lower) keyGuides.push_back({ "Arrow Down",  "Go Down"  });
	if (left)  keyGuides.push_back({ "Arrow Left",  "Go Left"  });
	if (right) keyGuides.push_back({ "Arrow Right", "Go Right" });
}

void TextButton::Make(int _posX, int _posY, std::string _element) {

	positionX = _posX;
	positionY = _posY;

	stringElement = _element;

	// Calculate object width by size of lement
	// Add 4 because button's element will be " - Element "
	sizeX = static_cast<unsigned>(_element.size()) + 4u;
	sizeY = 1;

	// Initialize Render Buffer
	Object          = Make2DimDynamicArray(1, sizeX, ' ');
	ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

	Object[0][1] = '-';

	// Draw Element in Render Buffer, Same with Upper, offset will be 3
	for (unsigned x = 0u; x < _element.size(); x++) {
		Object[0][x + 3] = _element[x];
	}

	ForegroundColor[0][1] = Color::HilightedForegroundColor;

	NeedUpdate = true;

}

void TextButton::SetCallBack(std::function<void()> _func) {
	callBack = _func;
}

void TextButton::CallBack() {
	callBack();
}

void TextButton::SetForegroundColor(ColorCode _color) {
	foregroundColor = _color;
}

void TextButton::SetBackgroundColor(ColorCode _color) {
	backgroundColor = _color;
}

void TextButton::SetSelectedForegroundColor(ColorCode _color) {
	selectedForegroundColor = _color;
}

void TextButton::SetSelectedBackgroundColor(ColorCode _color) {
	selectedBackgroundColor = _color;
}

void TextButton::Select() {

	// Change Bar
	Object[0][1] = '>';

	// Recolor element
	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = selectedForegroundColor;
		BackgroundColor[0][x] = selectedBackgroundColor;
	}

}

void TextButton::UnSelect() {

	// Change Bar
	Object[0][1] = '-';

	// Recolor element
	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = foregroundColor;
		BackgroundColor[0][x] = backgroundColor;
	}

	ForegroundColor[0][1] = selectedForegroundColor;

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
	RebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkLower(ISelectable* _lower) {
	lower = _lower;
	RebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkLeft(ISelectable* _left) {
	left = _left;
	RebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::LinkRight(ISelectable* _right) {
	right = _right;
	RebuildKeyGuides();
	NeedUpdate = true;
}

void TextButton::SetPositionX(int _x) {
	positionX = _x;
}

void TextButton::SetPositionY(int _y) {
	positionY = _y;
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