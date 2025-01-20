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
// �÷��̾�
class Player;
// ����
class Monster;

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
	~GameLevel();

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

private:
	bool CheckGameOver();

private:
	bool isGameOver = false;
	float bpm = 60.0f;
	float spawnTime = 60.0f / bpm;
};
