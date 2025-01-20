#include "ChildNode.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

ChildNode::ChildNode(Vector2 position, float speed)
	: DrawableActor("|"), speed(speed)
{
	this->position = position;
	xPosition = static_cast<float>(position.x);
}

void ChildNode::Draw()
{
	Game::Get().Draw(position, image, Color::BrightYellow);
}

bool ChildNode::MoveToCenter(int target, float deltaTime)
{
	// left
	if (speed > 0.0f)
	{
		if (target < position.x)
		{
			position.x = target;
		}
	}
	// right
	else if (speed < 0.0f)
	{
		if (target > position.x)
		{
			position.x = target;
		}
	}

	if (target == position.x)
	{
		return true;
	}

	xPosition += speed * deltaTime;
	position.x = std::round(xPosition);

	return false;
}

