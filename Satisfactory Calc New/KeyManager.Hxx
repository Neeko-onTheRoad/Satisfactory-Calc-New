#pragma once

#ifndef _KEY_MANAGER_HXX_
#define _KEY_MANAGER_HXX_

#include <ctime>
#include <functional>
#include <unordered_map>
#include "ConsoleManager.Hxx"

constexpr int KEY_PRESSING = 0x8000;
constexpr int KEY_TOGGLE   = 0x1;

constexpr clock_t AUTO_PRESSING_DELAY = 380ull;
constexpr clock_t AUTO_PRESSING_GAP   = 45ull;

enum class Keys {
	UP, DOWN, LEFT, RIGHT, SELECT, BACK, HOME, LEFTTAB, RIGHTTAB
};

enum class KeyState {
	Pressed, Released
};

class KeySettings {
public:

	static constexpr int UP    = VK_UP;
	static constexpr int DOWN  = VK_DOWN;
	static constexpr int LEFT  = VK_LEFT;
	static constexpr int RIGHT = VK_RIGHT;

	static constexpr int LEFTTAB  = VK_LSHIFT;
	static constexpr int RIGHTTAB = VK_RSHIFT;

	static constexpr int SELECT = VK_RETURN;
	static constexpr int BACK   = VK_BACK;
	static constexpr int HOME   = VK_ESCAPE;

	static int  Get(Keys key);
	static void ForeachKeys(std::function<void(Keys)> action);

};


class KeyManager {

private:

	static std::unordered_map<Keys, bool>     Pressing;
	static std::unordered_map<Keys, bool>     Pressed;
	static std::unordered_map<Keys, bool>     Released;
	static std::unordered_map<Keys, bool>     PressingPrev;
	static std::unordered_map<Keys, KeyState> PRLatch;
	static std::unordered_map<Keys, clock_t>  PressingStart;
	static std::unordered_map<Keys, KeyState> AutoPressLatch;
	static std::unordered_map<Keys, int>      AutoPressCount;


public:
	
	static void Initialize();
	static void Update();

	static bool GetKeyPressing(Keys key);
	static bool GetKeyPressed (Keys key);
	static bool GetKeyReleased(Keys key);
	
};


#endif