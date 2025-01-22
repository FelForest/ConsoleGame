#pragma once

#include "Actor/DrawableActor.h"

class GameLevel;
class Monster;

class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)

public:
	Player(Vector2 postion, GameLevel* level);

	~Player();

	void Move();

	void Attack(Monster* other, int damage);

	void Attacked(int damage);

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

public:
	int player_hp = 3;
	int player_damage = 1;
	int player_maxhp = 3;

private:
	GameLevel* reflevel = nullptr;
	bool canMove = true;

private:
	void ProcessMove(Vector2 target);
};