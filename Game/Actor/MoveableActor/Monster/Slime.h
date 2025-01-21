#pragma once


#include "Monster.h"

class GameLevel;

class Slime : public Monster
{
	RTTI_DECLARATIONS(Slime, Monster)

public:
	Slime(Vector2 position, GameLevel* level);

	virtual void MoveOrAttack(Vector2 target) override;

	virtual void Update(float deltaTime);

private:
	bool isUp = false;
	int count = 2;
};