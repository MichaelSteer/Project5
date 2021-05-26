/** File:   Mouse.h
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Main File for the entire program
*/

#pragma once
#include <Windows.h>
#include <glm.hpp>
#include <iostream>

// Mouse Class
class Mouse {
	public:
		Mouse();
		~Mouse();
		glm::vec2 getCursorPosition();			// Returns the position of the cursor in terms of screen coordinates
		glm::vec2 getVelocity();				// Returns the velocity of the cursor
		glm::vec2 getAccelleration();			// Returns the accelleration of the cursor
		void updateMouse();						// Update the mouse position
		void setHRAWINPUT(HRAWINPUT& input);	// Set the raw input of the cursor
												// TODO: windows specific, rewrite
		void printInfo();
	private:
		glm::vec2 position, lastPosition;
		glm::vec2 velocity, lastVelocity;
		glm::vec2 accelleration;
		HRAWINPUT input;
};