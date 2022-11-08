#include "Camera.h"

Camera::Camera()
{
  //45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::getCamera(void) {
  return glm::lookAt(eye, eye + target, up);
}

void Camera::calculateTarget(void) {
  target.x = sin(alpha) * cos(phi);
  target.z = sin(alpha) * sin(phi);
  target.y = cos(alpha);
}


