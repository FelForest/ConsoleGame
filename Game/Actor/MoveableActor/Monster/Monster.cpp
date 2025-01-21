#include "Monster.h"
#include "Actor/Heart/Heart.h"

Monster::Monster(const Vector2& position, GameLevel* level)
	: MoveableActor(level)
{
    this->image = image;
}

Monster::~Monster()
{
}

void Monster::MoveOrAttack(Vector2 target)
{
	Super::MoveOrAttack(target);
}

void Monster::Update(float deltaTime)
{
    if (!Heart::Get().MISS())
    {
        return;
    }

    Super::Update(deltaTime);
}