#include "Slime.h"

Slime::Slime(Vector2 position, GameLevel* level)
	: Monster(position, level)
{

}

void Slime::MoveOrAttack(Vector2 target)
{
	if (count != 0)
	{
		count--;
		return;
	}

	count = 2;

	Super::MoveOrAttack(target);
}

void Slime::Update(float deltaTime)
{
	// 한 타이밍에만 갱신
	Super::Update(deltaTime);

	if (isUp)
	{
		MoveOrAttack({ position.x - 1, position.y });
		isUp = !isUp;
	}
	else
	{
		MoveOrAttack({ position.x + 1, position.y });
		isUp = !isUp;
	}
}
