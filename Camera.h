#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class Camera
{
private:
	glm::vec3 target = { 0, 0, 0 };		// Looks at the origin.
	glm::vec3 eye = { 10, 10, 10 };		// Camera / eye position.
	glm::vec3 up = { 0, 1, 0 };				// Head is up (set to 0, -1, 0 to look upside-down)

	float alpha;
	float phi;

	const float camera_speed = 0.3f;

	void calculateTarget();

public:
	Camera();
  glm::mat4 getCamera(void);

	glm::mat4 projectionMatrix;
};
