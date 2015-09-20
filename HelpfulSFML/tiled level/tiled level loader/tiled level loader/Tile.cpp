#include "stdafx.h"
#include "Tile.h"

Tile::Tile(sf::Vector2f pos, int x, int y, int w, int h)
{
	setPosition(pos);
	tileTX = x;
	tileTY = y;
	tileTWidth = w;
	tileTHeight = h;
	loadTexture();
}

Tile::~Tile()
{

}

void Tile::loadTexture()
{
	//load the correct texture or load the debug texture if something is wrong
	if (mTexture.loadFromFile("Assets/Tiles/BackgroundTiles.png")){}
	else mTexture.loadFromFile("Assets/Sprites/Debug.png");	//if it fails load placeholder
	mSprite.setTexture(mTexture);

	mSprite.setTextureRect(sf::IntRect(tileTX, tileTY, tileTWidth, tileTHeight));
}

void Tile::draw(sf::RenderTarget& window, sf::RenderStates state) const{}

void Tile::draw(sf::RenderTarget& window)
{
	window.draw(mSprite, getTransform());
}