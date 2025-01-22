#include "HeartPart.h"
#include "Engine/Timer.h"
#include "Game/Game.h"

HeartPart::HeartPart(Vector2 position)
	: DrawableActor("@")
{ 
	this->position = position;
}

HeartPart::~HeartPart()
{
}

// 호출은 Heart에서 할거임
void HeartPart::Beat(bool isBeat)
{
	this->isBeat = isBeat;
}

void HeartPart::Draw()
{
	if (isBeat)
	{
		Game::Get().Draw(position, "@", Color::BrightRed);
		//OutputDebugStringA("a\n");
	}
	else
	{
		Game::Get().Draw(position, "@", Color::BrightBlue);
		//OutputDebugStringA("b\n");
	}
}
