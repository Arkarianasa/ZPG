#include "CallbackMethods.h"
#include <stdio.h>

#include "Camera.h"

CallbackMethods* CallbackMethods::manager = NULL;

CallbackMethods* CallbackMethods::getInstance()
{
	if (!manager)
  {
		manager = new CallbackMethods();
	}
	return manager;
}

void CallbackMethods::setCamera(Camera* c)
{
  camera = c;
}

CallbackMethods::~CallbackMethods()
{
  
}

void CallbackMethods::window_size_callback(GLFWwindow* window, int width, int height)
{
  printf("resize %d, %d \n", width, height);
  glViewport(0, 0, width, height);
  camera->calculateProjectionMaxtrix(width, height);
}

void CallbackMethods::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);

  if (key == GLFW_KEY_A)
  {
    printf("LEFT\n");
    camera->moveLeft();
  }

  if (key == GLFW_KEY_D)
  {
    printf("RIGHT\n");
    camera->moveRight();
  }

  if (key == GLFW_KEY_W)
  {
    printf("FORWARD\n");
    camera->moveForward();

  }

  if (key == GLFW_KEY_S)
  {
    printf("BACK\n");
    camera->moveBack();
  }

  
  if (key == GLFW_KEY_C)
  {
    camera->setChangeViewStatus(true);
  } 

}

void CallbackMethods::cursor_callback(GLFWwindow* window, double x, double y)
{ 
	printf("cursor_callback %f %f\n", x, y);
  camera->setNewTarget(x, y);

  camera->setChangeViewStatus(false);
}