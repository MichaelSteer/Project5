#pragma once
#include <glew.h>
#include <gl/GL.h>
#include <glm.hpp>
class ColorWheel {
public:
	ColorWheel();
	~ColorWheel();
	glm::vec3 cardinal_to_rgb(GLfloat x, GLfloat y, GLfloat val, GLfloat offset = 0.f);
};