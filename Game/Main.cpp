#include <iostream>
#include "Engine/Engine.h"
#include "Level/GameLevel.h"
#include "Game/Game.h"

int main()
{
	// �ܼ� ũ�� 180 50
	// �޸� ���� Ȯ��.
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new GameLevel());
	game.Run();
}