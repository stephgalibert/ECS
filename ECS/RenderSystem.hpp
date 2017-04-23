#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include <SFML\Graphics.hpp>

#include "Entity.hpp"
#include "RenderComponent.hpp"
#include "EntityManager.hpp"

namespace System
{
	class Render
	{
	public:
		Render(EntityManager &entityManager);
		~Render(void);

		void render(sf::RenderWindow &window);

	private:
		EntityManager &manager_;
	};
}

