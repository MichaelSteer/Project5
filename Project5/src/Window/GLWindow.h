#pragma once
#include <Windows.h>
#include <glew.h>
#include <wglew.h>
#include <gl/GL.h>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include "../Shader/Shader.h"
#include "../Model/Model.h"

class GLWindow {
public:
	bool createWindow();
	bool createWindow(HWND hwnd);
	bool createContext(HWND hwnd);
	bool destroyWindow();

	bool setupWindow();
	
	void reshapeWindow(int w, int h);

	void renderWindow();

	void testGeometry();

private:
	int width;
	int height;

	Shader *shader; // GLSL Vertex and Fragment Shader

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;
	glm::mat4 modelMatrix;

	Model model;

protected:
	HGLRC hrc;  // rendering context
	HDC hdc;    // device content
	HWND hwnd;  // window identifier
};