#include "Ribosome.h"

Ribosome::Ribosome() : Entity("Ribosome")
{
	texture.loadFromFile("Resources/Textures/enemy.png");
	setTexture(texture);
	Color c = RandomColor();
	this->SetColor(c);
	setColor(c);
	speed = 200.f;
}

Ribosome::~Ribosome()
{
}

void Ribosome::Update(float deltaTime)
{
	velocity = Vector2f();
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		velocity.x = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		velocity.y = -speed;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		velocity.y = speed;
	}
	move(velocity * deltaTime);
	float xPos = Clamp(getPosition().x, 0.f, (float)1200 - texture.getSize().x);
	float yPos = Clamp(getPosition().y, 0.f, (float)800 - texture.getSize().y);
	setPosition(xPos, yPos);

	if (this->JustCollide()) {
		Color c = RandomColor();
		this->SetColor(c);
		setColor(c);
		this->RestCollision(false);
	}

}

void Ribosome::ResolveCollision(Vector2f diff, Vector2f displacement)
{
	move(displacement);
}

void Ribosome::AddFollower(Entity* entity)
{
	followers.push_back(entity);
}

int Ribosome::PosToFollow()
{
	return followers.size()-2;
}



Entity* Ribosome::GetEntityToFollow(int n)
{
	return followers[n];

}

void Ribosome::SlowDown(float v)
{
	float newSpeed=this->speed - v;
	this->speed = newSpeed;
}


