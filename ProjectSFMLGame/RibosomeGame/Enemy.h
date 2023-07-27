#pragma once
#include "Entity.h"
#include "Ribosome.h"
class Enemy : public Entity
{
private:
	Texture texture;
	float lifeSpan=RandomTime();
	Ribosome* ribosome;
	bool noFollowedEntitySet=true;
	int followingPos;
public:
	Enemy(string name);
	~Enemy();
	void Update(float deltaTime) override;
	virtual void ResolveCollision(Vector2f diff, Vector2f displacement);
	Vector2f RandPos();
	void Follow(Entity* entity, Vector2f offset,float speed);
	void SetRibosome(Ribosome* ribosome);
	Ribosome* GetRibosome();
	void SetFollowedEntity(bool b);
	void SetFollowingPos(int n);


};


