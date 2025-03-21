#ifndef MYCUBE_H_INCLUDED
#define MYCUBE_H_INCLUDED
int myCubeVertexCount = 72;
float myCubeVertices[] = {
//Floor face
0.0f, 0.0f, 0.0f, 1.0f,
2.0f, 0.0f, 0.0f, 1.0f,
2.0f, 0.0f, 5.0f, 1.0f,
0.0f, 0.0f, 0.0f, 1.0f,
2.0f, 0.0f, 5.0f, 1.0f,
0.0f, 0.0f, 5.0f, 1.0f,
//Left wall
2.0f, 0.0f, 0.0f, 1.0f,
2.0f, 1.0f, 0.0f, 1.0f,
2.0f, 1.0f, 5.0f, 1.0f,
2.0f, 0.0f, 0.0f, 1.0f,
2.0f, 1.0f, 5.0f, 1.0f,
2.0f, 0.0f, 5.0f, 1.0f,
//Right wall
0.0f, 0.0f, 0.0f, 1.0f,
0.0f, 0.0f, 5.0f, 1.0f,
0.0f, 1.0f, 5.0f, 1.0f,
0.0f, 0.0f, 0.0f, 1.0f,
0.0f, 1.0f, 5.0f, 1.0f,
0.0f, 1.0f, 0.0f, 1.0f,
//Floor face
2.0f, 0.0f, 7.0f, 1.0f,
4.0f, 0.0f, 7.0f, 1.0f,
4.0f, 0.0f, 5.0f, 1.0f,
2.0f, 0.0f, 7.0f, 1.0f,
4.0f, 0.0f, 5.0f, 1.0f,
2.0f, 0.0f, 5.0f, 1.0f,
//Left wall
4.0f, 0.0f, 7.0f, 1.0f,
4.0f, 1.0f, 7.0f, 1.0f,
4.0f, 1.0f, 5.0f, 1.0f,
4.0f, 0.0f, 7.0f, 1.0f,
4.0f, 1.0f, 5.0f, 1.0f,
4.0f, 0.0f, 5.0f, 1.0f,
//Right wall
2.0f, 0.0f, 7.0f, 1.0f,
2.0f, 0.0f, 5.0f, 1.0f,
2.0f, 1.0f, 5.0f, 1.0f,
2.0f, 0.0f, 7.0f, 1.0f,
2.0f, 1.0f, 5.0f, 1.0f,
2.0f, 1.0f, 7.0f, 1.0f,

};
float myCubeNormals[] = {
//Floor face normals
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
//Left wall normals
-1.0f, 0.0f, 1.0f, 0.0f,
-1.0f, 0.0f, 1.0f, 0.0f,
-1.0f, 0.0f, 1.0f, 0.0f,
-1.0f, 0.0f, 1.0f, 0.0f,
-1.0f, 0.0f, 1.0f, 0.0f,
-1.0f, 0.0f, 1.0f, 0.0f,
//Right wall normals
1.0f, 0.0f, -1.0f, 0.0f,
1.0f, 0.0f, -1.0f, 0.0f,
1.0f, 0.0f, -1.0f, 0.0f,
1.0f, 0.0f, -1.0f, 0.0f,
1.0f, 0.0f, -1.0f, 0.0f,
1.0f, 0.0f, -1.0f, 0.0f,
//Floor face normals
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
0.0f, 1.0f, 0.0f, 0.0f,
//Left wall normals
1.0f, 0.0f, 1.0f, 0.0f,
1.0f, 0.0f, 1.0f, 0.0f,
1.0f, 0.0f, 1.0f, 0.0f,
1.0f, 0.0f, 1.0f, 0.0f,
1.0f, 0.0f, 1.0f, 0.0f,
1.0f, 0.0f, 1.0f, 0.0f,
//Right wall normals
-1.0f, 0.0f, -1.0f, 0.0f,
-1.0f, 0.0f, -1.0f, 0.0f,
-1.0f, 0.0f, -1.0f, 0.0f,
-1.0f, 0.0f, -1.0f, 0.0f,
-1.0f, 0.0f, -1.0f, 0.0f,
-1.0f, 0.0f, -1.0f, 0.0f,

};
float myCubeTexCoords[] = {
//Floor face texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
//Left wall texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
//Right wall texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
//Floor face texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
//Left wall texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,
//Right wall texture coords
0.0f, 0.0f,
1.0f, 0.0f,
1.0f, 1.0f,
0.0f, 0.0f,
1.0f, 1.0f,
0.0f, 1.0f,

};
#endif // MYCUBE_H_INCLUDED
