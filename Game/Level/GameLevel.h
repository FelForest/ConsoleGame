#pragma once

#include "Level/Level.h"
#include "Math/Vector2.h"

// 있어야 할 액터
// UI 부분
// 리듬에 맞는 심장 노드
// 리듬 노드
class Node;
class ChildNode;
// 라이프

// 플레이어
class Player;
// 몬스터
class Monster;

class Slime;


// 필드
class Map;
// 벽
class Wall;
// 땅
class Ground;
// 문
class Door;
// 방
class Room;
// 길
class road;
// 전방 선언

class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

	void AddMonster(Monster* newMonster);

	bool CheckCanMove(Vector2 target);

	const List<Monster*>& GetMonsters();
public:
	bool CanMove = false;

	Player* player = nullptr;

private:
	bool CheckGameOver();

private:
	bool isGameOver = false;
	float bpm = 60.0f;
	float spawnTime = 60.0f / bpm;

	Vector2 heartAndNotePosition;

	List<Monster*> monsters;
};
