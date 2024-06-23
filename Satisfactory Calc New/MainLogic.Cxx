#include "ConsoleWindow.Hxx"

void ConsoleWindow::ChangeScene(unsigned index) {
	nowSceneIndex        = index;
	nowScene             = scenes[index];
	selecting            = nowScene->Selecting;
	nowScene->NeedUpdate = true;
}

void ConsoleWindow::Initialize() {

	Satisfactory::Initialize();
	Resources::Initialize();

	// Faster I/O
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	// Make and Push All Scenes
	scenes.push_back(new MainScreen);
	scenes.push_back(new ItemWiki);


	// Initialize All Scenes
	for (auto& scene : scenes) {
		scene->InitializeBase();
	}

	// Exception : Remove Go Home Key in Home Page
	scenes[0]->AdditionalKeyGuides.erase(scenes[0]->AdditionalKeyGuides.begin());

	// Make Console to UI
	ConsoleManager::SetFont(L"D2Coding", 24);
	ConsoleManager::SetSize(1280, 832);
	ConsoleManager::DisableResize();
	ConsoleManager::DisableUserSelection();
	ConsoleManager::DisableScrollBar();
	ConsoleManager::SetCursorBlinking(false);
	ConsoleManager::SetTitle("Satisfactory Calculator V 0.01");
	ConsoleManager::SetCloseButton(false);
	ConsoleManager::SetMinimizeButton(false);
	ConsoleManager::UseANSIEscapeCode();

	// Set Start Scene
	ChangeScene(0);
}



void ConsoleWindow::Run() {

	// Main Events and Logic Thread
	std::function<void()> mainLoop = [&]() {

		while (true) {

			KeyManager::Update();

			// User Input : Move Left Page
			if (KeyManager::GetKeyPressed(Keys::LEFTTAB)) {
				if (nowSceneIndex > 0) {
					ChangeScene(--nowSceneIndex);
				}
				else ChangeScene(static_cast<int>(scenes.size()) - 1);
			}

			// User Input : Move Right Page
			else if (KeyManager::GetKeyPressed(Keys::RIGHTTAB)) {
				if (nowSceneIndex < scenes.size() - 1) {
					ChangeScene(++nowSceneIndex);
				}
				else ChangeScene(0);
			}

			else if (KeyManager::GetKeyPressed(Keys::HOME)) {
				ChangeScene(0);
			}

			nowScene->UpdateBase();

			// Change Scene if now Scene's state is need to chage scene
			if (nowScene->NeedToChangeScene) {

				int sceneChangeTemp = nowScene->NeedToChangeScene;
				nowScene->NeedToChangeScene = 0;

				if (sceneChangeTemp > 0) {
					for (int i = 0; i < sceneChangeTemp; i++) {
						if (nowSceneIndex < scenes.size() - 1) {
							ChangeScene(++nowSceneIndex);
						}
						else ChangeScene(0);
					}
				}
				else {
					for (int i = 0; i < -sceneChangeTemp; i++) {
						if (nowSceneIndex > 0) {
							ChangeScene(--nowSceneIndex);
						}
						else ChangeScene(static_cast<int>(scenes.size()) - 1);
					}
				}
			}

		}
	};

	// Saperated Output Thread
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