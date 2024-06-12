#include "ConsoleWindow.Hxx"

void ConsoleWindow::RerenderTitleBar() {

	for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
		titleBar[0][x] = ASCII_HZ_BAR;
		titleBar[2][x] = ASCII_HZ_BAR;
		titleBarForegroundColor[0][x] = Color::HilightedForegroundColor;
		titleBarForegroundColor[2][x] = Color::HilightedForegroundColor;
	}

	std::string sceneStatusBar = "  ";
	size_t selectingStart = 0u;
	size_t selectingEnd = 0u;

	sceneStatusBar += ASCII_VT_BAR;

	for (unsigned index = 0; index < scenes.size(); index++) {
		if (index == nowSceneIndex) {
			selectingStart = sceneStatusBar.size();
			sceneStatusBar += "  " + scenes[index]->GetTitle() + "  ";
			selectingEnd = sceneStatusBar.size() - 1;
			sceneStatusBar += ASCII_VT_BAR;
		}

		else {
			sceneStatusBar += "  " + scenes[index]->GetTitle() + "  " + ASCII_VT_BAR;
		}
	}

	for (int index = 0; index < sceneStatusBar.size(); index++) {
		titleBar[1][index] = sceneStatusBar[index];

		if (selectingStart <= index && index <= selectingEnd) {
			titleBarForegroundColor[1][index] = Color::HilightedBackgroundColor;
			titleBarBackgroundColor[1][index] = Color::DefaultForegroundColor;
		}
	}
}