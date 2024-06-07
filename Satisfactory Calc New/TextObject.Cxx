#include "TextObject.Hxx"

TextObject::TextObject(unsigned posX, unsigned posY, unsigned sizeX, unsigned sizeY) {
	positionX = posX;
	positionY = posY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;

	Initialize();
}

void TextObject::Initialize() {
}

void TextObject::Update() {
}


unsigned TextObject::GetSizeX() const {
	return sizeX;
}

unsigned TextObject::GetSizeY() const {
	return sizeY;
}

unsigned TextObject::GetPositionX() const {
	return positionX;
}

unsigned TextObject::GetPositionY() const {
	return positionY;
}
