#ifndef FILESYSTEM_OBJECT_H
#define FILESYSTEM_OBJECT_H
#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "constants.h"
#include "TextComposer.h"

class FilesystemObject
{
public:

	std::string _path;
	std::string _name;

	
	//std::filesystem::path _path;
	int _type = 0;//0 - wall; 1 - folder; 2 - file; 3 - floor; 4 - text

	//bool _isDir = false;
	bool _isRoot = false;

	int _orientation = 0;

	float* _vertices[2];
	float* _normals[2];
	float* _coords[2];
	int _vertexCount[2];
	int _extType = 0; // 0 default, 1-mp4,avi,mov 2-zip,7zip,rar 
	// 3jpg,png,bmp 4-mp3,wav 5-other file extensions, 6-txt,doc,docx,pdf

	int _textr[3] = { 0,0,0};
	TextComposer* _textData;
	glm::mat4 _textPos = glm::mat4(1.0);


	int x =0, z =0;

	std::vector<glm::mat4> wallSegments;
	std::vector<glm::mat4> objSegments;
	glm::mat4 Mpos = glm::mat4(1.0);
	//glm::mat4 box = glm::mat4(1.0);
	float bounds[4] = { 999,999,999,999 };
	float presses[4] = { 999,999,999,999 };




	int _objType = 0;
	float _objRotation = 0.05;
	int rotationCnt = 0;

	int setM(glm::mat4 M);

	void CalcBay();
	void CalcScreen();
	void CalcObj();
	void SpinObj(int forward);
	void CalcBox();
	void CalcTxt();

	//FilesystemObject(std::string path, std::string name, int type);
	FilesystemObject(std::string path, std::string name, int type,int extType, float** verticesModel, float** normalsModel,
		float** texcoordsModel, int* vertexCountModel);
	~FilesystemObject();

	FilesystemObject() = default;
};

#endif