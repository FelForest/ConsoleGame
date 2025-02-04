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
	// �̵� ��û�� ���� ���� - ������ �ϴ°���
	bool requestMove = false;

	// �̵��Ŀ� �̵� �ߴٰ� �˷��ִ� ����
	bool wasMove = false;
};
