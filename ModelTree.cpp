#include "ModelTree.h"

ModelTree::ModelTree()
{
	count = 92814;
}

void ModelTree::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), tree, GL_STATIC_DRAW);
}
