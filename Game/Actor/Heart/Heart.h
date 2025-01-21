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
private:
	List<HeartPart*> heartParts;

	bool isBeat = false;

	float bpm;

	static Heart* instance;
};