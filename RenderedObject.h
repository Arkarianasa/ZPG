#pragma once
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "ColorPoint.h"
#include "Shader.h"
#include "Model.h"

class RenderedObject
{
private:
	Model* model;
	GLuint VAO = 0;
	Shader shader;
	glm::mat4 mMatrix; // transformacni modelova matice

public:
	RenderedObject(Model* m);
	void addShader(Shader s);
	Shader* getShader();
	void draw();
	void rotate(float angle, glm::vec3 axes);
	void rotateAroundPoint(float angle, glm::vec3 axes, glm::vec3 vector);
	void translate(float myView);
	void scale(float s);
	~RenderedObject();

};
