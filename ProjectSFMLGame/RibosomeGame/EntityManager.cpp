#include "EntityManager.h"
#include "Entity.h"


EntityManager* EntityManager::instance = nullptr;

EntityManager::~EntityManager()
{
	for (Entity* entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

void EntityManager::UpdateEntities(float deltaTime)
{
	for (Entity* entity : entities)
	{
		if (entity != NULL) {
			entity->Update(deltaTime);
		}
	}
}

void EntityManager::AddEntity(Entity* entity)
{
	entities.push_back(entity);
}
