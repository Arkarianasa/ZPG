#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::addObject(RenderedObject* object)
{
	objects.push_back(object);
}

void Scene::draw()
{

	for (RenderedObject* o : objects) {
		o->draw();
	}
	objects[0]->rotateAroundPoint((float)0.01, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.5f, 0.0f));

}