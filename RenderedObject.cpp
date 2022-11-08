#include "RenderedObject.h"

RenderedObject::RenderedObject(Model* m)
{
  mMatrix = glm::mat4(1.0f);

  model = m;

  GLuint VBO = 0; //vertex buffer object
  glGenBuffers(1, &VBO); // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  //glBufferData(GL_ARRAY_BUFFER, model->count * sizeof(ColorPoint), m->points, GL_STATIC_DRAW);
  model->Draw();

  this->VAO = 0;
  glGenVertexArrays(1, &this->VAO); //generate the VAO
  glBindVertexArray(this->VAO);			//bind the VAO

  glEnableVertexAttribArray(0); //enable vertex attributes
  glEnableVertexAttribArray(1); //enable vertex attributes

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0); // x, y, z
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float))); // color / normal
}

void RenderedObject::setColor(glm::vec3 c)
{
  color = c;
}

void RenderedObject::addShader(Shader s)
{
  shader = s;
}

Shader* RenderedObject::getShader()
{
  return &shader;
}

void RenderedObject::rotateObject(float angle, glm::vec3 axes)
{
  mMatrix *= glm::rotate(glm::mat4(1.0f), angle, axes);
}

void RenderedObject::rotateAroundPoint(float angle, glm::vec3 axes, glm::vec3 vector)
{
  mMatrix *= glm::translate(glm::mat4(1.0f), vector);
  mMatrix *= glm::rotate(glm::mat4(1.0f), angle, axes);
  mMatrix *= glm::translate(glm::mat4(1.0f), -vector);
}

void RenderedObject::moveObject(glm::vec3 vector)
{
  mMatrix *= glm::translate(glm::mat4(1.0f), vector);
}

void RenderedObject::scaleObject(float s)
{
  mMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(s));
}

void RenderedObject::draw()
{

  shader.useShaderProgram(mMatrix, color);

  glBindVertexArray(VAO);
  //glDrawArrays(GL_TRIANGLE_FAN, 0, model->count); //mode, first, count
  glDrawArrays(GL_TRIANGLES, 0, model->count); //mode, first, count
}

RenderedObject::~RenderedObject()
{
}
