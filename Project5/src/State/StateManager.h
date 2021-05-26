/** File:   Object.cpp
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Main logic controller for the entire application
*/

#pragma once

#include <thread>
#include <iostream>
#include "../Window/GLWindow.h"
#include "../Utility/Timer/Timer.h"
#include "../Input/Keyboard.h"
#include "State.h"
#include "Main/MainState.h"

typedef MainState initialState;

const Tp fps_60(time_ns(16666667));

class StateManager {
private:
	std::unique_ptr<State> state;
	std::unique_ptr<Timer> timer;
	
	time_ns logic_time, input_time, render_time, total_time;

	GLWindow window;

public:
	StateManager(GLWindow& window);
	~StateManager();

	void init();
	void start();
	void stop();
	void tick();
	void onSecond();
	void reshapeWindow(unsigned int w, unsigned int h);
};