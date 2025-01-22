#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"
#include "Actor/Heart/Heart.h"
#include "Actor/MoveableActor/MoveableActor.h"
#include "Actor/MoveableActor/Player/Player.h"
#include "Actor/MoveableActor/Monster/Slime.h"
#include "Actor/MoveableActor/Monster/Zombie.h"

GameLevel::GameLevel()
{
    heartAndNotePosition = { ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y - 3) };
    
    Heart* heart = new Heart(heartAndNotePosition, bpm);
    AddActor(heart);

    player = new Player("P", { heartAndNotePosition.x, Game::Get().ScreenSize().y / 2 }, this);
    AddActor(player);
    AddMoveActor(player);
    

    Slime* slime = new Slime({ heartAndNotePosition.x - 1, Game::Get().ScreenSize().y / 2 }, this);
    actors.PushBack(slime);
    AddMoveActor(slime);
    AddMonster(slime);

    Zombie* zombie = new Zombie({ heartAndNotePosition.x - 2, Game::Get().ScreenSize().y / 2 - 1 }, this);
    actors.PushBack(zombie);
    AddMoveActor(zombie);
    AddMonster(zombie);
}

void GameLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

    CanMove = false;

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
        actors.PushBack(node);
        timer.Reset();
        timer.SetTime(spawnTime / 2);
        CanMove = true;
    }

    if (Heart::Get().HIT())
    {
        //OutputDebugStringA("D\n");
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

void GameLevel::AddMonster(Monster* newMonster)
{
    monsters.PushBack(newMonster);
}

bool GameLevel::CheckCanMove(Vector2 target)
{
    // 움직이는 액터 확인
    for (MoveableActor* actor : moveables)
    {
        if (target == actor->Position())
        {
            return false;
        }
    }

    // 범위 벗어났는지 확인 -> 벽으로 감쌀 거여서 괜찮을듯

    return true;
}

const List<MoveableActor*>& GameLevel::GetMoveables()
{
    return moveables;
}

bool GameLevel::CheckGameOver()
{
    return false;
}
