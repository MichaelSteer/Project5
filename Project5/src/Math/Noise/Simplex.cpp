#include "Simplex.h"


Simplex::Simplex(int seed) : _seed(seed) {}
Simplex::~Simplex() {}

// Returns a noise value from a float
float Simplex::val(float x) {
	int x0 = (int)x;
	int x1 = x0 + 1;
	
	float sx = x - (float)x0;

	float n0, n1, idx0;

	n0 = dotGridGrad(x0, x);
	n1 = dotGridGrad(x1, x);
	idx0 = slerp(n0, n1, sx);

	return idx0;
}

// Returns a noise value from 2 floats
float Simplex::val(float x, float y) {
	int x0 = (int)x;
	int y0 = (int)y;

	int x1 = x0 + 1;
	int y1 = y0 + 1;

	float sx = x - (float)x0;
	float sy = y - (float)y0;

	float n0, n1, ix0, ix1, v;

	n0 = dotGridGrad(x0, y0, x, y);
	n1 = dotGridGrad(x1, y0, x, y);
	ix0 = slerp(n0, n1, sx);

	n0 = dotGridGrad(x0, y1, x, y);
	n1 = dotGridGrad(x1, y1, x, y);
	ix1 = slerp(n0, n1, sx);

	v = slerp(ix0, ix1, sy);
	return v;
}

float Simplex::val(float x, float y, float z) {
	int x0 = (int)x;
	int y0 = (int)y;
	int z0 = (int)z;

	int x1 = x0 + 1;
	int y1 = y0 + 1;
	int z1 = z0 + 1;

	float sx = x - (float)x0;
	float sy = x - (float)x0;
	float sz = x - (float)x0;

	float n0, n1, ix0, ix1, ix2, iy0, iy1, iy2, iz0, iz1, iz2;

	return 0;
	// TODO: Finish writing
}

// Returns a noise value from a GLM vec3
float Simplex::val(glm::vec3 v) {
	return val(v.x, v.y, v.z);
}

// Returns a noise value from a GLM vec2
float Simplex::val(glm::vec2 v) {
	return val(v.x, v.y);
}

// Cubic interpolation between x0 and x1 at point w
float Simplex::slerp(float x0, float x1, float w) {
	return (x1 - x0) * (3.f - w * 2.f) * w * w + x0;
}

// Pick a random gradient for point x
float Simplex::randGrad(int x) {
	const float MAGIC_1 = 2920.f;
	const float MAGIC_2 = 21942.f;
	const float MAGIC_5 = 23157.f;

	float r = MAGIC_1 * std::sin(x * MAGIC_2) * std::cos(x * MAGIC_5);
	return r;
}


// Pick a random gradient for point (x, y). Uses some fucked trig function with a bunch of irrational coeficients to produce psudorandomness
glm::vec2 Simplex::randGrad(int x, int y) {
	const float MAGIC_1 = 2920.f;
	const float MAGIC_2 = 21942.f;
	const float MAGIC_3 = 171324.f + _seed;
	const float MAGIC_4 = 8912.f;
	const float MAGIC_5 = 23157.f;
	const float MAGIC_6 = 217832.f;
	const float MAGIC_7 = 9758.f + _seed / 314159.f;

	float r = MAGIC_1 * std::sin(x * MAGIC_2 + y * MAGIC_3 + MAGIC_4) * std::cos(x * MAGIC_5 * y * MAGIC_6 + MAGIC_7);
	
	return glm::vec2(std::cos(r), std::sin(r));
}

glm::vec3 Simplex::randGrad(int x, int y, int z) {
	return glm::vec3(0.f, 0.f, 0.f);
	//TODO: FIX LATER
}

// Return random gradient vector
float Simplex::dotGridGrad(int ix, float x) {
	float grad = randGrad(ix);
	float dx = x - (float)ix;
	return dx * grad;
}

// Return random gradient vector
float Simplex::dotGridGrad(int ix, int iy, float x, float y) {
	glm::vec2 grad = randGrad(ix, iy);

	float dx = x - (float)ix;
	float dy = y - (float)iy;

	return dx * grad.x + dy * grad.y;
}

float Simplex::dotGridGrad(int ix, int iy, int iz, float x, float y, float z) {
	glm::vec3 grad = randGrad(ix, iy, iz);

	float dx = x - (float)ix;
	float dy = y - (float)iy;
	float dz = z - (float)iz;

	return dx * grad.x + dy * grad.y + dz * grad.z;
}

