#include "Scene.h"

#include "Camera.h"

Scene::Scene()
{
	camera = new Camera(this);
	//CallbackMethods::getInstance()->setCamera(camera);
}

Scene::~Scene()
{

}

void Scene::addObject(RenderedObject* object)
{
	glm::mat4 vm = camera->getCameraLookAt();

	camera->registerObserver(object->getShader());
	camera->notify();

	objects.push_back(object);
}

void Scene::removeObject(RenderedObject* object)
{
	objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
	camera->removeObserver(object->getShader());
}

void Scene::draw()
{
	CallbackMethods::getInstance()->setCamera(camera);
	for (RenderedObject* o : objects)
	{
		o->draw();
	}
	//objects[0]->rotateAroundPoint((float)0.01, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.5f, 0.0f));
	//objects[2]->rotateAroundPoint((float)-0.01, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 1.f, 0.0f));
}
