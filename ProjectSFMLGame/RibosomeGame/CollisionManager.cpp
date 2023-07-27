#include "CollisionManager.h"
#include "Entity.h"
#include "Ribosome.h"


CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager()
{
}


void CollisionManager::ResolveCollision(Entity* entityA, Ribosome* ribosome)
{
	if (!(*entityA).JustCollide()) {
		if ((*ribosome).GetColor() == (*entityA).GetColor()) {
			this->playerScore += 1;
			(*ribosome).RestCollision(true);
		}
		else {
			ribosome->SlowDown(20);
		}
		(*entityA).RestCollision(true);
		(*ribosome).AddFollower(entityA);
	}
}

CollisionManager::~CollisionManager()
{
}

void CollisionManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}
void CollisionManager::SetRibosome(Ribosome* ribosome)
{
	this->ribosome = ribosome;
}

Ribosome* CollisionManager::GetRibosome()
{
	return ribosome;
}

int CollisionManager::GetScore()
{
	return playerScore;
}

void CollisionManager::UpdateCollisions()
{
	for (list<Entity*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		Entity* entity = *it;
		if (entity->getGlobalBounds().intersects(ribosome->getGlobalBounds())){
			ResolveCollision(entity, ribosome);
		}
	}
}

