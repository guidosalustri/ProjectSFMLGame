#pragma once
#include <list>
#include <iostream>

using namespace std;

class Entity;
class Ribosome;

class CollisionManager
{
private:
	static CollisionManager* instance;
	Ribosome* ribosome;
	list<Entity*> entities;
	int playerScore = 0;
	CollisionManager();
	void ResolveCollision(Entity* entityA, Ribosome* ribosome);
public:
	virtual ~CollisionManager();
	static CollisionManager* GetInstance() {
		if (instance == nullptr)
		{
			instance = new CollisionManager();
		}
		return instance;
	}
	void AddEntity(Entity* entity);
	void UpdateCollisions();
	void SetRibosome(Ribosome* ribosome);
	Ribosome* GetRibosome();
	int GetScore();
};
