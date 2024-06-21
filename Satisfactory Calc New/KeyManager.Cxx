#include "KeyManager.Hxx"

std::unordered_map<Keys, bool>     KeyManager::Pressing;
std::unordered_map<Keys, bool>     KeyManager::Pressed;
std::unordered_map<Keys, bool>     KeyManager::Released;
std::unordered_map<Keys, bool>     KeyManager::PressingPrev;
std::unordered_map<Keys, KeyState> KeyManager::PRLatch;
std::unordered_map<Keys, clock_t>  KeyManager::PressingStart;
std::unordered_map<Keys, KeyState> KeyManager::AutoPressLatch;
std::unordered_map<Keys, int>      KeyManager::AutoPressCount;

#define AUTO_CASE(key) case Keys::##key: { return KeySettings::##key; }

// Return Key Code by int converted by Key Enum
int KeySettings::Get(Keys key) {
	switch (key) {
		AUTO_CASE(UP)
		AUTO_CASE(DOWN)
		AUTO_CASE(LEFT)
		AUTO_CASE(RIGHT)
		AUTO_CASE(SELECT)
		AUTO_CASE(BACK)
		AUTO_CASE(HOME)
		AUTO_CASE(LEFTTAB)
		AUTO_CASE(RIGHTTAB)
		default: return 0;
	}
}

#undef AUTO_CASE

// Run function _action in all Keys
void KeySettings::ForeachKeys(std::function<void(Keys)> _action) {
	_action(Keys::UP);
	_action(Keys::DOWN);
	_action(Keys::LEFT);
	_action(Keys::RIGHT);
	_action(Keys::SELECT);
	_action(Keys::BACK);
	_action(Keys::HOME);
	_action(Keys::LEFTTAB);
	_action(Keys::RIGHTTAB);
}


// Reset All KeyState
void KeyManager::Initialize() {
	KeySettings::ForeachKeys([&](Keys key) {
		Pressing      [key] = false;
		Pressed       [key] = false;
		Released      [key] = false;
		PressingPrev  [key] = false;
		PRLatch       [key] = KeyState::Pressed;
		PressingStart [key] = 0ull;
		AutoPressCount[key] = 0;
		AutoPressLatch[key] = KeyState::Pressed;
	});

}



void KeyManager::Update() {

	// If Window is not focused, disable all Key
	if (!ConsoleManager::GetConsoleSelected()) {
		KeyManager::Initialize();
		return;
	}
	
	// Else Update all Keys
	KeySettings::ForeachKeys([&](Keys key) {

		// Get Key Pressed
		bool PressingTemp = GetAsyncKeyState(KeySettings::Get(key)) < 0;

		Pressing[key] = PressingTemp;
		
		// If Key state is diffrent with Current Key State
		if (PressingTemp ^ PressingPrev[key]) {

			// Get Curent Key State and Change Key State
			if (PRLatch[key] == KeyState::Released) {

				Pressed      [key] = false;
				Released     [key] = true;
				PRLatch      [key] = KeyState::Pressed;
				PressingStart[key] = 0;
			}
			else {

				Pressed       [key] = true;
				Released      [key] = false;
				PRLatch       [key] = KeyState::Released;
				PressingStart [key] = clock();
				AutoPressCount[key] = 0;
				AutoPressLatch[key] = KeyState::Released;
			}

		}
		else {
			Pressed [key] = false;
			Released[key] = false;
		}

		// Manage Auto Click if User Pressing Key with long time
		if (PressingStart[key] != 0) {

			if (clock() - PressingStart[key] - (AUTO_PRESSING_GAP * AutoPressCount[key]) > AUTO_PRESSING_DELAY) {
				
				PRLatch[key] = KeyState::Released;

				if (AutoPressLatch[key] == KeyState::Released) {
					AutoPressLatch[key] = KeyState::Pressed;
					Pressed       [key] = true;
					Released      [key] = false;
				}
				else {
					AutoPressLatch[key] = KeyState::Released;
					Pressed       [key] = false;
					Released      [key] = true;
					AutoPressCount[key]++;
				}

			}
		}


		PressingPrev[key] = PressingTemp;

	});
}


bool KeyManager::GetKeyPressing(Keys key) {
	return Pressing[key];
}

bool KeyManager::GetKeyPressed(Keys key) {
	return Pressed[key];
}

bool KeyManager::GetKeyReleased(Keys key) {
	return Released[key];
}