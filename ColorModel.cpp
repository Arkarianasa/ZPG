#include "ColorModel.h"

ColorModel::ColorModel(ColorPoint* vertices, int c)
{
	points = vertices;
	count = c;
}

void ColorModel::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(ColorPoint), points, GL_STATIC_DRAW);
}
