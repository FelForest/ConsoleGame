#include <iostream>
#include "Engine/Engine.h"
#include "Level/GameLevel.h"
#include "Game/Game.h"

int main()
{
	// 콘솔 크기 180 50
	// 메모리 누수 확인.
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new GameLevel());
	game.Run();
}