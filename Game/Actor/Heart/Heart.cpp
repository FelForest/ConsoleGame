#include "Heart.h"
#include "Game/Game.h"
#include "HeartPart.h"

// 하트 외관
// 심장 뛰는거 표현
// 일단 이 정도
Heart::Heart()
{
	Vector2 screenSize = Game::Get().ScreenSize();
	int mid = screenSize.x / 2;

	// 하트 외관 생성 별로네 짭
	/*
	*  * *
	* *   *
	*  * *
	*   *
	*/

	// 일단 단일객체 만들고 그다음 리스트
	heartParts.PushBack(new HeartPart());
}

Heart::~Heart()
{
	for (auto* part : heartParts)
	{
		delete part;
		part = nullptr;
	}
}
