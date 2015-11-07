#ifndef VECTORMATHSHELPER
#define VECTORMATHSHELPER

class VectorMathsHelper
{
public:
	static VectorMathsHelper* GetInstance();
	~VectorMathsHelper();

	/*Add two vectors together*/
	sf::Vector2f AddVectors(sf::Vector2f vec1, sf::Vector2f vec2);

	/*Subtract vector 2 from vector 1*/
	sf::Vector2f SubtractVectors(sf::Vector2f vec1, sf::Vector2f vec2);

	/*Multiply two vectors together*/
	sf::Vector2f MultiplyVectors(sf::Vector2f vec1, sf::Vector2f vec2);

	/*divide 2 vectors*/
	sf::Vector2f DivideVectors(sf::Vector2f vec1, sf::Vector2f vec2);

	/*Multiply a vector by a scalar*/
	sf::Vector2f MultiplyVectorScalar(sf::Vector2f vec1, float scalar);

	/*Divide a vector by a scalar*/
	sf::Vector2f DivideVectorScalar(sf::Vector2f vec1, float scalar);

	//Cross product
	sf::Vector2f CrossProduct(sf::Vector2f vec1, sf::Vector2f vec2);

	//Dot product
	float DotProduct(sf::Vector2f vec1, sf::Vector2f vec2);

	//euclidean distance
	float EuclideanDistance(sf::Vector2f vec1, sf::Vector2f vec2);

private:
	static bool instanceFlag;
	static VectorMathsHelper* instance;
	//private constructor
	VectorMathsHelper()
	{

	}
};

#endif;
