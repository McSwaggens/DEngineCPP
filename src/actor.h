#pragma once

#include "engine_object.h"
#include "vector.h"

class Actor : virtual public BaseEngineObject
{
public:

//	MEMBER VARIABLES
	Vector position;
	Vector size;

//	CONSTRUCTOR
	Actor ();
	Actor (Vector position, Vector size);

//	MEMBER FUNCTIONS
	

//	VIRTUAl
	
	/* Render - Called only when visible,  */
	virtual void Render () { }
};
