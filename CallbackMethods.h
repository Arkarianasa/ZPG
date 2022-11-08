#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class CallbackMethods
{
private:
	static CallbackMethods* manager;
public:
	static CallbackMethods* getInstance();
	~CallbackMethods();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_callback(GLFWwindow* window, double x, double y);
	};



