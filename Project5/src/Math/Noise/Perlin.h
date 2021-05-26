#pragma once

#include <vector>
#include "Simplex.h"

enum OCTAVE_COUNT {
	OCTAVES_1 = 1,
	OCTAVES_2 = 2, 
	OCTAVES_4 = 4, 
	OCTAVES_8 = 8,
	OCTAVES_16 = 16
};

class Perlin {
public:
	Perlin();
	Perlin(OCTAVE_COUNT nOctaves, float persistance, float lacunarity);
	~Perlin();

	float val(float x);
	float val(float x, float y);
	float val(float x, float y, float z);
private:
	float lacunarity;
	float persistance;
	float nOctaves;
	std::vector<Simplex> generators;

	int rand();
};