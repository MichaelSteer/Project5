/** File:   MainState.h
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Main executable state for the entire program
 *  NOTE: ALMOST ALL KEY CODE JUMPS HAPPEN HERE. THE REST IS THE SYSTEM LOOP
*/

#pragma once

#include <iostream>
#include "../../Input/Keyboard.h"
#include "../../Input/Mouse.h"
#include "../State.h"


// Main state
class MainState : public State {
public:
	MainState(GLWindow& window);
	~MainState();

	void init(); 		// Setup		
	void input();		// Main Application IO
	void logic();		// Game Logic
	void render();		// Render Logic
	//State changeState(ProgramState *state);
	//void* transferStateInfo();
	//TODO: Impliment remaining systems
private:

	Camera camera;

	glm::vec3 move;						// Next character position
	float dx_step, dy_step, dz_step;	// Directional movement
	float step_size;					// movement speed
	// TODO: Parameter manager
};