#include "Player.h"
#include "Game/Game.h"
#include "Actor/Monster/Monster.h"
#include "Level/GameLevel.h"
#include "Actor/Heart/Heart.h"

Player::Player(Vector2 position, GameLevel* level)
	: DrawableActor("P")
{
	reflevel = level;
	this->position = position;
}

Player::~Player()
{
}

void Player::Move()
{
	if (Game::Get().GetKeyDown(VK_RIGHT) || Game::Get().GetKeyDown('D') || Game::Get().GetKeyDown('d'))
	{
		ProcessMove(Vector2(position.x + 1, position.y));
	}
	else if (Game::Get().GetKeyDown(VK_LEFT) || Game::Get().GetKeyDown('A') || Game::Get().GetKeyDown('a'))
	{
		ProcessMove(Vector2(position.x - 1, position.y));
	}
	else if (Game::Get().GetKeyDown(VK_UP) || Game::Get().GetKeyDown('W') || Game::Get().GetKeyDown('w'))
	{
		ProcessMove(Vector2(position.x, position.y - 1));
	}
	else if (Game::Get().GetKeyDown(VK_DOWN) || Game::Get().GetKeyDown('S') || Game::Get().GetKeyDown('s'))
	{
		ProcessMove(Vector2(position.x, position.y + 1));
	}
}

void Player::Attack(Monster* other, int damage)
{
	other->Attacked(damage);
	OutputDebugStringA("Attack \n");
}

void Player::Attacked(int damage)
{
	if (player_hp - damage < 0)
	{
		player_hp = 0;
		return;
	}

	player_hp -= damage;
}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (reflevel->CanMove)
	{
		canMove = true;
	}
	if (Heart::Get().HIT() && canMove)
	{
		Move();
	}

}

void Player::Draw()
{
	Super::Draw();

	if (player_hp == 0)
	{
		Destroy();
		return;
	}

	if (player_hp == player_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightGreen);
	}
	else if (player_hp != 1 && player_hp != player_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightYellow);
	}
	else
	{
		Game::Get().Draw(position, this->image, Color::Red);
	}

	for (int ix = 0; ix < player_maxhp; ++ix)
	{
		if (ix < player_hp)
		{
			Game::Get().Draw({ 3, 3 + ix }, "\u2665", Color::Red);
		}
		
	}

	//OutputDebugStringA("Player Draw \n");
}

void Player::ProcessMove(Vector2 target)
{
	// ������ �����ϸ� ������
	if (reflevel->CheckCanMove(target))
	{
		position = target;
		return;
	}

	// ���͵� Ȯ���ϸ� ��
	for (auto& actor : reflevel->GetActors())
	{
		Monster* monster = actor->As<Monster>();
		if (monster == nullptr)
		{
			continue;
		}

		if (target != monster->Position())
		{
			continue;
		}
		// ����
		Attack(monster, player_damage);
		return;
	}
}
