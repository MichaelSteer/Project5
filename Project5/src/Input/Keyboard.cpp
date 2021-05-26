/** File:   Kayboard.cpp
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Keyboard implementation
*/

#include "Keyboard.h"

Keyboard::Keyboard() {}
Keyboard::~Keyboard() {}

/** Polls the keyboard to populate all keystates
 *  TODO: This is a really shitty way to do this. Rewrite properly later
*/
void Keyboard::pollKeyboard() {
	for (int i = 0; i < KEYS_SIZE; i++) {
		keys[i] = GetAsyncKeyState(i);
	}
}

/** Returns if a given key is pressed
 *  Inputs: [Key] key : The key to be returned
*/
bool Keyboard::isPressed(Key key) {
	return keys[key];
}