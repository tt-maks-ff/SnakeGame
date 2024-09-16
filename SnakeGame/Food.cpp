#include "Food.h"

Food::Food() {
	this->posX = 0;
	this->posY = 0;
	this->isActive = false;
}

void Food::spawnFood(int M, int N, int sizeOfUnit, std::vector<Unit*> *body)
{
	bool isNormalPos = false;
	while (!isNormalPos) {
		this->posX = rand() % M * sizeOfUnit;
		this->posY = rand() % N * sizeOfUnit;

		for (auto unit : *body) {
			if (this->posX == unit->getPosX() && this->posY == unit->getPosY()) isNormalPos = false;
			else {
				isNormalPos = true;
				break;
			}
		}
	}

	this->foodShape = sf::RectangleShape(sf::Vector2f(32, 32));
	this->foodShape.setFillColor(sf::Color::Red);
	this->foodShape.setPosition(this->getPosX(), this->getPosY());
	this->isActive = true;
}

int Food::getPosX() {
	return this->posX;
}

int Food::getPosY() {
	return this->posY;
}

void Food::setPosX(int posX) {
	this->posX = posX;
}

void Food::setPosY(int posY) {
	this->posY = posY;
}

sf::RectangleShape Food::getFoodShape() {
	return this->foodShape;
}

int Food::checkSnakeCollision(std::vector<Unit*>* body) {
	if (this->posX == body->at(0)->getPosX() && this->posY == body->at(0)->getPosY()) return 1;
	return 0;
}

void Food::removeUnit() {
	this->isActive = false;
}

Food::~Food()
{
}