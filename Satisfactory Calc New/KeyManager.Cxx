#include "KeyManager.Hxx"

std::unordered_map<Keys, bool>    KeyManager::Pressing;
std::unordered_map<Keys, bool>    KeyManager::PressingPrev;
std::unordered_map<Keys, bool>    KeyManager::PressedFlag;

#define CASE(key) case Keys::##key: { return KeySettings::##key; }

int KeySettings::Get(Keys key) {
	switch (key) {
		CASE(UP)
		CASE(DOWN)
		CASE(LEFT)
		CASE(RIGHT)
		CASE(SELECT)
		CASE(BACK)
		CASE(FIND)
		CASE(ESCAPE)
		CASE(LEFTTAB)
		CASE(RIGHTTAB)
		default: return 0;
	}
}

#undef CASE

void KeySettings::ForeachKeys(std::function<void(Keys)> _action) {
	_action(Keys::UP);
	_action(Keys::DOWN);
	_action(Keys::LEFT);
	_action(Keys::RIGHT);
	_action(Keys::SELECT);
	_action(Keys::BACK);
	_action(Keys::FIND);
	_action(Keys::ESCAPE);
	_action(Keys::LEFTTAB);
	_action(Keys::RIGHTTAB);
}



void KeyManager::Initialize() {
	KeySettings::ForeachKeys([&](Keys key) {
		Pressing    [key] = false;
		PressingPrev[key] = false;
		PressedFlag [key] = false;
	});

}



void KeyManager::Update() {
	KeySettings::ForeachKeys([&](Keys key) {

		if (!ConsoleManager::GetConsoleSelected()) {
			Pressing    [key] = false;
			PressingPrev[key] = false;
			PressedFlag [key] = false;

			return;
		}

		bool PressingTemp = GetAsyncKeyState(KeySettings::Get(key)) < 0;

		Pressing[key] = PressingTemp;
		Pressed [key] = PressingTemp ^ PressingPrev[key];

		

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