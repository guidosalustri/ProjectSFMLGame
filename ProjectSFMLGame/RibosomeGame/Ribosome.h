#pragma once
#include "Entity.h"

class Ribosome : public Entity
{
private:
	Texture texture;
	Vector2f velocity;
	float speed;
	vector<Entity*> followers = {this};
public:
	Ribosome();
	~Ribosome();
	void Update(float deltaTime) override;
	void ResolveCollision(Vector2f diff, Vector2f displacement) override;
	void AddFollower(Entity* entity);
	int PosToFollow();
	Entity* GetEntityToFollow(int n);
	void SlowDown(float v);
};

