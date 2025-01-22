#pragma once

#include "Monster.h"

class Slime : public Monster
{
	RTTI_DECLARATIONS(Slime, Monster)

public:
	Slime(const Vector2& position, GameLevel* level);

	~Slime();

	virtual void Update(float deltaTime);

	virtual void Move(Vector2 target) override;

	virtual void Draw() override;

	virtual void Attack(int damage) override;

protected:
	//virtual void ProcessMove(Vector2 target) override;


private:
	int slime_hp = 2;
	int slime_damage = 1;
	int slime_maxhp = 2;
	int slime_count = 3;

	bool slime_can_move = true;
	bool isUp = true;
};