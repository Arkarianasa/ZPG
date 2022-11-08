#include "RenderedObject.h"

RenderedObject::RenderedObject(Model* m)
{
  mMatrix = glm::mat4(1.0f);
  vMatrix = glm::mat4(1.0f);
  pMatrix = glm::mat4(1.0f);

  model = m;

  GLuint VBO = 0; //vertex buffer object
  glGenBuffers(1, &VBO); // generate the VBO
  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glBufferData(GL_ARRAY_BUFFER, model->count * sizeof(ColorPoint), m->points, GL_STATIC_DRAW);

  this->VAO = 0;
  glGenVertexArrays(1, &this->VAO); //generate the VAO
  glBindVertexArray(this->VAO);			//bind the VAO

  glEnableVertexAttribArray(0); //enable vertex attributes
  glEnableVertexAttribArray(1); //enable vertex attributes

  glBindBuffer(GL_ARRAY_BUFFER, VBO);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (GLvoid*)0);
  glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
}

void RenderedObject::addShader(Shader s)
{
  shader = s;
}

void RenderedObject::rotate(float angle, glm::vec3 axes)
{
  mMatrix *= glm::rotate(glm::mat4(1.0f), angle, axes);
}

void RenderedObject::rotateAroundPoint(float angle, glm::vec3 axes, glm::vec3 vector)
{
  mMatrix *= glm::translate(glm::mat4(1.0f), vector);
  mMatrix *= glm::rotate(glm::mat4(1.0f), angle, axes);
  mMatrix *= glm::translate(glm::mat4(1.0f), -vector);
}

void RenderedObject::translate(float myView)
{
  mMatrix *= glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, myView));
}

void RenderedObject::scale(float s)
{
  mMatrix *= glm::scale(glm::mat4(1.0f), glm::vec3(s));
}

void RenderedObject::draw()
{

  shader.useShaderProgram(mMatrix, vMatrix, pMatrix);

  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLE_FAN, 0, model->count); //mode, first, count
}

RenderedObject::~RenderedObject()
{
}
