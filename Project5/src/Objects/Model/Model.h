#pragma once
#include <glew.h>
#include <gl/GL.h>
class Model {
public:
	Model();
	~Model();

	void draw();

	void testGeometry();

private:
	unsigned int vaoID[1];
	unsigned int vboID[2];
	float* vertices;
	float* colors;
	unsigned int nVertices;
};