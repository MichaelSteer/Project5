

#include "Mouse.h"

Mouse::Mouse() {
}

Mouse::~Mouse() {

}

glm::vec2 Mouse::getCursorPosition() {
	return position;
}

glm::vec2 Mouse::getVelocity() {
	return velocity;
}

glm::vec2 Mouse::getAccelleration() {
	return accelleration;
}

void Mouse::updateMouse() {

	UINT bufferSize;
	GetRawInputData(input, RID_INPUT, NULL, &bufferSize, sizeof(RAWINPUTHEADER));
	BYTE *buffer = new BYTE[bufferSize];
	GetRawInputData(input, RID_INPUT, (LPVOID)buffer, &bufferSize, sizeof(RAWINPUTHEADER));

	RAWINPUT *raw = (RAWINPUT*)buffer;

	if (raw->header.dwType == RIM_TYPEMOUSE) {
		lastPosition = position;
		long mX = raw->data.mouse.lLastX;
		long mY = raw->data.mouse.lLastY;

		position.x = mX;
		position.y = mY;
	}

	lastVelocity = velocity;
	velocity = position - lastPosition;

	// TODO: Might need some ordering changes due to tabbing out and stuff like that that intterupts this thread

	accelleration = velocity - lastVelocity;
}

void Mouse::setHRAWINPUT(HRAWINPUT& input) {
	this->input = input;
}

void Mouse::printInfo() {
	std::cout << "Mouse X: " << position.x << " Mouse Y: " << position.y << std::endl;
	std::cout << "Velocity X: " << velocity.x << " Velocity y" << position.y << std::endl;
}