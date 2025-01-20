#include "Heart.h"
#include "Game/Game.h"

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


}

Heart::~Heart()
{
}
