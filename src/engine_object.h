#pragma once

/*
	
	This class type should be the base of all engine objects,
		such as Entity, Actor, Physical etc...
	
*/

class BaseEngineObject
{
public:
	int class_id = 0;
	virtual int GetClassFlags ()
	{
		return this->class_id;
	}
};