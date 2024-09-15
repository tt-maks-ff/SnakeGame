#include "Snake.h"

Snake::Snake(int posX, int posY) {
	this->size = 0;
	this->body.push_back(new Unit(posX, posY, true, &body, 2, size));
	this->size++;

	for (int i = 0; i < 15; i++) {
		this->body.push_back(new Unit(0, 0, false, &body, 0, size));
		this->size++;
	}
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
	body.at(0)->addDirection(direction);
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

Snake::~Snake() {
	this->body.clear();
}