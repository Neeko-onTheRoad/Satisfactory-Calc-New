#include "ConsoleWindow.Hxx"

void ConsoleWindow::RerenderBottomBar() {

	for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
		bottomBar[0][x] = ASCII_HZ_BAR;
		bottomBarForegroundColor[0][x] = Color::HilightedForegroundColor;
		bottomBarForegroundColor[3][x] = Color::HilightedForegroundColor;
	}
}