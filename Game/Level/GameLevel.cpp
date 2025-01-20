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

    static Timer timer(60.0f / bpm);
    timer.Update(deltaTime);
    if(timer.IsTimeOut())
    {
        // TODO : 이거 고처야함
        Node* node = new Node(15);
        AddActor(node);
        timer.Reset();
        timer.SetTime(60.0f / bpm);
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
