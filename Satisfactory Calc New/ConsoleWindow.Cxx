#include <iostream>
#include "ConsoleWindow.Hxx"

void ConsoleWindow::Rerender() {
	for (auto& layer : nowScene->Objects) {
		for (auto& object : layer.second) {

			for (int y = 0; y < object->GetSizeY(); y++) {
				for (int x = 0; x < object->GetSizeX(); x++) {
					
					int renderY = y + object->GetPositionY();
					int renderX = x + object->GetPositionX();

					if (
						renderY >= 0 &&
						renderX >= 0 &&
						renderY < MAX_CONSOLE_HEIGHT &&
						renderX < MAX_CONSOLE_WIDTH
					) {
						int renderPositionY = renderY + object->GetPositionY();
						int renderPositionX = renderX + object->GetPositionX();

						renderBuffer[renderPositionY][renderPositionX] = object->Object[renderY][renderX];
					}

				}
			}
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

	for (int y = 0; y < TITLE_BAR_HEIGHT; y++) {
		for (int x = 0; x < MAX_CONSOLE_WIDTH; x++) {
			titleBar[y][x] = ' ';
		}
	}

	for (int y = 0; y < BOTTOM_BAR_HEIGHT; y++) {
		for (int x = 0; x < MAX_CONSOLE_WIDTH; x++) {
			bottomBar[y][x] = ' ';
		}
	}

	for (int y = 0; y < MAX_CONSOLE_HEIGHT; y++) {
		for (int x = 0; x < MAX_CONSOLE_WIDTH; x++) {
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
