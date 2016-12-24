#include "physical.h"
#include "engine.h"


Physical::Physical ()
{
	// Register the physical extension with the engine
	Engine::RegisterPhysical (this);
	
	// Set the PHYSICAL bitflag in the BaseEngineObject class_id variable
	class_id |= PHYSICAL;
}