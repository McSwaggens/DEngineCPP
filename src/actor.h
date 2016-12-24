#pragma once

#include "engine_object.h"

class Actor : virtual public BaseEngineObject
{
public:

//	MEMBER VARIABLES
	

//	CONSTRUCTOR
	// Not needed for now
	Actor ();

//	MEMBER FUNCTIONS
	

//	VIRTUAl
	
	/* Render - Called only when visible,  */
	virtual void Render () { }
};