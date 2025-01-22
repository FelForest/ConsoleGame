#pragma once


#include "Actor/DrawableActor.h"

class Ground : public DrawableActor
{
	RTTI_DECLARATIONS(Ground , DrawableActor)

public:
	Ground(Vector2 position);


};