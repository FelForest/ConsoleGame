#pragma once

#include "Actor/DrawableActor.h"

class MoveableActor : public DrawableActor
{
	RTTI_DECLARATIONS(MoveableActor, DrawableActor)

public:
	MoveableActor();

	void Move(Vector2 targetPosition);

	inline bool RequestMove() const { return requestMove;}

	inline bool WasMove() const { return wasMove; }

private:
	// 이동 요청을 위한 변수 - 레벨에 하는거임
	bool requestMove = false;

	// 이동후에 이동 했다고 알려주는 변수
	bool wasMove = false;
};
