#pragma once
#include <GL/glew.h>
#include <glm/ext/matrix_float4x4.hpp>

class Model
{
public:
	int count;
	virtual void Draw() = 0;
};