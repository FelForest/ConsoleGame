#include "Player.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"
#include "Actor/Heart/Heart.h"
#include "Actor/MoveableActor/Monster/Monster.h"

Player::Player(const Vector2& position, GameLevel* level)
	: MoveableActor(level)
{
	this->position = position;
}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ??
	/*if (Heart::Get().cur_miss != Heart::Get().pre_miss)
	{
		Heart::Get().isCanMove = true;
	}*/

	isMove = false;

	playerMove();


	if (Heart::Get().MISS())
	{
		if (!isMove)
		{
			isCorrect = false;
		}
	}

	Heart::Get().SetBeat(isCorrect);
}

void Player::Draw()
{
	if (isAttacked)
	{
		Game::Get().Draw(position, "P", Color::BrightRed);
		//static Timer timer(0.2f);
	}
	else
	{
		Game::Get().Draw(position, "P", Color::BrightGreen);
	}
}

void Player::playerMove()
{
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		ProcessMove(Vector2(position.x + 1, position.y));
	}
	else if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		ProcessMove(Vector2(position.x - 1, position.y));
	}
	else if (Engine::Get().GetKeyDown(VK_UP))
	{
		ProcessMove(Vector2(position.x, position.y - 1));
	}
	else if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		ProcessMove(Vector2(position.x, position.y + 1));
	}
}

void Player::ProcessMove(const Vector2& newPosition)
{
	if (Heart::Get().HIT()) // 타이밍에 맞게 이동했다면
	{
		MoveOrAttack(newPosition);
		isCorrect = true; // 올바른 움직임
	}
	else
	{
		isCorrect = false; // 타이밍에 맞지 않은 움직임
	}
	isMove = true; // 움직임 발생 기록
}

void Player::MoveOrAttack(Vector2 target)
{
	Super::MoveOrAttack(target);
}
