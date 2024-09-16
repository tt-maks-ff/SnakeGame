#pragma once
#include "SFML/Graphics.hpp"
#include "Unit.h"

class Food
{
public:
	Food();
	void spawnFood(int M, int N, int sizeOfUnit, std::vector<Unit*> *body);
	~Food();
	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);
	int checkSnakeCollision(std::vector<Unit*> *body);
	sf::RectangleShape getFoodShape();
	void removeUnit();
	bool isActive;

private:
	sf::RectangleShape foodShape;
	int posX, posY;
};