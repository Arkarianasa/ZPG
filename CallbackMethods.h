#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class Camera;

class CallbackMethods
{
private:
	static CallbackMethods* manager;
	Camera* camera;

public:
	static CallbackMethods* getInstance();
	~CallbackMethods();

  void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void cursor_callback(GLFWwindow* window, double x, double y);
	void window_size_callback(GLFWwindow* window, int width, int height);
	void setCamera(Camera* c);
	};



