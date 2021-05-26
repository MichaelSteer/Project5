/** File:   Object.h
 *  Author: Michael Steer
 *  Date:   25-05-21
 * 
 *  Grand-daddy Object class. Main reference for everything in 3D space
*/

#pragma once
#include <glm.hpp>
#include <gtc/quaternion.hpp>

class Object {
public:
	Object();											// Blank Object
	Object(float x, float y, float z);					// Object defined by a point
	Object(glm::vec3 v);								// Vector defined object
	~Object();

	void translate(float x, float y, float z);			// Move Object relative to global coordinates
	void translate(glm::vec3 v);

	void translateLocal(float x, float y, float z);		// Move Object relative to its current rotation
	void translateLocal(glm::vec3 v);

	void rotate(float p, float r, float y);				// Rotate Object using global axis
	void rotate(glm::quat r);

	// void localRotate(float p, float r, float y);		// Rotate Object using local axis
	// void localRotate(glm::quat r);

	glm::vec3 getPosition();							// Position
	glm::quat getRotation();							// Rotation in quaternion form

	void setPosition(float x, float y, float z);		// Set Position relative to global coordinates
	void setPosition(glm::vec3 v);

	void setRotation(float p, float r, float y);		// Set Rotation relative to global coordinates
	void setRotation(glm::quat r);
protected:
	glm::vec3 position;
	glm::quat rotation;
};