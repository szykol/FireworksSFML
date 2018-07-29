#include "Particle.h"

Particle::Particle(const sf::Vector2f & position, float radius)
	:sf::CircleShape(radius, 60U), acceleration(0.f,0.f)
{
	setPosition(position);
	sf::Color randomColor(rand() % 256, rand() % 256, rand() % 256);
	setFillColor(randomColor);
}

bool ParticleBase::falling() const
{
	return direction.y >= 0;
}

Particle::~Particle()
{
}

sf::Vector2f randomVector2f()
{
	int randA = rand() % 11 - 5;
	while (randA == 0)
		randA = rand() % 11 - 5;

	int randB = rand() % 11 - 5;
	while (randB == 0)
		randB = rand() % 11 - 5;

	sf::Vector2f randVect(randA, randB);
	randVect = randVect / sqrt((randVect.x * randVect.x) + (randVect.y * randVect.y));
	return randVect;
}

ParticleBase::ParticleBase(sf::RenderWindow & window, float radius)
	:Particle(sf::Vector2f(rand() % window.getSize().x, window.getSize().y + radius * 3), radius)
{	
	direction = sf::Vector2f(0.f, -(rand() % 5 + 15));
}

void ParticleBase::update()
{
	acceleration *= 0.f;
	acceleration += gravityVector;
	direction += acceleration;
	move(direction);
}

ParticleExplosion::ParticleExplosion(const sf::Vector2f & position, float radius)
	:Particle(position, radius)
{
	direction = randomVector2f();
	direction *= float(rand() % 7 + 1);
	explosionEnded = false;
}

void ParticleExplosion::update()
{
	acceleration *= 0.f;
	acceleration += gravityBangVector;
	direction += acceleration;
	direction *= 0.95f;
	

	
	sf::Color color = getFillColor();
	if (color.a > 0)
	{
		color.a -= 5;
		setFillColor(color);
	}
	else
		explosionEnded = true;

	move(direction);
}
