#pragma once

#include "vector.h"
#include "engine_object.h"

class Physical : virtual public BaseEngineObject
{
private:
	void ApplyGravity ();
public:
	
	Physical ();
	
	float weight;
	Vector velocity;
	
	void CalculatePhysics ();
};