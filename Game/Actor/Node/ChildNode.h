#pragma once

#include "Actor/DrawableActor.h"

class ChildNode : public DrawableActor
{
	RTTI_DECLARATIONS(ChildNode, DrawableActor)

public:
	ChildNode(Vector2 position, float speed);

	virtual void Draw() override;

	void MoveToCenter(int target, float deltaTime, bool& isMiss, bool& isHit);

private:
	float speed = 0.0f;

	float xPosition = 0.0f;
};
