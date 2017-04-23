#pragma once

#include <SFML\Graphics.hpp>

#include "EntityManager.hpp"
#include "RenderSystem.hpp"

class Engine
{
public:
	Engine(void);
	~Engine(void);

	void draw(sf::RenderWindow &window);
	void update(float delta);

	// tmp
	void createPlayer();

private:
	EntityManager entityManager_;

	System::Render renderSystem_;
};

