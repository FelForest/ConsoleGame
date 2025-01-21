#include "MoveableActor.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"
#include "../Heart/Heart.h"
#include "../MoveableActor/Monster/Monster.h"

MoveableActor::MoveableActor(GameLevel* level)
{
    reflevel = level;
}

MoveableActor::~MoveableActor()
{
}



void MoveableActor::MoveOrAttack(Vector2 target)
{
    // Move
    if (reflevel->CheckCanMove(target))
    {
        position = target;
        return;
    }

    const size_t& typeId = TypeIdInstance();

    // Attack
    for (auto& actor : reflevel->GetMoveables())
    {
        if (actor->Is(typeId))
        {
            continue;
        }

        if (actor->As<Monster>() && this->As<Monster>())
        {
            continue;
        }

        Attack(*actor);
    }
}

void MoveableActor::Attack(MoveableActor& other)
{
    other.Attacked(this->damage);
}

void MoveableActor::Attacked(int damage)
{
    if (HP() - damage < 0)
    {
        hp = 0;
    }
    else
    {
        hp -= damage;
    }
}


