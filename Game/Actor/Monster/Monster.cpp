#include "Monster.h"
#include "Level/GameLevel.h"
#include "Actor/Player.h"


Monster::Monster(Vector2 position, GameLevel* level)
	: DrawableActor()
{
	this->position = position;
	reflevel = level;

	this->player = reflevel->player;
	monsters = reflevel->GetMonsters();

	MonsterCount++;
}

Monster::Monster()
{
	this->position = { 0,0 };
}

Monster::~Monster()
{
	reflevel = nullptr;
	player = nullptr;
}

void Monster::Attacked(int damage)
{
	if (monster_hp - damage < 0)
	{
		monster_hp = 0;
		return;
	}

	monster_hp -= damage;
}

void Monster::Attack(int damage)
{
	player->Attacked(damage);
}

void Monster::Update(float deltaTime)
{
	Super::Update(deltaTime);
	//OutputDebugStringA("Monster");
}

void Monster::Draw()
{
	Super::Draw();
}

void Monster::Move(Vector2 target)
{
}
