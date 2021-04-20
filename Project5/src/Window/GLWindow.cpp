#include "GLWindow.h"
#include <iostream>
/**
	Create OpenGL Window instance
**/
bool GLWindow::createWindow() {
	return true;
}

/**
  Create OpenGL Window instance with window identifier
**/
bool GLWindow::createWindow(HWND hwnd) {
	return createContext(hwnd);
}


/**
	Create the OpenGL context instance
**/
bool GLWindow::createContext(HWND hwnd) {
	this->hwnd = hwnd;
	
	hdc = GetDC(hwnd);

	// Setup pixel formatting
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 32;
	pfd.iLayerType = PFD_MAIN_PLANE;

	// Check pixel formatting
	int nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	if (nPixelFormat == 0) {
		std::cout << "Error: Bad Pixel format" << std::endl;
		return false;
	}

	// Apply pixel formatting
	bool bResult = SetPixelFormat(hdc, nPixelFormat, &pfd);
	if (!bResult) {
		std::cout << "Error: Failed to set pixel format" << std::endl;
		return false;
	}

	// Create OpenGL 2.0 temp context
	HGLRC tempOpenGLContext = wglCreateContext(hdc);
	wglMakeCurrent(hdc, tempOpenGLContext);


	// Try and start GLEW to Use OpenGL 3.2+
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		std::cout << "Error: Unable to initialize GLEW library" << std::endl;
	}

	int attributes[] = {
		WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
		WGL_CONTEXT_MINOR_VERSION_ARB, 2,
		WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
		0
	};

	// Check for OpenGL 3.2+ Support. Use the 2.0 temp context if unavailable
	if (wglewIsSupported("WGL_ARB_create_context") == 1) {
		hrc = wglCreateContextAttribsARB(hdc, NULL, attributes);
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(tempOpenGLContext);
		wglMakeCurrent(hdc, hrc);
	}
	else {
		std::cout << "Warning: Failed to create OpenGL 3.x Context. Defaulting to OpenGL 2.0" << std::endl;
		hrc = tempOpenGLContext;
	}
		

	int glVersion[2] = { -1, -1 };
	glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
	glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
	std::cout << "OpenGL Version: " << glVersion[0] << "." << glVersion[1] << std::endl;

	return true;
}

/**
	Destroy the OpenGL window instance.
**/
bool GLWindow::destroyWindow() {
	wglMakeCurrent(hdc, 0);
	wglDeleteContext(hrc);
	ReleaseDC(hwnd, hdc);
	return true;
}

/**
	setup the window to display something
**/
bool GLWindow::setupWindow() {
	glClearColor(0.4f, 0.6f, 0.9f, 0.0f);
	return true;
}

/**
	reshape callback
**/
void GLWindow::reshapeWindow(int w, int h) {
	width = w;
	height = h;
}

/**
	render
**/
void GLWindow::renderWindow() {
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	SwapBuffers(hdc);
}