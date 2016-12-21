#include "entity.h"
#include "engine.h"


Entity::Entity ()
{
	// Set the ID to an increment of the static uint64_t
	static uint64_t __static_id = 0;
	this->id = __static_id++;
	
	// Register the entity with the engine
	Engine::RegisterEntity (this);
}

void Entity::Listen ()
{
	Engine::event_listener_entities.push_back (this);
}