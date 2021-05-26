/** File:   State.h
 *  Author: Michael Steer
 *  Date:   26-05-21
 * 
 *  Base State class
 * 
 * TODO: Move all the I/O stuff into either this or the manager class and have methods for accessing it
*/

#pragma once

#include "../Window/GLWindow.h"

// State List
enum ProgramState {
	STATE_NULL,
	STATE_MAIN
};


// State Base Class
class State {
public:
	State(GLWindow& window);
	~State();

	virtual void init() = 0;		// Setup		

	virtual void input() = 0;		// I/O
	virtual void logic() = 0;		// Logic
	virtual void render() = 0;		// Render

	//virtual State changeState(ProgramState *state) = 0;
	//virtual void* transferStateInfo() = 0; // TODO: Dangerous

	GLWindow* getWindow();

private:
	ProgramState state;
protected:
	GLWindow window;
};