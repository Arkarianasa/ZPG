#include "ModelSuziFlat.h"

ModelSuziFlat::ModelSuziFlat()
{
	count = 17424 / 6;
}

void ModelSuziFlat::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), suziFlat, GL_STATIC_DRAW);
}
