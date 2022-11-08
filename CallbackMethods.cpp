#include "CallbackMethods.h"
#include <stdio.h>

CallbackMethods* CallbackMethods::manager = NULL;

CallbackMethods* CallbackMethods::getInstance()
{
	if (!manager) {
		manager = new CallbackMethods();
	}
	return manager;
}

CallbackMethods::~CallbackMethods()
{

}

void CallbackMethods::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void CallbackMethods::cursor_callback(GLFWwindow* window, double x, double y)
{ 
	printf("cursor_callback %f %f\n", x, y);
}