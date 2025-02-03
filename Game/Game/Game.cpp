#include "Game.h"

#include "Level/TitleLevel.h"
#include "Level/MenuLevel.h"
#include "Level/ScoreLevel.h"
#include "Level/GameLevel.h"

Game::Game()
	: Engine()
{
	titleLevel = new TitleLevel();
	menuLevel = new MenuLevel();
	scoreLevel = new ScoreLevel();
	gameLevel = new GameLevel();

	LoadLevel(titleLevel);
}

Game::~Game()
{
	SafeDelete(titleLevel);
	SafeDelete(menuLevel);
	SafeDelete(scoreLevel);
	SafeDelete(gameLevel);
}
