#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "Utils.h"

using namespace sf;


class Entity : public Sprite
{
private:
	string name;
	vector<Color> listColors = { Color::Green ,Color::Red, Color::Blue, Color::Magenta, Color::Cyan };
	Color color;
	bool collision;
public:
	Entity(string name);
	virtual ~Entity();
	virtual void Update(float deltaTime) = 0;
	virtual void ResolveCollision(Vector2f diff, Vector2f displacement) = 0;
	Color RandomColor();
	float RandomTime();
	void SetColor(Color c);
	Color GetColor();
	void RestCollision(bool b);
	bool JustCollide();

};
