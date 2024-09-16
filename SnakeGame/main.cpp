#include "Snake.h"
#include "Food.h"
#include <iostream>

int main() {
	int sizeOfUnit = 32;
	int M = 30, N = 20;
	int windowWidth = sizeOfUnit * M, windowHeight = sizeOfUnit * N;

	float FPS = 10;

	Food food;
	Snake snake(windowWidth / 2, windowHeight / 2);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.f;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake Game", sf::Style::Close, settings);

	sf::Clock fpsClock, foodClock;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();

			if (sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Up: {
					if (snake.getCurrentDirection() != 3) snake.goTo(1);
					break;
				}
				case sf::Keyboard::Down: {
					if (snake.getCurrentDirection() != 1) snake.goTo(3);
					break;
				}
				case sf::Keyboard::Left: {
					if (snake.getCurrentDirection() != 2) snake.goTo(4);
					break;
				}
				case sf::Keyboard::Right: {
					if (snake.getCurrentDirection() != 4) snake.goTo(2);
					break;
				}
				}
			}
		}

		std::vector<Unit*> units = snake.getAllUnits();
		for (auto unit : units) window.draw(unit->getShape());

		if (!food.isActive) {
			food.spawnFood(M, N, sizeOfUnit);
		}

		window.draw(food.getFoodShape());

		window.display();
		snake.Update();
		window.clear();
		
		if (snake.checkCollision()) return 1;
		if (food.checkSnakeCollision(&units)) {
			food.removeUnit();
			snake.addUnit();
		}

		// fps
		sf::Int32 frame_duration = fpsClock.getElapsedTime().asMilliseconds();
		sf::Int32 time_to_sleep = int(1000.f / FPS) - frame_duration;
		if (time_to_sleep > 0)
		{
			sf::sleep(sf::milliseconds(time_to_sleep));
			fpsClock.restart();
		}
	}
	return 0;
}