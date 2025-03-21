#include "FilesystemObject.h"
#include "myWall.h"
#include "myTeapot.h"
#include "myCubeX.h"
//#include <FileManager.h>
#include <iostream>



int FilesystemObject::setM(glm::mat4 M)
{


	Mpos = M;
	if (_type == 0) {
		CalcScreen();
	}
	else if (_type == 1) {
		CalcBay();
		CalcObj();
		CalcTxt();

	}
	else if (_type == 2) {

		CalcBay();
		CalcObj();
		CalcTxt();


	}
	else if (_type == 3 || _type ==5 ) {
		wallSegments.clear();
		wallSegments.push_back(M);
	}


	return 0;
}






void FilesystemObject::CalcBay() {

	wallSegments.clear();

	glm::mat4 Mh = Mpos;

	for (int i = 0; i < 6; i+=2) {
		glm::mat4 Mp;

		//middle
		Mp = glm::translate(Mh, glm::vec3(1.0f, 0.0f+i, 2.0f));
		wallSegments.push_back(Mp);
		Mp = glm::translate(Mh, glm::vec3(-1.0f, 0.0f+i, 2.0f));
		wallSegments.push_back(Mp);

		//sides
		Mp = glm::translate(Mh, glm::vec3(2.0f, 0.0f+i, 1.0f));
		Mp = glm::rotate(Mp, PI / 2, glm::vec3(0.0f, 1.0f, 0.0f));
		wallSegments.push_back(Mp);

		Mp = glm::translate(Mh, glm::vec3(-2.0f, 0.0f+i, 1.0f));
		Mp = glm::rotate(Mp, -PI / 2, glm::vec3(0.0f, 1.0f, 0.0f));
		wallSegments.push_back(Mp);

		//edges
		Mp = glm::translate(Mh, glm::vec3(3.0f, 0.0f+i, 0.0f));
		wallSegments.push_back(Mp);
		Mp = glm::translate(Mh, glm::vec3(-3.0f, 0.0f+i, 0.0f));
		wallSegments.push_back(Mp);

	}
	CalcBox();
}



void FilesystemObject::CalcScreen() {

	wallSegments.clear();

	glm::mat4 Mh = Mpos;
	for (int i = 0; i < 6; i += 2) {
		glm::mat4 Mp;

		Mp = glm::translate(Mh, glm::vec3(0.0f, 0.0f + i, 0.0f));
		wallSegments.push_back(Mp);
	}
	CalcBox();


}

glm::vec3 enlarge(float scale) {
	return glm::vec3(scale, scale, scale);

}

void FilesystemObject::CalcObj() { 
	objSegments.clear();
	glm::mat4 Mh = Mpos;
	Mh = glm::translate(Mh, glm::vec3(0.0f, 0.0f , 1.0f));
	//-----------------------------------------------------
	if (_extType == 1) { // 1 - mp4,avi,mov
		//star
		Mh = glm::translate(Mh, glm::vec3(0.0f, 0.5f, 0.0f));
		Mh = glm::scale(Mh,enlarge(0.25*1.15));
	} 
	else if(_extType == 2) { // 2 - zip,7zip,rar
		
		Mh = glm::scale(Mh, enlarge(0.25 * 1.6));
	}
	else if (_extType == 3) { // 3 - jpg,png,bmp
		
		Mh = glm::translate(Mh, glm::vec3(0.0f, 0.5f, 0.0f));
		Mh = glm::scale(Mh, enlarge(0.25 * 0.8));
	}
	else if (_extType == 4) { // 4 - mp3,wav
		
		Mh = glm::translate(Mh, glm::vec3(-0.0f, 0.5f, 0.0f));
		Mh = glm::scale(Mh,enlarge(0.25 * /*0.85*/0.5));
	}
	else if (_extType == 5) { // 5 - other file extensions
		Mh = glm::translate(Mh, glm::vec3(0.0f, 0.5f, 0.0f));
		Mh = glm::scale(Mh, enlarge(0.25 * 1.15));
	}
	else if (_extType == 6) { // 6 - txt,doc,docx,pdf
		//paper clip
		Mh = glm::translate(Mh, glm::vec3(0.0f, 1.0f, 0.0f));
		Mh = glm::scale(Mh, enlarge(0.25 * 1.2));
	}
	else {
		Mh = glm::translate(Mh, glm::vec3(0.0f, /*-0.5f*/ -1.0f, -0.5f));
		Mh = glm::scale(Mh, enlarge(/*0.25*/0.4));
	
	}
	//-----------------------------------------------------
	objSegments.push_back(Mh);

}

