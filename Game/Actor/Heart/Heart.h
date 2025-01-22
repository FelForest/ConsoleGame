#pragma once

#include "Actor/Actor.h"
#include "Container/List.h"
class HeartPart;



class Heart : public Actor
{
	RTTI_DECLARATIONS(Heart, Actor)

public:
	Heart(Vector2 position, float bpm);
	~Heart();

	void SetBeat(bool isBeat);

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

	static Heart& Get();

	void SetHit(bool hit);

	void SetMiss(bool miss);

	const bool HIT();

	const bool MISS();
public:

private:
	List<HeartPart*> heartParts;

	bool isBeat = false;

	float bpm;

	static Heart* instance;

	bool cur_hit = false;
	bool pre_hit = false;
	bool cur_miss = false;
	bool pre_miss = false;
	bool isCanMove = true;
};