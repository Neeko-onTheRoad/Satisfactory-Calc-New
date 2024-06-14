#include "ConsoleWindow.Hxx"

void ConsoleWindow::ChangeScene(unsigned index) {
	nowSceneIndex = index;
	nowScene = scenes[index];
	nowScene->InitializeBase();
	nowScene->NeedUpdate = true;
}

void ConsoleWindow::Initialize() {

	Resources::Initialize();

	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	scenes.push_back(new MainScreen);
	scenes.push_back(new Wiki);

	ConsoleManager::SetFont(L"D2Coding", 24);
	ConsoleManager::SetSize(1300, 785);
	ConsoleManager::DisableResize();
	ConsoleManager::DisableUserSelection();
	ConsoleManager::DisableScrollBar();
	ConsoleManager::SetCursorBlinking(false);
	ConsoleManager::SetTitle("Satisfactory Calculator V 0.01");
	ConsoleManager::SetCloseButton(false);
	ConsoleManager::SetMinimizeButton(false);
	ConsoleManager::UseANSIEscapeCode();

	ChangeScene(0);
}

void ConsoleWindow::Run() {

	std::function<void()> mainLoop = [&]() {
		while (true) {

			KeyManager::Update();

			if (KeyManager::GetKeyPressed(Keys::LEFTTAB)) {
				if (nowSceneIndex > 0) {
					ChangeScene(--nowSceneIndex);
				}
				else ChangeScene(static_cast<int>(scenes.size()) - 1);
			}

			else if (KeyManager::GetKeyPressed(Keys::RIGHTTAB)) {
				if (nowSceneIndex < scenes.size() - 1) {
					ChangeScene(++nowSceneIndex);
				}
				else ChangeScene(0);
			}

			nowScene->UpdateBase();
		}
	};

	std::function<void()> outputLoop = [&]() {
		while (true) {
			if (nowScene->NeedUpdate) {
				Rerender();
				Display();
				nowScene->NeedUpdate = false;
			}
		}
	};

	std::thread mainThread(mainLoop);
	std::thread outputThread(outputLoop);

	mainThread.join();
	outputThread.join();

}