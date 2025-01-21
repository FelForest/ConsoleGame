#include "MoveableActor.h"
#include "Game/Game.h"

MoveableActor::MoveableActor()
{
}

MoveableActor::~MoveableActor()
{
}



void MoveableActor::Move(Vector2 target)
{
    position = target;
}
