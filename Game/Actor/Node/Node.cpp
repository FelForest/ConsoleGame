#include "Node.h"
#include "Actor/Node/ChildNode.h"
#include "Game/Game.h"
#include "Engine/Timer.h"

Node::Node(float speed)
{
	this->nodeSpeed = speed;
	Vector2 screenSize = Game::Get().ScreenSize();
	int xScreenSize = screenSize.x;

	target = xScreenSize / 2;

	position.y = screenSize.y - 10;
	SetPosition(position);

	for (int ix = 0; ix < 4; ++ix)
	{
		children.PushBack(new ChildNode({ 1, position.y + ix }, nodeSpeed));
		children.PushBack(new ChildNode({ xScreenSize - 1, position.y + ix }, -nodeSpeed));
	}
}

Node::~Node()
{

	for (int ix = 0; ix < 8; ++ix)
	{
		delete children[ix];
		children[ix] = nullptr;
	}
}

void Node::Update(float deltaTime)
{
	Super::Update(deltaTime);

	//Log("%d", Game::Get().ScreenSize().x);

	for (auto& child : children)
	{
		child->SetIsVisible(false);
		isMiss = child->MoveToCenter(target, deltaTime);
	}

	if (isMiss || isHit)
	{
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (timer.IsTimeOut())
		{
			Destroy();
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


