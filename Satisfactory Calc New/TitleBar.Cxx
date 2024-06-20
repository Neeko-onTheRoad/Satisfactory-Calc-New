#include "ConsoleWindow.Hxx"

void ConsoleWindow::RerenderTitleBar() {

	// Render Color and Lines of Title Bar
	for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
		titleBar[0][x] = Ascii::HZ_BAR;
		titleBar[2][x] = Ascii::HZ_BAR;
		titleBarForegroundColor[0][x] = Color::HilightedForegroundColor;
		titleBarForegroundColor[2][x] = Color::HilightedForegroundColor;
	}

	std::string sceneStatusBar = "  ";
	size_t selectingStart = 0u;
	size_t selectingEnd = 0u;

	sceneStatusBar += Ascii::VT_BAR;

	// Write Scenes' names in Buffer
	for (unsigned index = 0u; index < scenes.size(); index++) {

		// Hilight if Scene is selected
		if (index == nowSceneIndex) {
			selectingStart = sceneStatusBar.size();
			sceneStatusBar += "  " + scenes[index]->GetTitle() + "  ";
			selectingEnd = sceneStatusBar.size() - 1;
			sceneStatusBar += Ascii::VT_BAR;
		}

		// Else just write
		else {
			sceneStatusBar += "  " + scenes[index]->GetTitle() + "  " + Ascii::VT_BAR;
		}
	}

	// Put Buffer's element in RenderBuffer
	for (int index = 0u; index < sceneStatusBar.size(); index++) {
		titleBar[1][index] = sceneStatusBar[index];

		if (selectingStart <= index && index <= selectingEnd) {
			titleBarForegroundColor[1][index] = Color::HilightedBackgroundColor;
			titleBarBackgroundColor[1][index] = Color::DefaultForegroundColor;
		}
	}
}