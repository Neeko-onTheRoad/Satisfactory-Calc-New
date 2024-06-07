#include <iostream>
#include "ConsoleWindow.Hxx"

void ConsoleWindow::Rerender() {

	nowScene->Rerender();

	for (unsigned y = 0; y < SCENE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {

			renderBuffer[y + TITLE_BAR_HEIGHT][x] = nowScene->SceneRenderBuffer[y][x];

		}
	}


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

	for (unsigned y = 0; y < CONSOLE_HEIGHT; y++) {
		for (unsigned x = 0; x < CONSOLE_WIDTH; x++) {
			renderBuffer   [y][x] = ' ';
			backgroundColor[y][x] = Color::DefaultBackgroundColor;
			foregroundColor[y][x] = Color::DefaultForegroundColor;
		}
	}

	ChangeScene(startScene);
}

void ConsoleWindow::Run() {

	while (true) {
		nowScene->UpdateBase();
		
		if (nowScene->NeedUpdate) {
			Rerender();
			nowScene->NeedUpdate = false;
		}
	}
}
