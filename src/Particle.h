#pragma once
#include <SFML/Graphics.hpp>

#define gravityVector sf::Vector2f(0.f, 0.2f)
#define gravityBangVector sf::Vector2f(0.f, 0.1f)
#define stopVector sf::Vector2f(0.f,0.f)

class Particle : public sf::CircleShape
{
protected:
	sf::Vector2f direction;
	sf::Vector2f acceleration;
public:
	Particle(const sf::Vector2f &position, float radius = 3.5f);
	virtual void update() = 0;
	virtual void render(sf::RenderWindow &window) final { window.draw(*this); }
	
	~Particle();
};

class ParticleBase : public Particle
{
public:
	ParticleBase(sf::RenderWindow &window, float radius = 3.5f);
	virtual void update();
	bool falling() const;
	~ParticleBase() {}

};
class ParticleExplosion : public Particle
{
	bool explosionEnded;
public:
	ParticleExplosion(const sf::Vector2f &position, float radius = 3.5f);
	virtual void update();
	~ParticleExplosion() {}
	bool exploded() const { return explosionEnded; }
};

sf::Vector2f randomVector2f();


