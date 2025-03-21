//#pragma once
#ifndef MYWALL_H_INCLUDED
#define MYWALL_H_INCLUDED


//myCubeVertices -homogenous coordinates of vertices in model space
//myCubeNormals - homogenous normal vectors of faces (per vertex) in model space
//myCubeVertexNormals - homogenous vertex normals in model space
//myCubeTexCoords - texturing coordinates
//myCubeColors - vertex colors
//myCubeC1 - TBN^-1 matrix column
//myCubeC2 - TBN^-1 matrix column
//myCubeC3 - TBN^-1 matrix column

int myWallVertexCount = 6;

float myWallVertices[] = {
	//Wall 1
	1.0f,-1.0f,0.0f,1.0f,
	-1.0f, 1.0f,0.0f,1.0f,
	-1.0f,-1.0f,0.0f,1.0f,

	1.0f,-1.0f,0.0f,1.0f,
	1.0f, 1.0f,0.0f,1.0f,
	-1.0f, 1.0f,0.0f,1.0f


};


float myWallColors[] = {
	//Wall 1
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,

	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f,
	1.0f,0.0f,0.0f,1.0f

};

float myWallNormals[] = {
	//Wall 1
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,

	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f,
	0.0f, 0.0f,-1.0f,0.0f

};

float myWallVertexNormals[] = {
	//Wall 1
	1.0f,-1.0f,-1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f,
	-1.0f,-1.0f,-1.0f,0.0f,

	1.0f,-1.0f,-1.0f,0.0f,
	1.0f, 1.0f,-1.0f,0.0f,
	-1.0f, 1.0f,-1.0f,0.0f


};

float myWallTexCoords[] = {
	//Wall 1
	1.0f,1.0f, 0.0f,0.0f, 0.0f,1.0f,
	1.0f,1.0f, 1.0f,0.0f, 0.0f,0.0f


};

float myWallC1[] = {
	//Wall 1
	1.000000f,-0.000000f,0.000000f,0.000000f,
	1.000000f,-0.000000f,0.000000f,0.000000f,
	1.000000f,-0.000000f,0.000000f,0.000000f,
	1.000000f,-0.000000f,0.000000f,0.000000f,
	1.000000f,-0.000000f,0.000000f,0.000000f,
	1.000000f,-0.000000f,0.000000f,0.000000f

};
float myWallC2[] = {
	//Wall 1
	-0.000000f,-1.000000f,-0.000000f,0.000000f,
	-0.000000f,-1.000000f,-0.000000f,0.000000f,
	-0.000000f,-1.000000f,-0.000000f,0.000000f,
	-0.000000f,-1.000000f,-0.000000f,0.000000f,
	-0.000000f,-1.000000f,-0.000000f,0.000000f,
	-0.000000f,-1.000000f,-0.000000f,0.000000f

};
float myWallC3[] = {
	//Wall 1
	0.000000f,0.000000f,-1.000000f,0.000000f,
	0.000000f,0.000000f,-1.000000f,0.000000f,
	0.000000f,0.000000f,-1.000000f,0.000000f,
	0.000000f,-0.000000f,-1.000000f,0.000000f,
	0.000000f,-0.000000f,-1.000000f,0.000000f,
	0.000000f,-0.000000f,-1.000000f,0.000000f


};



#endif // MYWALL_H_INCLUDED