void FilesystemObject::SpinObj(int forward) { 

	if (_type == 1) {
		int dir;
		if (forward) {
			dir = 1;
		}
		else
		{
			dir = -1;
		}

		if (rotationCnt < 20 || !forward) {

			for (int i = 0; i < objSegments.size(); i++) {
				objSegments[i] = glm::translate(objSegments[i], glm::vec3(2.0f, 0.0f, 0.0f));
				objSegments[i] = glm::rotate(objSegments[i], dir * _objRotation * PI / 2, glm::vec3(0.0f, 1.0f, 0.0f));
				objSegments[i] = glm::translate(objSegments[i], glm::vec3(-2.0f, 0.0f, 0.0f));
			}

			rotationCnt += dir;

		}

	} else {
		for (int i = 0; i < objSegments.size(); i++) {
			objSegments[i] = glm::rotate(objSegments[i], _objRotation * PI / 2, glm::vec3(0.0f, 1.0f, 0.0f));
		}
	}
}


void FilesystemObject::CalcBox() { //

	float mul = 0;
	if (_type == 0) {
		mul = 0.5;
	}
	else if (_type == 1 || _type == 2) {
		mul = 2;
	}


	if (_orientation == 0) {
		bounds[0] = x - 2*mul;
		bounds[1] = x + 2*mul;
		bounds[2] = z-0.25;
		bounds[3] = z + 1*2;


		presses[0] = x-2;
		presses[1] = x + 2;
		presses[2] = z-1*4;
		presses[3] = z;


	}
	else if (_orientation == 1) {
		bounds[0] = x - 0.25;
		bounds[1] = x + 1*2;
		bounds[2] = z - 2*mul;
		bounds[3] = z + 2*mul;


		presses[0] = x -1*4;
		presses[1] = x;
		presses[2] = z - 2;
		presses[3] = z + 2;


	}
	else if (_orientation == -1) {
		bounds[0] = x-1*4;
		bounds[1] = x + 0.25;
		bounds[2] = z - 2*mul;
		bounds[3] = z + 2*mul;

		presses[0] = x;
		presses[1] = x + 1*4;
		presses[2] = z - 2;
		presses[3] = z + 2;


	}
	else if (_orientation == -2) {

		bounds[0] = x-2*mul;
		bounds[1] = x + 2*mul;
		bounds[2] = z - 1*2;
		bounds[3] = z + 0.25;

		presses[0] = x - 2;
		presses[1] = x + 2;
		presses[2] = z;
		presses[3] = z+1*4;

	}


}


void FilesystemObject::CalcTxt() { 

	glm::mat4 Mh = Mpos;
	float txtScale = 0.0025f; //text height
	Mh = glm::translate(Mh, glm::vec3(-(_textData->_width * txtScale / 2), 3.0f, -0.1f)); // away from the panel, centered and up
	Mh = glm::scale(Mh, glm::vec3(txtScale, txtScale, txtScale));
	_textPos = Mh;

}






FilesystemObject::FilesystemObject(std::string path, std::string name, int type,int extType, float** verticesModel, float** normalsModel,
	float** texcoordsModel, int* vertexCountModel)
{
	_path = path;
	_type = type;
	_name = name;
	_extType = extType;



	if (_type == 0) {
		//procedure for creating a wall
		_vertices[0] = myWallVertices;
		_normals[0] = myWallNormals;
		_coords[0] = myWallTexCoords;
		_vertexCount[0] = myWallVertexCount;
		_textr[0] = 2;

		CalcScreen();
		
	}
	else if (_type == 1) {
		//procedure for creating a bay
		_vertices[0] = myWallVertices;
		_normals[0] = myWallNormals;
		_coords[0] = myWallTexCoords;
		_vertexCount[0] = myWallVertexCount;
		_textr[0] = 2;

		CalcBay();

		_vertices[1] = verticesModel[0];
		_normals[1] = normalsModel[0];
		_coords[1] = texcoordsModel[0];

		_vertexCount[1] = vertexCountModel[0];
		_textr[1] = 4;
		_objRotation = 0.025;
		CalcObj();

		_textData = new TextComposer(_name);
		CalcTxt();
		_textr[2] = 0;

	}
	else if (_type == 2) {
		_vertices[0] = myWallVertices;
		_normals[0] = myWallNormals;
		_coords[0] = myWallTexCoords;
		_vertexCount[0] = myWallVertexCount;
		_textr[0] = 2;
		CalcBay();



		int k = _extType;
		_vertices[1] = verticesModel[_extType];
		_normals[1] = normalsModel[_extType];
		_coords[1] = texcoordsModel[_extType];
		_vertexCount[1] =vertexCountModel[_extType];
		_textr[1] = _extType +4;
		_objRotation = 0.025;

		CalcObj();

		_textData = new TextComposer(_name);
		CalcTxt();
		_textr[2] = 0;

	}
	else if (_type == 3) {
		_vertices[0] = myWallVertices;
		_normals[0] = myWallNormals;
		_coords[0] = myWallTexCoords;
		_vertexCount[0] = myWallVertexCount;
		_textr[0] = 3;


	} 
	else if (_type == 5) {
		_vertices[0] = myWallVertices;
		_normals[0] = myWallNormals;
		_coords[0] = myWallTexCoords;
		_vertexCount[0] = myWallVertexCount;
		_textr[0] = 1;
	}


	

}

FilesystemObject::~FilesystemObject()
{
	delete _textData;
}