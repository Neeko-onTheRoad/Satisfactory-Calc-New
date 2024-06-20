#include "Color.Hxx"

// Return Foreground ANSI Escape code
std::string Color::Foreground(ColorCode color) {
	return "\x1b[38;5;" + std::to_string(color) + "m";
}

// Return Background ANSI Escpae code
std::string Color::Background(ColorCode color) {
	return "\x1b[48;5;" + std::to_string(color) + "m";
}