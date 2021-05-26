/** File:   Keyboard.h
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Keyboard Class Header, where all the key bindings live
*/

#pragma once
#include <Windows.h>
#include <iostream>
#include "../EngineDefs.h"
#include "../Utility/Singleton/Singleton.h"

#ifdef __ENGINE__WINDOWS__
// Windows 10 Key Bindings. This list is largely hand made with values from
// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
enum Key {
	KEY_0 = 0x30, KEY_1 = 0x31, KEY_2 = 0x32, KEY_3 = 0x33, KEY_4 = 0x34, 
	KEY_5 = 0x35, KEY_6 = 0x36, KEY_7 = 0x37, KEY_8 = 0x38, KEY_9 = 0x39, 

	KEY_NUMPAD_0 = 0x60, KEY_NUMPAD_1 = 0x61, KEY_NUMPAD_2 = 0x62,
	KEY_NUMPAD_3 = 0x63, KEY_NUMPAD_4 = 0x64, KEY_NUMPAD_5 = 0x65,
	KEY_NUMPAD_6 = 0x66, KEY_NUMPAD_7 = 0x67, KEY_NUMPAD_8 = 0x68,
	KEY_NUMPAD_9 = 0x69, KEY_NUMPAD_PLUS = VK_ADD, KEY_NUMPAD_MINUS = VK_SUBTRACT,
	KEY_NUMPAD_SLASH = VK_DIVIDE, KEY_NUMPAD_ASTERISK = VK_MULTIPLY, 
	KEY_NUMPAD_DASH = VK_SEPARATOR, KEY_NUMPAD_PERIOD = VK_DECIMAL,

	KEY_A = 0x41, KEY_B = 0x42, KEY_C = 0x43, KEY_D = 0x44, KEY_E = 0x45,
	KEY_F = 0x46, KEY_G = 0x47, KEY_H = 0x48, KEY_I = 0x49, KEY_J = 0x4a,
	KEY_K = 0x4b, KEY_L = 0x4,  KEY_M = 0x4d, KEY_N = 0x4e, KEY_O = 0x4f,
	KEY_P = 0x50, KEY_Q = 0x51, KEY_R = 0x52, KEY_S = 0x53, KEY_T = 0x54,
	KEY_U = 0x55, KEY_V = 0x56, KEY_W = 0x57, KEY_X = 0x58, KEY_Y = 0x59, KEY_Z = 0x5a,

	KEY_CAPSLOCK = VK_CAPITAL, KEY_PAUSE = VK_PAUSE, KEY_ENTER = VK_RETURN, KEY_CLEAR = VK_CLEAR,
	KEY_TAB = VK_TAB, KEY_BACKSPACE = VK_BACK, KEY_ESCAPE = VK_ESCAPE, KEY_SPACE = VK_SPACE, 
	KEY_PAGEUP = VK_PRIOR, KEY_PAGEDOWN = VK_NEXT, KEY_END = VK_END, KEY_HOME = VK_HOME, 
	KEY_LEFT = VK_LEFT, KEY_RIGHT = VK_RIGHT, KEY_UP = VK_UP, KEY_DOWN = VK_DOWN, 
	KEY_INSERT = VK_INSERT, KEY_DELETE = VK_DELETE, KEY_HELP = VK_HELP, KEY_WINDOWS = VK_LWIN,
	KEY_CONTROL = VK_CONTROL, KEY_ALT = VK_MENU,
	KEY_LSHIFT = VK_LSHIFT, KEY_RSHIFT = VK_RSHIFT, KEY_LCONTROL = VK_LCONTROL, KEY_RCONTROL = VK_RCONTROL,
	KEY_NUMLOCK = VK_NUMLOCK, KEY_SCROLLLOCK = VK_SCROLL
};

const std::size_t KEYS_SIZE = 256;
#elif __ENGINE__LINUX__ 
// ...
// TODO: Write linux key bindings
#endif

// TODO: Fill out all key bindings


// Keyboard Class
class Keyboard {
public:
	Keyboard();
	~Keyboard();

	bool isPressed(Key key);
	void pollKeyboard();
	void debug();
private:
	
	short keys[KEYS_SIZE];
	
};