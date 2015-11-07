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
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");

	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	sf::Vector2f vec1 = sf::Vector2f(9, 4);
	sf::Vector2f vec2 = sf::Vector2f(7, 2);
	float scalar1 = 21;
	sf::Vector2f result;
	float resultScalar;

	//add 2 vectors
	result = VectorMathsHelper::GetInstance()->AddVectors(vec1, vec2);
	std::cout << "Result of adding vec1 and vec2: " << result.x << ", " << result.y << std::endl;

	//subtract 2 vectors
	result = VectorMathsHelper::GetInstance()->SubtractVectors(vec1, vec2);
	std::cout << "Result of subtracting vec2 from vec1: " << result.x << ", " << result.y << std::endl;

	//multiply 2 vectors
	result = VectorMathsHelper::GetInstance()->MultiplyVectors(vec1, vec2);
	std::cout << "Result of multiplying vec1 by vec2: " << result.x << ", " << result.y << std::endl;

	//divide 2 vectors
	result = VectorMathsHelper::GetInstance()->DivideVectors(vec1, vec2);
	std::cout << "Result of dividing vec1 by vec2: " << result.x << ", " << result.y << std::endl;

	//multiply a vector by a scalar
	result = VectorMathsHelper::GetInstance()->MultiplyVectorScalar(vec1,scalar1);
	std::cout << "Result of multiplying vec1 by scalar1: " << result.x << ", " << result.y << std::endl;

	//divide a vector by a scalar
	result = VectorMathsHelper::GetInstance()->DivideVectorScalar(vec1, scalar1);
	std::cout << "Result of dividing vec1 by scalar1: " << result.x << ", " << result.y << std::endl;

	//dot product
	resultScalar = VectorMathsHelper::GetInstance()->DotProduct(vec1, vec2);
	std::cout << "Result of dot product of vec1 and vec2: " << resultScalar << std::endl;

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

		//prepare frame
		window.clear();

		//draw frame items
		


		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}