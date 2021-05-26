/** File:   Shader.h
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  OpenGL Shader Wrangling Class and helpers
*/

#pragma once

#include <iostream>
#include <glew.h>
#include <wglew.h>
#include <gl/GL.h>

// Shader class
class Shader {
public:
	Shader();												// Blank shader
	Shader(std::string vertFile, std::string fragFile);		// Shader from vertex and fragment file

	~Shader();

	void init(std::string vertFile, std::string fragFile);	// Setup function

	void bind();											// Load
	void unbind();											// Unload

	unsigned int id();										// ID

private:
	unsigned int _id;
	unsigned int vp;
	unsigned int fp;
};