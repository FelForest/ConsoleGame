#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	~Game();

	static Game& Get() { return *instance; }

	Level* CurrentLevel();

private:
	bool showMenu = false;

	Level* menuLevel = nullptr;
	Level* backLevel = nullptr;


private:
	static Game* instance;
};