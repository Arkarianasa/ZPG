#include "ModelGift.h"

ModelGift::ModelGift()
{
	count = 66624;
}

void ModelGift::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), gift, GL_STATIC_DRAW);
}