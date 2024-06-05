#include "Color.Hxx"

std::string Color::Foreground(__int8 color) {
	return "\x1b[38;5;" + std::to_string(color) + "m";
}

std::string Color::Background(__int8 color) {
	return "\x1b[48;5;" + std::to_string(color) + "m";
}