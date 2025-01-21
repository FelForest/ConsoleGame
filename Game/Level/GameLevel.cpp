#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"
#include "Actor/Heart/Heart.h"
#include "Actor/MoveableActor/MoveableActor.h"

GameLevel::GameLevel()
{
    heartAndNotePosition = { (Game::Get().ScreenSize().x / 2) - 1, (Game::Get().ScreenSize().y - 3) };
    
    Heart* heart = new Heart(heartAndNotePosition, bpm);
    AddActor(heart);
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

    // 하트 추가
    

    static Timer timer(spawnTime);
    static float nodeSpeed = ((Game::Get().ScreenSize().x / 2) - 1) / spawnTime;

    timer.Update(deltaTime);
    if(timer.IsTimeOut())
    {
        // TODO : 이거 고처야함
        Node* node = new Node(heartAndNotePosition, nodeSpeed);
        AddActor(node);
        timer.Reset();
        timer.SetTime(spawnTime / 2);
    }

}

void GameLevel::Draw()
{
    Super::Draw();
    Heart::Get().Draw();
}

void GameLevel::AddMoveActor(MoveableActor* newMoveActor)
{
    moveables.PushBack(newMoveActor);
}

bool GameLevel::CheckCanMove(Vector2 target)
{
    for (MoveableActor* actor : moveables)
    {
        if (target == actor->Position())
        {
            return false;
        }
    }
    return true;
}

bool GameLevel::CheckGameOver()
{
    return false;
}
