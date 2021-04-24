#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "color.h"

const float triad = M_PI / 3;

float floatmod(float f, float m) {
	float d = (float)floor(f / m);
	return f - d * m;
}

ColorWheel::ColorWheel() {}

ColorWheel::~ColorWheel() {}

// More or less HSV to RGB. V being val, HS being polar coordinates
glm::vec3 ColorWheel::cardinal_to_rgb(GLfloat x, GLfloat y, GLfloat val, GLfloat offset) {
	std::cout << "call for (" << x << ", " << y << ", " << val << ")" << std::endl;
	GLfloat _s = sqrt(x * x + y * y); // saturation
	GLfloat _h = 0.f;
	if ((x > 0) && (y > 0)) {
		_h = atan(y / x);
	}
	else if ((x < 0) && (y > 0)) {
		_h = M_PI - atan(y / x);
	}
	else if ((x < 0) && (y < 0)) {
		_h = M_PI + atan(y / x);
	}
	else {
		atan(y / x);
	}

	GLfloat _v = 1.f;

	std::cout << "H: " << _h << " S: " << _s << " V: " << _v << std::endl;

	// formula from https://www.rapidtables.com/convert/color/hsv-to-rgb.html
	GLfloat _c = _v * _s;
	GLfloat _x = _c * 1 - abs(floatmod((_h / triad), 2) - 1);
	GLfloat _m = _v - _c;

	GLfloat rp = 0.f; GLfloat gp = 0.f; GLfloat bp = 0.f;

	if ((_h >= 0) && (_h <= triad)) {
		rp = _c; gp = _x; bp = 0;
	}
	else if ((_h > triad) && (_h <= 2 * triad)) {
		rp = _x; gp = _c; bp = 0;
	}
	else if ((_h > (2 * triad)) && (_h <= 3 * triad)) {
		rp = 0; gp = _c; bp = _x;
	}
	else if ((_h > (3 * triad)) && (_h <= 4 * triad)) {
		rp = 0; gp = x; bp = _c;
	}
	else if ((_h > (4 * triad)) && (_h <= 5 * triad)) {
		rp = _x; gp = 0; bp = _c;
	}
	else if ((_h > (5 * triad)) && (_h <= 6 * triad)) {
		rp = _c; bp = 0; gp = _x;
	}

	GLfloat r = rp + _m; GLfloat g = gp + _m; GLfloat b = gp + _m;
	std::cout << "R:" << r << " G: " << g << " B: " << b << std::endl;
	return glm::vec3(r, g, b);
}