#include "Node.h"
#include "Actor/Node/ChildNode.h"
#include "Game/Game.h"
#include "Engine/Timer.h"
#include "Actor/Heart/Heart.h"
#include "Level/GameLevel.h"


Node::Node(Vector2 position, float speed)
{
	this->position = position;
	this->nodeSpeed = speed;

	int xScreenSize = Game::Get().ScreenSize().x;

    target = 12;

	int margin = 20;
	for (int ix = 0; ix < noteCount; ++ix)
	{
		children.PushBack(new ChildNode({ margin, position.y + ix }, nodeSpeed));
        isHits.PushBack(false);
        isMisses.PushBack(false);
		children.PushBack(new ChildNode({ xScreenSize - margin, position.y + ix }, -nodeSpeed));
        isHits.PushBack(false);
        isMisses.PushBack(false);
	}
}

Node::~Node()
{
	for (int ix = 0; ix < noteCount * 2; ++ix)
	{
		delete children[ix];
		children[ix] = nullptr;
        
	}
}

void Node::Update(float deltaTime)
{
    Super::Update(deltaTime);

    isHit = false;
    isMiss = false;

    for (int ix = 0; ix < noteCount * 2; ++ix)
    {
        children[ix]->MoveToCenter(target, deltaTime, isMisses[ix], isHits[ix]);
    }

    for (int ix = 0; ix < noteCount * 2; ++ix)
    {
        if (!isHit)
        {
            isHit = isHits[ix];
        }
        if (!isMiss)
        {
            isMiss = isMisses[ix];
        }
    }

    if (isHit)
    {
        for (auto& child : children)
        {
            child->SetIsVisible(false);

        }

        
        Heart::Get().SetHit(true);
    }

    if (!isMiss)
    {
        Heart::Get().SetMiss(false);
        for (int ix = 0; ix < noteCount * 2; ++ix)
        {
            isMisses[ix] = false;
        }
    }
    
    if (isMiss)
    {
        //OutputDebugStringA("A");
        //OutputDebugStringA("D");
        //Heart::Get().SetBeat(true);
        Heart::Get().SetHit(false);
        Heart::Get().SetMiss(true);
        Heart::Get().Update(deltaTime);
        isMiss = false;
        Destroy();
    }
    
    


}

void Node::Draw()
{
	Super::Draw();

	for (auto& child : children)
	{
		child->Draw();
	}

    if (Heart::Get().HIT())
    {
        
        //Log("%d", Heart::Get().HIT());
    }

    if (isHit && Game::Get().GetKey(VK_SPACE))
    {
        Game::Get().Draw({ 0,0 }, "Hit");
        
        //std::cout << "Heart instance address: " << &Heart::Get() << std::endl;
    }
}


