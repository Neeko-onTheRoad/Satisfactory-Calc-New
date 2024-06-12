#include "ConsoleWindow.Hxx"

void ConsoleWindow::RenderDefault() {

	for (unsigned y = 0; y < TITLE_BAR_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = ' ';
			titleBarBackgroundColor[y][x] = Color::HilightedBackgroundColor;
			titleBarForegroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	for (unsigned y = TITLE_BAR_HEIGHT; y < BOTTOM_BAR_OFFSET; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = ' ';
			backgroundColor[y][x] = Color::DefaultBackgroundColor;
			foregroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	for (unsigned y = 0; y < BOTTOM_BAR_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
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


	for (unsigned y = 0; y < TITLE_BAR_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = titleBar[y][x];
			backgroundColor[y][x] = titleBarBackgroundColor[y][x];
			foregroundColor[y][x] = titleBarForegroundColor[y][x];
		}
	}


	for (unsigned y = 0; y < SCENE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y + TITLE_BAR_HEIGHT][x] = nowScene->SceneRenderBuffer[y][x];
		}
	}

	for (unsigned y = 0; y < BOTTOM_BAR_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y + BOTTOM_BAR_OFFSET][x] = bottomBar[y][x];
			backgroundColor[y + BOTTOM_BAR_OFFSET][x] = bottomBarBackgroundColor[y][x];
			foregroundColor[y + BOTTOM_BAR_OFFSET][x] = bottomBarForegroundColor[y][x];
		}
	}

}

void ConsoleWindow::Display() {

	ConsoleManager::ResetCursor();

	displayBuffer.clear();
	for (unsigned y = 0; y < CONSOLE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH - 1; x++) {
			displayBuffer += Color::Foreground(foregroundColor[y][x]);
			displayBuffer += Color::Background(backgroundColor[y][x]);
			displayBuffer += renderBuffer[y][x] == '\0' ? ' ' : renderBuffer[y][x];
		}
		displayBuffer += Color::Background(Color::FullBlack);
		displayBuffer += "\r\n";
	}

	std::cout << displayBuffer.substr(0, displayBuffer.size() - 1);

}