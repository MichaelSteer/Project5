#include "Camera.h"
// TODO: Very bad C++. Memory leak hell if i dont fix

Camera::Camera() {
	up = glm::vec3(0.f, 1.f, 0.f);
}

Camera::~Camera() {}

glm::mat4 Camera::viewMatrix() {
	return _viewMatrix;
}

void Camera::lookAt(Object target) {
	_viewMatrix = glm::lookAt(position, target.getPosition(), up);
}

void Camera::lookAt(glm::vec3 target) {
	_viewMatrix = glm::lookAt(position, target, up);
}

void Camera::lookAt(float x, float y, float z) {
	lookAt(glm::vec3(x, y, z));
}

void Camera::setTarget(Object& target) {
	this->target = target;
}

void Camera::setTarget(glm::vec3 v) {
	target.setPosition(v);
}

void Camera::setTarget(float x, float y, float z) {
	setTarget(glm::vec3(x, y, z));
}


void Camera::update() {
	glm::vec3 direction = glm::normalize(position - target.getPosition());
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, direction));
	glm::vec3 cameraUp = glm::cross(direction, cameraRight);

	lookAt(target);
}

void Camera::translate(float x, float y, float z) {
	translate(glm::vec3(x, y, z));
}

void Camera::translate(glm::vec3 v) {
	Object::translate(v);
	target.translate(v);
}

void Camera::translateLocal(float x, float y, float z) {
	translateLocal(glm::vec3(x, y, z));
}

void Camera::translateLocal(glm::vec3 v) {
	Object::translateLocal(v);
	target.translateLocal(v);
}
