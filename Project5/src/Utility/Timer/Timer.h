#include <chrono>

typedef std::chrono::high_resolution_clock::time_point Tp;
typedef std::chrono::high_resolution_clock Clock;
typedef std::chrono::nanoseconds time_ns;

class Timer {
public:
	Timer();
	~Timer();

	void start();
	void stop();

	time_ns getElapsedTime();

	bool isStopped();
private:
	Tp _start, _stop;
	Clock clock;
	bool stopped;
};