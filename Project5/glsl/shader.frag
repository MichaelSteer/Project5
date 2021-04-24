#version 330 core
out vec4 FragColor;
in vec3 pass_Color;
void main(void) {
	FragColor = vec4(pass_Color, 1.0f);
}