#include "Slime.h"
#include "Actor/Player.h"
#include "Level/GameLevel.h"
#include "Game/Game.h"
Slime::Slime(const Vector2& position, GameLevel* level)
	: Monster(position, level)
{
	this->position = position;
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
	Super::Update(deltaTime);
	if (!reflevel->CanMove)
	{
		return;
	}

	if (slime_count > 0)
	{
		if (slime_count == 1)
		{
			ChangeImage("s");
		}
		slime_count--;
		return;
	}
	ChangeImage("S");
	slime_count = 3;
	slime_can_move = true;

	if (isUp)
	{
		Move(Vector2(position.x - 1, position.y));
	}
	else
	{
		Move(Vector2(position.x + 1, position.y));
	}


}

void Slime::Move(Vector2 target)
{
	if (target == player->Position())
	{
		Attacked(slime_damage);
		return;
	}

	for (Monster* monster : monsters)
	{
		if (monster->Position() == position)
		{
			slime_can_move = false;
			break;
		}
	}
	if (slime_can_move)
	{
		position = target;
		isUp = !isUp;
	}
}

void Slime::Draw()
{
	Super::Draw();

	if (slime_hp == slime_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightGreen);
	}
	else if (slime_hp != 1 && slime_hp != slime_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightYellow);
	}
	else
	{
		Game::Get().Draw(position, this->image, Color::Red);
	}
}

void Slime::Attack(int damage)
{
}
