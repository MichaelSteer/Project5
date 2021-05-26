#pragma once
#include <cmath>
#include <random>
#include <glm.hpp>
/* Simplex noise class
   Takes in up to a 3D input [x, y, z] and outputs a noise value from [0, 1]
*/
class Simplex {
public:
	Simplex(int seed);
	~Simplex();

	// 1D
	float val(float x);

	// 2D
	float val(float x, float y); 
	float val(glm::vec2 v);

	// 3D
	float val(float x, float y, float z);
	float val(glm::vec3 v);
private:
	int _seed;

	// Interpolation
	float slerp(float x0, float x1, float w);

	// Gradient
	float randGrad(int x);
	glm::vec2 randGrad(int x, int y);
	glm::vec3 randGrad(int x, int y, int z);

	// Approx. Gradient
	float dotGridGrad(int ix, float x);
	float dotGridGrad(int ix, int iy, float x, float y);
	float dotGridGrad(int ix, int iy, int iz, float x, float y, float z);
};