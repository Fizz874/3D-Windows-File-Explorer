#define GLM_FORCE_RADIANS

#include <stdlib.h>
#include <stdio.h>

#include "lodepng.h"
#include "shaderprogram.h"


#include <windows.h>

#include "FileManager.h"


using namespace std;
using namespace glm;

float speed_x = 0; //angular speed in radians
float speed_y = 0; //angular speed in radians
float ws_val = 0;

int enter = 0;

int test = 0;

//float pos_z = -3;
float aspectRatio = 1;
//glm::vec3 observer_vect = glm::vec3(2.0f, 1.0f, -3.0f);
ShaderProgram* sp; //Pointer to the shader program
FileManager* fmanager;



float angle_x = 0; //current rotation angle of the object, x axis
float angle_y = 0; //current rotation angle of the object, y axis



vec3 pos = vec3(0, 1, 0);
vec3 dir = vec3(0, 0, 1);
vec3 newPos;

GLuint tex[12];

int upPressed = 0;
int downPressed = 0;


//Error processing callback procedure
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_LEFT) speed_y = 1.25;
		if (key == GLFW_KEY_RIGHT) speed_y = -1.25;
		if (key == GLFW_KEY_W) speed_x = -1;
		if (key == GLFW_KEY_S) speed_x = 1;
		if (key == GLFW_KEY_UP) {
			ws_val = 4;
			upPressed = 1;
		}
		if (key == GLFW_KEY_DOWN) {
			ws_val = -4;
			downPressed = 1;
		}
		if (key == GLFW_KEY_ENTER) enter = 1;
		if (key == GLFW_KEY_ESCAPE) glfwSetWindowShouldClose(window, GL_TRUE);
		if (key == GLFW_KEY_LEFT_SHIFT) ws_val = 10;

	}
	if (action == GLFW_RELEASE) {
		if (key == GLFW_KEY_LEFT) speed_y = 0;
		if (key == GLFW_KEY_RIGHT) speed_y = 0;

		if (key == GLFW_KEY_UP) {
			ws_val = 0;
			upPressed = 0;
		}
		if (key == GLFW_KEY_DOWN) {
			ws_val = 0;
			downPressed = 0;
		}

		if (key == GLFW_KEY_W) speed_x = 0;
		if (key == GLFW_KEY_S) speed_x = 0;

		if (key == GLFW_KEY_ENTER) enter = 0;
		if (key == GLFW_KEY_LEFT_SHIFT) {
			if (upPressed) {
				ws_val = 4;
			}
			else if (downPressed) {
				ws_val = -4;
			}
			else {
				ws_val = 0;
			}
		}
	}
}

void windowResizeCallback(GLFWwindow* window, int width, int height) {
	if (height == 0) return;
	aspectRatio = (float)width / (float)height;
	glViewport(0, 0, width, height);
}

GLuint readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);

	//Load into computer's memory
	std::vector<unsigned char> image;   //Allocate a vector for image storage
	unsigned width, height;   //Variables for image size
	//Read image
	unsigned error = lodepng::decode(image, width, height, filename);

	//Import into graphics card's memory
	glGenTextures(1, &tex); //Initialize one handle
	glBindTexture(GL_TEXTURE_2D, tex); //Activate the handle
	//Import image into graphics card's memory associated with the handle
	glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return tex;
}

//Initialization code procedure
void initOpenGLProgram(GLFWwindow* window) {
	//************Place any code here that needs to be executed once, at the program start************
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window, windowResizeCallback);
	glfwSetKeyCallback(window, keyCallback);
	sp = new ShaderProgram("v_simplest1.glsl", NULL, "f_simplest1.glsl");
	tex[0] = readTexture("textures/trawa1.png");
	tex[1] = readTexture("textures/wood_cabinet_worn_long_diff_2k.png");
	tex[2] = readTexture(/*"bricks.png"*/"textures/rustic_stone_wall_diff_2k.png");
	tex[3] = readTexture("textures/monastery_stone_floor_diff_2k.png"/* "stone-wall.png"*/);
	tex[4] = readTexture("models/wooden_door.png");//door texture
	tex[5] = readTexture("textures/gold2.png");//star texture
	tex[6] = readTexture("textures/metal6.png");//lock texture
	tex[7] = readTexture("textures/metal5.png");//camera texture
	tex[8] = readTexture("textures/headphones.png");//headphones texture
	tex[9] = readTexture("textures/Plastic-Textures.png");//lego texture
	tex[10] = readTexture("models/paper_clip_metal.png");//paperclip texture
}

//Release resources allocated by the program
void freeOpenGLProgram(GLFWwindow* window) {
	//************Place any code here that needs to be executed once, after the main loop ends************
	delete sp;
}


void printVec3(glm::vec3 vec) { // print player's position
	printf("x: %f y: %f z: %f\n", vec.x, vec.y, vec.z);
}

void printVec4(glm::vec4 vec) {
	printf("[0]: %f [1]: %f [2]: %f [3]: %f\n", vec[0], vec[1], vec[2], vec[3]);
}




