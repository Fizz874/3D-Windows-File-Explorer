#include "FileManager.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "constants.h"
#include "models/OBJ_Loader.h"



int FileManager::Prepare(std::string directory)
{
	for (int i = 0; i < _fsEntries.size(); i++) {
		delete _fsEntries[i];
	}
	for (int i = 0; i < _fsUtils.size(); i++) {
		delete _fsUtils[i];
	}

	missingX.clear();
	missingZ.clear();
	_fsEntries.clear();
	_fsUtils.clear();
	std::string path = directory;
	std::filesystem::path dirPath{ directory };

	std::string name = dirPath.filename().string();

	FilesystemObject* fs = new FilesystemObject(dirPath.parent_path().string(), "/..", 1,0, verticesModel, normalsModel,
		 texcoordsModel,  vertexCountModel);
	_fsEntries.push_back(fs);

	for (const auto& entry : std::filesystem::directory_iterator(path))
	{

		if (entry.is_directory())
		{
			FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 1,0, verticesModel, normalsModel,
				texcoordsModel, vertexCountModel);
			_fsEntries.push_back(fs);

		}
		if (entry.is_regular_file()) {
			std::string ext = entry.path().extension().string();
			if (ext == ".mp4" || ext==".avi" || ext == ".mov") {
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,1, verticesModel, normalsModel,
					texcoordsModel, vertexCountModel);

				_fsEntries.push_back(fs);
			}
			 else if(ext == ".zip" || ext == ".rar" || ext == ".7zip") { // 2
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,2, verticesModel, normalsModel,
					texcoordsModel, vertexCountModel);

				_fsEntries.push_back(fs);
			}
			else if(ext == ".jpg" || ext == ".png" || ext == ".bmp") { // 3
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,3, verticesModel,
					normalsModel,texcoordsModel, vertexCountModel);
			
				_fsEntries.push_back(fs);
			}
			else if (ext == ".mp3" || ext == ".wav" || ext == ".m4a") { // 4
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,4, verticesModel, normalsModel,
					texcoordsModel, vertexCountModel);
				_fsEntries.push_back(fs);
			}
			else if(ext == ".txt" || ext == ".doc" || ext == ".docx" || ext == ".pdf" || ext == ".odt") { // 6
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,6, verticesModel, normalsModel,
					texcoordsModel, vertexCountModel);
				_fsEntries.push_back(fs);
			}
			else {
				FilesystemObject* fs = new FilesystemObject(entry.path().string(), entry.path().filename().string(), 2,5, verticesModel, normalsModel,
					texcoordsModel, vertexCountModel);
				_fsEntries.push_back(fs);
			}
		}


	}
	float x= 0, z = 0;
	int past_orientation = -1;
	int len = _fsEntries.size();

	
	int base = 2;//len / 3;
	int add = (len - 2) % 2;//len % 3;
	x = -(base + add+0.5) *2*2;
	if (len > 3) {
		z = -4*2;
	}
	else {
		z = 0;
	}

	for (int i = 0; i < len; i++) {

		if (i < (len - (base+add))/2) {
			_fsEntries[i]->_orientation = -1;
			x += 0;
			z += 4*2;
		}
		else if (i < (len- (base + add))/2 + base + add) {
			_fsEntries[i]->_orientation = 0;
			x += 4*2;
			z += 0;
			if (past_orientation == -1) {
				past_orientation = 0;
				missingX.push_back(x - 8);
				missingZ.push_back(z+5);

				missingX.push_back(x-7);
				missingZ.push_back(z+6);


				z+=3*2;
				x += -2;




			}

		}
		else {
			_fsEntries[i]->_orientation = 1;
			x += 0;
			z += -4*2;

			if (past_orientation == 0) {
				past_orientation = 1;

				missingX.push_back(x + 5);
				missingZ.push_back(z+8);
				missingX.push_back(x + 6);
				missingZ.push_back(z + 7);
				z += 2;
				x += 3*2;


			}

		}

		float rotangle = _fsEntries[i]->_orientation * PI / 2;
		glm::mat4 M = glm::mat4(1.0f);
		M = glm::translate(M, glm::vec3(x, 0.0f, z)); //Compute model matrix
		M = glm::rotate(M, rotangle, glm::vec3(0.0f, 1.0f, 0.0f)); //Compute model matrix
		_fsEntries[i]->x = x;
		_fsEntries[i]->z = z;
		_fsEntries[i]->setM(M);

	}


	//generate empty walls
	int screenNum = (base + add + 2 ) * 4;
	if (len > 3) {
		for (int i = 0; i < (base + add ) * 4; i++) {
			FilesystemObject* fs = new FilesystemObject("", "",0,0, verticesModel, normalsModel,
				texcoordsModel, vertexCountModel);
			_fsUtils.push_back(fs);

			_fsUtils[i]->_orientation = -2;
			x += -2;
			z += 0;
			if (past_orientation == 1) {
				past_orientation = -2;

				missingX.push_back(x + 2);
				missingZ.push_back(z - 5);
				missingX.push_back(x + 1);
				missingZ.push_back(z - 6);

				z += -3 *2;
				x += -1;
			}


			if (i == (base + add) * 4 - 1) {

				missingX.push_back(x - 2);
				missingZ.push_back(z);
				missingX.push_back(x - 3);
				missingZ.push_back(z + 1);


			}


			float rotangle = _fsUtils[i]->_orientation * PI / 2;
			glm::mat4 M = glm::mat4(1.0f);
			M = glm::translate(M, glm::vec3(x, 0.0f, z)); //Compute model matrix
			M = glm::rotate(M, rotangle, glm::vec3(0.0f, 1.0f, 0.0f)); //Compute model matrix
			_fsUtils[i]->x = x;
			_fsUtils[i]->z = z;
			_fsUtils[i]->setM(M);

		}
	}
	else if(screenNum != 8) {

		for (int i = 0; i < (base + add  + 2) * 4; i++) {

			FilesystemObject* fs = new FilesystemObject("","", 0,0, verticesModel, normalsModel,
				texcoordsModel, vertexCountModel);
			_fsUtils.push_back(fs);

			if (i < 4) {

				_fsUtils[i]->_orientation = 1;
				x += 0;
				z += -2;

				if (past_orientation == 0) {
					past_orientation = 1;
					missingX.push_back(x + 5);
					missingZ.push_back(z + 2);
					missingX.push_back(x + 6);
					missingZ.push_back(z + 1);
					z += -1;
					x += 3 *2;
				}

			}
			else if (i >=(base + add  + 2) * 4 - 4) {

				_fsUtils[i]->_orientation = -1;
				x += 0;
				z += 2;


				if (past_orientation == -2) {
					past_orientation = -1;
					missingX.push_back(x -2);
					missingZ.push_back(z-2);
					missingX.push_back(x - 3);
					missingZ.push_back(z -1 );



					z += 1;
					x += -3;
				}

			}
			else {

				_fsUtils[i]->_orientation = -2;
				x += -2;
				z += 0;
				if (past_orientation == 1) {
					past_orientation = -2;

					missingX.push_back(x + 2);
					missingZ.push_back(z-2);
					missingX.push_back(x + 1);
					missingZ.push_back(z - 3);

					z += -3;
					x += -1;
				}


			}

			float rotangle = _fsUtils[i]->_orientation * PI / 2;
			glm::mat4 M = glm::mat4(1.0f);
			M = glm::translate(M, glm::vec3(x, 0.0f, z)); //Compute model matrix
			M = glm::rotate(M, rotangle, glm::vec3(0.0f, 1.0f, 0.0f)); //Compute model matrix
			_fsUtils[i]->x = x;
			_fsUtils[i]->z = z;
			_fsUtils[i]->setM(M);
		}

	}
	
	
	for (int i = 0; i < 8; i++) {
		FilesystemObject* fs = new FilesystemObject("","", 0,0, verticesModel, normalsModel,
			texcoordsModel, vertexCountModel);
		_fsUtils.push_back(fs);
		if (i == 0 || i == 7) {
			_fsUtils[_fsUtils.size() - 1]->_orientation = -1;
		}
		else if (i == 3 || i == 4) {
			_fsUtils[_fsUtils.size() - 1]->_orientation = 1;
		}
		else if (i == 1 || i ==2){
			_fsUtils[_fsUtils.size() - 1]->_orientation = 0;
		}
		else {
			_fsUtils[_fsUtils.size() - 1]->_orientation = -2;

		}

		float rotangle = _fsUtils[_fsUtils.size() - 1]->_orientation * PI / 2;
		glm::mat4 M = glm::mat4(1.0f);
		M = glm::translate(M, glm::vec3(missingX[i], 0.0f, missingZ[i])); //Compute model matrix
		M = glm::rotate(M, rotangle, glm::vec3(0.0f, 1.0f, 0.0f)); //Compute model matrix
		_fsUtils[_fsUtils.size() - 1]->x = missingX[i];
		_fsUtils[_fsUtils.size() - 1]->z = missingZ[i];
		_fsUtils[_fsUtils.size() - 1]->setM(M);

	}

	




	//floor

	float width = /*len * 6.0;//*/_fsEntries.size() *6.0;
	glm::mat4 M = glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(0.0f, -1.0f, width/2));
	M = glm::rotate(M, PI / 2, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::scale(M, glm::vec3(width+5, width+5, width+5));

	_fsFloor = new FilesystemObject("","", 3,0, verticesModel, normalsModel,
		texcoordsModel, vertexCountModel);
	float* temp = new float[_fsFloor->_vertexCount[0]*2];
	for (int i = 0; i < _fsFloor->_vertexCount[0]*2; i++) {
		temp[i] = _fsFloor->_coords[0][i] ? width+5 : 0;
	}
	_fsFloor->_coords[0] = temp;

	_fsFloor->setM(M);


	//stationary text
	M = glm::mat4(1.0);
	TextComposer* tD = new TextComposer(name);
	float txtObsScale = 0.0003f; //text height
	M = glm::translate(M, glm::vec3(0.5, -0.5, 0.6));
	M = glm::scale(M, glm::vec3(txtObsScale, txtObsScale, txtObsScale));
	M = glm::translate(M, glm::vec3(-(tD->_width), 0, 0)); //centered
	_fsText = new FilesystemObject("", "", 4,0, verticesModel, normalsModel,
		texcoordsModel, vertexCountModel);

	_fsText->_textPos = M;
	_fsText->_textData = tD;
	_fsText->_textr[2] = 0;

	//ceiling
	width = /*len * 6.0;//*/_fsEntries.size() * 8.0;
	M = glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(0.0f, 4.0f, width / 2));
	M = glm::rotate(M, -PI / 2, glm::vec3(1.0f, 0.0f, 0.0f));
	M = glm::scale(M, glm::vec3(width + 5, width + 5, width + 5));

	_fsCeil = new FilesystemObject("", "", 5, 0, verticesModel, normalsModel,
		texcoordsModel, vertexCountModel);
	temp = new float[_fsCeil->_vertexCount[0] * 2];
	for (int i = 0; i < _fsCeil->_vertexCount[0] * 2; i++) {
		temp[i] = _fsCeil->_coords[0][i] ? width + 5 : 0;
	}
	_fsCeil->_coords[0] = temp;

	_fsCeil->setM(M);
	


	return 0;
}

