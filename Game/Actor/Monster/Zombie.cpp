#include "Zombie.h"
#include "Actor/Player.h"
#include "Level/GameLevel.h"
#include "Game/Game.h"

#include <iostream>
#include <algorithm>
#include <cmath>

Zombie::Zombie(const Vector2& position, GameLevel* level)
	: Monster(position, level)
{
	this->position = position;
	ChangeImage("Z");
}

Zombie::~Zombie()
{
}

void Zombie::Update(float deltaTime)
{
	if (zombie_hp == 0)
	{
		SetIsVisible(false);
		SetActive(false);
		MonsterCount--;
		position = { 0,0 };
		return;
	}

	Super::Update(deltaTime);

	if (!reflevel->CanMove)
	{
		return;
	}

	if (!isMove)
	{
		return;
	}
	if (zombie_count > 0)
	{
		if (zombie_count == 1)
		{
			ChangeImage("z");
		}
		zombie_count--;
		return;
	}
	ChangeImage("Z");
	zombie_count = 2;

	if (isMove)
	{
		Vector2 target = { position.x - player->Position().x, position.y - player->Position().y };
		if (std::abs(target.x) > std::abs(target.y))
		{
			if (target.x > 0)
			{
				Move(Vector2(position.x - 1, position.y));
			}
			else
			{
				Move(Vector2(position.x + 1, position.y));
			}
		}
		else
		{
			if (target.y > 0)
			{
				Move(Vector2(position.x , position.y - 1));
			}
			else
			{
				Move(Vector2(position.x , position.y + 1));
			}
		}
	}

}

void Zombie::Move(Vector2 target)
{
	if (target == player->Position())
	{
		Attack(zombie_damage);
		return;
	}

	zombie_can_move = reflevel->CheckCanMove(target);

	if (zombie_can_move)
	{
		position = target;
	}
}

void Zombie::Draw()
{
	Super::Draw();

	if (zombie_hp == zombie_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightGreen);
	}
	else if (zombie_hp > 1 && zombie_hp != zombie_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightYellow);
	}
	else
	{
		Game::Get().Draw(position, this->image, Color::Red);
	}
}

void Zombie::Attack(int damage)
{
	player->Attacked(damage);
}

void Zombie::Attacked(int damage)
{
	isMove = true;
	if (zombie_hp - damage < 0)
	{
		zombie_hp = 0;
		return;
	}

	zombie_hp -= damage;
}
