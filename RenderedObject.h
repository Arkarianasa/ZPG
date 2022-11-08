#pragma once
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Shader.h"
#include "Model.h"

class RenderedObject
{
private:
	Model* model;
	GLuint VAO = 0;
	Shader shader;
	glm::mat4 mMatrix; // transformacni modelova matice
	glm::vec3 color = { 0.0, 1.0, 0.0 }; // default BLUE COLOR

public:
	RenderedObject(Model* m);
	void addShader(Shader s);
	void setColor(glm::vec3 c);
	Shader* getShader();
	void draw();
	void rotateObject(float angle, glm::vec3 axes);
	void rotateAroundPoint(float angle, glm::vec3 axes, glm::vec3 vector);
	void moveObject(glm::vec3 vector);
	void scaleObject(float s);
	~RenderedObject();

};
