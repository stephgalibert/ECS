#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "AComponent.hpp"

namespace Component
{
	class Render : public AComponent
	{
	public:
		static const int Index = 0;

	public:
		Render(void);
		virtual ~Render(void);

		void setTexture(std::string const& path);
		sf::Sprite &getSprite(void);

	private:
		sf::Texture texture_;
		sf::Sprite sprite_;
	};
}
