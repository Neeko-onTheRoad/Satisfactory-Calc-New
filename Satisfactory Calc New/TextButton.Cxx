#include "TextButton.Hxx"

void TextButton::Initialize() {}
void TextButton::Update() {}

void TextButton::Make(int _posX, int _posY, std::string _element) {

	positionX = _posX;
	positionY = _posY;

	stringElement = _element;

	sizeX = static_cast<unsigned>(_element.size()) + 4u;
	sizeY = 1;

	Object          = Make2DimDynamicArray(1, sizeX, ' ');
	ForegroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(1, sizeX, Color::DefaultBackgroundColor);

	Object[0][1] = '-';

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

void TextButton::Select() {

	Object[0][1] = '>';

	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = Color::HilightedForegroundColor;
		BackgroundColor[0][x] = Color::HilightedBackgroundColor;
	}

}

void TextButton::UnSelect() {

	Object[0][1] = '-';

	for (unsigned x = 0u; x < sizeX; x++) {
		ForegroundColor[0][x] = Color::DefaultForegroundColor;
		BackgroundColor[0][x] = Color::DefaultBackgroundColor;
	}

	ForegroundColor[0][1] = Color::HilightedForegroundColor;

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
}

void TextButton::LinkLower(ISelectable* _lower) {
	lower = _lower;
}

void TextButton::LinkLeft(ISelectable* _left) {
	left = _left;
}

void TextButton::LinkRight(ISelectable* _right) {
	right = _right;
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