#include "OBJ.h"


void OBJ::addTextCoord(float u, float v) {
	texCoords.push_back(u);
	texCoords.push_back(v);
}

void OBJ::addNormalCoord(float x, float y, float z) {
	normals.push_back(x);
	normals.push_back(y);
	normals.push_back(z);
}

void OBJ::addVertexCoord(float x, float y, float z) {
	vertices.push_back(x);
	vertices.push_back(y);
	vertices.push_back(z);
}

void OBJ::addVertexTriangle(unsigned long a, unsigned long b, unsigned long c) {
	faces.push_back(a);
	faces.push_back(b);
	faces.push_back(c);
}

void OBJ::addTextureTriangle(unsigned long a, unsigned long b, unsigned long c) {
	texFaces.push_back(a);
	texFaces.push_back(b);
	texFaces.push_back(c);
}

void OBJ::addNormalTriangle(unsigned long a, unsigned long b, unsigned long c) {
	normFaces.push_back(a);
	normFaces.push_back(b);
	normFaces.push_back(c);
}
/*  Split a string up into a series of integer values at slashes
	Input: ['1/2/3']
	Output: [1, 2, 3]
*/
std::vector<unsigned long> OBJ::tokenizeIndicies(std::string indicies) {
	std::vector<unsigned long> out;
	std::istringstream iss(indicies);
	std::string v;
	while (std::getline(iss, v, '/'))
		out.push_back(stoi(v));
	return out;
}

/* Split a string up into a series of substring with the following form
   Input: ['test string goes here']
   Output ['test', 'string', 'goes', 'here']
*/
std::vector<std::string> OBJ::tokenizeLine(std::string line) {
	std::istringstream iss(line);
	std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
		std::istream_iterator<std::string>());
	return tokens;
}

/*  parse an individual line in the file
	format: [usemtl/mtl/v/vt/vn/f] a, b, c
	vertices: v x y z
	texture coordinates: vt u v
	normals: vn x y z

	faces: f a1/b1/c1 a2/b2/c2 a3/b3/c3
	- a: vertex index
	- b: texture coord index
	- c: normal index
*/
OBJ_ERROR OBJ::parseLine(std::string line) {
	try {
		std::vector<std::string> values = tokenizeLine(line);

		// first character encodes the type of data
		switch (values[0][0]) {

			// Comments
		case '#':
			break;

			// mtllib
		case 'm':
			break;

			// vertices and texture coords
		case 'v':
			if (values[0][1] == 't')
				addTextCoord(stof(values[1]), stof(values[2]));
			else if (values[0][1] == 'n')
				addNormalCoord(stof(values[1]), stof(values[2]), stof(values[3]));
			else
				addVertexCoord(stof(values[1]), stof(values[2]), stof(values[3]));
			break;

			// material stuff
		case 'u':
			break;

			// faces
		case 'f':
			std::vector<unsigned long> a, b, c;
			a = tokenizeIndicies(values[1]);
			b = tokenizeIndicies(values[2]);
			c = tokenizeIndicies(values[3]);

			addVertexTriangle(a[0], b[0], c[0]);
			addTextureTriangle(a[1], b[1], c[1]);
			addNormalTriangle(a[2], b[2], c[2]);
			break;
		}
	}
	catch (std::exception &e) {
		std::cout << "Error: Exception Occured | " << e.what() << std::endl;
		return OBJ_BAD;
	}

	return OBJ_OK;
}

OBJ::OBJ() {

}

OBJ::OBJ(std::string file) {
	load(file);
}

OBJ::~OBJ() {
	vertices.clear();
	texCoords.clear();
	normals.clear();
	faces.clear();
	texFaces.clear();
	normFaces.clear();
}

bool OBJ::load(std::string path) {
	std::ifstream file(path.c_str());

	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			if (parseLine(line) != OBJ_OK) {
				std::cout << "Error: Bad OBJ File" << std::endl;
				file.close();
				return false;
			}
		}
	}
	file.close();
	return true;
}