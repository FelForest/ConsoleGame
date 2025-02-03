﻿#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
	// 메모리 해제.
	for (Actor* actor : actors)
	{
		delete actor;
	}
}

void Level::AddActor(Actor* newActor)
{
	//actors.PushBack(newActor);
	//addRequestedActor = newActor;
	addRequestedActors.PushBack(newActor);
}

void Level::ProcessAddedAndDestroyedActor()
{
	// 액터 순회 후 삭제 요청된 액터를 처리.
	for (int ix = 0; ix < actors.Size();)
	{
		if (actors[ix]->isExpired)
		{
			SafeDelete(actors[ix]);
			actors.Erase(ix);
			continue;
		}
		else
		{
			++ix;
		}
	}

	// 추가 요청된 액터 처리.
	while (!addRequestedActors.IsEmpty())
	{
		actors.PushBack(std::move(addRequestedActors[0]));
		addRequestedActors.Erase(0);
	}
}

void Level::Update(float deltaTime)
{
	// 레벨에 포함된 액터를 순회하면서 Update 함수 호출.
	for (Actor* actor : actors)
	{
		// 액터가 비활성화 상태이거나, 삭제 요청된 경우 건너뛰기.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}

		actor->Update(deltaTime);
	}
}

void Level::Draw()
{
	// 레벨에 포함된 액터를 순회하면서 Draw 함수 호출.
	for (Actor* actor : actors)
	{
		// 액터가 비활성화 상태이거나, 삭제 요청된 경우 건너뛰기.
		if (!actor->isActive || actor->isExpired)
		{
			continue;
		}

		actor->Draw();
	}
}

const List<Actor*>& Level::GetActors()
{
	return actors;
}

