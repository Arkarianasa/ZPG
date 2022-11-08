#include "Camera.h"
#include "Scene.h"

Camera::Camera(Scene* s)
{
  scene = s;

  //45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
  projectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
  
  calculateViewMatrix();
}

void Camera::registerObserver(Observer* observer)
{
  observers.push_back(observer);
}

void Camera::removeObserver(Observer* observer)
{
  observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Camera::notify()
{
  for (Observer* observer : observers)
  {
    calculateViewMatrix();
    observer->update(viewMatrix, projectionMatrix);
  }
}

glm::mat4 Camera::getCameraLookAt(void)
{
  return glm::lookAt(eye, (eye + target), up);
}

void Camera::calculateViewMatrix()
{
  viewMatrix = glm::lookAt(eye, (eye + target), up);
}

void Camera::moveLeft()
{
  eye -= (glm::normalize(glm::cross(target, up)) * cameraSpeed);
  notify();
  printf("LEFT\n");
}

void Camera::moveRight()
{
  eye += (glm::normalize(glm::cross(target, up)) * cameraSpeed);
  notify();
  printf("RIGHT\n");
}

void Camera::moveForward()
{
  eye += (glm::normalize(target) * cameraSpeed);
  notify();
  printf("FORWARD\n");
}

void Camera::moveBack()
{
  eye -= (glm::normalize(target) * cameraSpeed);
  notify();
  printf("BACK\n");
}

void Camera::calculateTarget(void)
{
  target.x = sin(alpha) * cos(phi);
  target.z = sin(alpha) * sin(phi);
  target.y = cos(alpha);
}

void Camera::setChangeViewStatus(bool status)
{
  changeViewStatus = status;
}

void Camera::setNewTarget(double mouseXPos, double mouseYPos)
{
  if (changeViewStatus == true)
  {
    if (oldMouseXPos == 0)
      oldMouseXPos = mouseXPos;
    if (oldMouseYPos == 0)
      oldMouseYPos = mouseYPos;
    double x = oldMouseXPos - mouseXPos;
    double y = oldMouseYPos - mouseYPos;

    

    //phi += x * mouseSpeed;
    //alpha += y * mouseSpeed;

    //printf("x: %f y: %f\nphi: %f alpha: %f\n", x, y, glm::degrees(phi), glm::degrees(alpha));
    

    
    if (x > 0) {
      phi -= mouseSpeed;
    }
    else if (x < 0) {
      phi += mouseSpeed;
    }

    if (y > 0 && alpha > glm::radians(1.0)) {
      alpha -= mouseSpeed;
    }
    else if (y < 0 && alpha < glm::radians(179.0)) {
      alpha += mouseSpeed;
    }
    
    calculateTarget();
  }

  oldMouseXPos = mouseXPos;
  oldMouseYPos = mouseYPos;

  notify();
}

void Camera::calculateProjectionMaxtrix(int width, int height)
{
  projectionMatrix = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
  notify();
}


