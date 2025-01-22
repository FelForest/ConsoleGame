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

    // �������� ���� �ð�
    /*static Timer gameOver(20.0f);
    gameOver.Update(deltaTime);
    if (gameOver.IsTimeOut())
    {
        Game::Get().QuitGame();
    }*/

    // ��Ʈ �߰�
    

    static Timer timer(spawnTime);
    static float nodeSpeed = ((Game::Get().ScreenSize().x / 2) - 1) / spawnTime;

    timer.Update(deltaTime);
    if(timer.IsTimeOut())
    {
        
        // TODO : �̰� ��ó����
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
    // �����̴� ���� Ȯ��
    for (Monster* monster : monsters)
    {
        if (target == monster->Position())
        {
            return false;
        }
    }

    // ���� ������� Ȯ�� -> ������ ���� �ſ��� ��������

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
