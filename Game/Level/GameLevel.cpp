#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"
#include "Actor/Heart/Heart.h"

#include "Actor/Player.h"

#include "Actor/Monster/Monster.h"
#include "Actor/Monster/Slime.h"

GameLevel::GameLevel()
{
    heartAndNotePosition = { ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y - 3) };
    
    Heart* heart = new Heart(heartAndNotePosition, bpm);
    AddActor(heart);

    player = new Player({ ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y / 2) }, this);
    AddActor(player);

    Slime* slime = new Slime({ ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y / 2) - 2 }, this);
    AddActor(slime);
    AddMonster(slime);
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



void GameLevel::AddMonster(Monster* newMonster)
{
    monsters.PushBack(newMonster);
}

bool GameLevel::CheckCanMove(Vector2 target)
{
    // 움직이는 액터 확인
    for (Monster* monster : monsters)
    {
        if (target == monster->Position())
        {
            return false;
        }
    }

    // 범위 벗어났는지 확인 -> 벽으로 감쌀 거여서 괜찮을듯

    return true;
}

const List<Monster*>& GameLevel::GetMonsters()
{
    return monsters;
}

bool GameLevel::CheckGameOver()
{
    return false;
}
