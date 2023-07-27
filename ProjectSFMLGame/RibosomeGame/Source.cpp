#include "Game.h"
#include <HighScoreManager.cpp>


//Concepto del juego:
// 
//El juego en si lo simplifique bastante con respecto a la idea original, pero me quedo un concepto bastante útil para
//seguir desarrollando la idea de juego que tenía.
//  
//El juego consiste en que el player(ribosoma) tiene que ir levantando los distintos aminoácidos(bolitas), según su color 
//para construir un peptido.Si levanta una bolita de su mismo color suma un punto en el score.al colisionar si la bolita 
//no es de su mismo color, tambien la levanta pero no suma al score y el ribosoma se vuelve más lento.En cambio si los 
//colores coinciden el ribosoma cambia de color y se vuelve mas rapido.El juego tiene 5 waves de spawns y cuando termina 
//el jugador puede ingresar su nombre por consola, y se agrega su score al Score Board
//
//Algunos temas que tiene el juego: En el source no me llama al destructor de game. Tambien si justo spawnea una bolita donde 
//esta el ribosoma se rompe el follow. Ademas, el color de fondo del ribosoma confunde un poco los colores, sobre todo el magenta.
// 
//Haciendo el juego me di un poco cuenta, que quiza una de las habilidades practicas mas claves a la hora de hacer game design 
//es lograr simplificar el juego sin que pierda jugabilidad



void displayLeaderBoard(leaderBoard lb) {

	// create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	sf::Font font;
	font.loadFromFile("Resources//Textures/xolonium-regular.ttf");
	sf::Text title;
	title.setFont(font);
	title.setCharacterSize(42);
	title.setFillColor(sf::Color::Red);
	title.setString("Scores");
	title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	title.setPosition(310, 40);

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(36);
	text.setFillColor(sf::Color::Red);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);
		// window.draw(...);
		window.draw(title);

		int sp = 130;
		for (int i = 0; i < lb.scores.size(); i++) {
			int j = (lb.scores[i].name + to_string(lb.scores[i].score)).size();
			string dots;
			for (int i = j; i <= 27; i++) {
				dots += ". ";
			}
			string s = lb.scores[i].name + dots + to_string(lb.scores[i].score);
			text.setString(s);
			text.setPosition(50, sp);
			window.draw(text);
			sp += 45;
		}

		// end the current frame
		window.display();
	}
}




int main()
{
    srand(time(0));

    Game game;
    int s= game.Run();
	//~Game();
    
    //building score
    leaderBoard lb = fileToVectorScores("Scores.dat");
    
    char name[MAX_WIDTH_NAME];
    cin >> name;
    Score score(s,name);
    lb.addNewScore(score, 10);

	writeScoresInFile(lb, "Scores.dat");

	displayLeaderBoard(lb);

    return 0;
}