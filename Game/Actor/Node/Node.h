#pragma once

#include "Actor/Actor.h"
#include "Container/List.h"

class ChildNode;

class Node : public Actor
{
	RTTI_DECLARATIONS(Node, Actor)

public:
	Node(Vector2 position,float speed);
	~Node();

	virtual void Update(float deltaTime);
	virtual void Draw();

private:
	float nodeSpeed = 0.0f;
	Vector2 target;
	bool isHit = false;
	bool isMiss = false;

	int noteCount = 1;

	List<ChildNode*> children;

	List<bool> isHits;
	List<bool> isMisses;

	/*ChildNode* leftNode = nullptr;
	ChildNode* rightNode = nullptr;*/
};