#pragma once
#include <Windows.h>
#include <glew.h>
#include <wglew.h>
#include <gl/GL.h>

class GLWindow {
public:
	bool createWindow();
	bool createWindow(HWND hwnd);
	bool createContext(HWND hwnd);
	bool destroyWindow();

	bool setupWindow();
	
	void reshapeWindow(int w, int h);

	void renderWindow();

private:
	int width;
	int height;
protected:
	HGLRC hrc;  // rendering content
	HDC hdc;    // device content
	HWND hwnd;  // window identifier
};