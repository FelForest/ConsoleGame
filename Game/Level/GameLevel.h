#pragma once

#include "Level/Level.h"
#include "Math/Vector2.h"

// �־�� �� ����
// UI �κ�
// ���뿡 �´� ���� ���
// ���� ���
class Node;
class ChildNode;
// ������

// �����̴� ����
class MoveableActor;
// �÷��̾�
class Player;
// ����
class Monster;

class Slime;

// �ʵ�
class Map;
// ��
class Wall;
// ��
class Ground;
// ��
class Door;
// ��
class Room;
// ��
class road;
// ���� ����

class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

	void AddMoveActor(MoveableActor* newMoveActor);

	void AddMonster(Monster* newMonster);

	bool CheckCanMove(Vector2 target);

	const List<MoveableActor*>& GetMoveables();

public:
	bool CanMove = false;

private:
	bool CheckGameOver();

private:
	bool isGameOver = false;
	float bpm = 60.0f;
	float spawnTime = 60.0f / bpm;

	Vector2 heartAndNotePosition;

	List<MoveableActor*> moveables;
	List<Monster*> monsters;

	Player* player = nullptr;
};
