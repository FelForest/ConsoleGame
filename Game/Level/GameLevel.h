#pragma once
#include "Level/Level.h"

// ���漱��
class Test;

class GameLevel : public Level
{
	friend GameLevel;

	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

	virtual void Update(float deltaTime) override;

	void ProcessRequestMoveActor();

private:
	List<Test*> tests;
};