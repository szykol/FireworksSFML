#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "Particle.h"
#include "Firework.h"

#define PARTICLES_SIZE 20

sf::SoundBuffer baseBuffer;
sf::SoundBuffer bangBuffer;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Fireworks!", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	std::srand(std::time(NULL));

	baseBuffer.loadFromFile("Sounds/base.wav");
	bangBuffer.loadFromFile("Sounds/bang.wav");

	std::vector<Firework> fireworks;

	while (window.isOpen())
	{
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		if (fireworks.size() < 5)
			fireworks.push_back(Firework(window));



		for (auto &x : fireworks)
			x.update(window);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();
		
		window.display();
	}
	return 0;
}