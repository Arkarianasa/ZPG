#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "Render.h"
#include "Shader.h"
#include "RenderedObject.h"
#include "Model.h"
#include "CallbackMethods.h"
#include "Scene.h"


class Application
{
private:
	static Application* app;
	//static void error_callback(int error, const char* description);
	//static void window_focus_callback(GLFWwindow* window, int focused);
	//static void window_iconify_callback(GLFWwindow* window, int iconified);
	//static void window_size_callback(GLFWwindow* window, int width, int height);
	//static void button_callback(GLFWwindow* window, int button, int action, int mode);

	GLFWwindow* window;

public:
	static Application* getInstance();
	~Application();
	void draw();
	//void setCallbacks();
};
