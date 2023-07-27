#include "Entity.h"


Entity::Entity(std::string name) : Sprite()
{
	this->name = name;
	this->color;
	EntityManager::GetInstance()->AddEntity(this);
	this->collision = false;
}

Entity::~Entity()
{
}

Color Entity::RandomColor()
{
	int rd = rand() % 5;
	return listColors[rd];
}

float Entity::RandomTime()
{
	float rd = 1+ rand() % 3;
	return rd;
}

void Entity::SetColor(Color c)
{
	this->color = c;
}

Color Entity::GetColor()
{
	return color;
}

void Entity::RestCollision(bool b)
{
	this->collision = b;
}

bool Entity::JustCollide()
{
	return collision;
}


