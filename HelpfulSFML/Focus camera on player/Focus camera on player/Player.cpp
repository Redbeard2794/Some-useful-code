#include "stdafx.h"
#include "Player.h"



Player::Player() :speed(0.05f), score(0), velocity(sf::Vector2f(1, 1)), health(100)
{
	//load the correct texture or load the debug texture if something is wrong
	if (mTexture.loadFromFile("Assets/Sprites/Player/Dranzer.png")){}
	else mTexture.loadFromFile("Assets/Sprites/Debug.png");	//if it fails load placeholder

	mSprite.setTexture(mTexture);
	setPosition(200, 200);

}//end constructor


Player::~Player()
{
	//blank destructor for now
}

void Player::Update()
{
	Move();
	//boundary();
}//end Update()


void Player::Move()
{
	//detecting keyboard input for player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		setPosition(sf::Vector2f(getPosition().x, getPosition().y - speed));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		setPosition(sf::Vector2f(getPosition().x, getPosition().y + speed));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		setPosition(sf::Vector2f(getPosition().x - speed, getPosition().y));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		setPosition(sf::Vector2f(getPosition().x + speed, getPosition().y));
	}
}//end Move()

void Player::draw(sf::RenderTarget& window, sf::RenderStates state) const
{

}//end Draw()

void Player::draw(sf::RenderTarget& window)
{
	window.draw(mSprite, getTransform());
}
void Player::boundary()
{
	//STOP THE PLAYER FROM GOING OFF THE EDGE OF THE SCREEN.....FINALLY!!!!
	if (getPosition().x > SCREENWIDTH)
	{
		setPosition(sf::Vector2f(20, getPosition().y));
	}
	if (getPosition().x < 0)
	{
		setPosition(sf::Vector2f(SCREENWIDTH - 20, getPosition().y));
	}
	if (getPosition().y > SCREENHEIGHT)
	{
		setPosition(sf::Vector2f(getPosition().x, 20));
	}
	if (getPosition().y < 0)
	{
		setPosition(sf::Vector2f(getPosition().x, SCREENHEIGHT - 20));
	}
}
