#pragma once
#include <iostream>
#include <glew.h>
#include <wglew.h>
#include <gl/GL.h>
class Shader {
public:
	Shader();
	Shader(std::string vertFile, std::string fragFile);

	~Shader();

	void init(std::string vertFile, std::string fragFile);

	void bind();
	void unbind();

	unsigned int id();

private:
	unsigned int _id;
	unsigned int vp; // vertex pointer
	unsigned int fp; // fragment pointer
};