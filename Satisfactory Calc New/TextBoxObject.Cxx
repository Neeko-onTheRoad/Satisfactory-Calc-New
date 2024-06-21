#include "TextBoxObject.Hxx"

void TextBoxObject::Initialize() {}
void TextBoxObject::Update(ISelectable*& _selecting) {
	
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

void TextBoxObject::rebuildKeyGuides() {
	keyGuides.clear();

	// Initialize Default key Guides
	           keyGuides.push_back({ "Enter",       "Select"   });
	if (upper) keyGuides.push_back({ "Arrow Up",    "Go Up"    });
	if (lower) keyGuides.push_back({ "Arrow Down",  "Go Down"  });
	if (left ) keyGuides.push_back({ "Arrow Left",  "Go Left"  });
	if (right) keyGuides.push_back({ "Arrow Right", "Go Right" });
}

void TextBoxObject::Make(int _posX, int _posY, std::string _element, int _bottomMargin) {
	
	// Delete All Element
	Delete2DimDynamicArray(Object, sizeY);
	Delete2DimDynamicArray(ForegroundColor, sizeY);
	Delete2DimDynamicArray(BackgroundColor, sizeY);

	positionX = _posX;
	positionY = _posY;

	std::vector<std::string> splited;
	std::string token = "";
	
	// Split String by '\n' to vector
	for (const auto& ch : _element) {
		if (ch == '\n') {
			if (static_cast<int>(token.size()) > sizeX) sizeX = static_cast<int>(token.size());

			splited.push_back(token);
			token.clear();
		}

		else {
			token += ch;
		}
	}

	// Calcualte total Height with size of vector and _bottomMargin
	sizeY = static_cast<int>(splited.size()) + _bottomMargin;

	// Initialize Redner Buffer
	Object          = Make2DimDynamicArray(sizeY, sizeX, ' ');
	ForegroundColor = Make2DimDynamicArray(sizeY, sizeX, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(sizeY, sizeX, Color::DefaultBackgroundColor);

	// Draw Initialized string in Render Buffer
	for (unsigned y = 0u; y < splited.size(); y++) {
		for (unsigned x = 0u; x < splited[y].size(); x++) {
			Object[y][x] = splited[y][x];
		}
	}

	NeedUpdate = true;

}

void TextBoxObject::Select() {}
void TextBoxObject::UnSelect() {}

KeyGuides TextBoxObject::GetKeyGuides() const {

	// Add Original Key Guide and Additional Key Guide and return
	KeyGuides result;

	for (const auto& keyGuide : keyGuides) {
		result.push_back(keyGuide);
	}

	for (const auto& keyGuide : AdditionalKeyGuides) {
		result.push_back(keyGuide);
	}

	return result;
}

ISelectable* TextBoxObject::GetUpper() const {
	return upper;
}

ISelectable* TextBoxObject::GetLower() const {
	return lower;
}

ISelectable* TextBoxObject::GetLeft() const {
	return left;
}

ISelectable* TextBoxObject::GetRight() const {
	return right;
}

void TextBoxObject::LinkUpper(ISelectable* _upper) {
	upper = _upper;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextBoxObject::LinkLower(ISelectable* _lower) {
	lower = _lower;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextBoxObject::LinkLeft(ISelectable* _left) {
	left = _left;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextBoxObject::LinkRight(ISelectable* _right) {
	right = _right;
	rebuildKeyGuides();
	NeedUpdate = true;
}

void TextBoxObject::SetPositionX(int _x) {
	positionX = _x;
	NeedUpdate = true;
}

void TextBoxObject::SetPositionY(int _y) {
	positionY = _y;
	NeedUpdate = true;
}

unsigned TextBoxObject::GetSizeX() const {
	return sizeX;
}

unsigned TextBoxObject::GetSizeY() const {
	return sizeY;
}

int TextBoxObject::GetPositionX() const {
	return positionX;
}

int TextBoxObject::GetPositionY() const {
	return positionY;
}

