#include "MainState.h"


MainState::MainState(GLWindow& window) : State(window) {
	// TODO: NEEDS ACCESS TO GLWINDOW
	// i think this is done? dont have brain power to check rn 25/05/21
}

MainState::~MainState() {

}

void MainState::init() {
	std::cout << "Setting up main state" << std::endl;

	dx_step = 0.1f;
	dy_step = 0.1f;
	dz_step = 0.1f;

	camera.setPosition(0.f, 8.f, -5.f);
	camera.lookAt(0.f, 0.f, 0.f);
	window.view(camera);

	window.setupWindow();
}

void MainState::input() {
	Singleton<Keyboard>::getInstance().pollKeyboard();

	if (Singleton<Keyboard>::getInstance().isPressed(KEY_D)) {
		move.x = dx_step;
		std::cout << "W Pressed" << std::endl;
	}
	else if (Singleton<Keyboard>::getInstance().isPressed(KEY_A))
		move.x = -dx_step;
	else
		move.x = 0;

	if (Singleton<Keyboard>::getInstance().isPressed(KEY_C))
		move.z = dz_step;
	else if (Singleton<Keyboard>::getInstance().isPressed(KEY_SPACE))
		move.z = -dz_step;
	else
		move.z = 0;

	if (Singleton<Keyboard>::getInstance().isPressed(KEY_S))
		move.y = dy_step;
	else if (Singleton<Keyboard>::getInstance().isPressed(KEY_W))
		move.y = -dy_step;
	else
		move.y = 0;
}

void MainState::logic() {
	camera.translateLocal(move);
	camera.update();
	window.view(camera);
	window.updateViewMatrix();
}

void MainState::render() {
	window.renderWindow();
}
