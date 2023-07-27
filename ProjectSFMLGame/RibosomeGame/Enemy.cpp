#include "Enemy.h"

Enemy::Enemy(string name) : Entity(name)
{
	texture.loadFromFile("Resources/Textures/ball.png");
	setScale(0.2,0.2);
	Color c = RandomColor();
	this->SetColor(c);
	setColor(c);
	setTexture(texture);
}

Enemy::~Enemy()
{
	//delete this;
}

void Enemy::Update(float deltaTime)
{
	if (JustCollide()) {
		if (noFollowedEntitySet) {
			int n = ribosome->PosToFollow();
			this->SetFollowingPos(n);
			this->SetFollowedEntity(false);
		}
		if (followingPos == 0) {
			Vector2f offset = Vector2f(40,95);
			this->Follow(ribosome->GetEntityToFollow(followingPos), offset, 0.0025);
		}
		else {
			this->Follow(ribosome->GetEntityToFollow(followingPos), Vector2f(0, 30), 0.005);
		}

	}
	lifeSpan += deltaTime;
	if (lifeSpan > 5) {
		//Color c = RandomColor();
		//setColor(c);
		//this->SetColor(c);
		//lifeSpan = 0;

		//this->~Enemy();
		//delete this;
	}
}

void Enemy::ResolveCollision(Vector2f diff, Vector2f displacement)
{
}

Vector2f Enemy::RandPos()
{
	int rdy =49+ (1+ rand() % 1100);
	int rdx =49+ (1+ rand() % 700);
	return Vector2f(rdy, rdx);
}

void Enemy::Follow(Entity* entity, Vector2f offset, float speed)
{
	Vector2f followpos = Vector2f(entity->getPosition().x + offset.x, entity->getPosition().y + offset.y);
	float x = followpos.x - this->getPosition().x;
	float y = followpos.y - this->getPosition().y;
	
	Vector2f velocity = Vector2f(this->getPosition().x + x * speed, this->getPosition().y + y * speed);

	this->setPosition(velocity);

}

void Enemy::SetRibosome(Ribosome* ribosome)
{
	this->ribosome = ribosome;
}

Ribosome* Enemy::GetRibosome()
{
	return ribosome;
}

void Enemy::SetFollowedEntity(bool b)
{
	this->noFollowedEntitySet = b;
}

void Enemy::SetFollowingPos(int n)
{
	this->followingPos = n;
}
