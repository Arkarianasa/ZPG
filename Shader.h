#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/ext/matrix_float4x4.hpp>

#include "ShaderLoader.h"

using namespace std;

class Shader : ShaderLoader
{
private:
	GLuint shaderProgram;

public:
	
	const char* vertexShaderChar =
		"#version 330\n"
		"uniform mat4 modelMatrix;"
		"uniform mat4 viewMatrix;"
		"uniform mat4 projectionMatrix;"
		"layout(location=0) in vec3 in_position;"
		"layout(location=1) in vec3 in_color;"
		"out vec3 color;"
		"void main () {"
		"     gl_Position = modelMatrix * viewMatrix * projectionMatrix * vec4 (in_position, 1.0);"
		"     color = in_color;"
		"}";

	const char* fragmentShaderChar =
		"#version 330\n"
		"out vec4 frag_colour;"
		"in vec3 color;"
		"void main () {"
		"     frag_colour = vec4 (color, 1.0);"
		"}";
	


	Shader();
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	void useShaderProgram(glm::mat4 m, glm::mat4 v, glm::mat4 p);
};