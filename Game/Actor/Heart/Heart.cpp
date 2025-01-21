#include "Heart.h"
#include "Game/Game.h"
#include "HeartPart.h"
#include "Engine/Timer.h"
#include "Actor/Node/Node.h"

// 하트 외관
// 심장 뛰는거 표현
// 일단 이 정도

// 쓰기 싫은데 노트에서 접근 방식이 생각이 안나네
// 현재레벨 -> 액터 -> 하트 이렇게 받아오면 되는데 문제는 actors가 protected여서 못 받아옴
// 그럴꺼면 싱글톤 으로 가져오는게 맞음 -> 심장은 하나만 있을 거니까

Heart* Heart::instance = nullptr;

Heart::Heart(Vector2 position, float bpm)
{
	// \u2661, \u2665
	this->position = position;
	this->bpm = bpm;

	instance = this;

	// 하트 외관 생성 별로네 짭
	/*
	*  * *
	* *   *
	*  * *
	*   *
	*/

	// 일단 단일객체 만들고 그다음 리스트
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
	// bpm 한번에 한번 뛰기 -> 실패!
	/*static Timer Beat(oneStep);
	Beat.Update(deltaTime);
	if (Beat.IsTimeOut())
	{
		isBeat = !isBeat;
		Beat.Reset();
		Beat.SetTime(oneStep);
	}*/

	// 프레임 업데이트 시 하는 그거
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
