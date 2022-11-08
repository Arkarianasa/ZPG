#include "Application.h"

//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

int main(void)
{
	Application* app = Application::getInstance();
	app->draw();
}
