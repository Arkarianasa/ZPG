#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "CallbackMethods.h"
#include "Scene.h"

class Render
{
private:
	static Render* renderer;

	static void error_callback(int error, const char* description);
	static void window_focus_callback(GLFWwindow* window, int focused);
	static void window_iconify_callback(GLFWwindow* window, int iconified);
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void button_callback(GLFWwindow* window, int button, int action, int mode);

	GLFWwindow* window;

	Scene* scene;

public:
	static Render* getInstance();
	Render();
	~Render();

	void initialization();
	void setScene(Scene* s);
	void draw();
	void setCallbacks();
};

