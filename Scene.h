#pragma once

#include <vector>
#include "Camera.h"
#include "RenderedObject.h"
#include "CallbackMethods.h"

class Camera;

class Scene
{
private:
  Camera* camera;
  std::vector<RenderedObject*> objects;

public:
  Scene();
  ~Scene();

  void addObject(RenderedObject* object);
  void removeObject(RenderedObject* object);
  void draw();
  
};