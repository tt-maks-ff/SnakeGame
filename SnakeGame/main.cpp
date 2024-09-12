#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	int M = 30, N = 20;
	int size = 32;
	int winWidth = size * M, winHeight = size * N;

	sf::RenderWindow window(sf::VideoMode(winWidth, winHeight), "Snake Game");

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

			window.clear();
			window.display();
		}
	}
	return 0;
}