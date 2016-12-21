#include "actor.h"
#include "engine.h"


Actor::Actor ()
{
	// Register the actor with the engine
	Engine::RegisterActor (this);
}