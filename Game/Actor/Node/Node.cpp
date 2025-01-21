#include "Node.h"
#include "Actor/Node/ChildNode.h"
#include "Game/Game.h"
#include "Engine/Timer.h"
#include "Actor/Heart/Heart.h"

Node::Node(Vector2 position, float speed)
{
	this->position = position;
	this->nodeSpeed = speed;

	int xScreenSize = Game::Get().ScreenSize().x;

    target = { position.x - 3, position.x + 3 };

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

    if (isMiss)
    {
        Heart::Get().SetBeat(true);
        Heart::Get().Update(deltaTime);

        for (auto& child : children)
        {
            child->SetIsVisible(false);
        }

        static Timer timer(0.15f);
        timer.Update(deltaTime);
        if (timer.IsTimeOut())
        {
            isMiss = false;
            Destroy();
            Heart::Get().SetBeat(false);
        }
    }
}

void Node::Draw()
{
	Super::Draw();

	for (auto& child : children)
	{
		child->Draw();
	}
}


