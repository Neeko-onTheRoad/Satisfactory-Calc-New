#include <iostream>
#include "ConsoleWindow.Hxx"

void ConsoleWindow::Rerender() {

	nowScene->Rerender();

	for (unsigned y = 0; y < TITLE_BAR_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer[y][x] = titleBar[y][x];
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
		}
	}
	
}

void ConsoleWindow::Display() {
	
	ConsoleManager::Clear();

	displayBuffer.clear();
	for (unsigned y = 0; y < CONSOLE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH - 1; x++) {
			displayBuffer += renderBuffer[y][x];
		}
		displayBuffer += "\n";
	}

	std::cout << displayBuffer.substr(0, displayBuffer.size() - 1);

}

void ConsoleWindow::ChangeScene(ConsoleScene* scene) {
	nowScene = scene;
	nowScene->InitializeBase();
}

void ConsoleWindow::Initialize(ConsoleScene* startScene) {

	std::ios_base::sync_with_stdio(0);
	std::cin .tie(0); 
	std::cout.tie(0);

	ConsoleManager::UseANSIEscapeCode();
	ConsoleManager::SetFont("Consolas", 24);
	ConsoleManager::SetSize(1280, 790);
	ConsoleManager::DisableResize();
	ConsoleManager::DisableUserSelection();
	ConsoleManager::DisableScrollBar();
	ConsoleManager::SetCursorBlinking(false);
	ConsoleManager::SetTitle("Satisfactory Calculator V 0.01");
	ConsoleManager::SetCloseButton(false);
	ConsoleManager::SetMinimizeButton(false);

	for (unsigned y = 0; y < 3; y += 2) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			titleBar[y][x] = '=';
		}
	}

	for (unsigned y = 0; y < CONSOLE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer   [y][x] = ' ';
			backgroundColor[y][x] = Color::DefaultBackgroundColor;
			foregroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	for (unsigned y = 0; y < 4; y += 3) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			bottomBar[y][x] = '=';
		}
	}

	ChangeScene(startScene);
}

void ConsoleWindow::Run() {

	while (true) {
		nowScene->UpdateBase();
		
		if (nowScene->NeedUpdate) {
			Rerender();
			Display();
			nowScene->NeedUpdate = false;
		}
	}
}
