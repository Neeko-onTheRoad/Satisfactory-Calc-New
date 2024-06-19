#include "ConsoleWindow.Hxx"

void ConsoleWindow::RenderDefault() {

	// Clear Title bar
	for (unsigned y = 0u; y < TITLE_BAR_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = ' ';
			titleBarBackgroundColor[y][x] = Color::HilightedBackgroundColor;
			titleBarForegroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	// Clear Main Screen
	for (unsigned y = TITLE_BAR_HEIGHT; y < BOTTOM_BAR_OFFSET; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = ' ';
			backgroundColor[y][x] = Color::DefaultBackgroundColor;
			foregroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	// Clear Bottom Bar
	for (unsigned y = 0u; y < BOTTOM_BAR_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			bottomBar[y][x] = ' ';
			bottomBarBackgroundColor[y][x] = Color::HilightedBackgroundColor;
			bottomBarForegroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}
}



void ConsoleWindow::Rerender() {

	RenderDefault();


	RerenderTitleBar();
	RerenderBottomBar();
	nowScene->Rerender();
	
	// Write Title Bar's element in Output Buffer
	for (unsigned y = 0u; y < TITLE_BAR_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = titleBar[y][x];
			backgroundColor[y][x] = titleBarBackgroundColor[y][x];
			foregroundColor[y][x] = titleBarForegroundColor[y][x];
		}
	}

	// Write Main Screen's element in Output Buffer
	for (unsigned y = TITLE_BAR_HEIGHT; y < BOTTOM_BAR_OFFSET; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x]    = nowScene->SceneRenderBuffer   [y - TITLE_BAR_HEIGHT][x];
			backgroundColor[y][x] = nowScene->SceneBackgroundColor[y - TITLE_BAR_HEIGHT][x];
			foregroundColor[y][x] = nowScene->SceneForegroundColor[y - TITLE_BAR_HEIGHT][x];
		}
	}

	// Write Bottom Bar's element in Output Buffer
	for (unsigned y = 0u; y < BOTTOM_BAR_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y + BOTTOM_BAR_OFFSET][x] = bottomBar[y][x];
			backgroundColor[y + BOTTOM_BAR_OFFSET][x] = bottomBarBackgroundColor[y][x];
			foregroundColor[y + BOTTOM_BAR_OFFSET][x] = bottomBarForegroundColor[y][x];
		}
	}

}



void ConsoleWindow::Display() {

	// Set Cursor Position to 0, 0 and make Output be Covered Over
	ConsoleManager::ResetCursor();
	displayBuffer.clear();

	// Put Final Results in Display Buffer
	for (unsigned y = 0u; y < CONSOLE_HEIGHT; y++) {
		for (unsigned x = 0u; x < CONSOLE_WIDTH - 1u; x++) {
			displayBuffer += Color::Foreground(foregroundColor[y][x]);
			displayBuffer += Color::Background(backgroundColor[y][x]);
			displayBuffer += renderBuffer[y][x] == '\0' ? ' ' : renderBuffer[y][x];
		}
		displayBuffer += Color::Background(Color::NoColor);
		displayBuffer += "\r\n";
	}

	// print Rendered Elements and Clear Buffer
	std::cout << displayBuffer.substr(0, displayBuffer.size() - 1);

}