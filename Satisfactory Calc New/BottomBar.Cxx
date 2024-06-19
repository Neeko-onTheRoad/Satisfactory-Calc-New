#include "ConsoleWindow.Hxx"

void ConsoleWindow::RerenderBottomBar() {

	for (unsigned x = 0u; x < CONSOLE_WIDTH; x++) {
		bottomBar[0][x] = Ascii::HZ_BAR;
		bottomBarForegroundColor[0][x] = Color::HilightedForegroundColor;
		bottomBarForegroundColor[1][x] = Color::HilightedForegroundColor;
		bottomBarForegroundColor[3][x] = Color::HilightedForegroundColor;
	}

	int index = 0;
	for (auto& key : nowScene->GetAllKeyGuides()) {
		
		index += 3;

		bool actionLonger;
		int  minLength;

		if (key.Action.size() > key.Key.size()) {
			actionLonger = true;
			minLength = static_cast<int>(key.Key.size());
		}
		else {
			actionLonger = false;
			minLength = static_cast<int>(key.Action.size());
		}


		for (int i = 0; i < minLength; i++) {
			bottomBar[1][index] = key.Key[i];
			bottomBar[2][index] = key.Action[i];
			index++;
		}

		
		if (actionLonger) {
			for (int i = minLength; i < key.Action.size(); i++) {
				bottomBar[2][index++] = key.Action[i];
			}
		}
		else {
			for (int i = minLength; i < key.Key.size(); i++) {
				bottomBar[1][index++] = key.Key[i];
			}
		}


	}

}