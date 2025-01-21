#pragma once

#include "Actor/DrawableActor.h"

class HeartPart : public DrawableActor
{
	RTTI_DECLARATIONS(HeartPart, DrawableActor)

public:
	HeartPart(Vector2 position);
	~HeartPart();

	void Beat(bool isBeat);

	virtual void Draw() override;
private:
	bool isBeat = false;
};