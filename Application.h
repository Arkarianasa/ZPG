#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

#include "Render.h"
#include "Shader.h"
#include "RenderedObject.h"
#include "CallbackMethods.h"
#include "Scene.h"

#include "Model.h"
#include "ColorModel.h"
#include "ModelSphere.h"
#include "ModelSuziFlat.h"
#include "ModelTree.h"
#include "ModelPlain.h"
#include "ModelBushes.h"
#include "ModelGift.h"

class Application
{
private:
	static Application* app;

	GLFWwindow* window;

public:
	static Application* getInstance();
	~Application();
	void draw();
};
