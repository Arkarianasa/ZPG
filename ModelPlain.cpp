#include "ModelPlain.h"
#include "models/plain.h"

ModelPlain::ModelPlain()
{
	count = 36 / 6;
}

void ModelPlain::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), plain, GL_STATIC_DRAW);
}