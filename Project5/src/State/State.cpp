#include "State.h"

State::State(GLWindow& window) {
	this->window = window;
}

State::~State() {}


GLWindow* State::getWindow() {
	return &window;
}