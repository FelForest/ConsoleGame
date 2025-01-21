#pragma once

#include "Actor/MoveableActor/MoveableActor.h"

class Heart;

class Monster : public MoveableActor
{
	RTTI_DECLARATIONS(Monster, MoveableActor)

public:
	Monster(const Vector2& position, GameLevel* level);

	~Monster();

	const int Gold() { return gold; }

	virtual void MoveOrAttack(Vector2 target) override;

	virtual void Update(float deltaTime);
protected:
	int gold = 0;
};