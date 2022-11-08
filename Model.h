#pragma once
#include <GL/glew.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <vector>

#include "ColorPoint.h"

class Model
{
public:
	ColorPoint* points;
	uint32_t count;
	Model(ColorPoint* vertices, uint32_t c);
	~Model();
	void loadModel(const char* file);
};

//predelat na abstract a budou dedit dalsi tridy jednotlivych modelu - kulicka, apod.