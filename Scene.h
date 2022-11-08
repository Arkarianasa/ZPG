#pragma once

#include <vector>
#include "Camera.h"
#include "RenderedObject.h"

class Scene
{
private:
  //Camera* camera;
  std::vector<RenderedObject*> objects;

public:
  Scene();
  ~Scene();

  void addObject(RenderedObject* object);
  void draw();
  //void changeCamera();
  
};