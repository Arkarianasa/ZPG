#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Subject.h"
#include "Observer.h"

#include <iostream>

#include <algorithm>
#include <vector>

class Scene;

class Camera : public Subject
{
private:
	glm::vec3 target = { 0, 0, -10 };		// Looks at the origin: eye + target
	glm::vec3 eye = { 0, 0, 10 };				// Camera / eye position.
	glm::vec3 up = { 0, 1, 0 };					// Head is up (set to 0, -1, 0 to look upside-down)

	Scene* scene = NULL;
	std::vector<Observer*> observers;

	float alpha = glm::radians(79.99);
	float phi = glm::radians(269.99);

	const float cameraSpeed = 0.3f;
	const float mouseSpeed = 0.05;

	double oldMouseXPos = 0;
	double oldMouseYPos = 0;

	bool changeViewStatus = false;

	glm::mat4 projectionMatrix;
	glm::mat4 viewMatrix;

	void calculateTarget();
	void calculateViewMatrix();

public:
	Camera(Scene* s);

  glm::mat4 getCameraLookAt(void);

	void moveLeft();
	void moveRight();
	void moveForward();
	void moveBack();

	void setNewTarget(double mouseXPos, double mouseYPos);

	void calculateProjectionMaxtrix(int width, int height);

	void registerObserver(Observer* observer) override;
	void removeObserver(Observer* observer) override;
	void notify() override;

	void setChangeViewStatus(bool status);

};
