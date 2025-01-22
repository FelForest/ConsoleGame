#pragma once

#include "Actor/DrawableActor.h"
#include "Container/List.h"

class GameLevel;
class Player;


class Monster : public DrawableActor
{
	RTTI_DECLARATIONS(Monster, DrawableActor)

	friend class GameLevel;
public:
	Monster(Vector2 position, GameLevel* level);
	Monster();
	~Monster();

	virtual void Attacked(int damage);

	virtual void Attack(int damage);

	virtual void Update(float deltaTime);

	virtual void Draw();

	int MonsterCount = 0;
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