#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Unit
{
public:
	Unit(int posX, int posY, bool isHead, std::vector<Unit*>* body, int direction, int number);
	sf::RectangleShape getShape();
	int getCurrentDirection();
	void setDirection(int direction);
	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);
	void move(std::vector<Unit*>* body);
	bool isUnitHead();
	~Unit();

private:
	bool isHead;
	int posX, posY;
	int currentDirection;
	Unit* previousUnit;
	sf::RectangleShape snakeUnit;
	unsigned int number;
};