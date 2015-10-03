//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>



////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Focus camera on player");
	sf::RenderWindow *pWindow = &window;
	sf::View player_view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
	//player_view.zoom(0.5f);
	unsigned int size = 100;
	sf::View minimap(sf::FloatRect(player_view.getCenter().x, player_view.getCenter().y, size, window.getSize().y*size / window.getSize().x));
	minimap.setViewport(sf::FloatRect(1.f - (1.f*minimap.getSize().x) / window.getSize().x - 0.02f, 1.f - (1.f*minimap.getSize().y) / window.getSize().y - 0.02f, (1.f*minimap.getSize().x) / window.getSize().x, (1.f*minimap.getSize().y) / window.getSize().y));
	minimap.zoom(4.f);

	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	Player* p = new Player();

	sf::Sprite background;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Assets/testingBackground.png");
	background.setTexture(backgroundTexture);
	background.setPosition(sf::Vector2f(-600, -300));

	sf::Sprite background2;
	sf::Texture backgroundTexture2;
	backgroundTexture2.loadFromFile("Assets/minmap.png");
	background2.setTexture(backgroundTexture2);
	background2.setPosition(sf::Vector2f(-600, -300));

	player_view.setViewport(sf::FloatRect(0, 0, 1, 1));
	//minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));


	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();


		}

		player_view.setCenter(p->getPosition());
		window.setView(player_view);

		p->Update();
		//prepare frame
		window.clear();

		//draw frame items
		window.draw(background);
		p->draw(*pWindow);
		window.setView(minimap);
		window.draw(background);
		p->draw(*pWindow);

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}