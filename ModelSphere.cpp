#include "ModelSphere.h"

ModelSphere::ModelSphere()
{
	count = (17280 / 6);

	/*points = new ColorPoint [(17280 / 6)];

	int counter = 0;

	for (int i = 0; i < count; i += 6)
	{
		points[counter++] = ColorPoint{ {sphere[i + 0], sphere[i + 1], sphere[i + 2]}, {sphere[i + 3], sphere[i + 4], sphere[i + 5]} };
	} */
}

void ModelSphere::Draw()
{
	glBufferData(GL_ARRAY_BUFFER, count * 6 * sizeof(float), sphere, GL_STATIC_DRAW);
}