void draw(glm::mat4 M, int texNum, float* vertices, float* coords, float* normals, int count) {

	glm::mat4 W = M;

	

	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(W));

	glEnableVertexAttribArray(sp->a("vertex")); //Enable sending data to the attribute vertex
	glVertexAttribPointer(sp->a("vertex"), 4, GL_FLOAT, false, 0, vertices ); //Specify source of the data for the attribute vertex

	glEnableVertexAttribArray(sp->a("texCoord0")); //Enable sending data to the attribute texCoord0
	glVertexAttribPointer(sp->a("texCoord0"), 2, GL_FLOAT, false, 0, coords); //Specify source of the data for the attribute texCoord0

	glEnableVertexAttribArray(sp->a("normal")); //Enable sending data to the attribute color
	glVertexAttribPointer(sp->a("normal"), 4, GL_FLOAT, false, 0, normals);


	glUniform1i(sp->u("textureMap0"), 0); // Associate sampler textureMap0 with the 0-th texturing unit
	glActiveTexture(GL_TEXTURE0); //Assign texture tex0 to the 0-th texturing unit
	glBindTexture(GL_TEXTURE_2D, tex[texNum]);

	glDrawArrays(GL_TRIANGLES, 0, count); //Draw the object

	glDisableVertexAttribArray(sp->a("vertex")); //Disable sending data to the attribute vertex
	glDisableVertexAttribArray(sp->a("texCoord0")); //Disable sending data to the attribute texCoord0
	glDisableVertexAttribArray(sp->a("normal")); //Disable sending data to the attribute normal

}



void drawFsO(FilesystemObject* fs) {

	for (int i = 0; i < fs->wallSegments.size(); i++) {

		draw(fs->wallSegments[i], fs->_textr[0], fs->_vertices[0], fs->_coords[0], fs->_normals[0], fs->_vertexCount[0]);


	}

	if (fs->_type == 1  || fs -> _type == 2 ) {

		for (int i = 0; i < fs->objSegments.size(); i++) {

			draw(fs->objSegments[i], fs->_textr[1], fs->_vertices[1], fs->_coords[1], fs->_normals[1], fs->_vertexCount[1]);

		}

		draw(fs->_textPos, fs->_textr[2], fs->_textData->_vertices0, fs->_textData->_coords, fs->_textData->_normals, fs->_textData->_vertexCount);


	}
	if (fs->_type == 4) {
		
		mat4 M = glm::translate(mat4(1.0f), pos);
		M = rotate(M, angle_y, vec3(0, 1, 0)); 
		M = rotate(M, angle_x, vec3(1, 0, 0));

		draw(M*fs->_textPos, fs->_textr[2], fs->_textData->_vertices0, fs->_textData->_coords, fs->_textData->_normals, fs->_textData->_vertexCount);

	}

}



glm::vec3 getTranslationFromMatrix(const glm::mat4& matrix) {
	return glm::vec3(matrix[3]); // returns the translation part of the matrix
}

glm::vec3 getScaleFromMatrix(const glm::mat4& matrix) {
	glm::vec3 scale;
	scale.x = glm::length(glm::vec3(matrix[0]));
	scale.y = glm::length(glm::vec3(matrix[1]));
	scale.z = glm::length(glm::vec3(matrix[2]));
	return scale;
}

glm::vec4 getBoundingBox(glm::vec3 cubePos, glm::vec3 cubeScale) {
	glm::vec4 boundingBox = glm::vec4(cubePos.x  - cubeScale.x, cubePos.x  + cubeScale.x, cubePos.z - cubeScale.z, cubePos.z + cubeScale.z);
	return boundingBox;
}


void updateBoundB(vec4 &model, mat4& part) {
	vec4 temp = getBoundingBox(getTranslationFromMatrix(part), getScaleFromMatrix(part));
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 1) {
			if (temp[i] > model[i]) {
				model[i] = temp[i];
			}
		}
		else {
			if (temp[i] < model[i]) {
				model[i] = temp[i];
			}
		}
	}
}



//Drawing procedure
void drawScene(GLFWwindow* window) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	sp->use();//activate shading program
	//glm::vec4 numOfLights = glm::vec4(10.0,10.0,10.0,10.0); // number of lights


	glm::mat4 V = glm::lookAt(
		pos,
		pos + dir,
		glm::vec3(0.0f, 1.0f, 0.0f)); //compute view matrix
	glm::mat4 P = glm::perspective(90.0f * PI / 180.0f, 1.0f, 0.05f, 100.0f); //compute projection matrix

	//Send parameters to graphics card
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	float num = 2*(fmanager->_fsEntries.size() - 2) / 5 +2;
	
	glUniform1f(sp->u("numOfLights"),num); // _fsEntries/2 -1 )* 4 +2  /5  = 2 * _fsEntries -2 )/5 
	//float x=0, z = 0;
	for (int i = 0; i < fmanager->_fsEntries.size(); i++)
	{

		FilesystemObject* fs = fmanager->_fsEntries[i];
		drawFsO(fs);
		
	}

	
	for (int i = 0; i < fmanager->_fsUtils.size(); i++)
	{

		FilesystemObject* fs = fmanager->_fsUtils[i];
		drawFsO(fs);

	}

	drawFsO(fmanager->_fsFloor);

	drawFsO(fmanager->_fsCeil); //temp

	drawFsO(fmanager->_fsText);

	glUniform4f(sp->u("ViewPos"), pos.x, pos.y, pos.z, 1.0f);


	glfwSwapBuffers(window); //Copy back buffer to front buffer
}



