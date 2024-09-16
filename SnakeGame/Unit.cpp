#include "Unit.h"

Unit::Unit(int posX = 0, int posY = 0, bool isHead = false, std::vector<Unit*> *body = nullptr, int direction = 0, int number = 0) {
	this->number = number;
	
	if (isHead) {
		this->posX = posX;
		this->posY = posY;
		this->isHead = isHead;
		this->currentDirection = direction;
	}
	else {
		Unit* previousUnit = body->at(body->size() - 1);
		this->posX = previousUnit->getPosX();
		this->posY = previousUnit->getPosY();

		this->currentDirection = body->at(this->number - 1)->getCurrentDirection();

		switch (currentDirection) {
		case 1: {
			this->posY -= 32;
			break;
		}
		case 2: {
			this->posX -= 32;
			break;
		}
		case 3: {
			this->posY += 32;
			break;
		}
		case 4: {
			this->posX += 32;
			break;
		}
		}
	}

	this->snakeUnit = sf::RectangleShape(sf::Vector2f(32, 32));
	this->snakeUnit.setFillColor(sf::Color::Green);
	this->snakeUnit.setPosition(this->getPosX(), this->getPosY());
}

sf::RectangleShape Unit::getShape() {
	return this->snakeUnit;
}

int Unit::getCurrentDirection() {
	return this->currentDirection;
}

int Unit::getPosX() {
	return this->posX;
}

int Unit::getPosY() {
	return this->posY;
}

void Unit::setPosX(int posX) {
	this->posX = posX;
}

void Unit::setPosY(int posY) {
	this->posY = posY;
}

void Unit::move(std::vector<Unit*> *body) {
	if (this->isHead) {
		switch (this->currentDirection)
		{
		case 1: {
			this->posY -= 32;
			break;
		}
		case 2: {
			this->posX += 32;
			break;
		}
		case 3: {
			this->posY += 32;
			break;
		}
		case 4: {
			this->posX -= 32;
			break;
		}
		}
	}
	else {
		Unit* previousUnit = body->at(number - 1);
		this->posX = previousUnit->getPosX();
		this->posY = previousUnit->getPosY();
	}

	this->snakeUnit.setPosition(this->posX, this->posY);
}

bool Unit::isUnitHead() {
	return this->isHead;
}

void Unit::setDirection(int direction) {
	this->currentDirection = direction;
}

Unit::~Unit() {

}