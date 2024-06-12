#include "TextBoxObject.Hxx"

void TextBoxObject::Initialize() {
}

void TextBoxObject::Update() {
}

void TextBoxObject::SetPositionX(unsigned _x) {
	positionX = _x;
}

void TextBoxObject::SetPositionY(unsigned _y) {
	positionY = _y;
}

void TextBoxObject::Make(int _posX, int _posY, std::string _element) {
	
	positionX = _posX;
	positionY = _posY;


	std::vector<std::string> splited;
	std::string token = "";

	while (_element.back() != '\n') _element.pop_back();

	for (auto& ch : _element) {
		if (ch == '\n') {
			if (static_cast<int>(token.size()) > sizeX) sizeX = static_cast<int>(token.size());

			splited.push_back(token);
			token.clear();
		}

		else {
			token += ch;
		}
	}

	sizeY = static_cast<int>(splited.size());

	Object = MakeDynamicArray(sizeY, MakeDynamicArray(sizeX, ' '));

	for (unsigned y = 0; y < splited.size(); y++) {
		
		for (unsigned x = 0; x < splited[y].size(); x++) {
			Object[y][x] = splited[y][x];
		}

	}

}

unsigned TextBoxObject::GetSizeX() const {
	return sizeX;
}

unsigned TextBoxObject::GetSizeY() const {
	return sizeY;
}

unsigned TextBoxObject::GetPositionX() const {
	return positionX;
}

unsigned TextBoxObject::GetPositionY() const {
	return positionY;
}