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

void Application::draw()
{
	//98, 168, 50 / 30, 130, 29 / 14, 135, 70 / 25, 107, 29 / 109, 122, 21
	glm::vec3 greens[5] = { {98 / 255.0F, 168 / 255.0F, 50 / 255.0F},
													{30 / 255.0F, 130 / 255.0F, 29 / 255.0F},
													{14 / 255.0F, 135 / 255.0F, 70 / 255.0F},
													{25 / 255.0F, 107 / 255.0F, 29 / 255.0F},
													{109 / 255.0F, 122 / 255.0F, 21 / 255.0F} };


	ColorPoint matrix1[] = {
	{ { 0.0f, 0.5f, 0.0f }, { 1, 0, 0 } },
	{ { 0.5f, -0.5f, 0.0f }, { 1, 0, 1 } },
	{ { -0.5f, -0.5f, 0.0f }, { 0, 0, 1 } }
	};

	ColorPoint matrix2[] = {
	{ { .5f, -.5f, 0 }, { 1, 0, 0 } },
	{ { -.5f, -.5f, 0 }, { 1, 0, 1 } },
	{ { -.5f, .5f, 0, }, { 0, 0, 1 } },
	{ { .5f, .5f, 0, }, { 0, 1, 0 } }
	};

	ColorPoint matrix3[] = {
{ { -0.75f, 0.5f, 0.0f }, { 1, 0, 0 } },
{ { -0.5f, -0.5f, 0.0f }, { 1, 0, 1 } },
{ { -1.0f, -0.5f, 0.0f }, { 0, 0, 1 } }
	};

	ColorPoint matrix4[] = {
{ { 0.5f, 0.5f, 0.0f }, { 1, 0, 0 } },
{ { 0.0f, -0.5f, 0.0f }, { 1, 0, 1 } },
{ { 1.0f, -0.5f, 0.0f }, { 0, 0, 1 } }
	};

	Render* renderer = Render::getInstance();
	renderer->initialization();

	Scene scene = Scene();

	Scene scene1 = Scene();
	Scene scene2 = Scene();
	Scene scene3 = Scene();

	ModelSphere* sphereModel = new ModelSphere();
	ModelSuziFlat* suziModel = new ModelSuziFlat();
	ModelTree* treeModel = new ModelTree();
	ModelPlain* plainModel = new ModelPlain();
	ModelBushes* bushesModel = new ModelBushes();
	ModelGift* giftModel = new ModelGift();

	ColorModel* model1 = new ColorModel(matrix1, 3);
	ColorModel* model2 = new ColorModel(matrix2, 4);
	ColorModel* model3 = new ColorModel(matrix3, 3);
	ColorModel* model4 = new ColorModel(matrix4, 3);


	RenderedObject* object1 = new RenderedObject(model1);
	RenderedObject* object2 = new RenderedObject(model2);
	RenderedObject* object3 = new RenderedObject(model3);
	RenderedObject* object4 = new RenderedObject(model4);

	RenderedObject* sphere = new RenderedObject(sphereModel);
	RenderedObject* suzi = new RenderedObject(suziModel);
	RenderedObject* plain = new RenderedObject(plainModel);
	RenderedObject* bushes = new RenderedObject(bushesModel);
	RenderedObject* gift = new RenderedObject(giftModel);

	RenderedObject* orb1 = new RenderedObject(sphereModel);
	RenderedObject* orb2 = new RenderedObject(sphereModel);
	RenderedObject* orb3 = new RenderedObject(sphereModel);
	RenderedObject* orb4 = new RenderedObject(sphereModel);

	RenderedObject* orb = new RenderedObject(sphereModel);

	RenderedObject* tree1 = new RenderedObject(treeModel);

	plain->scaleObject(1000.0);
	plain->moveObject({ 0.0, -0.001, 0.0 });

	sphere->scaleObject(0.5);

	orb1->moveObject({ 2.0, 0.0, 0.0 });
	orb2->moveObject({ 0.0, -2.0, 0.0 });
	orb3->moveObject({ 0.0, 2.0, 0.0 });
	orb4->moveObject({ -2.0, 0.0, 0.0 });

	orb1->setColor({ 1.0, 0.0, 0.0 });
	orb2->setColor({ 1.0, 0.0, 0.0 });
	orb3->setColor({ 1.0, 0.0, 0.0 });
	orb4->setColor({ 1.0, 0.0, 0.0 });

	orb->moveObject({ 0.0, 0.0, 2.0 });

	suzi->moveObject({ 0.0, 0.0, 3.0 });
	suzi->rotateObject(90, glm::vec3(0.0f, 1.0f, 0.0f));

	gift->moveObject({ 3.0, -1.0, 0.0 });
	gift->scaleObject(3.0);
	gift->setColor({ 1.0, 0.0, 1.0 });

	Shader shader0 = Shader("shaders/VertexColor.txt", "shaders/FragmentUniformColor.txt");
	Shader shader1 = Shader("shaders/VertexColor.txt", "shaders/FragmentColor.txt");
	Shader shader2 = Shader("shaders/VertexColor.txt", "shaders/FragmentColorPurple.txt");
	Shader shader3 = Shader("shaders/VertexLambert.txt", "shaders/FragmentLambert.txt");
	Shader shader4 = Shader("shaders/VertexPhong.txt", "shaders/FragmentPhong.txt");

	object1->addShader(shader1);
	object4->addShader(shader2);
	sphere->addShader(shader3);
	suzi->addShader(shader4);
	plain->addShader(shader3);
	gift->addShader(shader4);

	plain->setColor({ 77 / 255.F, 84 / 255.F, 36 / 255.F }); //77, 84, 36

	orb1->addShader(shader4);
	orb2->addShader(shader4);
	orb3->addShader(shader4);
	orb4->addShader(shader4);

	orb->addShader(shader4);

	scene.addObject(object4);
	scene.addObject(object1);
	scene.addObject(sphere);

	scene1.addObject(orb1);
	scene1.addObject(orb2);
	scene1.addObject(orb3);
	scene1.addObject(orb4);

	scene2.addObject(orb);

	scene3.addObject(plain);
	scene3.addObject(suzi);
	scene3.addObject(gift);

	srand((unsigned)time(NULL));
	
	RenderedObject* greenery[200];
	for (int i = 0; i < 200; i++)
	{
		greenery[i] = new RenderedObject(bushesModel);

		float x = (rand() % 51) - 25;
		float y = (rand() % 51) - 25;
		float size = 1.0 + ((rand() % 5));
		float angle = (rand() % 100) / 100;
		int color = (rand() % 5);

		greenery[i]->moveObject({ x, -1.0, y });
		greenery[i]->scaleObject(size);
		greenery[i]->rotateObject(angle, glm::vec3(1.0f, 0.0f, 0.0f));
		greenery[i]->addShader(shader3);
		greenery[i]->setColor(greens[color]);

		scene3.addObject(greenery[i]);
	}

	RenderedObject* forest[80];
	for (int i = 0; i < 80; i++)
	{
		forest[i] = new RenderedObject(treeModel);

		float x = (rand() % 51) - 25;
		float y = (rand() % 51) - 25;
		float size = 1 + ((rand() % 9) - 4) * 0.1;
		float angle = (rand() % 100) / 100;
		int color = (rand() % 5);

		forest[i]->moveObject({ x, -1.0, y });
		forest[i]->scaleObject(size);
		forest[i]->rotateObject(angle, glm::vec3(1.0f, 0.0f, 0.0f));
		forest[i]->addShader(shader3);
		forest[i]->setColor(greens[color]);

		scene3.addObject(forest[i]);
	}

	

	//renderer->setScene(&scene);
	//renderer->setScene(&scene1);
	//renderer->setScene(&scene2);
	renderer->setScene(&scene3);

	renderer->draw();

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