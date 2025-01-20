#pragma once

#include "Actor/Actor.h"
#include "Container/List.h"
class HeartPart;

class Heart : public Actor
{
	RTTI_DECLARATIONS(Heart, Actor)

public:
	Heart();
	~Heart();


private:
	List<HeartPart*> heartParts;

	bool isBeat = false;



};