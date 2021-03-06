/** File:   Main.cpp
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Main File for the entire program
*/

#include <iostream>
#include "src/Window/GLWindow.h"
#include "src/State/StateManager.h"
bool running = true;
GLWindow window;
HINSTANCE hInstance;

/** Windows callback function for things like resizing the window or Alt-F4
**/
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {
	case WM_SIZE:
	{
		window.reshapeWindow(LOWORD(lParam), HIWORD(lParam));
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

/** Create a Window in the OS Window Manager and attach the OpenGL Window to it
**/
bool createWindow(LPCSTR title, int width, int height) {
	WNDCLASS windowClass;
	HWND hWnd;
	DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE; // Styling

	hInstance = GetModuleHandle(NULL);

	// More Styling, i.e. Icon, cursor, etc
	windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowClass.lpfnWndProc = (WNDPROC)WndProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = hInstance;
	windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = NULL;
	windowClass.lpszMenuName = NULL;
	windowClass.lpszClassName = title;

	if (!RegisterClass(&windowClass)) {
		std::cout << "Error: Failed to initialize Window" << std::endl;
		return false;
	}

	hWnd = CreateWindowEx(dwExStyle, title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, width, height, NULL, NULL, hInstance, NULL);

	if (!window.createContext(hWnd)) {
		std::cout << "Error: Could not Create OpenGL Context Instance" << std::endl;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);
	return true;
}

void debugConsole() {
	// Create a console and pipe the stdio to it so we can see it
	AllocConsole();
	FILE *fDummy;
	freopen_s(&fDummy, "conin$", "r", stdin);
	freopen_s(&fDummy, "conout$", "w", stdout);
	freopen_s(&fDummy, "conout$", "w", stderr);
}
/** Main
**/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	MSG msg;
	debugConsole();

	const char *title = "OpenGL 4.2 Test";
	createWindow(title, 1024, 768);

	StateManager mainLoop(window);
	mainLoop.start();

	// Core Loop
	while (running) {

		// Windows Message stuff
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			if (msg.message == WM_QUIT)
				running = false;
			else {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		else
			mainLoop.tick();
	}
	mainLoop.stop();
	return (int)msg.wParam;
}