#include "Model.h"

Model::Model(ColorPoint* vertices, uint32_t c)
{
	points = vertices;
	count = c;
}

Model::~Model()
{

}