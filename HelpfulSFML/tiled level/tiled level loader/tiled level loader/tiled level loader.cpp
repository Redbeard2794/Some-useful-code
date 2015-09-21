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
#include "rapidxml_utils.hpp"
using namespace rapidxml;
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <vector>
////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Simple Player class");
	sf::RenderWindow *pWindow = &window;

	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	//create a formatted text string
	sf::Text text;
	text.setFont(font);
	text.setString("Here is a simple player class in action.");
	text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	text.setPosition(20, 0);
	text.setCharacterSize(40);

	Player* p = new Player();

	std::vector<Tile*> tiles;
	//tiles.reserve(10);

	//rapidxml::file<> xmlFile("Assets/Levels/level1.xml"); // Default template is char
	//rapidxml::xml_document<> doc;
	//doc.parse<0>(xmlFile.data());
	//std::cout << "Name of root node is: " << doc.first_node()->name() << "\n" << std::endl;

	xml_document<> doc;
	std::ifstream file("Assets/Levels/level1.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	xml_node<> *pRoot = doc.first_node();
	std::cout << "Name of root node is: " << doc.first_node()->name() << "\n" << std::endl;

	
	xml_node<>* level = doc.first_node("level");
	xml_node<>* tile = level->first_node("tile");
	while (tile != NULL)
	{
		std::string type = "";
		int x = 0, y = 0, textureRectX = 0, textureRectY = 0, textureRectWidth = 0, textureRectHeight = 0;

		std::cout << "Type: " << tile->first_attribute("type")->value() << std::endl;
		type = tile->first_attribute("type")->value();

		std::cout << "X:" << tile->first_node("posX")->value() << std::endl;
		x = atoi(tile->first_node("posX")->value());

		std::cout << "Y: " << tile->first_node("posY")->value() << std::endl;
		y = atoi(tile->first_node("posY")->value());

		std::cout << "textureRectX: " << tile->first_node("textureRectX")->value() << std::endl;
		textureRectX = atoi(tile->first_node("textureRectX")->value());

		std::cout << "textureRectY: " << tile->first_node("textureRectY")->value() << std::endl;
		textureRectY = atoi(tile->first_node("textureRectY")->value());

		std::cout << "textureRectWidth: " << tile->first_node("textureRectWidth")->value() << std::endl;
		textureRectWidth = atoi(tile->first_node("textureRectWidth")->value());

		std::cout << "textureRectHeight: " << tile->first_node("textureRectHeight")->value() << std::endl;
		textureRectHeight = atoi(tile->first_node("textureRectHeight")->value());

		//create the tile
		Tile* t = new Tile(sf::Vector2f(x, y), textureRectX, textureRectY, textureRectWidth, textureRectHeight, type);
		tiles.push_back(t);
		std::cout << "Size of tiles vector: " << tiles.size() << std::endl;

		tile = tile->next_sibling("tile");
	}


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
		p->Update();
		//prepare frame
		window.clear();

		//draw frame items

		p->draw(*pWindow);

		for (int i = 0; i < tiles.size(); i++)
		{
			Tile * t = tiles.at(i);
			t->draw(window);
		}

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}