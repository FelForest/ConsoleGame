#pragma once

#include "Monster.h"

class Zombie : public Monster
{
	RTTI_DECLARATIONS(Zombie, Monster)

public:
	Zombie(const Vector2& position, GameLevel* level);

	~Zombie();

	virtual void Update(float deltaTime);

	virtual void Move(Vector2 target) override;

	virtual void Draw() override;

	virtual void Attack(int damage) override;

	virtual void Attacked(int damage) override;

protected:
	//virtual void ProcessMove(Vector2 target) override;


private:
	int zombie_hp = 4;
	int zombie_damage = 1;
	int zombie_maxhp = 4;
	int zombie_count = 2;

	bool zombie_can_move = true;
	bool isMove = false;
};