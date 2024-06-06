#include "KeyManager.Hxx"
#include <iostream>

std::unordered_map<Keys, bool> KeyManager::Pressing;
std::unordered_map<Keys, bool> KeyManager::PressingPrev;
std::unordered_map<Keys, bool> KeyManager::Pressed;
std::unordered_map<Keys, bool> KeyManager::Released;

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
}



void KeyManager::Initialize() {
	KeySettings::ForeachKeys([&](Keys key) {
		Pressing    [key] = false;
		PressingPrev[key] = false;
		Pressed     [key] = false;
		Released    [key] = false;
	});

}



void KeyManager::Update() {
	KeySettings::ForeachKeys([&](Keys key) {

		bool PressingTemp = GetKeyState(KeySettings::Get(key)) < 0;

		if (PressingTemp) {
			
			if (PressingPrev[key] == false) {
				Pressing[key] = true;
				Pressed [key] = true;
			}
			else {
				Pressed[key] = false;
			}

		}
		else {
			
			if (PressingPrev[key] == true) {
				Pressing[key] = false;
				Released[key] = true;
			}
			else {
				Released[key] = false;
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