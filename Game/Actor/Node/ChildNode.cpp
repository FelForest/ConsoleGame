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
	if (!isVisible)
	{
		return;
	}
	// 상속 받는데 뭐가 문제일까
	//Super::Draw();
	Game::Get().Draw(position, image, Color::BrightYellow);
}

void ChildNode::MoveToCenter(Vector2 target, float deltaTime, bool& isMiss, bool& isHit)
{
	static int mid = (target.x + target.y) / 2;
	// left
	if (speed > 0.0f)
	{
		if (target.x < position.x && mid >= position.x)
		{
			isHit = true;
			return;
		}

		if (mid < position.x)
		{
			position.x = mid;
		}
	}
	// right
	else if (speed < 0.0f)
	{
		if (target.x > position.x && mid <= position.x)
		{
			isHit = true;
			return;
		}
		if (mid > position.x)
		{
			position.x = mid;
		}
	}

	if (mid == position.x)
	{
		isMiss = true;
		return;
	}

	xPosition += speed * deltaTime;
	position.x = std::round(xPosition);
}

