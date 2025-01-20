#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"


GameLevel::GameLevel()
{
    
}

GameLevel::~GameLevel()
{
}

void GameLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

    // 스테이지 제한 시간
    /*static Timer gameOver(20.0f);
    gameOver.Update(deltaTime);
    if (gameOver.IsTimeOut())
    {
        Game::Get().QuitGame();
    }*/

    static Timer timer(spawnTime);
    static float nodeSpeed = ((Game::Get().ScreenSize().x / 2) - 1) / spawnTime;
    timer.Update(deltaTime);
    if(timer.IsTimeOut())
    {
        // TODO : 이거 고처야함
        Node* node = new Node(nodeSpeed);
        AddActor(node);
        timer.Reset();
        timer.SetTime(spawnTime / 2);
    }
}

void GameLevel::Draw()
{
    Super::Draw();
}

bool GameLevel::CheckGameOver()
{
    return false;
}
