

#pragma once
#include <iostream>
#include "../Object.h"

class Camera : public Object {
public:
	Camera();
	~Camera();

	glm::mat4 viewMatrix();

	void lookAt(Object target);
	void lookAt(glm::vec3 target);
	void lookAt(float x, float y, float z);
	void setTarget(Object& target);
	void setTarget(glm::vec3 v);
	void setTarget(float x, float y, float z);

	void update();

	void translate(float x, float y, float z);
	void translateLocal(float x, float y, float z);

	void translate(glm::vec3 v);
	void translateLocal(glm::vec3 v);

	void rotate(float p, float r, float y);
	void rotate(glm::quat r);
private:
	Object target;
	glm::vec3 up;
	glm::vec3 front;
	glm::mat4 _viewMatrix;
};