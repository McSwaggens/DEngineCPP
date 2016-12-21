#include "physical.h"
#include "engine.h"


Physical::Physical ()
{
	// Register the physical extension with the engine
	Engine::RegisterPhysical (this);
}