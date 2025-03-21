#pragma once
#include <string>
#include <vector>

class TextComposer
{

	std::vector<float> vertices0;
	std::vector<float> normals;
	std::vector<float> coords;
	std::string _text = "";
	int Compose();
	float AddChar(float* vData, int vCount, float x);
public:
	float* _vertices0;
	float* _normals;
	float* _coords;
	float _width = 0;
	int _vertexCount = 0;
	TextComposer(std::string text);
	~TextComposer();
};

