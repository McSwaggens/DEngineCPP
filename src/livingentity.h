#pragma once

#include "vector.h"
#include <stdint.h>

class LivingEntity
{
public:
// MEMBER VARIABLES
	uint32_t	health;		// Health of the entity.
	bool		is_alive;	// Whether or not the eneity is dead or alive.
	
// MEMBER FUNCTIONS
	virtual void Damage		(uint32_t damage);
	virtual void Attack		(LivingEntity* livingentity, uint32_t damage);
	virtual void Damaged	(LivingEntity* livingentity_attacker, uint32_t damage);
	void AddHealth			(uint32_t health);
	void SetHealth			(uint32_t health);
};