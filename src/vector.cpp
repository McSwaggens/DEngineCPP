#include "vector.h"

IVector2D Vector2D::ToIVector()
{
	return IVector2D (x, y);
}

Vector2D IVector2D::ToVector()
{
	return Vector2D (x, y);
}
