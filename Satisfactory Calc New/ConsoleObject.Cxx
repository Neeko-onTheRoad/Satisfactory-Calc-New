#include "ConsoleObject.Hxx"

char**    Object;
__int16** ForeGroundColor;
__int16** BackGroundColor;

void ConsoleObject::InitializeBase() {
	this->Object          = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), '\0'));
	this->ForeGroundColor = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), Color::DefaultForegroundColor));
	this->BackGroundColor = MakeDynamicArray(GetSizeY(), MakeDynamicArray(GetSizeX(), Color::DefaultBackgroundColor));

	Initialize();
	Rerender();
}

void ConsoleObject::UpdateBaes() {
	Update();
}
