#pragma once

#include "Engine/Engine.h"


class Level;

class Game : public Engine
{
public :
	Game();
	~Game();

private:
	Level* titleLevel = nullptr;
	Level* menuLevel = nullptr;
	Level* scoreLevel = nullptr;
	Level* gameLevel = nullptr;
};
