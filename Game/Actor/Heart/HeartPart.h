#pragma once

#include "Actor/DrawableActor.h"

class HeartPart : public DrawableActor
{
	RTTI_DECLARATIONS(HeartPart, DrawableActor)

public:
	HeartPart();
	~HeartPart();

	virtual void Update(float deltaTime) override;

	virtual void Draw() override;

private:


};