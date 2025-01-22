#pragma once

#include "Actor/DrawableActor.h"
#include "Level/GameLevel.h"
class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public :
	Player(Vector2 postion, GameLevel* level)
	{

	}
};