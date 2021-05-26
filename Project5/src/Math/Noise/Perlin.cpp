#include "Perlin.h"

Perlin::Perlin() {}

Perlin::~Perlin() {
	generators.clear();
}

float Perlin::val(float x) {
	float out = 0.f;
	int octave = 0;
	for (auto n : generators) {
		float frequency = std::pow(lacunarity, octave);
		float amplitude = std::pow(persistance, -octave);

		out += amplitude * n.val(x * frequency);
		octave++;
	}
	return out;
}

float Perlin::val(float x, float y) {
	float out = 0.f;
	int octave = 0;
	for (auto n : generators) {
		float frequency = std::pow(lacunarity, octave);
		float amplitude = std::pow(persistance, -octave);

		out += amplitude * n.val(x * frequency, y * frequency);
		octave++;
	}

	return out;
}
int Perlin::rand() {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> d;
	return d(generator);
}

Perlin::Perlin(OCTAVE_COUNT nOctaves, float persistance, float lacunarity) : persistance(persistance), lacunarity(lacunarity) {
	for (int i = 0; i < nOctaves; i++) {
		generators.push_back(Simplex(this->rand()));
	}
}