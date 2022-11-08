#include "ModelBushes.h"
#include "models/bushes.h"

ModelBushes::ModelBushes()
{
	count = 54210 / 6;
}

void ModelBushes::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), plain, GL_STATIC_DRAW);
}
