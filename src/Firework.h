#pragma once

#include "Particle.h"
#include <vector>
#include <memory>
#include <SFML/Audio.hpp>

#define BANG_SIZE 60


extern sf::SoundBuffer baseBuffer;
extern sf::SoundBuffer bangBuffer;


class Firework
{

	sf::Sound sound;
	float secondsToFade;
	std::shared_ptr<ParticleBase> rocket;
	std::vector<ParticleExplosion> bang;
	bool vanished;
	bool bangVanished;
public:
	Firework(sf::RenderWindow &window);
	void update(sf::RenderWindow &window);
	Firework(const Firework &fwork);
	Firework & operator=(const Firework &fwork);
	static void setBuffers();
	~Firework();
};


