#include "TextBoxObject.Hxx"	
#include <iostream>

void TextBoxObject::Initialize() { }
void TextBoxObject::Update() { }

void TextBoxObject::Make(int _posX, int _posY, std::string _element, int _bottomMargin) {
	
	positionX = _posX;
	positionY = _posY;


	std::vector<std::string> splited;
	std::string token = "";


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

	sizeY = static_cast<int>(splited.size()) + _bottomMargin;

	Object          = Make2DimDynamicArray(sizeY, sizeX, ' ');
	ForegroundColor = Make2DimDynamicArray(sizeY, sizeX, Color::DefaultForegroundColor);
	BackgroundColor = Make2DimDynamicArray(sizeY, sizeX, Color::DefaultBackgroundColor);

	for (unsigned y = 0; y < splited.size(); y++) {
		for (unsigned x = 0; x < splited[y].size(); x++) {
			Object[y][x] = splited[y][x];
		}
	}

	NeedUpdate = true;

}