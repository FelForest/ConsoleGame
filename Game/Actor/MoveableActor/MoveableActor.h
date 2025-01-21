#pragma once

#include "Actor/DrawableActor.h"

class GameLevel;
class MoveableActor : public DrawableActor
{
	RTTI_DECLARATIONS(MoveableActor, DrawableActor)

public:
	MoveableActor();
	~MoveableActor();

	void Move(Vector2 target);

	//int GetHP();
public:
	//int HP = 0;
	
private:

};