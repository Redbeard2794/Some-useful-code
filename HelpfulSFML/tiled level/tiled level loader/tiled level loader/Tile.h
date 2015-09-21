#ifndef TILE_H
#define TILE_H

class Tile : public sf::Drawable, public sf::Transformable
{
private:
	//texture rect x,y,width,height
	int tileTX;
	int tileTY;
	int tileTWidth;
	int tileTHeight;
	sf::Sprite mSprite;
	sf::Texture mTexture;
	std::string type;
public:
	//constructor takes in position, width , height, type
	Tile(sf::Vector2f pos, int x, int y, int w, int h, std::string t);
	~Tile();
	void loadTexture();
	void draw(sf::RenderTarget& window, sf::RenderStates state) const;
	void Tile::draw(sf::RenderTarget& window);

	//add gets and sets
};
#endif