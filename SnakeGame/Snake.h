#pragma once
#include "Unit.h"
#include <vector>

class Snake {
public:
	Snake(int posX, int posY);
	~Snake();
	std::vector<Unit*> getAllUnits();
	void Update();
	void goTo(int direction);
	int checkCollision();
	int getCurrentDirection();

private:
	int size;
	std::vector<Unit*> body;
};
