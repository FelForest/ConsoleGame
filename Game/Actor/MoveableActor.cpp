#include "MoveableActor.h"

MoveableActor::MoveableActor()
{
}

void MoveableActor::Move(Vector2 targetPosition)
{
	// 이동에 대한 것
	// 일단 이동하고 싶다고 요청을 함
	// 그러면 레벨에서 요청을 확인해서 그거에 맞는 액터를 반환함
	// 그 액터에 따라 상호작용을 다르게 하면 될듯

	// 이동 요청
	requestMove = true;
}