bool checkBounds() {

	for (int i = 0; i < fmanager->_fsEntries.size(); i++) {  
		FilesystemObject* fs = fmanager->_fsEntries[i];
		if (newPos.x >= fs->bounds[0] && newPos.x <= fs->bounds[1] &&
			newPos.z >= fs->bounds[2] && newPos.z <= fs->bounds[3]) {
			return false;
		}
	}
	for (int i = 0; i < fmanager->_fsUtils.size(); i++) { // utils are 
		FilesystemObject* fs = fmanager->_fsUtils[i];
		if (newPos.x >= fs->bounds[0] && newPos.x <= fs->bounds[1] &&
			newPos.z >= fs->bounds[2] && newPos.z <= fs->bounds[3]) {
			return false;
		}
	}
	return true;
}

bool checkPressed() {

	for (int i = 0; i < fmanager->_fsEntries.size(); i++) {
		FilesystemObject* fs = fmanager->_fsEntries[i];
		if (newPos.x >= fs->presses[0] && newPos.x <= fs->presses[1] &&
			newPos.z >= fs->presses[2] && newPos.z <= fs->presses[3]) {
			fs->SpinObj(1);

			if (enter) {
				if (fs->_type == 1) {
					pos = vec3(0, 1, 0);
					angle_x = 0;
					angle_y = 0;
					fmanager->Prepare(fs->_path);
					enter = false;
				}
				else if (fs->_type == 2) {

						enter = false;

						ShellExecuteA(0, 0, fs->_path.c_str(), 0, 0, SW_SHOW);

				}
			}

		}
		else if (fs->rotationCnt > 1) {
			fs->SpinObj(0);
		}
	}

	return false;
}


int main(void)
{

	GLFWwindow* window; //Pointer to object that represents the application window

	glfwSetErrorCallback(error_callback);//Register error processing callback procedure

	if (!glfwInit()) { //Initialize GLFW library
		fprintf(stderr, "Can't initialize GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(600, 600, "OpenGL", NULL, NULL);  //Create a window 500pxx500px titled "OpenGL" and an OpenGL context associated with it.

	if (!window) //If no window is opened then close the program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Since this moment OpenGL context corresponding to the window is active and all OpenGL calls will refer to this context.
	glfwSwapInterval(1); //During vsync wait for the first refresh

	GLenum err;
	if ((err = glewInit()) != GLEW_OK) { //Initialize GLEW library
		fprintf(stderr, "Can't initialize GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Call initialization procedure
	fmanager = new FileManager();
	fmanager->LoadObjects();
	
	std::string initPath = "C:\\Users\\filip\\Documents\\Filip"; //Place for the path to start folder (with "\\" instead of "\")
	initPath = initPath.replace(initPath.find("\\"), 1, "/");


	//cout << initPath << endl;

	fmanager->Prepare(initPath );

	
	glfwSetTime(0); //Zero the timer
	//Main application loop
	while (!glfwWindowShouldClose(window)) //As long as the window shouldnt be closed yet...
	{
		angle_x += speed_x * glfwGetTime(); //Add angle by which the object was rotated in the previous iteration
		angle_y += speed_y * glfwGetTime(); //Add angle by which the object was rotated in the previous iteration

		mat4 Mc = rotate(mat4(1.0f), angle_y, vec3(0, 1, 0)); //Wylicz macierz rotacji dla obiektu wokó³ osi Y 
		Mc = rotate(Mc, angle_x, vec3(1, 0, 0));
		vec4 dir_ = Mc * vec4(0, 0, 1, 0); //Pomnó¿ wektor kierunku przez macierz rotacji aby uzyskaæ nowy wektor kierunku
		dir = vec3(dir_); //Przypisz nowy wektor kierunku do zmiennej dir

		vec3 mdir = normalize(vec3(dir.x, 0, dir.z)); //Wylicz wektor kierunku ruchu aby by³ równoleg³y do p³aszczyzny pod³ogi
		newPos = pos;
		newPos += ws_val* (float)glfwGetTime() * mdir; 
		
		if (checkBounds()) {
			pos = newPos;
		}

		checkPressed();
		
		glfwSetTime(0); //Zero the timer
		drawScene(window); //Execute drawing procedure
		glfwPollEvents(); //Process callback procedures corresponding to the events that took place up to now
	}
	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Delete OpenGL context and the window.
	glfwTerminate(); //Free GLFW resources
	exit(EXIT_SUCCESS);
}

