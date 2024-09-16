#include "Snake.h"

Snake::Snake(int posX, int posY) {
	this->size = 0;
	this->body.push_back(new Unit(posX, posY, true, &body, 2, size));
	this->size++;
	this->addUnit();
}

std::vector<Unit*> Snake::getAllUnits() {
	return this->body;
}

void Snake::Update() {
	for (int i = size - 1; i >= 0; i--) {
		body.at(i)->move(&body);
	}
}

void Snake::goTo(int direction) {
	body.at(0)->setDirection(direction);
}

int Snake::checkCollision() {
	for (auto unit : body) {
		if (!unit->isUnitHead()) {
			if (unit->getPosX() == body.at(0)->getPosX() && unit->getPosY() == body.at(0)->getPosY()) return 1;
		}
	}
	return 0;
}

int Snake::getCurrentDirection() {
	return this->body.at(0)->getCurrentDirection();
}

void Snake::addUnit() {
	this->body.push_back(new Unit(0, 0, false, &body, 0, size));
	this->size++;
}

int Snake::getHeadX() {
	return this->body.at(0)->getPosX();
}

int Snake::getHeadY() {
	return this->body.at(0)->getPosY();
}

void Snake::checkBorders(int M, int N, int sizeOfUnit) {
	if (this->body.at(0)->getPosX() < 0) this->body.at(0)->setPosX(M * sizeOfUnit);
	if (this->body.at(0)->getPosX() > M * sizeOfUnit) this->body.at(0)->setPosX(0);
	if (this->body.at(0)->getPosY() < 0) this->body.at(0)->setPosY(N * sizeOfUnit);
	if (this->body.at(0)->getPosY() > N * sizeOfUnit) this->body.at(0)->setPosY(0);
}

Snake::~Snake() {
	this->body.clear();
}
