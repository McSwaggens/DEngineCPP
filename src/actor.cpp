#include "actor.h"
#include "engine.h"


Actor::Actor ()
{
	// Register the actor with the engine
	Engine::RegisterActor (this);
	
	// Set the ACTOR bitflag in the BaseEngineObject class_id variable
	class_id |= ACTOR;
}

Actor::Actor (Vector position, Vector size)
{
	this->position = position;
	this->size = size;
}
