#include "Heart.h"
#include "Game/Game.h"
#include "HeartPart.h"

// ��Ʈ �ܰ�
// ���� �ٴ°� ǥ��
// �ϴ� �� ����
Heart::Heart()
{
	Vector2 screenSize = Game::Get().ScreenSize();
	int mid = screenSize.x / 2;

	// ��Ʈ �ܰ� ���� ���γ� ¬
	/*
	*  * *
	* *   *
	*  * *
	*   *
	*/

	// �ϴ� ���ϰ�ü ����� �״��� ����Ʈ
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
