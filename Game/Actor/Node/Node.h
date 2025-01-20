#pragma once

#include "Actor/Actor.h"
#include "Container/List.h"
class ChildNode;

class Node : public Actor
{
	RTTI_DECLARATIONS(Node, Actor)

public:
	Node(float speed);
	~Node();

	virtual void Update(float deltaTime);
	virtual void Draw();

private:
	float nodeSpeed = 0.0f;
	int target = 0;
	bool isHit = false;
	bool isMiss = false;

	List<ChildNode*> children;
	/*ChildNode* leftNode = nullptr;
	ChildNode* rightNode = nullptr;*/
};