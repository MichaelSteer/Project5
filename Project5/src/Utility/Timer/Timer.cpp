#include "Timer.h"

Timer::Timer() : stopped(true) {}
Timer::~Timer() {}

void Timer::start() {
	_start = clock.now();
	stopped = false;
}

void Timer::stop() {
	_stop = clock.now();
	stopped = true;
}

time_ns Timer::getElapsedTime() {
	if (stopped) {
		auto r = _stop - _start;
		return r;
	}
	else {
		auto r = (clock.now() - _start);
		return r;
	}
}



bool Timer::isStopped() { 
	return stopped;
}