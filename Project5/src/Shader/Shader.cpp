#include <string>
#include <direct.h>
#include "Shader.h"

// TODO: Rewrite later. Reads a plaintext file in from a path
static char* fromFile(std::string path) {
	char* text = NULL;
	std::string full = "glsl\\";
	// char* cwd = _getcwd(NULL, 0);
	// std::cout << "CWD: " << cwd << std::endl;
	if (path.c_str() != NULL) {
		FILE *file;
		int result = fopen_s(&file, full.append(path).c_str(), "rt");

		if (file != NULL) {
			fseek(file, 0, SEEK_END);
			int count = ftell(file);
			rewind(file);

			if (count > 0) {
				text = (char*)malloc(sizeof(char) * (count + 1));
				count = fread(text, sizeof(char), count, file);
				text[count] = '\0';
			}
			else {
				std::cout << "more fuckery" << std::endl;
			}
			fclose(file);
		}
		else
			std::cout << "Failed to find shader: " << full << std::endl;
	}
	else {
		std::cout << "fucked" << std::endl;
		text = NULL;
	}
	return text;
}

static void validateShader(GLuint shader, const char* file = 0) {
	const unsigned int BUFFER_SIZE = 512;
	GLsizei length = 0;

	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);

	glGetShaderInfoLog(shader, BUFFER_SIZE, &length, buffer);

	if (length > 0)
		std::cout << "Error: Shader" << shader << "(" << (file ? file : "") << ") compile error: " << std::endl << buffer << std::endl;
}

static void validateProgram(GLuint program) {
	const unsigned int BUFFER_SIZE = 512;
	GLsizei length = 0;

	char buffer[BUFFER_SIZE];
	memset(buffer, 0, BUFFER_SIZE);

	glGetShaderInfoLog(program, BUFFER_SIZE, &length, buffer);

	if (length > 0)
		std::cout << "Error: Program" << program << "link error: " << std::endl << buffer << std::endl;

	glValidateProgram(program);
	GLint status;
	glGetProgramiv(program, GL_VALIDATE_STATUS, &status);

	if (status == GL_FALSE)
		std::cout << "Error: Could not validate shader" << std::endl;
}

Shader::Shader() {}

Shader::Shader(std::string vertFile, std::string fragFile) {
	init(vertFile, fragFile);
}

void Shader::init(std::string vertFile, std::string fragFile) {
	vp = glCreateShader(GL_VERTEX_SHADER);
	fp = glCreateShader(GL_FRAGMENT_SHADER);

	const char* vFile = fromFile(vertFile);
	const char* fFile = fromFile(fragFile);

	if (vFile == NULL || fFile == NULL) {
		std::cout << "ERROR: Shaders failed to load" << std::endl;
		return;
	}

	glShaderSource(vp, 1, &vFile, 0);
	glShaderSource(fp, 1, &fFile, 0);

	glBindAttribLocation(_id, 0, "in_position");
	glBindAttribLocation(_id, 1, "in_color");

	glCompileShader(vp);
	validateShader(vp);

	glCompileShader(fp);
	validateShader(fp);

	_id = glCreateProgram();

	glAttachShader(_id, vp);
	glAttachShader(_id, fp);

	glLinkProgram(_id);
	validateProgram(_id);
}

unsigned int Shader::id() {
	return _id;
}

void Shader::bind() {
	glUseProgram(_id);
}

void Shader::unbind() {
	glUseProgram(0);
}

Shader::~Shader() {
	glDetachShader(_id, fp);
	glDetachShader(_id, vp);

	glDeleteShader(fp);
	glDeleteShader(vp);
	glDeleteProgram(_id);
}