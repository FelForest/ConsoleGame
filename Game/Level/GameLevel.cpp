#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"
#include "Actor/Heart/Heart.h"

#include "Actor/Player.h"

#include "Actor/Monster/Monster.h"
#include "Actor/Monster/Slime.h"
#include "Actor/Monster/Zombie.h"

#include "Actor/Map/Wall.h"
#include "Actor/Map/Ground.h"


GameLevel::GameLevel()
{
    
    heartAndNotePosition = { ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y - 3) };
    
    Heart* heart = new Heart(heartAndNotePosition, bpm);
    AddActor(heart);

    // 맵 추가
    for (int ix = 0; ix < 10; ++ix)
    {
        for (int jx = 0; jx < 10; ++jx)
        {
            Vector2 position = { (Game::Get().ScreenSize().x / 2) - 5 + ix , (Game::Get().ScreenSize().y / 2) - 5 + jx};
            actors.PushBack(new Ground(position));
        }
    }

    for (int ix = 0; ix < 12; ++ix)
    {
        for (int jx = 0; jx < 12; ++jx)
        {
            if (jx == 0 || jx == 11)
            {
                Vector2 position = { (Game::Get().ScreenSize().x / 2) - 6 + ix , (Game::Get().ScreenSize().y / 2) - 6 + jx };
                actors.PushBack(new Wall(position));
            }
            else
            {
                if (ix == 0 || ix == 11)
                {
                    Vector2 position = { (Game::Get().ScreenSize().x / 2) - 6 + ix , (Game::Get().ScreenSize().y / 2) - 6 + jx };
                    actors.PushBack(new Wall(position));
                }
                
            }
            
        }
    }

    player = new Player({ ((Game::Get().ScreenSize().x / 2)), (Game::Get().ScreenSize().y / 2) }, this);
    actors.PushBack(player);

    


    // 슬라임 추가
    /*Slime* slime = new Slime({ ((Game::Get().ScreenSize().x / 2) - 1), (Game::Get().ScreenSize().y / 2) - 2 }, this, false);
    actors.PushBack(slime);

    Slime* slime3 = new Slime({ ((Game::Get().ScreenSize().x / 2) - 1), (Game::Get().ScreenSize().y / 2) - 4 }, this, false);
    actors.PushBack(slime3);*/


    //AddMonster(slime1);
}

void GameLevel::Update(float deltaTime)
{
    /*for (int ix = 0; ix < monsters.Size(); ++ix)
    {
        if (monsters[ix]->isExpired)
        {
            monsters.Erase(ix);
        }
    }*/

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
    

    static Timer HeartTimer(spawnTime);
    static float nodeSpeed = ((Game::Get().ScreenSize().x / 2) - 1) / spawnTime;
    HeartTimer.Update(deltaTime);
    if(HeartTimer.IsTimeOut())
    {
        
        // TODO : 이거 고처야함
        Node* node = new Node(heartAndNotePosition, nodeSpeed);
        actors.PushBack(node);
        HeartTimer.Reset();
        HeartTimer.SetTime(spawnTime / 2);
        CanMove = true;

    }

    int monster_count = 0;
    for (auto* actor : actors)
    {
        if (actor->As<Monster>())
        {
            if (actor->IsAcive())
            {
                monster_count++;
            }
        }
    }

    static Timer MonsterSpawnTimer(spawnTime * 2);
    MonsterSpawnTimer.Update(deltaTime);

    if (MonsterSpawnTimer.IsTimeOut() && monster_count < 5)
    {
        int count = Random(0, 3);

        for (int ix = 0; ix < count; ++ix)
        {
            Vector2 position = Vector2(Random((Game::Get().ScreenSize().x / 2) - 5, (Game::Get().ScreenSize().x / 2) + 4), Random((Game::Get().ScreenSize().y / 2) - 5, (Game::Get().ScreenSize().y / 2) + 4));

            if (!CheckCanMove(position))
            {
                continue;
            }

            int type = Random(0, 1);

            if (type == 0)
            {
                AddActor(new Slime(position, this, Random(0, 1)));
            }
            else if (type == 1)
            {
                AddActor(new Zombie(position, this));
            }

            monster_count++;
            if (type == 2)
            {
                OutputDebugStringA("2");
            }
        }

        MonsterSpawnTimer.Reset();
        MonsterSpawnTimer.SetTime(spawnTime * Random(2, 4));
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
    for (auto* actor : actors)
    {
        if (actor->Position() == target)
        {
            if (actor->As<Monster>())
            {
                return false;
            }
            else if (actor->As<Wall>())
            {
                return false;
            }
            else if (actor->As<Player>())
            {
                return false;
            }
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
