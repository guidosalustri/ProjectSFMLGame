#include "Game.h"

void Game::_Update(float deltaTime)
{
    EntityManager::GetInstance()->UpdateEntities(deltaTime);
    CollisionManager::GetInstance()->UpdateCollisions();
}

void Game::_Draw(int score, Sprite background, Text textScore)
{
    window->clear(Color::Cyan);

    window->draw(background);
    for (Entity* entity : EntityManager::GetInstance()->GetEntities())
    {
        if (entity != NULL) {
            window->draw(*entity);
        }
    }
    textScore.setString(to_string(score));
    window->draw(textScore);
    window->display();
}

Game::Game() {
    window = new RenderWindow(VideoMode(1200, 800), "My window");

    ribosome = new Ribosome();
    ribosome->setPosition(550, 300);
 
    CollisionManager::GetInstance()->SetRibosome(ribosome);
    Spawn(ribosome);
    //Spawn();

    isRunning = true;
}

Game::~Game() {
    if (window)
    {
        delete window;
        window = nullptr;
    }
    if (EntityManager::GetInstance())
    {
        delete EntityManager::GetInstance();
    }
    if (CollisionManager::GetInstance())
    {
        delete CollisionManager::GetInstance();
    }
}

int Game::Run() {

    //background
    Sprite bg;
    Texture t;
    t.loadFromFile("Resources/Textures/Background_Tile.png");
    bg.setTexture(t);
    bg.setColor(Color::Green);
    bg.setScale(Vector2f(4.7, 3.15));

    //font and text for socre
    Font font;
    font.loadFromFile("Resources/Textures/xolonium-regular.ttf");
    Text title;
    title.setFont(font);
    title.setCharacterSize(56);
    title.setFillColor(Color::Red);
    title.setStyle(Text::Bold);
    title.setPosition(590, 20);

    Clock clockDelta;
    float deltaTime = clockDelta.restart().asSeconds();
    int waves = 0;
    int gameScore=0;
    // run the program as long as the window is open
    while ((window->isOpen() || isRunning) && waves <= 4)
    {
        spawnTimer += deltaTime;
        gameScore=CollisionManager::GetInstance()->GetScore();
        //cout << score << endl;
        if (spawnTimer > 8) {
            Spawn(ribosome);
            spawnTimer = 0;
            waves += 1;
        }
        deltaTime = clockDelta.restart().asSeconds();
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }
        _Update(deltaTime);
        _Draw(gameScore, bg, title);
    }
    window->close();
    return gameScore;
}

void Game::Spawn(Ribosome* ribosome)
{
    vector<Enemy> enemies;
    for (int i = 0; i < 8; i++) {
        enemy = new Enemy("Enemigo" + to_string(i));
        enemy->setPosition(enemy->RandPos());
        enemy->SetRibosome(ribosome);
        CollisionManager::GetInstance()->AddEntity(enemy);
        enemies.push_back(*enemy);
    }

}
