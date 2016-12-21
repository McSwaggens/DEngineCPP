#pragma once

#include "vector.h"

class Physical
{
private:
	void ApplyGravity ();
public:
	
	Physical ();
	
	float weight;
	Vector velocity;
	
	void CalculatePhysics ();
};