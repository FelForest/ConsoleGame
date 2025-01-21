﻿#include "ChildNode.h"
#include "Engine/Timer.h"
#include "Game/Game.h"
#include "Actor/Heart/Heart.h"

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

void ChildNode::MoveToCenter(int target, float deltaTime, bool& isMiss, bool& isHit)
{
	static int mid = Heart::Get().Position().x;
	int min = mid - target / 2;
	int max = mid + target / 2;
	// left
	if (speed > 0.0f)
	{
		if (min < position.x && mid >= position.x)
		{
			isHit = true;
			isMiss = false;
		}

		if (mid < position.x)
		{
			position.x = mid;
		}
	}
	// right
	else if (speed < 0.0f)
	{
		if (max > position.x && mid <= position.x)
		{
			isHit = true;
			isMiss = false;
		}
		if (mid > position.x)
		{
			position.x = mid;
		}
	}

	if (mid == position.x)
	{
		isMiss = true;
		isHit = false;
	}

	xPosition += speed * deltaTime;
	position.x = std::round(xPosition);
}