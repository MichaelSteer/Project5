/** File:   Object.cpp
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Object Implementation
*/

#include "Object.h"

// Constructors
Object::Object() {

}

Object::Object(float x, float y, float z) {

}

Object::Object(glm::vec3 v) {
	position = v;
}

Object::~Object() {

}


// Move object relative to global coordinates
void Object::translate(float x, float y, float z) {
	translate(glm::vec3(x, y, z));
}

void Object::translate(glm::vec3 v) {
	position += v;
}

// Move object relative to local coordinates
void Object::translateLocal(glm::vec3 v) {
	position += (rotation * v);
}

void Object::translateLocal(float x, float y, float z) {
	translateLocal(glm::vec3(x, y, z));
}

// Rotate object relative to global axis
void Object::rotate(float p, float r, float y) {
	glm::vec3 t(p, r, y);
	glm::quat out(t);
	rotate(out);
}

void Object::rotate(glm::quat r) {
	rotation *= r;
}


// Return position
glm::vec3 Object::getPosition() {
	return position;
}

// Return orientation
glm::quat Object::getRotation() {
	return rotation;
}

// Set position relative to global coordinates
void Object::setPosition(float x, float y, float z) {
	position = glm::vec3(x, y, z);
}

void Object::setPosition(glm::vec3 v) {
	position = v;
}

// Set rotation relative to global axis
void Object::setRotation(float p, float r, float y) {
	rotation = glm::vec3(p, r, y);
}

void Object::setRotation(glm::quat r) {
	rotation = r;
}

