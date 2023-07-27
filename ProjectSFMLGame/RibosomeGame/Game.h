#include "Ribosome.h"
#include "Enemy.h"
#include "CollisionManager.h"

using namespace sf;
class Game : public Sprite {
private:
	RenderWindow* window;
	bool isRunning;
	void _Update(float deltaTime);
	void _Draw(int score, Sprite background, Text textScore);
	Ribosome* ribosome;
	Enemy* enemy;
	float spawnTimer = 0;
public:
	Game();
	virtual ~Game();
	int Run();
	void Spawn(Ribosome* ribosome);
};