void FileManager::LoadObjects() {

	LoadModel("models/door.obj", 0); // 
	LoadModel("models/star.obj", 1); // videos
	LoadModel("models/padlock.obj", 2); //zip
	LoadModel("models/camera.obj", 3); //jpg,pngs,...
	LoadModel("models/headphones.obj", 4);//music
	LoadModel("models/lego.obj", 5); // other
	LoadModel("models/paper_clip.obj", 6); //txt

}


int FileManager::LoadModel(std::string model, int j)
{

	std::vector<float> vvobj;
	std::vector<float> vnobj;
	std::vector<float> vtobj;
	
	objl::Loader Loader;

	// Load .obj File
	bool loadout = Loader.LoadFile(model);

	//int kolor = 0;
	for (int m = 0; m < Loader.LoadedMeshes.size(); m++)
	{

		vvobj.clear(); vnobj.clear(); vtobj.clear();
		objl::Mesh curMesh = Loader.LoadedMeshes[m];
		int obj_vertexcount = curMesh.Vertices.size();


		for (int i = 0; i < obj_vertexcount; i++)
		{
			vvobj.push_back(curMesh.Vertices[i].Position.X);
			vvobj.push_back(curMesh.Vertices[i].Position.Y);
			vvobj.push_back(curMesh.Vertices[i].Position.Z);
			vvobj.push_back(1);
		}
		for (int i = 0; i < obj_vertexcount; i++)
		{
			vnobj.push_back(curMesh.Vertices[i].Normal.X);
			vnobj.push_back(curMesh.Vertices[i].Normal.Y);
			vnobj.push_back(curMesh.Vertices[i].Normal.Z);
			vnobj.push_back(0);
		}
		for (int i = 0; i < obj_vertexcount; i++)
		{
			vtobj.push_back(curMesh.Vertices[i].TextureCoordinate.X);
			vtobj.push_back(curMesh.Vertices[i].TextureCoordinate.Y);
		}
	}
	
	verticesModel[j] = new float[vvobj.size()];
	std::copy(vvobj.begin(), vvobj.end(), verticesModel[j]);
	normalsModel[j] = new float[vnobj.size()];
	std::copy(vnobj.begin(), vnobj.end(), normalsModel[j]);
	texcoordsModel[j] = new float[vtobj.size()];
	std::copy(vtobj.begin(), vtobj.end(), texcoordsModel[j]);
	vertexCountModel[j] = vvobj.size() / 4;


	return 0;
}