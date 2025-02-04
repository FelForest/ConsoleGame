#include "GameLevel.h"

#include "Actor/Test.h"

#include "Game/Game.h"

GameLevel::GameLevel()
{
	tests.PushBack(new Test);
}

GameLevel::~GameLevel()
{
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);
	
	if (Game::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().QuitGame();
	}
}

void GameLevel::ProcessRequestMoveActor()
{

}
