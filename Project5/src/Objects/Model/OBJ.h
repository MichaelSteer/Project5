#pragma once
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <exception>
#include "Model.h"

enum OBJ_ERROR {
	OBJ_OK,
	OBJ_BAD
};

class OBJ {
public:
	OBJ();
	OBJ(std::string file);
	~OBJ();

	bool load(std::string file);
	bool save(std::string file);

	Model toModel();

private:
	std::vector<std::string> tokenizeLine(std::string line);
	std::vector<unsigned long> tokenizeIndicies(std::string indicies);

	OBJ_ERROR parseLine(std::string line);

	void addTextCoord(float u, float v);
	void addNormalCoord(float x, float y, float z);
	void addVertexCoord(float x, float y, float z);

	void addVertexTriangle(unsigned long a, unsigned long b, unsigned long c);
	void addTextureTriangle(unsigned long a, unsigned long b, unsigned long c);
	void addNormalTriangle(unsigned long a, unsigned long b, unsigned long c);

	std::vector<float> vertices;
	std::vector<float> texCoords;
	std::vector<float> normals;

	std::vector<unsigned long> faces;
	std::vector<unsigned long> texFaces;
	std::vector<unsigned long> normFaces;
};