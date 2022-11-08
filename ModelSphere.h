#pragma once

#include "Model.h"
#include "models/sphere.h"

class ModelSphere : public Model
{
public:
	ModelSphere();
	void Draw() override;
};

