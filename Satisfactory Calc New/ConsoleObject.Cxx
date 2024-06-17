#include "ConsoleObject.Hxx"


void ConsoleObject::InitializeBase() {
	Initialize();
}

void ConsoleObject::UpdateBaes() {
	Update(); 
}

void ConsoleObject::SetForegroundColor(ColorCode _color) {
	for (unsigned y = 0u; y < GetSizeY(); y++) {
		for (unsigned x = 0u; x < GetSizeX(); x++) {
			ForegroundColor[y][x] = _color;
		}
	}
}

void ConsoleObject::SetBackgroundColor(ColorCode _color) {
	for (unsigned y = 0u; y < GetSizeY(); y++) {
		for (unsigned x = 0u; x < GetSizeX(); x++) {
			BackgroundColor[y][x] = _color;
		}
	}
}

void ConsoleObject::SetForegroundColor(ColorCode _color, unsigned _x, unsigned _y) {

	if (_x >= GetSizeX() || _y >= GetSizeY()) {
		std::cerr << "ConsoleObject::SetForegroundColor()" << std::endl
		          << "Max Size is " << GetSizeX() << " " << GetSizeY()
				  << ", But you changed " << _x << " " << _y;

		throw std::out_of_range("ConsoleObject::SetForegroundColor()");
	}

	ForegroundColor[_y][_x] = _color;

}

void ConsoleObject::SetBackgroundColor(ColorCode _color, unsigned _x, unsigned _y) {
	if (_x >= GetSizeX() || _y >= GetSizeY()) {
		std::cerr << "ConsoleObject::SetBackroundColor()" << std::endl
		          << "Max Size is " << GetSizeX() << " " << GetSizeY()
				  << ", But you changed " << _x << " " << _y << std::endl;

		throw std::out_of_range("ConsoleObject::SetBackroundColor()");
	}

	BackgroundColor[_y][_x] = _color;
}
