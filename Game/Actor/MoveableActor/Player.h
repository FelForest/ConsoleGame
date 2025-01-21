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

	virtual void MoveOrAttack(Vector2 target) override;

public:
	bool isAttacked = false;
	bool isCorrect = false;
	bool isMove = false;
private:

	void ProcessMove(const Vector2& newPosition);
};