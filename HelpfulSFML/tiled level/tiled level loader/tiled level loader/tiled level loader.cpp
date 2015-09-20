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

	Tile* testTile = new Tile(sf::Vector2f(0, 0), 0, 0,50,50);
	Tile* testTile2 = new Tile(sf::Vector2f(50, 0), 50, 50, 50, 50);
	Tile* testTile3 = new Tile(sf::Vector2f(100, 0), 100, 100, 50, 50);

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
	std::cout << "Name of root node is: " << doc.first_node()->name() << "\n" << std::endl;
	xml_node<> *pRoot = doc.first_node();

	xml_node<> *pNode = pRoot->first_node("node");
	std::cout << "Name of root nodes first node is: " << pNode->first_node()->name() << "\n" << std::endl;

	for (xml_node<> *pNode = pRoot->first_node("node"); pNode; pNode = pNode->next_sibling())
	{
		// This loop will walk you through two nodes:
		//node attribute = "0" and then node attribute = "1"
		// Do something here

	}


	//xml_node<> *node = doc.first_node("tile");
	//std::cout << "Node 1, Attribute 1: " << node->first_attribute("x", 0, false) << std::endl;

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
		testTile->draw(*pWindow);
		testTile2->draw(*pWindow);
		testTile3->draw(*pWindow);

		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}