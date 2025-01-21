#pragma once

#include "Actor/MoveableActor/MoveableActor.h"


class Player : public MoveableActor
{
	RTTI_DECLARATIONS(Player, MoveableActor)

public:
	Player(const Vector2& position, GameLevel* level);

	virtual void Update(float deltaTime);

	virtual void Draw();

	void playerMove();

public:
	bool isAttacked = false;
private:
};