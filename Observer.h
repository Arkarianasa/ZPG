#pragma once

class Observer
{
public:
  virtual void update(glm::mat4 vMatrix, glm::mat4 pMatrix) = 0;
};
