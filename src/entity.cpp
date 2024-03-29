#include "entity.h"
#include "engine.h"


Entity::Entity ()
{
	// Set the ID to an increment of the static uint64_t
	static uint64_t __static_id = 0;
	this->id = __static_id++;
	
	// Register the entity with the engine
	Engine::RegisterEntity (this);
	
	// Set the ENTITY bitflag in the BaseEngineObject class_id variable
	class_id |= ENTITY;
}

void Entity::Listen ()
{
	Engine::event_listener_entities.push_back (this);
}