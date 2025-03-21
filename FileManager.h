#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#pragma once
#include <FilesystemObject.h>
#include <vector>


class FileManager
{
public:
	int Prepare(std::string directory);
	void LoadObjects();
	int LoadModel(std::string model, int i);
	std::vector<FilesystemObject*> _fsEntries;
	std::vector<FilesystemObject*> _fsUtils;
	FilesystemObject* _fsFloor;
	FilesystemObject* _fsText;

	FilesystemObject* _fsCeil; //temp


	std::vector<int> missingX;
	std::vector<int> missingZ;

	float* verticesModel[10];
	float* normalsModel[10];
	float* texcoordsModel[10];
	int vertexCountModel[10];


};
#endif
