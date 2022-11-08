#include "Application.h"

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

Application* Application::app = NULL;
/*
void Application::error_callback(int error, const char* description) { fputs(description, stderr); }

void Application::window_focus_callback(GLFWwindow* window, int focused) { printf("window_focus_callback \n"); }

void Application::window_iconify_callback(GLFWwindow* window, int iconified) { printf("window_iconify_callback \n"); }

void Application::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Application::button_callback(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}
*/

void Application::draw() {
	/*
	//GLM test

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 100.0f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(10, 10, 10), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
	);
	
	//glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	
	//inicializace konkretni verze
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	
	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);
	

	// Sets the key callback
	setCallbacks();

	*/
	
	Render* renderer = Render::getInstance();
	renderer->initialization();
	
	Scene scene = Scene();

	ColorPoint matrix1[] = {
	{ { 0.0f, 0.5f, 0.0f }, { 1, 0, 0, 1 } },
	{ { 0.5f, -0.5f, 0.0f }, { 1, 0, 1, 1 } },
	{ { -0.5f, -0.5f, 0.0f }, { 0, 0, 1, 1 } }
	};
	
	ColorPoint matrix2[] = {
	{ { .5f, -.5f, 0 }, { 1, 0, 0, 1 } },
	{ { -.5f, -.5f, 0 }, { 1, 0,1, 1 } },
	{ { -.5f, .5f, 0, }, { 0, 0, 1, 1 } },
	{ { .5f, .5f, 0, }, { 0, 1, 0, 1 } }
	};

	ColorPoint matrix3[] = {
{ { -0.75f, 0.5f, 0.0f }, { 1, 0, 0, 1 } },
{ { -0.5f, -0.5f, 0.0f }, { 1, 0, 1, 1 } },
{ { -1.0f, -0.5f, 0.0f }, { 0, 0, 1, 1 } }
	};

	ColorPoint matrix4[] = {
{ { 0.5f, 0.5f, 0.0f }, { 1, 0, 0, 1 } },
{ { 0.0f, -0.5f, 0.0f }, { 1, 0, 1, 1 } },
{ { 1.0f, -0.5f, 0.0f }, { 0, 0, 1, 1 } }
	};

	Model* model1 = new Model(matrix1, 3);
	Model* model2 = new Model(matrix2, 4);
	Model* model3 = new Model(matrix3, 3);
	Model* model4 = new Model(matrix4, 3);


	RenderedObject* object1 = new RenderedObject(model1);
	RenderedObject* object2 = new RenderedObject(model2);
	RenderedObject* object3 = new RenderedObject(model3);
	RenderedObject* object4 = new RenderedObject(model4);

	//Shader shader1 = Shader();
	Shader shader1 = Shader("Vertex.txt", "Fragment.txt");
	
	Shader shader2 = Shader("Vertex.txt", "FragmentPurple.txt");
	
	object1->addShader(shader1);
	object4->addShader(shader2);

	scene.addObject(object4);
	scene.addObject(object1);

	renderer->setScene(&scene);
	renderer->draw();

	/*
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//object2->draw();

		object1->draw();
		object1->rotateAroundPoint( (float) 0.01, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.5f, 0.0f));

		//object3->draw();

		//object4->draw();
		//object4->rotate(0.01, glm::vec3(0.0f, 1.0f, 0.0f));
		//object4->rotate(0.01, glm::vec3(0.0f, 0.0f, 1.0f));
		//object4->scale(0.999);
		
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
	*/
}


Application* Application::getInstance()
{
	if (!app) {
		app = new Application();
	}
	return app;
}

Application::~Application()
{
}

/*
void Application::setCallbacks()
{
	glfwSetMouseButtonCallback(window, button_callback);

	glfwSetWindowFocusCallback(window, window_focus_callback);

	glfwSetWindowIconifyCallback(window, window_iconify_callback);

	glfwSetWindowSizeCallback(window, window_size_callback);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mode) -> void {
				CallbackMethods::getInstance()->key_callback(window, key, scancode, action, mode);
		});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double mouseXPos, double mouseYPos) -> void {
			CallbackMethods::getInstance()->cursor_callback(window, mouseXPos, mouseYPos);
		});
}
*/