#include "Model.h"
#include <iostream>
#include "../experiments/color.h"

ColorWheel colorfill;

Model::Model() {
}

Model::~Model() {}

void Model::testGeometry() {
	vertices = new float[18];
	colors = new float[18];
	vertices[0] = -0.5; vertices[1] = -0.5; vertices[2] = 0.0; // Bottom left corner  

	glm::vec3 v = colorfill.cardinal_to_rgb(vertices[0], vertices[1], vertices[2]);
	colors[0] = v.r; colors[1] = v.g; colors[2] = v.b; // Bottom left corner  

	vertices[3] = -0.5; vertices[4] = 0.5; vertices[5] = 0.0; // Top left corner  
	v = colorfill.cardinal_to_rgb(vertices[3], vertices[4], vertices[5]);
	colors[3] = v.r; colors[4] = v.g; colors[5] = v.b; // Top left corner  

	vertices[6] = 0.5; vertices[7] = 0.5; vertices[8] = 0.0; // Top Right corner  
	v = colorfill.cardinal_to_rgb(vertices[6], vertices[7], vertices[8]);
	colors[6] = v.r; colors[7] = v.g; colors[8] = v.b; // Top Right corner  

	vertices[9] = 0.5; vertices[10] = -0.5; vertices[11] = 0.0; // Bottom right corner  
	v = colorfill.cardinal_to_rgb(vertices[9], vertices[10], vertices[11]);
	colors[9] = v.r; colors[10] = v.g; colors[11] = v.b; // Bottom right corner  

	vertices[12] = -0.5; vertices[13] = -0.5; vertices[14] = 0.0; // Bottom left corner  
	v = colorfill.cardinal_to_rgb(vertices[12], vertices[13], vertices[14]);
	colors[12] = v.r; colors[13] = v.g; colors[14] = v.b; // Bottom left corner  

	vertices[15] = 0.5; vertices[16] = 0.5; vertices[17] = 0.0; // Top Right corner  
	v = colorfill.cardinal_to_rgb(vertices[15], vertices[16], vertices[17]);
	colors[15] = v.r; colors[16] = v.g; colors[17] = v.b; // Top Right corner 

	glGenVertexArrays(1, &vaoID[0]);
	glBindVertexArray(vaoID[0]);

	glGenBuffers(2, &vboID[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
	glBufferData(GL_ARRAY_BUFFER, 18 * sizeof(GLfloat), colors, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);

	delete[] vertices;
	delete[] colors;
}

void Model::draw() {
	glBindVertexArray(vaoID[0]);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}