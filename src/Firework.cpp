#include "Firework.h"

Firework::Firework(sf::RenderWindow & window)
{


	rocket = std::shared_ptr<ParticleBase>(new ParticleBase(window));
	vanished = false;
	bangVanished = false;
	secondsToFade = 1.f;
	sound.setBuffer(baseBuffer);
	sound.setVolume(rand() % 30 + 15);

	sound.play();
}
void Firework::update(sf::RenderWindow & window)
{
	if (rocket != nullptr)
	{
		rocket->update();
		rocket->render(window);
		if (rocket->falling())
		{
			//delayer.restart();
			for (int i = 0; i < BANG_SIZE; ++i)
			{
				bang.push_back(ParticleExplosion(rocket->getPosition()));
			}
			rocket = nullptr;
			sound.setBuffer(bangBuffer);
			sound.play();
		}
	}

	
	bool notEverythingFaded = false;
	for (auto &x : bang)
	{
		if (!x.exploded())
		{
			x.update();
			x.render(window);
			notEverythingFaded = true;
			//break;
		}
	}

	if (!notEverythingFaded && rocket == nullptr)
	{
		if(rand()% 101 < 10)
			*this = Firework(window);
	}

}

Firework::Firework(const Firework & fwork)
{
	rocket = fwork.rocket;
	bang = fwork.bang;
	//sound = fwork.sound;
	sound.setBuffer(baseBuffer);
	sound.setVolume(rand() % 30 + 15);

	sound.play();
}

Firework& Firework::operator=(const Firework & fwork)
{
	if (this == &fwork)
		return *this;

	rocket = fwork.rocket;
	bang = fwork.bang;
	//sound = fwork.sound;
	sound.setBuffer(baseBuffer);
	sound.setVolume(rand() % 30 + 15);
	sound.play();
	return *this;
}

void Firework::setBuffers()
{
	//Firework::bangBuffer.loadFromFile("Sounds/bang.wav");
	//Firework::baseBuffer.loadFromFile("Sounds/base.wav");
}

Firework::~Firework()
{
	
}
