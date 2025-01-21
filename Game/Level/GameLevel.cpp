#include "GameLevel.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

#include "Actor/Node/ChildNode.h"
#include "Actor/Node/Node.h"
#include "Actor/Heart/Heart.h"
#include "Actor/MoveableActor/MoveableActor.h"
#include "Actor/MoveableActor/Player.h"
#include "Actor/MoveableActor/Monster/Slime.h"

GameLevel::GameLevel()
{
    heartAndNotePosition = { (Game::Get().ScreenSize().x / 2), (Game::Get().ScreenSize().y - 3) };
    
    Heart* heart = new Heart(heartAndNotePosition, bpm);
    AddActor(heart);

    player = new Player({ heartAndNotePosition.x , Game::Get().ScreenSize().y / 2 }, this);
    AddActor(player);
    AddMoveActor(player);

    Slime* slime = new Slime("S", { 3, 5 }, this);
    AddActor(slime);
    AddMoveActor(slime);
    AddMonster(slime);

}

GameLevel::~GameLevel()
{
}

void GameLevel::Update(float deltaTime)
{
    Super::Update(deltaTime);

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

void GameLevel::AddMonster(Monster* newMonster)
{
    monsters.PushBack(newMonster);
}

bool GameLevel::CheckCanMove(Vector2 target)
{
    // �����̴� ���� Ȯ��
    for (MoveableActor* actor : moveables)
    {
        if (target == actor->Position())
        {
            return false;
        }
    }

    // ���� ������� Ȯ�� -> ������ ���� �ſ��� ��������

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
