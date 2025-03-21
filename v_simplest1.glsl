#version 330

//Uniform variables
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
in vec4 ViewPos;
out vec4 ViewPosF;


//Attributes
in vec4 vertex; //Vertex coordinates in model space
in vec4 normal; //Vertex normal in model space
in vec2 texCoord0;

//Varying variables
out vec4 l;
out vec4 n; // normal 
out vec4 FragPos;
out vec2 iTexCoord0;

void main(void) {

    FragPos = vec4(M * vertex);
    n = normalize(M*normal); 
    ViewPosF = ViewPos;
    iTexCoord0 = texCoord0;

    gl_Position = P * V * M * vertex;

}