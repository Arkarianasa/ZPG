#pragma once
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <glm/ext/matrix_float4x4.hpp>

#include "ShaderLoader.h"
#include "Observer.h"

using namespace std;

class Shader : ShaderLoader, public Observer
{
private:
	GLuint shaderProgram;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

public:

	Shader();
	Shader(const char* vertexFile, const char* fragmentFile);
	~Shader();

	virtual void update(glm::mat4 vMatrix, glm::mat4 pMatrix) override;

	void useShaderProgram(glm::mat4 modelMatrix);
};