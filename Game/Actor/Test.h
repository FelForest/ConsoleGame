#pragma once

#include "Actor/DrawableActor.h"

class Test : public DrawableActor
{
	RTTI_DECLARATIONS(Test, DrawableActor)

public:
	Test()
		: DrawableActor("T")
	{
	}
};