#include "ConsoleWindow.Hxx"

void ConsoleWindow::RerenderBottomBar() {

	// Render Color And Line in BottomBar
	for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
		bottomBar[0][x] = Ascii::HZ_BAR;
		bottomBarForegroundColor[0][x] = Color::HilightedForegroundColor;
		bottomBarForegroundColor[1][x] = Color::HilightedForegroundColor;
		bottomBarForegroundColor[3][x] = Color::HilightedForegroundColor;
	}

	// Render KeyGuides in BottomBar
	int index = 0;
	for (auto& key : nowScene->GetAllKeyGuides()) {
		
		index += 3;

		bool actionLonger;
		int  minLength;

		// Get Shorter string
		if (key.Action.size() > KeyManager::GetName(key.Key).size()) {
			actionLonger = true;
			minLength = static_cast<int>(KeyManager::GetName(key.Key).size());
		}
		else {
			actionLonger = false;
			minLength = static_cast<int>(key.Action.size());
		}

		// Print both string to Shorter string's length
		for (int i = 0; i < minLength; i++) {
			bottomBar[1][index] = KeyManager::GetName(key.Key)[i];
			bottomBar[2][index] = key.Action[i];
			index++;
		}

		
		// Print Longer string's remaining string
		if (actionLonger) {
			for (int i = minLength; i < key.Action.size(); i++) {
				bottomBar[2][index++] = key.Action[i];
			}
		}
		else {
			for (int i = minLength; i < KeyManager::GetName(key.Key).size(); i++) {
				bottomBar[1][index++] = KeyManager::GetName(key.Key)[i];
			}
		}


	}

}