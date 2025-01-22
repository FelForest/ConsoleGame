#include "Slime.h"
#include "Actor/Player.h"
#include "Level/GameLevel.h"
#include "Game/Game.h"
#include "Actor/Actor.h"
Slime::Slime(const Vector2& position, GameLevel* level, bool isUP)
	: Monster(position, level)
{
	this->position = position;
	ChangeImage("S");
	this->isUp = isUP;

	OutputDebugStringA("Slime");
}

Slime::~Slime()
{
}

void Slime::Update(float deltaTime)
{
	if (slime_hp == 0)
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
		Attack(slime_damage);
		return;
	}

	slime_can_move = reflevel->CheckCanMove(target);

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
	else if (slime_hp > 1 && slime_hp != slime_maxhp)
	{
		Game::Get().Draw(position, this->image, Color::BrightYellow);
	}
	else
	{
		Game::Get().Draw(position, this->image, Color::Red);
	}

	

	//OutputDebugStringA("Slime Draw \n");
}

void Slime::Attack(int damage)
{
	player->Attacked(damage);
}

void Slime::Attacked(int damage)
{
	OutputDebugStringA("Attacked");
	//Super::Attacked(damage);

	if (slime_hp - damage < 0)
	{
		slime_hp = 0;
		return;
	}

	slime_hp -= damage;
}
