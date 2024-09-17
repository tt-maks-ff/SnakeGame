#include "Snake.h"
#include "Food.h"
#include <iostream>

int main() {
	// window settings
	int sizeOfUnit = 32;
	int M = 30, N = 20;
	int windowWidth = sizeOfUnit * M, windowHeight = sizeOfUnit * N;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.f;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake Game", sf::Style::Close, settings);

	// lock keyboard
	bool isKeysLocked = false;

	// framerate
	float FPS = 10;

	// game objects
	Food food;
	Snake snake(windowWidth / 2, windowHeight / 2);

	// timers
	sf::Clock fpsClock, foodClock;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Event::KeyPressed && !isKeysLocked) {
				switch (event.key.code)
				{
				case sf::Keyboard::Up: {
					if (snake.getCurrentDirection() != 3) snake.goTo(1);
					isKeysLocked = true;
					break;
				}
				case sf::Keyboard::Down: {
					if (snake.getCurrentDirection() != 1) snake.goTo(3);
					isKeysLocked = true;
					break;
				}
				case sf::Keyboard::Left: {
					if (snake.getCurrentDirection() != 2) snake.goTo(4);
					isKeysLocked = true;
					break;
				}
				case sf::Keyboard::Right: {
					if (snake.getCurrentDirection() != 4) snake.goTo(2);
					isKeysLocked = true;
					break;
				}
				}
			}
		}

		std::vector<Unit*> *body = snake.getAllUnits();
		for (auto unit : *body) window.draw(unit->getShape());

		if (!food.isActive) {
			food.spawnFood(M, N, sizeOfUnit, body);
		}

		window.draw(food.getFoodShape());

		window.display();
		snake.Update();
		window.clear();
		
		if (snake.checkCollision()) return 1;
		if (food.checkSnakeCollision(body)) {
			food.removeUnit();
			snake.addUnit();
		}
		isKeysLocked = true;
		snake.checkBorders(M, N, sizeOfUnit);

		// fps
		sf::Int32 frame_duration = fpsClock.getElapsedTime().asMilliseconds();
		sf::Int32 time_to_sleep = int(1000.f / FPS) - frame_duration;
		if (time_to_sleep > 0)
		{
			sf::sleep(sf::milliseconds(time_to_sleep));
			isKeysLocked = false;
			fpsClock.restart();
		}
	}
	return 0;
}