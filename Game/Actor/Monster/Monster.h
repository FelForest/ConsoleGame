#pragma once

#include "Actor/DrawableActor.h"
#include "Container/List.h"

class GameLevel;
class Player;


class Monster : public DrawableActor
{
	RTTI_DECLARATIONS(Monster, DrawableActor)

public:
	Monster(Vector2 position, GameLevel* level);
	~Monster();

	virtual void Attacked(int damage);

	virtual void Attack(int damage);

	virtual void Update(float deltaTime);

	virtual void Draw();
protected:
	GameLevel* reflevel = nullptr;

	int monster_hp;
	int monster_maxhp;
	int monster_damage;

	Player* player = nullptr;
	List<Monster*> monsters;

protected:
	virtual void Move(Vector2 target);

};