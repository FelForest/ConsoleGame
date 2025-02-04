#include "PreCompiledHeader.h"
#include "Core.h"

Timer::Timer(float setTime)
	: setTime(setTime)
{
}

void Timer::Update(float deltaTime)
{
	elapsedTime += deltaTime;
}

void Timer::Reset()
{
	elapsedTime = 0.0f;
}