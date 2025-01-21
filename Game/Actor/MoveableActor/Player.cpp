#include "Player.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"
#include "Actor/Heart/Heart.h"


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

	
	if (Heart::Get().HIT())
	{
		playerMove();
	}
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
		MoveOrAttack(Vector2(position.x + 1, position.y));
	}
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		MoveOrAttack(Vector2(position.x - 1, position.y));
	}
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		MoveOrAttack(Vector2(position.x, position.y - 1));
	}
	if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		MoveOrAttack(Vector2(position.x, position.y + 1));
	}
}
