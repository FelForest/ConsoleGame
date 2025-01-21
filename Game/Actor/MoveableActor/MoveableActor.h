#pragma once

#include "Actor/DrawableActor.h"
#include "Engine/Timer.h"

class GameLevel;
class MoveableActor : public DrawableActor
{
	RTTI_DECLARATIONS(MoveableActor, DrawableActor)

public:
	MoveableActor(GameLevel* level);
	~MoveableActor();

	virtual void MoveOrAttack(Vector2 target);

	//int GetHP();
public:
	const int HP() { return hp; }
	
	void Attack(MoveableActor& other);

	void Attacked(int damage);

protected:

	GameLevel* reflevel = nullptr;

	int hp = 3;

	int damage = 0;
};