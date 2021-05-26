#include "StateManager.h"

StateManager::StateManager(GLWindow& window) {
	state = std::make_unique<initialState>(window);
	timer = std::make_unique<Timer>();
	this->window = window;
}

StateManager::~StateManager() {}

void StateManager::init() {
	std::cout << "starting state initialization" << std::endl;
}

void StateManager::start() {
	std::cout << "starting state manager" << std::endl;
	state->init();
}

void StateManager::stop() {
	std::cout << "stopping state manager" << std::endl;
}


void StateManager::tick() {
	timer->start();

	state->input();
	input_time = timer->getElapsedTime();

	state->logic();
	logic_time = input_time - timer->getElapsedTime();

	state->render();
	render_time = logic_time - timer->getElapsedTime();
	
	time_ns logicTime = timer->getElapsedTime();
	time_ns waitTime = fps_60 - Tp(logicTime);

	std::this_thread::sleep_for(logicTime);
}