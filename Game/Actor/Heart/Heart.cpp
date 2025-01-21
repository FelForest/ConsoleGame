#include "Heart.h"
#include "Game/Game.h"
#include "HeartPart.h"
#include "Engine/Timer.h"
#include "Actor/Node/Node.h"

// ��Ʈ �ܰ�
// ���� �ٴ°� ǥ��
// �ϴ� �� ����

// ���� ������ ��Ʈ���� ���� ����� ������ �ȳ���
// ���緹�� -> ���� -> ��Ʈ �̷��� �޾ƿ��� �Ǵµ� ������ actors�� protected���� �� �޾ƿ�
// �׷����� �̱��� ���� �������°� ���� -> ������ �ϳ��� ���� �Ŵϱ�

Heart* Heart::instance = nullptr;

Heart::Heart(Vector2 position, float bpm)
{
	// \u2661, \u2665
	this->position = position;
	this->bpm = bpm;

	instance = this;

	// ��Ʈ �ܰ� ���� ���γ� ¬
	/*
	*  * *
	* *   *
	*  * *
	*   *
	*/

	// �ϴ� ���ϰ�ü ����� �״��� ����Ʈ
	heartParts.PushBack(new HeartPart(position));
}

Heart::~Heart()
{
	for (auto* part : heartParts)
	{
		delete part;
		part = nullptr;
	}
}

void Heart::SetBeat(bool isBeat)
{
	this->isBeat = isBeat;
}

void Heart::Update(float deltaTime)
{
	Super::Update(deltaTime);
	
	//static float oneStep = (60 / bpm) / 4;
	// bpm �ѹ��� �ѹ� �ٱ� -> ����!
	/*static Timer Beat(oneStep);
	Beat.Update(deltaTime);
	if (Beat.IsTimeOut())
	{
		isBeat = !isBeat;
		Beat.Reset();
		Beat.SetTime(oneStep);
	}*/

	// ������ ������Ʈ �� �ϴ� �װ�
	//pre_miss = cur_miss;
	//pre_hit = cur_hit;


	for (auto& part : heartParts)
	{
		part->Beat(isBeat);
	}

	
}

void Heart::Draw()
{
	for (auto& part : heartParts)
	{
		part->Draw();
	}
}

Heart& Heart::Get()
{
	if (instance == nullptr)
	{
		instance = new Heart({ Game::Get().ScreenSize().x / 2, Game::Get().ScreenSize().y - 3 }, 60.0f);
	}
	return *instance;
}

void Heart::SetHit(bool hit)
{
	
	
	this->cur_hit = hit;
}

void Heart::SetMiss(bool miss)
{
	this->cur_miss = miss;
}

const bool Heart::HIT()
{
	return cur_hit;
}

const bool Heart::MISS()
{
	return cur_miss;
}
