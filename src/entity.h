#pragma once

#include <stdint.h>
#include "engine_types.h"
#include "engine_object.h"

class Entity : virtual public BaseEngineObject
{
public:

//	MEMBER VARIABLES
	uint64_t id;

//	CONSTRUCTOR
	Entity ();

//	MEMBER FUNCTIONS
	void Listen ();

//	VIRTUAL
	
	/* Tick - Called every engine tick so long as it's alive */
	virtual void Tick () { }
	virtual void OnEventCalled (Event event) { }
	virtual void OnKeyPressed (Event event) { }
};