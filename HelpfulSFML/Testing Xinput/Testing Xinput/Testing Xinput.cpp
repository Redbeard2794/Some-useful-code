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

#include <Xinput.h>
#pragma comment(lib, "XInput9_1_0.lib")   // Library. If your compiler doesn't support this type of lib include change to the corresponding one


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

	//create a formatted text string
	sf::Text text;
	text.setFont(font);
	text.setString("Hello World");
	text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	text.setPosition(20, 40);
	text.setCharacterSize(40);
	//if (sf::Joystick::isConnected(0))
	//{
	//	// joystick number 0 is connected
	//	std::cout << "Contoller 0 is connected" << std::endl;
	//	int buttonCount = sf::Joystick::getButtonCount(0);
	//	std::cout << "It has " << buttonCount << " buttons" << std::endl;
	//}


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

			//SFML's way(doesn't support rumble or the use of the triggers)

			//if (sf::Joystick::isButtonPressed(0, 0))//A on xbox one controller
			//{
			//	std::cout << "A button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 1))//B on xbox one controller
			//{
			//	std::cout << "B button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 2))//X on xbox one controller
			//{
			//	std::cout << "X button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 3))//Y on xbox one controller
			//{
			//	std::cout << "Y button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 4))//LB on xbox one controller
			//{
			//	std::cout << "LB button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 5))//RB on xbox one controller
			//{
			//	std::cout << "RB button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 6))//View on xbox one controller
			//{
			//	std::cout << "View button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 7))//Menu on xbox one controller
			//{
			//	std::cout << "Menu button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 8))//Left analog click on xbox one controller
			//{
			//	std::cout << "Left analog click button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 9))//Right analog click on xbox one controller
			//{
			//	std::cout << "Right analog click button pressed on pad 0" << std::endl;
			//}
			//if (sf::Joystick::isButtonPressed(0, 10))// on xbox one controller
			//{
			//	std::cout << "10 button pressed on pad 0" << std::endl;
			//}


			//Xinputs way
			XINPUT_STATE state;
			memset(&state, 0, sizeof(XINPUT_STATE));

			if (XInputGetState(0, &state) == ERROR_SUCCESS)
			{
				// Controller is connected

				//face buttons(a,b,x,y)
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_A)
				{
					// Button A is pressed
					std::cout << "A button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_B)
				{
					// Button A is pressed
					std::cout << "B button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_X)
				{
					// Button A is pressed
					std::cout << "X button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_Y)
				{
					// Button A is pressed
					std::cout << "Y button pressed" << std::endl;
				}

				//shoulder buttons(rb,lb)
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER)
				{
					// Button A is pressed
					std::cout << "RB button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)
				{
					// Button A is pressed
					std::cout << "LB button pressed" << std::endl;
				}

				//menu/start and view/back
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_START)
				{
					// Button A is pressed
					std::cout << "Menu button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK)
				{
					// Button A is pressed
					std::cout << "View button pressed" << std::endl;
				}

				//dpad
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
				{
					// Button A is pressed
					std::cout << "Dpad up button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
				{
					// Button A is pressed
					std::cout << "Dpad down button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
				{
					// Button A is pressed
					std::cout << "Dpad right button pressed" << std::endl;
				}
				if (state.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
				{
					// Button A is pressed
					std::cout << "Dpad left button pressed" << std::endl;
				}

				//deadzones
				//https://msdn.microsoft.com/en-us/library/windows/desktop/ee417001%28v=vs.85%29.aspx#dead_zone


				XINPUT_VIBRATION motor;
				memset(&motor, 0, sizeof(XINPUT_VIBRATION));

				//vibrate constantly(both motors)
				//motor.wLeftMotorSpeed = 32000; // use any value between 0-65535 here
				//motor.wRightMotorSpeed = 16000; // use any value between 0-65535 here

				//triggers
				if (state.Gamepad.bLeftTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
				{
					motor.wLeftMotorSpeed = state.Gamepad.bLeftTrigger << 9000;//low frequency motor
					std::cout << "LT button pressed" << std::endl;
				}

				if (state.Gamepad.bRightTrigger > XINPUT_GAMEPAD_TRIGGER_THRESHOLD)
				{
					motor.wRightMotorSpeed = state.Gamepad.bRightTrigger << 5000;//high frequency motor
					std::cout << "RT button pressed" << std::endl;
				}

				XInputSetState(0, &motor);

			}
			else
			{
				// Controller is not connected, shouldn't recheck it for a few seconds
				std::cout << "Controller not connected" << std::endl;
			}

		}

		//prepare frame
		window.clear();

		//draw frame items


		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}