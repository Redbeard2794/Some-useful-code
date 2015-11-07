#include "stdafx.h"
#include "VectorMathsHelper.h"

bool VectorMathsHelper::instanceFlag = false;
VectorMathsHelper* VectorMathsHelper::instance = NULL;

VectorMathsHelper* VectorMathsHelper::GetInstance()
{
	if (!instanceFlag)
	{
		instance = new VectorMathsHelper();
		instanceFlag = true;
		return instance;
	}
	else return instance;
}

VectorMathsHelper::~VectorMathsHelper()
{
	instanceFlag = false;
}

/*Add two vectors together*/
sf::Vector2f VectorMathsHelper::AddVectors(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return sf::Vector2f((vec1.x + vec2.x), (vec1.y + vec2.y));
}

/*Subtract vector 2 from vector 1*/
sf::Vector2f VectorMathsHelper::SubtractVectors(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return sf::Vector2f((vec1.x - vec2.x), (vec1.y - vec2.y));
}

/*Multiply two vectors together*/
sf::Vector2f VectorMathsHelper::MultiplyVectors(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return sf::Vector2f((vec1.x * vec2.x), (vec1.y * vec2.y));
}

/*divide 2 vectors*/
sf::Vector2f VectorMathsHelper::DivideVectors(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return sf::Vector2f((vec1.x / vec2.x), (vec1.y / vec2.y));
}

/*Multiply a vector by a scalar*/
sf::Vector2f VectorMathsHelper::MultiplyVectorScalar(sf::Vector2f vec1, float scalar)
{
	return sf::Vector2f(vec1.x*scalar, vec1.y*scalar);
}

/*Divide a vector by a scalar*/
sf::Vector2f VectorMathsHelper::DivideVectorScalar(sf::Vector2f vec1, float scalar)
{
	return sf::Vector2f(vec1.x/scalar, vec1.y/scalar);
}

//Dot product
float VectorMathsHelper::DotProduct(sf::Vector2f vec1, sf::Vector2f vec2)
{
	return ((vec1.x*vec2.x) + (vec1.y*vec2.y));
}