#pragma once

template<typename T>
class Singleton {
public:
	static T& getInstance() {
		static T instance;
		return instance;
	}

	static void setup() {
		static T instance;
	}
};