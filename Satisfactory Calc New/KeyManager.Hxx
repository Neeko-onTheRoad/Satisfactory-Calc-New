#pragma once

#ifndef _KEY_MANAGER_HXX_
#define _KEY_MANAGER_HXX_

#include <Windows.h>
#include <functional>
#include <unordered_map>

#define KEY_PRESSING 0x8000
#define KEY_TOGGLE   0x1

enum Keys {
	UP, DOWN, LEFT, RIGHT, SELECT, BACK, FIND, ESCAPE
};

class KeySettings {
public:

	static constexpr int UP    = VK_UP;
	static constexpr int DOWN  = VK_DOWN;
	static constexpr int LEFT  = VK_LEFT;
	static constexpr int RIGHT = VK_RIGHT;

	static constexpr int SELECT = VK_RETURN;
	static constexpr int BACK   = VK_BACK;
	static constexpr int ESCAPE = VK_ESCAPE;
	static constexpr int FIND   = (int)'F';

	static int  Get(Keys key);
	static void ForeachKeys(std::function<void(Keys)> action);

};


class KeyManager {

private:

	static std::unordered_map<Keys, bool> Pressing;
	static std::unordered_map<Keys, bool> PressingPrev;
	static std::unordered_map<Keys, bool> Pressed;
	static std::unordered_map<Keys, bool> Released;


public:
	
	static void Initialize();
	static void Update();

	static bool GetKeyPressing(Keys key);
	static bool GetKeyPressed (Keys key);
	static bool GetKeyReleased(Keys key);
	
};


#endif