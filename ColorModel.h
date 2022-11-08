#pragma once

#include "Model.h"
#include "ColorPoint.h"

class ColorModel : public Model
{
public:
	ColorPoint* points;
	ColorModel(ColorPoint* vertices, int c);
	void Draw() override;
};

