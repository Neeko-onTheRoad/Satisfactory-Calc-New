#include "ConsoleObject.Hxx"


void ConsoleObject::InitializeBase() {
	this->Object          = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), '\0'));
	this->ForeGroundColor = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), Color::DefaultForegroundColor));
	this->BackGroundColor = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), Color::DefaultBackgroundColor));

	Initialize();
}

void ConsoleObject::UpdateBaes() {
	Update();
}

void ConsoleObject::SetSize(unsigned x, unsigned y) {
	SetSizeX(x);
	SetSizeY(y);
}

void ConsoleObject::SetPosition(unsigned x, unsigned y) {
	SetPositionX(x);
	SetPositionY(y);
}
