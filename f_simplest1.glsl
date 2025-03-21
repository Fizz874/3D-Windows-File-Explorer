#version 330

out vec4 pixelColor; //Output variable. Almost final pixel color.

uniform sampler2D textureMap0;
uniform sampler2D textureMap1;
uniform float numOfLights;

//Varying variables
in vec4 n;
in vec4 l;
in vec4 v;
in vec2 iTexCoord0;
in vec4 FragPos;
uniform vec4 ViewPosF;
//in float numOfLights;

struct Light {
	vec4 position;
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;

	float constant;
	float linear;
	float quadratic;
};

vec4 ViewPos = ViewPosF;
vec4 norm = normalize(n);
vec4 calculatePointLight(Light light) 
{
	
	
	vec4 lightDir = normalize(light.position - FragPos);
	vec4 viewDir = normalize(ViewPos - FragPos);

	vec4 kd = texture(textureMap0, iTexCoord0);
	vec4 ks = texture(textureMap1, iTexCoord0); 
	vec4 reflectDir = reflect(-lightDir, norm);

	float diff = clamp(dot(norm, lightDir), 0,1);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear*distance + light.quadratic * pow(distance, 2));
	vec4 ambient = attenuation * light.ambient * kd;
	vec4 diffuse = attenuation * light.diffuse * diff * kd;
	vec4 specular = attenuation * light.specular * spec * ks;

	return ambient + diffuse + specular;
}

Light setLight(vec4 position, float amb, float diff, float spec, float cons, float lin, float quad) {
	Light light;
	light.position = position;
	light.ambient = vec4(amb, amb, amb, 1);
	light.diffuse = vec4(diff, diff, diff, 1);
	light.specular = vec4(spec, spec, spec, 1);
	light.constant = cons;
	light.linear = lin;
	light.quadratic = quad;
	return light;
}


/*
void generateLights(float lightNumber,out vec4[60] lightPositions) {
	for (int i = 0; i < int(lightNumber); i++) {
		// i in range corresponding to the lihghtsnumer [0,lightnumber*10] 
		float i_norm = float(i) * 10; // adjust according to the corridor length
		float start_z = -3.0;

		vec4 position = vec4(0.0, 3.0, start_z+i_norm, 1.0); 
		lightPositions[i]  = position;
	}
}
*/
void main(void) {

	float constant = 1.0;
	float linear = 0.09;
	float quadratic = 0.032;
	float amb = 1;
	float diff = 0.9;
	float spec = 0.3;
	
	//vec4[60] lightPositions;
	vec4 tempPixelColor = vec4(0,0,0,1);

	vec4 lightPos;
	//float numOfLights = 4;
	//generateLights(numOfLights,lightPositions);
	for(int i=0;i<int(numOfLights);i++){
		lightPos = vec4(0.0, 3.0, -3 + float(i) * 10, 1.0);
		Light light = setLight(lightPos,amb, diff, spec, constant, linear, quadratic);
		tempPixelColor += calculatePointLight(light);
	}


	
	pixelColor = tempPixelColor;
}
