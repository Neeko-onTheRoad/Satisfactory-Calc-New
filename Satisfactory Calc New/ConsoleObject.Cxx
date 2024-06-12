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